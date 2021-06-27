# plant-logger
Code to do differential measuring with an ADC1115 and a digital filter. The code and readme is adapted for electrophysilogy on plants. 

## Setup
This setup used an ESP32 Devkit1 connected to an 16Bit ADC1115. The ADC1115 does differential measurements on a single plant. It uses electrodes made of copper with a silver mantle. Tests have been done with accupuncture needles made from stainless steel. Make sure your electrodes are within 0.4mm in diameter.

### ADC1x15
An ADC with a lower resolution such as the 12Bit ADC1110 could also be enough but you would need to go for a gain of at least 8x. 12Bit on a gain of 8x means that the LSB is 0.25mV. The signal expected electrophysiological changes are in a range of 10-50mV. So 0.25mV as the smallest recognizable change should be enough. Be aware though: In my tests i measured a drop in voltage the higher i set the gain. A gain of 8 already halfed the signal. That's why I chose a 16Bit ADC (16Bit,gainx1 means LSB is 0.125mV).

### ESP32
