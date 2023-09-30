#define NUM_LEDS 180
#include "FastLED.h"
#define PIN 13

CRGB leds[NUM_LEDS];
byte col = 5;
byte zad = 0;
bool zn=true;
void setup() {
  FastLED.addLeds<WS2812B, PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(255);
  pinMode(13, OUTPUT);
}

void loop() {
  int i = 0;
    for ( i ; i < NUM_LEDS/2-1; i++ ){
      leds[i].setHue(32); 
    }
    for (i; i < NUM_LEDS-1; i++ ){
      leds[i].setHue(160); 
    }
  if ((leds[0].r!=0)||(leds[0].g!=0)||(leds[0].b!=0)) {
    FastLED.show();
    delay(45); // скорость движения радуги
  }         
}