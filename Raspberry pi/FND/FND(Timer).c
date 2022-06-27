#include<stdio.h>
#include<stdlib.h>
#include <wiringPi.h>

const int FndSelectPin[6] = { 4,17,18,27,22,23 };
const int FndPin[8] = { 6,12,13,16,19,20,26,21 };
const int FndFont[10] = { 0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67 };

void Init() {
	int i;
	if (wiringPiSetupGpio() == -1) {
		printf("wiringPiSetupGpio() error\n");
		exit(-1);
	}
	for (i = 0; i < 6; i++) {
		pinMode(FndSelectPin[i], OUTPUT);
		digitalWrite(FndSelectPin[i], HIGH);
	}
	for (i = 0; i < 8; i++) {
		pinMode(FndPin[i], OUTPUT);
		digitalWrite(FndPin[i], LOW);
	}
}

void FndSelect(int position) {
	int i;
	for (i = 0; i < 6; i++) {
		if (i == position) {
			digitalWrite(FndSelectPin[i], LOW);
		}
		else {
			digitalWrite(FndSelectPin[i], HIGH);
		}
	}
}

void FndDisplay(int position, int num) {
	int i, j;
	int flag = 0;
	int shift = 0x01;
	for (i = 0; i < 8; i++) {
		flag = (FndFont[num] & shift);
		digitalWrite(FndPin[i], flag);
		shift <<= 1;
	}
	FndSelect(position);
}

int main() {
	int pos,tmp;
	int count, t = 0, cnt = 0;

	Init();

	while (1) {
		tmp = t;
		for (pos = 0; pos < 6; pos++) {
			FndDisplay(pos, tmp % 10);
			tmp = tmp / 10;
			delay(1);
			cnt++;
			if (t > 999999)t = 0;
		}
		delay(4);
		t++;
		cnt = 0;
	}
	return 0;
}