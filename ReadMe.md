### 🧩 1. Aşama: Küçük Liste Kurallarını Tüm Listeye Uygulamak

İlk denememde, liste sıralı mı diye kontrol ederek başladım. Eğer zaten sıralıysa, hiçbir işlem yapmadan algoritmayı sonlandırıyordum.

Eleman sayısına göre basit kurallar uyguladım:

- Eğer listedeki eleman sayısı **2** ise:
  - Sadece gerekliyse bir `swap` işlemi yaparak sıralamayı tamamlıyordum.

- Eğer eleman sayısı **3** ise:
  - `sort_three` adını verdiğim bir fonksiyonla bu üç elemanı sıralıyordum.
  - Bu fonksiyon içinde duruma göre `swap`, `rotate` veya `reverse` işlemlerinden uygun olanı seçiyordum.

- Eğer liste **3'ten büyükse**:
  - A yığınında en küçük elemanı buluyordum.
  - Bu elemanı yukarı taşımak için:
    - Eğer yığının üst yarısındaysa `rotate`,
    - Alt yarısındaysa `reverse` kullanıyordum.
  - En küçük eleman yukarı geldikten sonra `push_b` ile B yığınına gönderiyordum.
  - Bu işlemi A yığınında sadece 3 eleman kalana kadar tekrarlıyordum.

- Son olarak, A’da kalan 3 elemanı `sort_three` ile sıralayıp,
- B’deki elemanları teker teker `push_a` ile A’ya geri taşıyarak işlemi tamamlıyordum.
  - Çünkü bu noktada B yığını zaten küçükten büyüğe sıralıydı.

Bu yaklaşım küçük listelerde oldukça işe yarasa da, eleman sayısı büyüdükçe `rotate` ve `reverse` işlemlerinin sayısı artmaya başladı. Dolayısıyla daha verimli yöntemler araştırmam gerekti.

---

### ➗ 2. Aşama: Listeyi Tek Median ile Bölmek

İlk yaklaşımımda işlem sayısı fazlalaşınca, listeyi iki gruba ayırarak ilerlemenin daha verimli olabileceğini düşündüm. Bunun için önce tüm listenin **median** (ortanca) değerini hesapladım.

Bu değeri bir eşik olarak kullanarak A yığınındaki elemanları ikiye ayırdım:

- Median’dan **küçük veya eşit olanları** B yığınına gönderdim (`push_b`).
- Daha **büyük olanları** A yığınında tuttum ve sonra sıraladım.

Bu yöntemle, küçük değerleri önce ayırarak sıralama işini daha yönetilebilir hale getirmeyi amaçladım.

Ancak bu yapının bazı zorlukları vardı:

- B yığınına giden elemanlar rastgele bir sırada oluyordu.
- Geriye dönerken bu elemanları sıraya koymak için çok sayıda `rotate` ve `push` işlemi gerekiyordu.
- Ayrıca sadece iki parçaya ayırmak yeterince kontrollü bir dağılım sağlamıyordu.

Yine de, ilk yönteme göre daha az işlemle sıralama yapabildim. Bu da beni daha gelişmiş bir parçalama yöntemine yönlendirdi.

---

## 🧱 Aşama 3: Listeyi Chunk’lara Bölerek Sıralama

Bu aşamada, büyük bir listeyi daha küçük **chunk** (parça)’lara bölerek sıralama işlemi gerçekleştirilir. Bu yöntem, işlemleri hem daha yönetilebilir kılar hem de performansı artırır.

---

### 🔹 Chunk Nedir?

**Chunk**, büyük bir veri listesinin daha küçük alt gruplara bölünmesidir. Her chunk belirli bir sayı aralığını kapsar.

Örnek:
- Liste: `[3, 12, 25, 37, 44, 50, 61, 70]`
- Min: 3, Max: 70 → Aralık: `67`
- 5 parçaya bölünecekse → Her bir chunk ≈ `13.4` değerlik aralık kapsar.

Chunk aralığı aşağıdaki formülle hesaplanır:

```c
ch_range = (max_val - min_val + ch_size - 1) / ch_size;
```

> Bu formül, tamsayı bölmede veri kaybını önlemek için yukarı yuvarlama sağlar.

Örnek hesaplama:

```c
min_val = 3;
max_val = 70;
ch_size = 5;

ch_range = (70 - 3 + 5 - 1) / 5 = 14;
```

Buna göre chunk sınırları:

- Chunk 1: [3, 17)
- Chunk 2: [17, 31)
- Chunk 3: [31, 45)
- Chunk 4: [45, 59)
- Chunk 5: [59, 73)

---

### 🔹 Eşik (Threshold) Nedir?

Her chunk’ın **üst sınırı**, o parça için bir **eşik (threshold)** olarak kullanılır.

Örnek:
- Eşik = 40 ise → A yığınındaki değeri 40’tan küçük olanlar B’ye gönderilir.
- Eğer değer threshold’un **alt yarısında** ise (`< median`) → `rotate_b` ile B’de alta gönderilir.

Bu şekilde, B yığını kendi içinde kabaca sıralanmış olur.

---

### 🔹 Genel İşleyiş

1. A yığınındaki elemanlar, chunk threshold’una göre B’ye aktarılır.
2. Daha küçük olanlar B’de alta döndürülür (`rotate_b`).
3. A’da 3 eleman kalana kadar devam eder.
4. A’daki 3 eleman `sort_three()` ile sıralanır.
5. B’deki en büyük eleman teker teker yukarı alınarak A’ya geri gönderilir.
6. Sonuç olarak A yığını küçükten büyüğe sıralanmış olur.

---

### 🔸 Avantajları

- **Kontrollü** veri dağılımı sağlar.
- `rotate`, `reverse`, `push` işlemlerini **azaltır**.
- Büyük listelerde **önceki yöntemlerden daha verimlidir**.

---

### 📌 Genel Değerlendirme

Bu üç aşama boyunca farklı stratejiler deneyerek hangi yöntemlerin hangi listelerde daha iyi çalıştığını gözlemleme fırsatım oldu. En sonunda chunk tabanlı bölme yöntemi, işlem sayısını azaltmak ve yığınları daha kontrollü yönetmek açısından en verimli çözüm oldu.
