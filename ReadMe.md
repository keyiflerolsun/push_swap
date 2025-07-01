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

Son aşamada listeyi sadece iki gruba ayırmak yerine, daha küçük ve kontrollü parçalara ayırmayı denedim. Bu parçaları genellikle **chunk** olarak adlandırıyoruz.

Yaptığım işlem özetle şöyleydi:

- A yığınındaki minimum ve maksimum değeri hesapladım.
- Bu aralıkta kalan değerleri yaklaşık olarak 5 eşit parçaya (chunk) böldüm.
- Her parça için bir **eşik değeri** (threshold) belirleyip, o aralıktaki elemanları B yığınına gönderdim.

Bu noktada birkaç strateji kullandım:

- Eğer eleman `threshold` değerinden küçükse, `push_b` ile B’ye gönderdim.
- Eğer bu eleman aynı zamanda daha da küçük bir değerse (örneğin threshold’un yarısından küçükse), `rotate_b` ile B’nin **altına** gönderdim.
  - Bu sayede B yığını küçükten büyüğe olacak şekilde daha düzenli doldu.

Bu işlemi her chunk için tekrarladım. Sonuçta:

- A yığınında sadece 3 eleman kalmıştı, onları `sort_three` ile sıraladım.
- B yığınındaki elemanları da en büyüğünden başlayarak A’ya geri taşıdım (`push_a`).
  - Bu noktada B zaten büyükten küçüğe sıralı olduğu için A’ya doğrudan sıralı olarak yerleşti.

Bu yöntem, önceki denemelere göre çok daha verimli çalıştı. Elemanlar kontrollü şekilde taşındığı için işlem sayısı belirgin şekilde azaldı ve sıralama daha öngörülebilir hale geldi.

---

### 📌 Genel Değerlendirme

Bu üç aşama boyunca farklı stratejiler deneyerek hangi yöntemlerin hangi listelerde daha iyi çalıştığını gözlemleme fırsatım oldu. En sonunda chunk tabanlı bölme yöntemi, işlem sayısını azaltmak ve yığınları daha kontrollü yönetmek açısından en verimli çözüm oldu.
