#include <Wire.h>
#include <Adafruit_ADS1X15.h>
#include <Filters.h>

Adafruit_ADS1115 ads1115;
  // The ADC input range (or gain) can be changed via the following
  // functions, but be careful never to exceed VDD +0.3V max, or to
  // exceed the upper and lower limits if you adjust the input range!
  // Setting these values incorrectly may destroy your ADC!
  //                                                                ADS1015  ADS1115
  //                                                                -------  -------
  // ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV

// line output to serial
char linebuf_all[100];
// cutOffFequency of 15 is due to low slope effectively cancelling noise starting from 40Hz
float cutOffFrequency = 10;  
 FilterOnePole filterOneLowPass(LOWPASS, cutOffFrequency);

void setup(void)
{
  
  Serial.begin(115200);
  ads1115.begin();
  // war bei kompillierung nur gain 1x
  ads1115.setGain(GAIN_ONE);

}


void loop(void)
{ 
  uint16_t results_0_1;
   /* Be sure to update this value based on the IC and the gain settings! */
  float multiplier =  0.125F;

   
  results_0_1 = ads1115.readADC_Differential_0_1();
  
  filterOneLowPass.input( results_0_1 * multiplier );
  Serial.println("gainx8");
  sprintf(linebuf_all,
  "mv,%.3f,filtered,%.3f",
  results_0_1 * multiplier,filterOneLowPass.output());
  Serial.println(linebuf_all);

}