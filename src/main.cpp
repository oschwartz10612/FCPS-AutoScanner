#include <Arduino.h>
#include <Keyboard.h>

#define BUTTON 3
int buttonState;
unsigned long loopInterval = 100;
unsigned long previousMillis = 0;
int delayTime = 50;

String key = "2390N";

void setup() {
    Keyboard.begin();
    pinMode(BUTTON, INPUT_PULLUP);

    previousMillis = millis();
    while((millis() - previousMillis) <= 3000) {}

    Keyboard.write(9); //TAB
    for (unsigned int i = 0; i <= sizeof(key); i++) {
        Keyboard.print(key[i]);
        delay(delayTime);
    }
}

void loop() {
    unsigned long currentMillis = millis();
    if ((unsigned long)(currentMillis - previousMillis) >= loopInterval) {
        previousMillis = millis();

        buttonState = digitalRead(BUTTON);

        if (buttonState == LOW) {
            Keyboard.write(9); //TAB
	        delay(delayTime);
            Keyboard.write(9); //TAB
	        delay(delayTime);
            Keyboard.write(9); //TAB
	        delay(delayTime);
            Keyboard.write(111); //o
	        delay(delayTime);
            Keyboard.write(176); //Enter
	        delay(delayTime);
            Keyboard.write(176); //Enter
            delay(500);
        }
    }
}
