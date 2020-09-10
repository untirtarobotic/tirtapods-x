#define PIN_FLAME_INDICATOR 44
#define PIN_PHOTODIODE_A A0
#define PIN_PHOTODIODE_B A1
#define PIN_PHOTODIODE_C A2
#define PIN_PHOTODIODE_D A3
#define PIN_PHOTODIODE_E A4

void setup() {
  pinMode(PIN_FLAME_INDICATOR, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned int flame_a = analogRead(PIN_PHOTODIODE_A);
  unsigned int flame_b = analogRead(PIN_PHOTODIODE_B);
  unsigned int flame_c = analogRead(PIN_PHOTODIODE_C);
  unsigned int flame_d = analogRead(PIN_PHOTODIODE_D);
  unsigned int flame_e = analogRead(PIN_PHOTODIODE_E);

  Serial.print("A: ");
  Serial.print(flame_a);
  Serial.print(" B: ");
  Serial.print(flame_b);
  Serial.print(" C: ");
  Serial.print(flame_c);
  Serial.print(" D: ");
  Serial.print(flame_d);
  Serial.print(" E: ");
  Serial.print(flame_e);
  Serial.println();
}
