/*********************
CAN to LIN with PCAN-USB Pro FD, LIN Transceiver, Arduino Uno and MCP2515 CAN Controller

Author of the LIN libraries: Georg - https://github.com/gicking/LIN_master_portable_Arduino
Author of the CAN libraries: autowp- https://github.com/autowp/arduino-mcp2515

Edited by: Mesut - mesut.ulusoy@outlook.com.tr


Supported (=successfully tested) board:
 - Arduino UNO            

**********************/

// include files for LIN 

#include "LIN_master_SoftwareSerial.h"


// board pin definitions
#if defined(ARDUINO_AVR_UNO)
  #define PIN_TOGGLE    7         // pin to demonstrate background operation
  #define PIN_ERROR     6         // indicate LIN return status
  #define PIN_LIN_RX    4         // receive pin for LIN
  #define PIN_LIN_TX    5         // transmit pin for LIN
#else
  #error adapt parameters to board   
#endif

// pause between LIN frames
#define LIN_PAUSE       100

// setup LIN node. Note: not all pins support Rx!
LIN_Master_SoftwareSerial   LIN(PIN_LIN_RX, PIN_LIN_TX, false, "LIN_SW");       // parameter: Rx, Tx, inverseLogic, name

  //uint8_t Txr[8] = {0xFF, 0xFF, 0x00, 0x11, 0x11, 0x00, 0x00, 0x00};  // RED LED
  //uint8_t Txg[8] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x11, 0x11, 0x00};  // GREEN LED
  uint8_t Txb[8] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x11, 0x00, 0x11};  // BLUE LED
  uint8_t Tx_n[8]; // new Tx 


// include files for CAN 
#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;
MCP2515 mcp2515(10);


void setup() {
  
  // For CAN

  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();
  
  // For LIN 

    // indicate background operation
  pinMode(PIN_TOGGLE, OUTPUT);

  // indicate LIN status via pin
  pinMode(PIN_ERROR, OUTPUT);

  // open LIN connection
  LIN.begin(19200);



}// setup()

void loop() {

  int dummy;

  // FOR CAN
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {
    /*Serial.print(canMsg.can_id, HEX); // print ID
    Serial.print(" "); 
    Serial.print(canMsg.can_dlc, HEX); // print DLC
    Serial.print(" ");
    
    for (int i_2 = 0; i<canMsg.can_dlc; i_2++)  {  // print the data
      Serial.print(canMsg.data[i_2],HEX);
      Serial.print(" ");
    }

    Serial.println();  */    
  }

  // CAN to LIN 
    for (int i_2 = 0; i_2 < 8; i_2++) {
      Tx_n[i_2] = (i_2 < canMsg.can_dlc) ? canMsg.data[i_2] : 0x00;
    }
     /* for (int b = 0; i<canMsg.can_dlc; b++)  {  

      Tx_n[b] = canMsg.data[b];   // new Tx
      
    } */ 


  // FOR LIN 
  static uint32_t       tStart;


  LIN_Master::frame_t   Type;
  uint8_t               Id;
  uint8_t               NumData;
  uint8_t               Data[8];
  LIN_Master::error_t   error;

  // send master request frame and get result immediately
  error = LIN.sendMasterRequestBlocking(LIN_Master::LIN_V2, 0x25, 8, Tx_n); // new Tx

  // reset state machine & error
  LIN.resetStateMachine();
  LIN.resetError();

  // wait a bit. Toggle pin to show CPU load (100ms wait)
  tStart = millis();
  while (millis() - tStart < LIN_PAUSE)
  {
    dummy = dummy +1;;

  }

}

