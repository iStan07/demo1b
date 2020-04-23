#include "Sensors.h"

void ADC_init(){
  ADMUX = 0;
  //ADC5 or Sensor2, left adjusted, non-freerunning mode
  ADMUX |= (1<<REFS1)|(1<<REFS0)|(1<<MUX2)|(1<<MUX1)|(1<<MUX0)|(1<<ADLAR);
  ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);

  return;  
}
void ADC_init1(){
  ADMUX = 0;
  //ADC5 or Sensor2, left adjusted, non-freerunning mode
  ADMUX |= (1<<REFS1)|(1<<REFS0)|(1<<MUX3)|(1<<ADLAR);
  ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);

  return;  
}
uint8_t SensorValue(){

  //read value from ADC
  ADCSRA |= (1<<ADSC);
  while(ADCSRA & (1<<ADSC));
  uint8_t sensor_out = ADCH;
  
  return sensor_out;
}
