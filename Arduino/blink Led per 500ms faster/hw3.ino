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
  int j;
  int seconds=500;
  for(j=0;j<4;j++){
    for(i=0;i<4;i++){
    digitalWrite(Led[i],HIGH);
    delay(seconds);
    digitalWrite(Led[i],LOW);    
    delay(seconds);
  }
  seconds=seconds+seconds*j;
    }
  
}
