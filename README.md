# CAN’den LIN'e Veri Transferi ve RGB LED Kontrolü

# Hardware:
# Donanım ve Bağlantılar
PCAN-USB Pro: CAN verilerini bilgisayardan MCP2515 modülüne aktarır.
MCP2515 CAN Denetleyici: CAN verilerini alır ve SPI üzerinden Arduino UNO'ya iletir.
Arduino UNO: MCP2515'ten aldığı verileri işler ve LIN Bus üzerinden TJA1021 
transceiver aracılığıyla iletir.
TJA1020 LIN Modülü: Arduino UNO'dan gelen verileri LIN Bus'a iletir.
RGB LED: LIN Bus'tan gelen verilere göre farklı renklerde yanar.

![image](https://github.com/user-attachments/assets/40f8c7ee-4a51-4df8-8f58-f0fe06963e49)

## CAN Shield

The following code samples uses the CAN-BUS Shield, wired up as shown:

![MCP2515 CAN-Shield wiring](examples/wiring.png)


# Software Usage:

## Library Installation

1. Download the ZIP file from https://github.com/autowp/arduino-mcp2515/archive/master.zip
2. From the Arduino IDE: Sketch -> Include Library... -> Add .ZIP Library...
3. Restart the Arduino IDE to see the new "mcp2515" library with examples

