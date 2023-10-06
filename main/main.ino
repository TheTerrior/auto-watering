#define SOLENOID_PIN 8
#define LOWER_SENSOR_PIN 7
#define UPPER_SENSOR_PIN 6


bool solenoid_on; //the state of the solenoid


// Runs at startup
void setup() {
    pinMode(SOLENOID_PIN, OUTPUT);
    pinMode(LOWER_SENSOR_PIN, INPUT);
    pinMode(UPPER_SENSOR_PIN, INPUT);
}


// Runs continuously
void loop() {
    // turn on solenoid when both empty
    if (!solenoid_on && digitalRead(LOWER_SENSOR_PIN) == LOW && digitalRead(UPPER_SENSOR_PIN) == LOW) {
        solenoid_on = true;
        digitalWrite(SOLENOID_PIN, HIGH);
        return;
    }

    // turn off solenoid when top triggered
    if (solenoid_on && digitalRead(UPPER_SENSOR_PIN) == HIGH) {
        solenoid_on = false;
        digitalWrite(SOLENOID_PIN, LOW);
    }
}

