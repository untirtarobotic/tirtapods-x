#define PIN_LINE_SENSOR A8
#define PIN_LINE_SENSOR2 A9

void setup() {
  pinMode(PIN_LINE_SENSOR, INPUT);
  pinMode(PIN_LINE_SENSOR2, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print(analogRead(PIN_LINE_SENSOR));
  Serial.print(" ");
  Serial.println(analogRead(PIN_LINE_SENSOR2));
  delay(200);
}
