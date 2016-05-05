/*************************************************** 
  This is a library for the EB-Bluetooth 4.0

  The EB-Bluetooth 4.0 uses software seiral 
  
  MakerStudio invests time and resources providing this open source code, 
  please support MakerStudio and open-source hardware by purchasing 
  products from MakerStudio.cc

  Written by Steve for MakerStudio.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/
#include "EB_Bluetooth_4_0.h"

EB_Bluetooth_4_0::EB_Bluetooth_4_0(uint8_t EB_Rx, uint8_t EB_Tx):swSerial(EB_Tx, EB_Rx)
{
	EB_rxPin = EB_Rx;
	EB_txPin = EB_Tx;
}


//initialization
void EB_Bluetooth_4_0::begin()
{
	pinMode(EB_rxPin, OUTPUT);
	pinMode(EB_txPin, INPUT);
	
	
	swSerial.begin(9600);// the default baudrate is 9600
	

	
}

int EB_Bluetooth_4_0::setName(String name)
{
	int isSuccess = 0;
	
	String recvBuf;
	char recvChar;
	
	String cmd("AT+NAME");
	cmd += name;

	int cmdLen = cmd.length();
	
	for(int i = 0; i < 18; i++){
		swSerial.write(cmd[i]);
	}
	
	delay(100);
	int len = 0;
	if(len = available()){
		for(int i = 0; i < len; i++){
			recvChar = read();
			Serial.print(recvChar);
			recvBuf += recvChar;
		}
		if(recvBuf.indexOf(name) != -1){
			isSuccess= 1;
		}
	}
	return isSuccess;
}

int EB_Bluetooth_4_0::print(uint8_t byte)
{
	return(swSerial.write(byte));
}

int EB_Bluetooth_4_0::read()
{
	return(swSerial.read());
}

int EB_Bluetooth_4_0::available()
{
	return(swSerial.available());
}
