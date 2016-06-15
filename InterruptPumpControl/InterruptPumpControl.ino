
const int ENABLE_PIN = 2;
const int FULL_PIN = 3;
const int RELAY_115V_30A_PIN = 8;

void disablePump (void);
void enablePump (void);

void setup (void) {
  pinMode(ENABLE_PIN, INPUT);
  pinMode(FULL_PIN, INPUT);
  pinMode(RELAY_115V_30A_PIN, OUTPUT);

  // Set interrupts to guard against trigger conditions
  attachInterrupt(digitalPinToInterrupt(ENABLE_PIN), disablePump, LOW);
  attachInterrupt(digitalPinToInterrupt(FULL_PIN), enablePump, HIGH);

  // Check initial state
  if ( digitalRead(FULL_PIN) ) {
    enablePump();
  } else {
    disablePump();
  }
}

void loop (void) {
  // The pump logic is entirely interrupt driven.
}

void disablePump (void) {
  digitalWrite(RELAY_115V_30A_PIN, LOW);
}

void enablePump (void) {
  digitalWrite(RELAY_115V_30A_PIN, HIGH);
}

