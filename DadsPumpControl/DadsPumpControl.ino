/*
 *   PSUEDO CODE:
 *   Set flag to 0.
 *   bottom read if signal is on and flag is 0 then set to 1 and continue statements.
 *   next read to be top
 *   Top read if flag is 1 then turn on pump and set flag to 0
 *   next read to be bottom if circut is dead
 *   turn off pump after delay and set flag to 0 then turn off pump
 *   next read will be bottom and flag will be 0 which will form the loop
 */

bool control_flag = false;

const int LOW_WATER_PIN = 2;
const int HIGH_WATER_PIN = 3;
const int PUMP_PIN = 8;

void setup() {
  pinMode(LOW_WATER_PIN, INPUT);
  pinMode(HIGH_WATER_PIN, INPUT);
  pinMode(PUMP_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( digitalRead(LOW_WATER_PIN) && !control_flag ) {
    control_flag = true;
  }
  if ( digitalRead(HIGH_WATER_PIN) && control_flag ) {
    digitalWrite(PUMP_PIN, HIGH);
    control_flag = false;
  }
  if ( !digitalRead(LOW_WATER_PIN) ) {
    digitalWrite(PUMP_PIN, LOW);
    control_flag = false;  
  }
}

