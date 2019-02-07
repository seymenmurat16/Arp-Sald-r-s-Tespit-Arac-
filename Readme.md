
Programın Çalıştırılması
--------------
Program linux işletim sistemine göre yazılmıştır. Yani program windows ya da başka bir işletim sisteminde çalışmayacaktır.
Parametreler
-------------
filename => Arp dosyasının olduğu dizini tutar
ip[][] => Arp tablosundaki ip adreslerini tutar
mac [][] => Arp tablosundaki fiziksel adreleri tutar
satir => Kaçar tane ip ve fiziksel adres olduğunu tutar
Program Çıktısı
--------------
Eğer program arp saldırısı tespit ederse kullanıcıya "Saldırı altındasınız." diye uyarı vermektedir.
Kod 
-------------
İlk olarak proc/net/arp dosyasına ulaşıyorum. Dosyada verileri okuyorum. Dosya belirli bir düzenle oluşturulmuş, ilk satırda tanımlar alt satırlarda ise o tanımlarla ilgili bilgiler vardır. Her ip adresini ve fiziksel adresi mac ve ip adlı string matrislerinde saklıyorum. Tüm dosyayı okuma işlemi bittikten sonra dosyayı kapatıyorum. Daha sonra ise mac matrisindeki her fiziksel adresi diğerleri ile karşılaştırıyorum, eğer aynı fiziksel adresli iki adres varsa bu fiziksel adreslerin ip adreslerine bakıyorum, eğer ip adresleri birbirinden farklı ise kullanıcıya “Saldırı altındasiniz” uyarısını veriyorum.

> Written with [StackEdit](https://stackedit.io/).