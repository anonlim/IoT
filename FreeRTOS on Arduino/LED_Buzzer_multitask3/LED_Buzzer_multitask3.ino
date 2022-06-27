#include<FreeRTOS_AVR.h>

#define MS2TICKS(ms)(ms/portTICK_PERIOD_MS)
#define LED 5
#define BUZZER 9

enum {REST=0,DO=262,RE=294,MI=330,FA=349,SOL=392,LA=440,SHI=494,DO2=523};

int Num=9;
int Frequency[]={DO,RE,MI,REST,FA,SOL,LA,SHI,DO2};
int Delay[]={500,0,500,500,500,1000,0,500};

void LedTask(void* arg) {
  while (1) {
  // LED ON
  digitalWrite(LED, HIGH); 
  // 500ms 지연
  //vTaskDelay(MS2TICKS(500));
  delay(500);
  // LED OFF
  digitalWrite(LED, LOW); 
  // 500ms 지연
  //vTaskDelay(MS2TICKS(500));
  delay(500);
  }
}
void BuzzerTask(void* arg) {
  int i;
  while (1) {
    for (i = 0; i < Num; i++) {
      // 9번 PIN을 통해 출력
      tone(BUZZER, Frequency[i]); 
      // 유지 시간
      vTaskDelay(MS2TICKS(Delay[i])); 
     }
   }
}

void setup() {
  // LED, Buzzer Pin 출력으로 설정
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  // Task 생성
  xTaskCreate(LedTask, NULL, 200, NULL, 2, NULL);
  xTaskCreate(BuzzerTask, NULL, 200, NULL, 1, NULL);
  // scheduler 시작
  vTaskStartScheduler();
}
void loop() {
}
