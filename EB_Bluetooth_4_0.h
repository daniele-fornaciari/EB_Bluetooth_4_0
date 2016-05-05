/*************************************************** 
  This is a library for the EB-Bluetooth 4.0

  The EB-Bluetooth 4.0 uses software seiral
  
  MakerStudio invests time and resources providing this open source code, 
  please support MakerStudio and open-source hardware by purchasing 
  products from MakerStudio.cc

  Written by Steve for MakerStudio.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/
#ifndef _EB_BLUETOOTH_4_0_H
#define _EB_BLUETOOTH_4_0_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <WString.h>

class EB_Bluetooth_4_0{
public:
  EB_Bluetooth_4_0(uint8_t EB_Rx, uint8_t EB_Tx);
  
  void begin();
  
  int setName(String name);
  int print(uint8_t byte);
  int read();
  int available();
  
private:
  uint8_t EB_rxPin;
  uint8_t EB_txPin;
  SoftwareSerial swSerial;
  
};

#endif
