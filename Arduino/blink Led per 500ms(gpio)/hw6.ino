
void setup() {
  // put your setup code here, to run once:
  
  DDRB=0x80;
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for(i=0;i<4;i++){
   PORTB=0x80>>i;
   delay(500);
   PORTB=0x00;
   delay(500);
  }
}
