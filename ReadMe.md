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

### 🧱 3. Aşama: Listeyi Chunk’lara Bölerek Sıralama

Bu aşamada, uzun listelerdeki gereksiz dönüş ve taşıma işlemlerini azaltmak için listeyi birden fazla **chunk** (parça)’a bölerek işliyorum. Her chunk, benzer büyüklükte değer aralıklarını kapsıyor ve hem A’da hem B’deki yığınları dengeli kullanmamı sağlıyor.

- **Parça sayısının belirlenmesi**  
  Eleman sayısının log₂’sine dayanan bir fonksiyonla (en az 2, en çok 20) ideal parça sayısını hesaplıyorum. Bu, büyük listelerde aşırı küçük veya aşırı büyük chunk oluşumunu engelliyor.
  - `ch_size = log₂(lst_size)`

- **Chunk aralığının hesaplanması**  
  Tüm değer aralığını parça sayısına bölerken tam sayı bölmede yukarı yuvarlama yaparak her chunk’ın sınırını çıkarıyorum. Böylece veriler eşit dağılıyor ve “artık” kalmıyor.
  - `ch_range = (max_val - min_val + ch_size - 1) / ch_size`

- **Threshold ve Pivot**  
  - Her chunk için bir **eşik (threshold)** belirleniyor; bu değerin altındaki elemanlar B yığınına taşınıyor.
    - `threshold = min_val + ch_range * ch_step`
  - Eşik değerinin yarısını **pivot** olarak alıp, B’ye gönderilen küçük elemanları `rotate_b` ile alta itiyorum. Böylece B içinde kısmen sıralı bloklar oluşuyor.
    - `median = (min_val + threshold) / 2`

- **Genel işleyiş**  
  1. A yığınındaki ilk N elemanı tarayıp, eşiğin altındakiları B’ye gönder; çok küçükse B’de alta döndür.  
  2. A’da 3 eleman kalana dek en küçüğü üste çekip B’ye at.  
  3. Kalan 3 elemanı basit yöntemlerle (swap/rotate/reverse) sırala.  
  4. B’deki blokları, en büyük elemanı üste alıp `push_a` ile A’ya geri getir; böylece doğru sırayla ekleme yap.

- **Avantajları**  
  - İşlemler kontrollü parçalarda ilerlediği için `rotate`/`reverse` ve `push` sayısı azalıyor.  
  - B yığını içinde yarı-sıralı bloklar oluşturarak geri toplamada ek hamle ihtiyacını düşürüyor.  
  - Orta ve büyük ölçekli listelerde önceki yöntemlere kıyasla çok daha verimli sonuç veriyor.
