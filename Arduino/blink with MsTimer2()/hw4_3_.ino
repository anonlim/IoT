#include <MsTimer2.h>

int Led[5]={1,2,9,10,16};
void LedControl(){
  static int counter=0;
  static byte output=HIGH;

  digitalWrite(Led[counter++],output);
  if(counter>4){
    counter=0;
    output=!output;
  }
}

void setup() {
  // put your setup code here, to run once:
  int i;
  for (i=0;i<5;i++)
    pinMode(Led[i],OUTPUT);
  MsTimer2::set(500,LedControl);
  MsTimer2::start();
}

void loop() {
  // put your main code here, to run repeatedly:

}
