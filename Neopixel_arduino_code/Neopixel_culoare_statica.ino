// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN1        6
#define PIN2        3

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 12 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
// Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
// Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel ring_a = Adafruit_NeoPixel(12, 6);
Adafruit_NeoPixel ring_b = Adafruit_NeoPixel(12, 3);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  ring_a.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  ring_b.begin();

  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    ring_a.setPixelColor(i, ring_a.Color(255, 255, 255));
    ring_b.setPixelColor(i, ring_b.Color(255, 255, 255));

    ring_a.show();   // Send the updated pixel colors to the hardware.
    ring_b.show();
}
}
void loop() {

  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    ring_a.setPixelColor(i, ring_a.Color(255, 255, 255));
    ring_b.setPixelColor(i, ring_b.Color(255, 255, 255));

    ring_a.show();   // Send the updated pixel colors to the hardware.
    ring_b.show();
  }

  delay(1000);
}
