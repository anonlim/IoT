#include<wiringPi.h>
#include<softPwm.h>

#define MOTOR_MT_N_PIN 17
#define MOTOR_MT_P_PIN 4

#define LEFT_ROTATE 1
#define RIGHT_ROTATE 2

void MotorStop() {
	softPwmWrite(MOTOR_MT_N_PIN, 0);
	softPwmWrite(MOTOR_MT_P_PIN, 0);
}
void MotorControlLeft(int speed) {
	digitalWrite(MOTOR_MT_P_PIN, LOW);
	softPwmWrite(MOTOR_MT_N_PIN, speed);
}
void MotorControlRight(int speed) {
	digitalWrite(MOTOR_MT_N_PIN, LOW);
	softPwmWrite(MOTOR_MT_P_PIN, speed);
}
int main(void) {
	if (wiringPiSetupGpio() == -1)return 1;

	pinMode(MOTOR_MT_N_PIN, OUTPUT);
	pinMode(MOTOR_MT_P_PIN, OUTPUT);

	softPwmCreate(MOTOR_MT_N_PIN, 0, 128);
	softPwmCreate(MOTOR_MT_P_PIN, 0, 128);

	while (1) {
		MotorControl(32);
		delay(2000);
		MotorStop();
		delay(2000);

		MotorControl(64);
		delay(2000);
		MotorStop();
		delay(2000);

		MotorControl(96);
		delay(2000);
		MotorStop();
		delay(2000);

		MotorControl(128);
		delay(2000);
		MotorStop();
		delay(2000);
	}
	return 0;
}