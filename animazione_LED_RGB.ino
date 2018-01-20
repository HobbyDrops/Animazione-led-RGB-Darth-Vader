//questo codice è stato preso da questa pagina web che ringrazio
//http://moving-rainbow.readthedocs.io/en/latest/guide/fade-in-and-out/
//io lo ho solo adattato al progetto

#include <Adafruit_NeoPixel.h>
#define LEDPIN 12 // Collegate il pin dati del neopixel al pin 12 di Arduino
#define NUMBER_PIEXELS 2 // il numero di LED che utilizziamo (2 nel nostro caso)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMBER_PIEXELS, LEDPIN, NEO_GRB + NEO_KHZ800);

int waitTime = 10; //la velocità dell'animazione

void setup() {
  strip.begin();
}

void loop() {
  fadeInAndOut(255, 0, 0, waitTime); // rosso R,G,B --->RED,GREEN,BLUE
}

void fadeInAndOut(uint8_t red, uint8_t green, uint8_t blue, uint8_t wait) {

  for(uint8_t b=0; b <255; b++) {
     for(uint8_t i=0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, red*b/255, green*b/255, blue*b/255);
     }
     strip.show();
     delay(wait);
  };

  for(uint8_t b=255; b > 0; b--) {
     for(uint8_t i=0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, red*b/255, green*b/255, blue*b/255);
     }
     strip.show();
     delay(wait);
  };
};
