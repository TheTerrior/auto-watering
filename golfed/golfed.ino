#define SOLENOID_PIN 8
#define LOWER_SENSOR_PIN 7
#define UPPER_SENSOR_PIN 6

bool sol = false; //the state of the solenoid
int time = 0; //time solenoid has been open
bool close = false; //solenoid should shut off forever

void setup() {
    pinMode(SOLENOID_PIN, OUTPUT);
    pinMode(LOWER_SENSOR_PIN, INPUT);
    pinMode(UPPER_SENSOR_PIN, INPUT);
}

void loop() {
    close = close || time > 10; //after enough time, shut off the solenoid permanently
    time = sol ? time+1 : 0; //if solenoid is on, count up the time
    sol = !close && !digitalRead(UPPER_SENSOR_PIN) && (sol || (!sol && !digitalRead(LOWER_SENSOR_PIN)));
    digitalWrite(SOLENOID_PIN, sol);
}

