# CAN’den LIN'e Veri Transferi ve RGB LED Kontrolü

## Donanım ve Bağlantılar
PCAN-USB Pro: CAN verilerini bilgisayardan MCP2515 modülüne aktarır.
MCP2515 CAN Denetleyici: CAN verilerini alır ve SPI üzerinden Arduino UNO'ya iletir.
Arduino UNO: MCP2515'ten aldığı verileri işler ve LIN Bus üzerinden TJA1021 
transceiver aracılığıyla iletir.
TJA1020 LIN Modülü: Arduino UNO'dan gelen verileri LIN Bus'a iletir.
RGB LED: LIN Bus'tan gelen verilere göre farklı renklerde yanar.

### Bağlantı Şeması
![image](https://github.com/user-attachments/assets/40f8c7ee-4a51-4df8-8f58-f0fe06963e49)

## Yazılım Bileşenleri
1. Arduino IDE: Arduino Uno'yu programlamak için kullanılan geliştirme ortamıdır. 
Arduino kodlarının yazılması, derlenmesi ve karta yüklenmesi için kullanılır.
2. LIN Kütüphanesi: LIN Bus iletişimini yönetmek ve LIN protokolüne uygun çerçeveler 
oluşturmak için kullanılan kütüphanedir. Bu kütüphane, LIN Bus üzerinden veri 
gönderme ve alma işlemlerini kolaylaştırır. c
3. MCP2515 CAN Arayüz Kütüphanesi: MCP2515 CAN denetleyici modülünü 
Arduino ile kullanmak için geliştirilmiş kütüphanedir. CAN Bus üzerinden veri 
gönderme ve alma işlemlerini kolaylaştırır. 
4. PCAN-USB Pro FD kullanıcı arayüzü: Bu arayüz sayesinde bilgisayardan istediğimiz 
CAN verilerini ayarlayabiliriz. 
## Kütüphaneler
1. LIN: https://github.com/gicking/LIN_master_portable_Arduino
2. MCP2515 CAN Arayüz: https://github.com/autowp/arduino-mcp2515
3. PCAN USB PRO: https://www.peak-system.com/PCAN-USB-Pro-FD.366.0.html?&L=1

