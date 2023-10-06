#define SOLENOID_PIN 8
#define LOWER_SENSOR_PIN 7
#define UPPER_SENSOR_PIN 6
#define RESET_PIN 5
#define INDICATOR_PIN 4


bool sol; //the current state of the solenoid
bool close; //solenoid should lock off
unsigned long time; //time solenoid has been open


// Runs at startup
void setup() {
    pinMode(SOLENOID_PIN, OUTPUT);
    pinMode(LOWER_SENSOR_PIN, INPUT);
    pinMode(UPPER_SENSOR_PIN, INPUT);
    pinMode(RESET_PIN, INPUT);
    pinMode(INDICATOR_PIN, OUTPUT);
}


// Runs continuously
void loop() {

    // when the reset button is pressed, reset the solenoid lock
    if (digitalRead(RESET_PIN) == HIGH) {
        close = false; //allows the solenoid to reopen
        time = 0;
        digitalWrite(INDICATOR_PIN, LOW); //turn light off
    }

    // if the solenoid is locked, ignore all sensor inputs
    if (close) {
        return;
    }

    // once the time surpasses a minute, lock the solenoid off
    if (time > 5 * 10) { //60s * 10 deciseconds
        sol = false; //close the solenoid
        close = true; //lock the solenoid
        digitalWrite(INDICATOR_PIN, HIGH); //turn light on
        digitalWrite(SOLENOID_PIN, LOW);
        return;
    }

    // if the solenoid is on, count up the time
    if (sol) {
        time++;
    } else {
        time = 0;
    }

    // turn on solenoid when both sensors aren't triggered
    if (!sol && digitalRead(LOWER_SENSOR_PIN) == LOW && digitalRead(UPPER_SENSOR_PIN) == LOW) {
        sol = true;
        digitalWrite(SOLENOID_PIN, HIGH);
        return;
    }

    // turn off solenoid when top sensor triggered
    if (sol && digitalRead(UPPER_SENSOR_PIN) == HIGH) {
        sol = false;
        digitalWrite(SOLENOID_PIN, LOW);
    }

    delay(100);
}

