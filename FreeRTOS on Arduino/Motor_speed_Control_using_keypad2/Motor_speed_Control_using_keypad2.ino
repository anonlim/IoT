#include<FreeRTOS_AVR.h>

const int MT_P=10;
const int MT_N=9;

const int LeftKey=2;
const int StopKey=3;
const int RightKey=21;

SemaphoreHandle_t Sem,Sem1,Sem2;
int sendValue=0; 
int buf[5]={0,}; 
int in=0; 
int out=0; 
int empty=5;
int full=0;
int mutex=1;

void LeftKeyControl(){
  if(xSemaphoreTake(Sem1,portMAX_DELAY)){
    delay(50);
    buf[in]=1;
    in=(in+1)%5;  
    xSemaphoreGive(Sem);
    xSemaphoreGive(Sem1);
  }
}
void StopKeyControl(){
  if(xSemaphoreTake(Sem1,portMAX_DELAY)){
    delay(50);
    buf[in]=2;
    in=(in+1)%5;  
    xSemaphoreGive(Sem);
    xSemaphoreGive(Sem1);
  }
}
void RightKeyControl(){
  if(xSemaphoreTake(Sem1,portMAX_DELAY)){
    delay(50);
    buf[in]=3;
    in=(in+1)%5;  
    xSemaphoreGive(Sem);
    xSemaphoreGive(Sem1);
  }
}
void MotorTask(void *arg){
  while(1){
    if(xSemaphoreTake(Sem,portMAX_DELAY)){
      if(buf[out]==1){
        digitalWrite(MT_P,LOW);
        digitalWrite(MT_N,HIGH);
      }
      else if(buf[out]==2){
        digitalWrite(MT_P,LOW);
        digitalWrite(MT_N,LOW);
      }
      else if(buf[out]==3){
        digitalWrite(MT_P,HIGH);
        digitalWrite(MT_N,LOW);
      }  
    }out=(out+1)%5;
    xSemaphoreGive(Sem);
    xSemaphoreGive(Sem1);
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
  vSemaphoreCreateBinary(Sem1);
  xTaskCreate(MotorTask,NULL,200,NULL,1,NULL);
  vTaskStartScheduler();
    
 
}
void loop(){
  
}
