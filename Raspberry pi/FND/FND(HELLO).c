#include<stdio.h>
#include<stdlib.h>
#include <wiringPi.h>

const int FndSelectPin[6] = { 4,17,18,27,22,23 };
const int FndPin[8] = { 6,12,13,16,19,20,26,21 };
const int FndFont[6] = { 0x3F,0x38,0x38,0x79,0x76,0 };

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
	int pos;
	int data[6] = { 0,1,2,3,4,5 };

	Init();

	int posit = 0;
	int i = 0;
	while (1) {
		while (i < 500) {
			for (pos = 0; pos < 6; pos++) {
				FndDisplay((pos + posit) % 6, data[pos]);
				delay(1);
				i++;
			}
		}posit++;
		i = 0;
	}
	return 0;
}