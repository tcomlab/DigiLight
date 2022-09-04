
#include<Arduino.h>

#define USB_CFG_DEVICE_NAME     'D','i','g','i','L','l','g','h','t'
#define USB_CFG_DEVICE_NAME_LEN 9
#include <DigiUSB.h>


void setup() {
    DigiUSB.begin();
    pinMode(0,OUTPUT);
    pinMode(1,OUTPUT);
    pinMode(2,OUTPUT);
}


uint8_t buf[8], index_i = 0;
void loop() {
  DigiUSB.refresh();
  int data_index = DigiUSB.available();
  if (data_index > 0) {
    int val = DigiUSB.read();
    if ( val == 1) 
      {index_i = 0;}
      else
      {
        buf[index_i++] = val;
      }
      if (index_i > 5) index_i = 0;
  
    }

    analogWrite(0,buf[0]);
    analogWrite(1,buf[1]);
    analogWrite(2,buf[2]);
}
