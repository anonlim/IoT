#include <SArduino.h>

void dump(byte*buf,int len){
  int i;
  for(i=0;i<len;i++){
    Serial.print((char)buf[i]);
  }
  Serial.println();
}
void setup(){
  Serial.begin(9600,SERIAL_8E2);
  if(!Init_SE()){
    Serial.println("SE Connection Failure");
  }
  int key_num=0x0;
  byte plain_data[]="나는 2018년 6월 1일에 홍길동에게 100만원을 입금하였다";
  int plain_len=strlen(plain_data);
  byte sign_data[128];
  int sign_len;

  byte org_data[128];
  int org_len;
  sign_len=((sign_len/128)+1)*128;  
  org_len=((org_len/128)+1)*128;

  if(!Generate_RSA1024Key(key_num))
    Serial.println("Set RSA1024 Key Pair Failure");
   Serial.print("plain data: ");
   dump(plain_data,plain_len);

  if(Sign_RSA1024(key_num,plain_data,plain_len,sign_data,&sign_len)){
    Serial.print("sign_data: ");
    dump(sign_data,sign_len);
  }
  else
    Serial.println("Encrypt plain_data Failure");

  if(Verify_RSA1024(key_num,sign_data,sign_len,plain_data,&plain_len)){
    Serial.print("Verification");
  }
  else
    Serial.println("Decrypt sign_data Failure");
}
void loop(){}
