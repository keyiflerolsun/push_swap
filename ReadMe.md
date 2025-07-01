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

### 🧱 3. Aşama: Listeyi Chunk’lara Bölmek (Şu Anki Yöntem)

Son aşamada, listeyi sadece iki parçaya ayırmak yerine daha küçük ve kontrollü bölümlere ayırmaya karar verdim. Bu bölümler genellikle **chunk** olarak adlandırılır.

Kodda yaptığım işlem şu şekilde:

- Önce A yığınındaki minimum ve maksimum değeri `get_min_max` fonksiyonuyla tespit ettim.
- Bu aralık `(max - min)` yaklaşık olarak 5 eşit parçaya bölündü (`ch_range = (max - min) / 5`).
- Her bir chunk için bir **eşik değer** (`threshold`) belirlendi.
- `push_chunk_to_b` fonksiyonu ile bu eşiğin altındaki değerler A’dan B’ye gönderildi.

Bu sırada bazı optimizasyonlar kullandım:

- Eğer eleman `threshold` değerinden **küçük veya eşitse**, `push_b` ile B’ye alındı.
- Bu eleman aynı zamanda `threshold / 2`'den küçükse, `rotate_b` ile B’nin **altına** gönderildi.
  - Böylece B yığını kendi içinde küçükten büyüğe daha düzenli yerleşmiş oldu.
- Diğer elemanlar için A yığını `rotate_a` ile döndürüldü.
- Bu işlem her chunk için ayrı ayrı tekrarlandı.

Chunk işlemleri bittiğinde:

- A yığınında 3 eleman kalmıştı; bu elemanları `sort_three` fonksiyonuyla sıraladım.
- Ardından B yığınındaki elemanlar, en büyükten başlayarak sırayla A’ya geri alındı:
  - `move_max_to_top_b` ile B’deki en büyük eleman yukarı taşındı.
  - Sonra `push_a` ile A’ya alındı.

Bu yöntem sayesinde:

- B yığını büyükten küçüğe sıralı olduğu için A’ya alınan elemanlar doğrudan sıralı şekilde yerleşti.
- `rotate` ve `push` işlemlerinin toplam sayısı belirgin şekilde azaldı.
- Önceki yöntemlere göre çok daha **kontrollü ve verimli** bir sıralama elde edildi.

---

### 📌 Genel Değerlendirme

Bu üç aşama boyunca farklı stratejiler deneyerek hangi yöntemlerin hangi listelerde daha iyi çalıştığını gözlemleme fırsatım oldu. En sonunda chunk tabanlı bölme yöntemi, işlem sayısını azaltmak ve yığınları daha kontrollü yönetmek açısından en verimli çözüm oldu.
