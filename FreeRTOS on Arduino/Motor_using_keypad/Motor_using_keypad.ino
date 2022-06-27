#include<FreeRTOS_AVR.h>

const int MT_P=10;
const int MT_N=9;

const int LeftKey=2;
const int StopKey=3;
const int RightKey=21;

SemaphoreHandle_t Sem;
int sendValue=0;

void LeftKeyControl(){
  delay(50);
  sendValue=1;
  xSemaphoreGive(Sem);
}
void StopKeyControl(){
  delay(50);
  sendValue=2;
  xSemaphoreGive(Sem);
}
void RightKeyControl(){
  delay(50);
  sendValue=3;
  xSemaphoreGive(Sem);
}
void MotorTask(void *arg){
  while(1){
    if(xSemaphoreTake(Sem,portMAX_DELAY)){
      if(sendValue==1){
        digitalWrite(MT_P,LOW);
        digitalWrite(MT_N,HIGH);
      }
      else if(sendValue==2){
        digitalWrite(MT_P,LOW);
        digitalWrite(MT_N,LOW);
      }
      else if(sendValue==3){
        digitalWrite(MT_P,HIGH);
        digitalWrite(MT_N,LOW);
      }
    }
  }
}
void setup(){
  pinMode(MT_P,OUTPUT);
  pinMode(MT_N,OUTPUT);

  pinMode(LeftKey,INPUT);
  pinMode(StopKey,INPUT);
  pinMode(RightKey,INPUT);

  attachInterrupt(0,LeftKeyControl,RISING);
  attachInterrupt(1,StopKeyControl,RISING);
  attachInterrupt(2,RightKeyControl,RISING);
  vSemaphoreCreateBinary(Sem);
  xTaskCreate(MotorTask,NULL,200,NULL,1,NULL);
  vTaskStartScheduler();
    
 
}
void loop(){
  
}
