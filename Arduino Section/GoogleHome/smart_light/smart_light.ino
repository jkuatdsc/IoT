/*
 * TODO 
 * add your wifi credentials (SSID and password)
 * add the app secret, app key, switch id
 * - ensure all dependent libraries are installed
 *   - see https://github.com/sinricpro/esp8266-esp32-sdk/blob/master/README.md#arduinoide
 *   - see https://github.com/sinricpro/esp8266-esp32-sdk/blob/master/README.md#dependencies
 * - open serial monitor and check whats happening
 */

// Uncomment the following line to enable serial debug output
//#define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
       #define DEBUG_ESP_PORT Serial
       #define NODEBUG_WEBSOCKETS
       #define NDEBUG
#endif 

#include <Arduino.h>
#ifdef ESP8266 
       #include <ESP8266WiFi.h>
#endif 
#ifdef ESP32   
       #include <WiFi.h>
#endif

#include "SinricPro.h"
#include "SinricProSwitch.h"

#define WIFI_SSID         ""    
#define WIFI_PASS         ""
#define APP_KEY           ""      // Should look like "de0bxxxx-1x3x-4x3x-ax2x-5dabxxxxxxxx"
#define APP_SECRET        ""   // Should look like "5f36xxxx-x3x7-4x3x-xexe-e86724a9xxxx-4c4axxxx-3x3x-x5xe-x9x3-333d65xxxxxx"
#define SWITCH_ID         ""    // Should look like "5dc1564130xxxxxxxxxxxxxx"
#define BAUD_RATE         9600                // Change baudrate to your need

#define RELAY_PIN         5                  // Pin where the relay is connected (D1 = GPIO 5 on ESP8266)

bool onPowerState(const String &deviceId, bool &state) {
  digitalWrite(RELAY_PIN, state);             // set pin state
  return true;                                // request handled properly
}

void setup() {
  pinMode(RELAY_PIN, OUTPUT);                 // set relay-pin to output mode
  WiFi.begin(WIFI_SSID, WIFI_PASS);           // start wifi

  SinricProSwitch& mySwitch = SinricPro[SWITCH_ID];   // create new switch device
  mySwitch.onPowerState(onPowerState);                // apply onPowerState callback
  SinricPro.begin(APP_KEY, APP_SECRET);               // start SinricPro
}

void loop() {
  SinricPro.handle();                         // handle SinricPro commands
}
