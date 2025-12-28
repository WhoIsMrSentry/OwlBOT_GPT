// CLClab306: 11/2024 "Animatronic Owl" 
// Uses XIAO ESP32C3 microcontroller, EMAX ES08MDII digital servo, 
//  two WS2812B RGB LEDs & RCWL-0516 microwave motion detector
// GPIO-Wakeup from deep sleep when GPIO2 goes HIGH from RCWL-0516 OUT pin
// output to servo on GPIO7
// output to LED Din on GPIO20
// works best with +5V power on RCWL, servo, & LEDs

#include "FastLED.h"
#include <ESP32Servo.h>

#define NUM_LEDS 2
#define BUTTON_PIN_BITMASK(GPIO) (1ULL << GPIO)

CRGB leds[NUM_LEDS];
Servo myservo;  // create servo object

uint64_t bitmask = BUTTON_PIN_BITMASK(GPIO_NUM_2);  // wakeup pin is GPIO2
int pos = 0;                        // variable to store the servo position
int servoPin = 7;

void flash_red()
  {
    leds[0] = CRGB::DarkRed; leds[1] = CRGB::DarkRed; FastLED.show(); 
    delay(250); 
    leds[0] = CRGB::Black; leds[1] = CRGB::Black; FastLED.show();
    delay(250);
  }
    
void blink_eyes()
  {
    for(int i = 0; i < 5; i++)
      {
        leds[0] = CRGB::DarkOrange; leds[1] = CRGB::DarkOrange; 
        FastLED.show(); delay(250); 
        leds[0] = CRGB::Red; leds[1] = CRGB::Red; 
        FastLED.show(); delay(250);
      }
    leds[0] = CRGB::Black; leds[1] = CRGB::Black; FastLED.show(); 
  }

void setup() 
{
  Serial.begin(115200);
  FastLED.addLeds<NEOPIXEL, 20>(leds, NUM_LEDS); // Neopixel IN = GPIO20
  // Allow allocation of all timers
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
  
  myservo.setPeriodHertz(50);    // standard 50 hz servo
  myservo.attach(servoPin, 300, 2400);

  // Check wakeup reason
  esp_sleep_wakeup_cause_t wakeup_reason = esp_sleep_get_wakeup_cause();
  if (wakeup_reason == ESP_SLEEP_WAKEUP_UNDEFINED) 
    {
      Serial.println("First boot");
    } 
  else 
    {
      Serial.println("Woke up from deep sleep");
    }
  delay(500);
}

void loop() 
  {
    //
    Serial.println("I'm awake now");
    Serial.println("I'm doing my thing...");
    myservo.write(90);
    flash_red();
    myservo.write(135);
    blink_eyes();
    myservo.write(90);
    blink_eyes();
    myservo.write(45);
    blink_eyes();
    myservo.write(90);
    blink_eyes();
    flash_red();
    Serial.println("I'm going to chill out for about 10 sec now.");
    delay(10000);                         // prevent new motion trigger for 10 sec                                                                                                                                                                                                                                                     motion-trigger for 10-sec
    
    // Enable GPIO wakeup when GPIO2 goes HIGH
    esp_deep_sleep_enable_gpio_wakeup(bitmask, ESP_GPIO_WAKEUP_GPIO_HIGH);
    Serial.println("I'm going to sleep now...");Serial.println();
    delay(1000);
    esp_deep_sleep_start();
  }
