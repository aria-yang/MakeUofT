#include "RTClib.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SSD1306_128X32_UNIVISION_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // Adafruit Feather ESP8266/32u4 Boards + FeatherWing OLED

#define SCREEN_I2C_ADDR 0x3D
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

Adafruit_SSD1306 oled(128, 32, &Wire, -1);

// RTC_DS1307 rtc;
// RTC_PCF8523 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// variables
int led1 = 10;
int led2 = 11;
int sensorPin = A0; // analog pin
int SDAPinD = A2; // Display 
int SDIPinD = A3; // Display
int SDAPin = A4; // SDA for RTC
int SDIPin = A5; // SDI for RTC 
int sensorValue; // to store value

// clock variables
int hourupg;
int minupg;
int yearupg;
int monthupg;
int dayupg;
int menu=0;
const int debounce = 35;

void setup() {
  // put your setup code here, to run once:

  // set up display
  // if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
  // Serial.println(F("SSD1306 allocation failed"));
  // while (true);
  // }
  // oled.clearDisplay();
  // oled.setTextSize(1);
  // oled.setTextColor(SSD1306_WHITE);
  // oled.setCursor (0, 0);
  // oled.println("This works!");

  // set LED as outputs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  
  // initialize serial communication
  Serial.begin(9600);

  u8g2.begin();

  // #ifndef ESP8266
  // while (!Serial); // wait for serial port to connect. Needed for native USB
  // #endif

  // if (! rtc.begin()) {
  //   Serial.println("Couldn't find RTC");
  //   Serial.flush();
  //   abort();
  // }
}

void loop() {
  // put your main code here, to run repeatedly:
  // read sensor value
  sensorValue = analogRead(sensorPin);
  // DisplayDateTime(); 

  u8g2.clearBuffer();					// clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
  u8g2.drawStr(0,10, sensorValue);	// write something to the internal memory
  u8g2.sendBuffer();					// transfer internal memory to the display

  // Oled.setFont(u8x8_font_chroma48medium8_r);
  // Oled.setCursor(0, 33);
  // Oled.print("Analog Value:");
  // Oled.print(sensorValue);
  // Oled.refreshDisplay();
  // delay(1000);
  
  // print sensor value
  // Serial.println("Sensor Value: ");
  // Serial.println(sensorValue);

  // LED directions
  if(sensorValue > 750) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
  else if(sensorValue <= 750 && sensorValue > 100) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  else{
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
  delay(200);
}

// void DisplayDateTime()
// {
//   // Clock function
//   DateTime now = rtc.now();

//     Serial.print(now.year(), DEC);
//     Serial.print('/');
//     Serial.print(now.month(), DEC);
//     Serial.print('/');
//     Serial.print(now.day(), DEC);
//     Serial.print(" (");
//     Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
//     Serial.print(") ");
//     Serial.print(now.hour(), DEC);
//     Serial.print(':');
//     Serial.print(now.minute(), DEC);
//     Serial.print(':');
//     Serial.print(now.second(), DEC);
//     Serial.println();

//     Serial.print(" since midnight 1/1/1970 = ");
//     Serial.print(now.unixtime());
//     Serial.print("s = ");
//     Serial.print(now.unixtime() / 86400L);
//     Serial.println("d");
//     delay(30);
// }