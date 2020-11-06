#define PIN_PUMP 9
#define PIN_START 42

void setup () {
  pinMode(PIN_PUMP, OUTPUT);
  pinMode(PIN_START, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(PIN_START) == LOW) {
    digitalWrite(PIN_PUMP, HIGH);
  } else {
    digitalWrite(PIN_PUMP, LOW);
  }
}
