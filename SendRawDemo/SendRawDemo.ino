
#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial ESPserial(4, 5);
#define IR_SEND_PIN 1;
#define DISABLE_CODE_FOR_RECEIVER 
#include "PinDefinitionsAndMore.h" 
#include <IRremote.hpp>

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    ESPserial.begin(115200);
    Serial.begin(115200);
#if defined(__AVR_ATmega32U4__) || defined(SERIAL_PORT_USBVIRTUAL) || defined(SERIAL_USB) /*stm32duino*/|| defined(USBCON) /*STM32_stm32*/|| defined(SERIALUSB_PID) || defined(ARDUINO_attiny3217)
    delay(4000); 
#endif
    IrSender.begin(); 
}

const uint8_t rawDataP[]
#if defined(__AVR__)
PROGMEM
#endif
= { 180, 90 /*Start bit*/, 11, 11, 11, 11, 11, 34, 11, 34/*0011 0xC of 16 bit address LSB first*/, 11, 11, 11, 11, 11, 11, 11,
        11/*0000*/, 11, 34, 11, 34, 11, 11, 11, 34/*1101 0xB*/, 11, 34, 11, 34, 11, 34, 11, 34/*1111*/, 11, 11, 11, 11, 11, 11, 11,
        34/*0001 0x08 of command LSB first*/, 11, 34, 11, 11, 11, 11, 11, 11/*1000 0x01*/, 11, 34, 11, 34, 11, 34, 11,
        11/*1110 Inverted 8 of command*/, 11, 11, 11, 34, 11, 34, 11, 34/*0111 inverted 1 of command*/, 11 /*stop bit*/};

void loop() {

  while (ESPserial.available() ) {
    Serial.setTimeout(1);
    int kontrol=ESPserial.parseInt();
    Serial.print(kontrol);
    Serial.print("\n\r");

        if(kontrol==100){
    static const uint16_t rawData[] PROGMEM = {8930,4470, 580,520, 580,520, 580,570, 580,520, 580,570, 530,570, 580,520, 630,520, 580,1620, 580,1620, 580,1620, 580,1670, 530,570, 580,1620, 580,1670, 530,1670, 530,1670, 580,1620, 580,570, 580,520, 580,520, 580,570, 580,520, 580,520, 580,570, 580,520, 580,1620, 580,1670, 530,1670, 580,1620, 580,1620, 580,1670, 580};
    IrSender.sendRaw_P(rawData, sizeof(rawData) / sizeof(rawData[0]), NEC_KHZ); 
    Serial.flush();
    delay(150);
    static const uint16_t rawData2[] PROGMEM = {8930,4470, 580,520, 580,570, 530,570, 580,520, 580,570, 580,520, 580,520, 630,520, 580,1620, 580,1620, 630,1620, 530,1670, 580,520, 580,1620, 580,1670, 530,1670, 580,1620, 580,1620, 580,1670, 530,570, 580,520, 580,570, 580,520, 580,570, 530,570, 580,520, 580,570, 530,1670, 580,1620, 580,1620, 580,1670, 530,1670, 580}; 
    IrSender.sendRaw_P(rawData2, sizeof(rawData2) / sizeof(rawData2[0]), NEC_KHZ); 
    Serial.flush();
    delay(150);

  }
  if(kontrol==200){
    static const uint16_t rawData[] PROGMEM = {8930,4470, 580,520, 580,520, 630,520, 580,520, 580,570, 530,570, 580,520, 630,520, 580,1620, 580,1620, 630,1570, 630,1620, 580,520, 630,1570, 630,1620, 580,1620, 580,520, 630,1570, 630,520, 580,520, 580,570, 580,520, 580,520, 630,520, 580,1620, 580,520, 630,1620, 580,1620, 580,1620, 580,1620, 630,1620, 530,1670, 580};
    IrSender.sendRaw_P(rawData, sizeof(rawData) / sizeof(rawData[0]), NEC_KHZ); 
    Serial.flush();
    delay(200);

  } 

    if(kontrol==23){
    static const uint16_t rawData[] PROGMEM = {3080,8870, 630,1470, 630,620, 580,620, 630,620, 580,620, 630,620, 580,620, 630,620, 580,620, 630,1470, 630,1470, 630,620, 580,620, 630,1470, 630,1470, 630,1520, 580,620, 580,1520, 580,1520, 580,1520, 580,1520, 580,1520, 580,670, 580,620, 630,1470, 630,620, 580,620, 630,620, 580,620, 630,620, 580,620, 630,620, 580,620, 630,620, 580,1520, 580,620, 630,1470, 630,1520, 580,1520, 580,620, 580,1520, 630,620, 580,1520, 580,620, 630,1470, 630,620, 580,620, 630,620, 580,620, 630,620, 580,620, 630,620, 580,1520, 580,1520, 580,1520, 580,1520, 580};
    IrSender.sendRaw_P(rawData, sizeof(rawData) / sizeof(rawData[0]), NEC_KHZ);
    Serial.flush();
    delay(200);

  }
  if(kontrol==24){
    static const uint16_t rawData[] PROGMEM = {3030,8920, 580,1520, 580,620, 630,620, 580,620, 630,620, 580,620, 630,620, 580,670, 580,620, 580,1520, 580,1520, 580,670, 580,620, 580,670, 580,620, 580,670, 580,1520, 580,1520, 580,1520, 580,1520, 580,1520, 580,1520, 580,620, 630,620, 580,1520, 580,670, 580,620, 580,670, 580,620, 580,670, 530,670, 580,670, 530,670, 580,670, 580,1520, 580,620, 630,620, 580,620, 630,620, 580,1520, 580,1520, 580,670, 580,1520, 580,620, 580,1520, 580,670, 580,620, 580,670, 580,620, 630,620, 580,620, 630,620, 580,1520, 580,1520, 580,1520, 580,1520, 580};
    IrSender.sendRaw_P(rawData, sizeof(rawData) / sizeof(rawData[0]), NEC_KHZ); 
    Serial.flush();
    delay(200);

  }
 
    if(kontrol==26){
    static const uint16_t rawData[] PROGMEM = { 3050 ,8850 ,600 ,1550 ,550 ,650 ,600 ,600 ,600 ,650 ,600 ,600 ,600 ,650 ,600 ,600 ,600 ,650 ,600 ,600 ,600 ,1550 ,550 ,1550 ,600 ,600 ,600 ,600 ,650 ,600 ,600 ,600 ,650 ,600 ,600 ,1500 ,600 ,1500 ,600 ,1500 ,600 ,1500 ,600 ,1500 ,600 ,600 ,600 ,1550 ,550 ,650 ,600 ,1500 ,600 ,600 ,600 ,650 ,600 ,600 ,600 ,650 ,600 ,600 ,600 ,600 ,650 ,600 ,600 ,650 ,600 ,600 ,650 ,600 ,600 ,600 ,600 ,600 ,650 ,1500 ,600 ,600 ,600 ,1550 ,550 ,1500 ,650 ,550 ,650 ,600 ,600 ,650 ,600 ,600 ,600 ,650 ,600 ,1450 ,650 ,600 ,600 ,650 ,600 ,600 ,600 ,1500 ,600 ,650 ,550 ,1500 ,600 ,1500 ,600 ,1500 ,600 ,1500 ,600 ,30100};
    IrSender.sendRaw_P(rawData, sizeof(rawData) / sizeof(rawData[0]), NEC_KHZ); 
    Serial.flush();
    delay(200);

  }

  if(kontrol==27){
    static const uint16_t rawData[] PROGMEM = {3030,8870, 630,1470, 630,620, 580,670, 580,620, 580,620, 630,620, 580,670, 580,620, 580,670, 580,1520, 580,1520, 580,620, 580,670, 580,1520, 580,1520, 580,1520, 580,620, 580,1520, 580,1520, 630,1470, 580,1520, 630,1470, 580,670, 580,670, 580,1520, 580,620, 630,620, 580,620, 580,670, 580,620, 580,670, 580,620, 580,670, 580,620, 580,1520, 580,670, 580,1520, 580,1520, 580,620, 630,1520, 580,1520, 580,620, 580,1520, 630,620, 580,620, 580,670, 580,1520, 580,620, 630,620, 580,620, 630,620, 580,620, 630,1470, 630,1470, 580,1520, 630,1470, 630};
    IrSender.sendRaw_P(rawData, sizeof(rawData) / sizeof(rawData[0]), NEC_KHZ); 
    delay(200);
    
  }
  if(kontrol==28){
    static const uint16_t rawData[] PROGMEM = {3030,8920, 580,1520, 580,620, 580,670, 580,620, 630,620, 580,620, 580,670, 580,620, 580,670, 580,1520, 580,1520, 580,620, 580,1520, 630,1470, 630,1470, 580,1570, 580,620, 630,1470, 630,1470, 630,1470, 630,1470, 630,1470, 630,620, 580,620, 630,1470, 630,620, 580,620, 630,620, 580,620, 630,620, 580,620, 630,620, 630,570, 630,620, 630,1470, 630,570, 630,620, 630,570, 630,1470, 630,1520, 580,1520, 580,620, 630,1470, 630,620, 580,620, 630,620, 580,1520, 580,620, 630,620, 580,620, 580,670, 580,620, 630,1470, 630,1470, 630,1470, 630,1470, 630};
    IrSender.sendRaw_P(rawData, sizeof(rawData) / sizeof(rawData[0]), NEC_KHZ); 
    Serial.flush();
    delay(200);
    
  }
  if(kontrol==29){
    static const uint16_t rawData[] PROGMEM = {3080,8870, 530,1570, 580,620, 580,670, 530,720, 530,670, 530,670, 580,670, 530,720, 530,670, 580,1520, 580,1520, 580,620, 630,620, 580,1520, 580,1520, 580,1570, 530,670, 530,1570, 530,1570, 530,1570, 530,1570, 530,1570, 530,670, 580,670, 580,1570, 480,720, 530,670, 530,670, 580,670, 580,670, 580,620, 530,720, 530,720, 530,670, 530,1570, 530,720, 530,1570, 530,670, 530,1570, 530,1570, 530,1570, 530,670, 580,1570, 530,670, 530,720, 530,670, 580,1520, 580,670, 530,670, 580,620, 580,670, 580,670, 530,1570, 530,1570, 530,1570, 580,1520, 580}; 
    IrSender.sendRaw_P(rawData, sizeof(rawData) / sizeof(rawData[0]), NEC_KHZ); 
    Serial.flush();
    delay(200);
    
  }
 
   if(kontrol==30){
    static const uint16_t rawData[] PROGMEM = {3080,8820, 630,1470, 630,620, 580,620, 630,620, 580,670, 580,620, 580,670, 580,620, 580,670, 580,1520, 580,1520, 580,620, 580,670, 580,1520, 580,1520, 580,1520, 580,620, 630,1470, 630,1470, 630,1470, 630,1470, 630,1470, 630,620, 580,670, 580,1520, 580,620, 580,670, 580,620, 580,670, 580,620, 580,670, 580,620, 580,670, 580,620, 630,1470, 630,620, 580,620, 580,1520, 630,1470, 630,1520, 580,1520, 530,670, 580,1520, 580,670, 580,620, 580,670, 580,1520, 580,620, 580,670, 580,620, 580,670, 580,620, 580,1520, 630,1470, 630,1470, 630,1470, 630};
    IrSender.sendRaw_P(rawData, sizeof(rawData) / sizeof(rawData[0]), NEC_KHZ); 
    Serial.flush();
    delay(200);
    
  }
  
   if(kontrol==31){
    static const uint16_t rawData[] PROGMEM = {3080,8870, 580,1520, 580,670, 580,620, 580,670, 580,620, 580,670, 580,620, 580,670, 580,620, 580,1520, 630,1470, 580,670, 580,1520, 580,620, 630,620, 580,670, 580,1520, 580,1520, 580,1520, 580,1520, 530,1570, 580,1520, 580,620, 580,670, 580,1520, 580,620, 630,620, 580,620, 580,670, 580,620, 580,670, 580,620, 630,620, 580,620, 580,670, 580,620, 630,1470, 630,1470, 630,620, 580,1520, 580,1520, 580,670, 580,1520, 580,620, 580,670, 580,620, 580,1520, 630,620, 580,620, 630,620, 580,620, 630,620, 580,620, 630,620, 580,1520, 580,1520, 580};
    IrSender.sendRaw_P(rawData, sizeof(rawData) / sizeof(rawData[0]), NEC_KHZ); 
    Serial.flush();
    delay(200);
    
  }
  
  }
  

    
   
   }
  
    
    

