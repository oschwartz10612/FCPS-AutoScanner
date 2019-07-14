#include <Arduino.h>
#include <Keyboard.h>

#define BUTTON 3
int buttonState;
unsigned long loopInterval = 100;
unsigned long previousMillis = 0;

String key = "2390N";

void setup() {
    Keyboard.begin();
    pinMode(BUTTON, INPUT_PULLUP);

    previousMillis = millis();
    while((millis() - previousMillis) <= 4000) {}

    Keyboard.write(9); //TAB
    for (unsigned int i = 0; i <= sizeof(key); i++) {
        Keyboard.print(key[i]);
        delay(100);
    }
}

void loop() {
    unsigned long currentMillis = millis();
    if ((unsigned long)(currentMillis - previousMillis) >= loopInterval) {
        previousMillis = millis();

        buttonState = digitalRead(BUTTON);

        if (buttonState == LOW) {
            Serial.println("Pressed");
            Keyboard.write(9); //TAB
            Keyboard.write(9); //TAB
            Keyboard.write(9); //TAB
            Keyboard.write(111); //o
            Keyboard.write(176); //Enter
            Keyboard.write(176); //Enter
            delay(500);
        }
    }
}
