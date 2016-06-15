/* Created and copyrighted by Zachary J. Fields. Offered as open source under the MIT License (MIT). */

const int ENABLE_PIN = 2;
const int FULL_PIN = 3;
const int RELAY_115V_30A_PIN = 8;

void setup() {
  pinMode(ENABLE_PIN, INPUT);
  pinMode(FULL_PIN, INPUT);
  pinMode(RELAY_115V_30A_PIN, OUTPUT);
}

void loop() {
  if ( digitalRead(FULL_PIN) ) {
    digitalWrite(RELAY_115V_30A_PIN, HIGH);
  } else if ( !digitalRead(ENABLE_PIN) ) {
    digitalWrite(RELAY_115V_30A_PIN, LOW);
  }
}

/* Created and copyrighted by Zachary J. Fields. Offered as open source under the MIT License (MIT). */

