#define PIN_SOUND_ACTIVATION 23

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN_SOUND_ACTIVATION, INPUT);

  Serial.begin(9600);
}

void loop () {
  Serial.println(digitalRead(PIN_SOUND_ACTIVATION));

  if (digitalRead(PIN_SOUND_ACTIVATION) == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(44, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(44, LOW);
  }
}
