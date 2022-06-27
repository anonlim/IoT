enum{DO=262,RE=294,MI=330,FA=349,
SOL=392,LA=440,SHI=494,DO2=523,REST=0};

#define BUZZER 5

int Num=9;
int Frequency[]={DO,RE,MI,FA,SOL,LA,SHI,DO2,REST};


void setup(){
  pinMode(BUZZER,OUTPUT);
}
void loop(){
    tone(BUZZER,Frequency[0]);
    delay(500);
    tone(BUZZER,Frequency[8]);
    
    tone(BUZZER,Frequency[0]);
    delay(250);
    tone(BUZZER,Frequency[8]);
    
    tone(BUZZER,Frequency[0]);
    delay(250);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[0]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[0]);
    delay(500);
    tone(BUZZER,Frequency[8]);
///////////////////////////////////////
    tone(BUZZER,Frequency[2]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[4]);
    delay(250);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[4]);
    delay(250);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[2]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[0]);
    delay(500);
    tone(BUZZER,Frequency[8]);
////////////////////////////////////
    tone(BUZZER,Frequency[4]);
    delay(250);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[4]);
    delay(250);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[2]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[4]);
    delay(250);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[4]);
    delay(250);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[2]);
    delay(500);
    tone(BUZZER,Frequency[8]);
    /////////////////////////////
    tone(BUZZER,Frequency[0]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[0]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[0]);
    delay(1000);
    tone(BUZZER,Frequency[8]);
    /////////////////////////////
    tone(BUZZER,Frequency[4]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[4]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[2]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[0]);
    delay(500);
    tone(BUZZER,Frequency[8]);
////////////////////////////////////
    tone(BUZZER,Frequency[4]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[4]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[4]);
    delay(1000);
    tone(BUZZER,Frequency[8]);
////////////////////////////////////
    tone(BUZZER,Frequency[4]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[4]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[2]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[0]);
    delay(500);
    tone(BUZZER,Frequency[8]);
///////////////////////////////////////
    tone(BUZZER,Frequency[4]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[4]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[4]);
    delay(1000);
    tone(BUZZER,Frequency[8]);
    //////////////////////////////
    tone(BUZZER,Frequency[4]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[4]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[2]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[0]);
    delay(500);
    tone(BUZZER,Frequency[8]);
    ///////////////////////////////
    tone(BUZZER,Frequency[4]);
    delay(250);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[4]);
    delay(250);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[4]);
    delay(250);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[5]);
    delay(250);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[4]);
    delay(1000);
    tone(BUZZER,Frequency[8]);
    //////////////////////////
    tone(BUZZER,Frequency[7]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[4]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[7]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[4]);
    delay(500);
    tone(BUZZER,Frequency[8]);
    ////////////////////////////
    tone(BUZZER,Frequency[2]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[1]);
    delay(500);
    tone(BUZZER,Frequency[8]);

    tone(BUZZER,Frequency[0]);
    delay(1000);
    tone(BUZZER,Frequency[8]);
}
