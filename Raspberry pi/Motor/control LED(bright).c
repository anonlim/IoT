#include<wiringPi.h>
#include<softPwm.h>

#define LED_N_PIN 17
#define LED_P_PIN 4

#define HIGHH 1
#define LOWW 2

void LEDStop() {
	softPwmWrite(LED_N_PIN, 0);
	softPwmWrite(LED_P_PIN, 0);
}
void LEDControl(int light) {
	digitalWrite(LED_P_PIN, LOW);
	softPwmWrite(LED_N_PIN, speed);
}

int main(void) {
	if (wiringPiSetupGpio() == -1)return 1;

	pinMode(LED_N_PIN, OUTPUT);
	pinMode(LED_P_PIN, OUTPUT);

	softPwmCreate(LED_N_PIN, 0, 128);
	softPwmCreate(LED_P_PIN, 0, 128);
	int i;
	while (1) {
		for (i = 0; i < 128; i++) {
			LEDControl(i);
			delay(2000);
		}
	}
	return 0;
}