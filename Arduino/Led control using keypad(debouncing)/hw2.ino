#include <MsTimer2.h>

int Button=2;
int Button2=3;
int Led[3]={5,6,7};

int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup(){
  int i;

  pinMode(Button,INPUT_PULLUP);
  pinMode(Button2,INPUT_PULLUP);
  
  for(i=0;i<3;i++)
    pinMode(Led[i],OUTPUT);


}
void loop(){
  if(digitalRead(Button)==LOW)
    digitalWrite(Led[2],HIGH);
  if(digitalRead(Button2)==LOW)
    digitalWrite(Led[2],LOW);
  int reading=digitalRead(Button);
  if(reading!=lastButtonState){
    lastDebounceTime=millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }
  

  
    digitalWrite(Led[0],HIGH);
    delay(500);
    digitalWrite(Led[1],HIGH);
    delay(500);
    digitalWrite(Led[0],LOW);
    delay(500);
    digitalWrite(Led[1],LOW);
    delay(500);
}
