int Led[4]={1,9,2,10};

void setup() {
  // put your setup code here, to run once:
  int i;
  for(i=0;i<4;i++)
    pinMode(Led[i],OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for(i=0;i<2;i++){
    digitalWrite(Led[2*i],HIGH);
    digitalWrite(Led[2*i+1],HIGH);
    delay(500);
    digitalWrite(Led[2*i],LOW);
    digitalWrite(Led[2*i+1],LOW);
    delay(500);

  
  }
}
