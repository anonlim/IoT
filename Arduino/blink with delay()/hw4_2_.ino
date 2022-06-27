int Led[5]={1,2,9,10,16};

void setup() {
  // put your setup code here, to run once:
  int i;
  for(i=0;i<5;i++)
    pinMode(Led[i],OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for(i=0;i<5;i++){
    digitalWrite(Led[i],HIGH);
    delay(500);
    digitalWrite(Led[i],LOW);
    delay(500);

  
  }
}
