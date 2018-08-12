#include <Arduino.h>
#include <FastLED.h>

#define FAST_LED_LEDS_NUM 1

// On board D2 corresponds to GPIO4
#define NEO_PIXEL_DIN 4

CRGB ledsStripe[FAST_LED_LEDS_NUM];
void setStripeColor(uint8_t amount_red, uint8_t amount_green, uint8_t amount_blue);
void fade(uint8_t red, uint8_t green, uint8_t blue, bool fade_in);

void setup(void) {
  Serial.begin(115200);

  Serial.println(F("Configuring LED strip..."));

  //FastLED.addLeds<WS2812B, NEO_PIXEL_DIN, GRB>(ledsStripe, FAST_LED_LEDS_NUM);
  FastLED.addLeds<WS2811, NEO_PIXEL_DIN, GRB>(ledsStripe, FAST_LED_LEDS_NUM);

  setStripeColor(0, 0, 0);
  FastLED.show();

  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Starting...");
}

void loop(void) {
  digitalWrite(LED_BUILTIN, 1 - digitalRead(LED_BUILTIN));
  fade(255, 0, 0, false);
  fade(255, 0, 0, true);
  fade(0, 255, 0, false);
  fade(0, 255, 0, true);
  fade(0, 0, 255, false);
  fade(0, 0, 255, true);
}

void fade(uint8_t red, uint8_t green, uint8_t blue, bool fade_in) {
  uint8_t amount;
  for (uint16_t k = 0; k < 256; k++) {
    amount = fade_in ? k : 255 - k;

    setStripeColor(amount * red, amount * green, amount * blue);
    FastLED.show();
    delay(2);
  }
}

void setStripeColor(uint8_t amount_red, uint8_t amount_green, uint8_t amount_blue) {
  for (int i = 0; i < FAST_LED_LEDS_NUM; i++) {
    // actually red on our led is on "green" channel
    ledsStripe[i].g = amount_red;
    ledsStripe[i].r = amount_green;
    ledsStripe[i].b = amount_blue;
  }
}
