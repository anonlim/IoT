#include<wiringPi.h>
const int LedRed[8] = { 4,17,18,27,22,23,24,25 };
const int Keypad[8] = { 16,13,12,6,21,26,20,19 };
int buttonState;
int lastButtonState = LOW;
int ledState = HIGH;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

int KeypadRead() {
	int i, keypadnum = -1;
	for (i = 0; i < 8; i++) {
		if (!digitalRead(Keypad[i])) {
			keypadnum = i; break;
		}
	}
	return keypadnum;
}
void LedControl(int keypadnum) {
	int i;
	for (i = 0; i < 8; i++) {
		if (i == keypadnum) {
			int output = digitalRead(Ledred[i]);
			output = !output;
			digitalWrite(LedRed[i], output);
		}
	}
}

int main(void) {
	int i, keypadnum = -1;
	if (wiringPiSetupGpio() == -1)return 1;
	for (i = 0; i < 8; i++) {
		pinMode(LedRed[i], OUTPUT);
		digitalWrite(LedRed[i], LOW);
	}
	for (i = 0; i < 8; i++)pinMode(Keypad[i], INPUT);
	while (1) {
		keypadnum = KeypadRead();
		int reading = digitalRead(keypadnum);
		if (reading != lastButtonState) {
			lastDebounceTime = millis();
		}
		if ((millis() - lastDebounceTime) > debounceDelay) {
			if (reading != buttonState) {
				buttonState = reading;
				LedControl(keypadnum);
			}
		}
		lastButtonState = reading;
	}
	return 0;
}