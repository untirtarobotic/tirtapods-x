#define ULTRA_A_ECHO 36
#define ULTRA_A_TRIG 34
#define ULTRA_B_ECHO 51
#define ULTRA_B_TRIG 53
#define ULTRA_C_ECHO 41
#define ULTRA_C_TRIG 43
#define ULTRA_D_ECHO 31
#define ULTRA_D_TRIG 33
#define ULTRA_E_ECHO 28
#define ULTRA_E_TRIG 26

unsigned int read_ping (int trigPin, int echoPin) {
  // ping only waits for pulse in for 5ms
  // more than that, will return integer 64

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH, 5000);
  if (duration < 1) return 64;
  return (duration / 2) / 29.1;
}

void setup() {
  pinMode(ULTRA_A_TRIG, OUTPUT);
  pinMode(ULTRA_B_TRIG, OUTPUT);
  pinMode(ULTRA_C_TRIG, OUTPUT);
  pinMode(ULTRA_D_TRIG, OUTPUT);
  pinMode(ULTRA_E_TRIG, OUTPUT);
  pinMode(ULTRA_A_ECHO, INPUT);
  pinMode(ULTRA_B_ECHO, INPUT);
  pinMode(ULTRA_C_ECHO, INPUT);
  pinMode(ULTRA_D_ECHO, INPUT);
  pinMode(ULTRA_E_ECHO, INPUT);

  Serial.begin(9600);
}

void loop() {
  int pingA = read_ping(ULTRA_A_TRIG, ULTRA_A_ECHO);
  int pingB = read_ping(ULTRA_B_TRIG, ULTRA_B_ECHO);
  int pingC = read_ping(ULTRA_C_TRIG, ULTRA_C_ECHO);
  int pingD = read_ping(ULTRA_D_TRIG, ULTRA_D_ECHO);
  int pingE = read_ping(ULTRA_E_TRIG, ULTRA_E_ECHO);

  Serial.print("A: ");
  Serial.print(pingA);
  Serial.print(" B: ");
  Serial.print(pingB);
  Serial.print(" C: ");
  Serial.print(pingC);
  Serial.print(" D: ");
  Serial.print(pingD);
  Serial.print(" E: ");
  Serial.print(pingE);

  Serial.println();
}
