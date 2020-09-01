#define PIN_LINE_SENSOR A8
#define PIN_LINE_SENSOR2 A9

void setup() {
  pinMode(PIN_LINE_SENSOR, INPUT);
  pinMode(PIN_LINE_SENSOR2, INPUT);
  Serial.begin(9600);
}

void loop() {

}
