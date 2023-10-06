#define SOLENOID_PIN 8
#define LOWER_SENSOR_PIN 7
#define UPPER_SENSOR_PIN 6
#define RESET_PIN 5
#define INDICATOR_PIN 4

bool sol; //the state of the solenoid
bool close; //solenoid should lock off
unsigned long time; //time solenoid has been open

void setup() {
    pinMode(SOLENOID_PIN, OUTPUT);
    pinMode(LOWER_SENSOR_PIN, INPUT);
    pinMode(UPPER_SENSOR_PIN, INPUT);
    pinMode(RESET_PIN, INPUT);
    pinMode(INDICATOR_PIN, OUTPUT);
}

void loop() {
    close = !digitalRead(RESET_PIN) && (close || time > 600); //after about 1min (60s * 10), lock the solenoid off
    time = sol ? time+1 : 0; //if solenoid is on, count up the time
    sol = !close && !digitalRead(UPPER_SENSOR_PIN) && (sol || (!sol && !digitalRead(LOWER_SENSOR_PIN)));
    digitalWrite(SOLENOID_PIN, sol);
    digitalWrite(INDICATOR_PIN, close);
    delay(100);
}

