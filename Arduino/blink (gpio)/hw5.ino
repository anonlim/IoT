/*int digitalRead(uint8_t pin){
  uint8_t bit=digitalPinToBitMask(pin);
  uint8_t port=digitalPinToPort(pin);
  volatile uint8_t *out;

  if (port==NOT_A_PIN)return LOW;

  if(*portInputRegister(port)&bit)return HIGH;
  return LOW;
}*/

void setup(){
  DDRB=0x80;
}
void loop(){
  PORTB=0x80;
  delay(1000);
  PORTB=0x00;
  delay(1000);
}
