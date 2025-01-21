#include <FastLED>
#include <Arduino>
#include <FFTW>

#define LED_PIN 5 //ask Yajat
#define ROWS 15
#define COLS 16
#define NUM_LEDS (ROWS*COLS)
CRGB leds[NUM_LEDS];

double something = 0; //Find this value somehow? (Max val of an FFT band)
constexpr double Height_Modifier = 15.0/(something);
double Sampling_Period = 0; //Think about this value
constexpr Sampling_Time = 1000000.0 / Sampling_Period;


void setup()
{

}

void loop()
{

}

