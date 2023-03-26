/*
 * ESP_NeoPixel/src/main.ino
 */


#include <Adafruit_NeoPixel.h>


const uint PIXEL_PIN    = 21;
const uint PIXEL_LENGTH = 4;

Adafruit_NeoPixel pixel_strip(PIXEL_LENGTH, PIXEL_PIN, NEO_GRBW + NEO_KHZ800);


void color_wipe(uint32_t color, int wait);


void setup()
{
    pixel_strip.begin();
    pixel_strip.show();
    pixel_strip.setBrightness(1);
}


void loop()
{
    color_wipe(pixel_strip.Color(0, 255, 0), 1000);   // green
    color_wipe(pixel_strip.Color(255, 255, 0), 800);  // yellow
    color_wipe(pixel_strip.Color(255, 0, 0), 1500);   // red
}


void color_wipe(uint32_t color, int wait)
{
    for (int i = 0; i < PIXEL_LENGTH; i++) {
        pixel_strip.setPixelColor(i, color);
    }

    pixel_strip.show();
    delay(wait);
}
