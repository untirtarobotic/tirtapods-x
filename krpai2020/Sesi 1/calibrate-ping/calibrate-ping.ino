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
#include <Ewma.h>
Ewma adcFilter1(0.1); //* filter used to smooth sensor data
Ewma adcFilter2(0.1); //? Less smoothing - faster to detect changes, but more prone to noise
Ewma adcFilter3(0.1); //? More smoothing - less prone to noise, but slower to detect changes
Ewma adcFilter4(0.1); 
Ewma adcFilter5(0.1); 

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

  float  pingAf = adcFilter1.filter(pingA);
  float  pingBf = adcFilter2.filter(pingB);
  float  pingCf = adcFilter3.filter(pingC);
  float  pingDf = adcFilter4.filter(pingD);
  float  pingEf = adcFilter5.filter(pingE);

  // Serial.print("A:");
  Serial.print(pingA);
  Serial.print(",");
  // Serial.print(" B: ");
  Serial.print(pingB);
  Serial.print(",");
  // Serial.print(" C: ");
  Serial.print(pingC);
  Serial.print(",");
  // Serial.print(" D: ");
  Serial.print(pingD);
  Serial.print(",");
  // Serial.print(" E: ");
  Serial.print(pingE);
  Serial.print(",");
  Serial.print(pingAf);
  Serial.print(",");
  // Serial.print(" B: ");
  Serial.print(pingBf);
  Serial.print(",");
  // Serial.print(" C: ");
  Serial.print(pingCf);
  Serial.print(",");
  // Serial.print(" D: ");
  Serial.print(pingDf);
  Serial.print(",");
  // Serial.print(" E: ");
  Serial.print(pingEf);

  Serial.println();
}
