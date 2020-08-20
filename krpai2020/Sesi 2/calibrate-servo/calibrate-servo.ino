#include <SoftwareSerial.h>

SoftwareSerial Leg(19, 18); // RX, TX

void setup() {
  Leg.begin(9600);
}

void loop() {
  newComboA();
}

void newComboA () {
  // LEFT LEGS
  Leg.println("#4P1450 #5P1550 #6P1500 T200");
  Leg.println("#8P1400 #9P1600 #10P1550 T200");
  Leg.println(F("#12P1400 #13P1400 #14P1600 T200"));

  // RIGHT LEGS
  Leg.println(F("#20P1500 #21P1400 #22P1380 T200"));
  Leg.println(F("#24P1400 #25P1500 #26P1280 T200"));
  Leg.println(F("#28P1300 #29P1400 #30P1400 T200"));

  delay(200);
}

void newComboB () {
  // LEFT LEGS
  Leg.println("#4P900 #5P2000 #6P2000 T200");
  Leg.println("#8P1000 #9P2070 #10P2000 T200");
  Leg.println(F("#12P950 #13P1850 #14P2050 T200"));

  // RIGHT LEGS
  Leg.println(F("#20P2000 #21P940 #22P900 T200"));
  Leg.println(F("#24P1900 #25P1040 #26P800 T200"));
  Leg.println(F("#28P1800 #29P900 #30P850 T200"));

  delay(200);
}

void comboA () {
  // LEFT LEGS
  Leg.println(F("#0P1500 #1P1380 #2P1440 T200"));
  Leg.println(F("#4P1500 #5P1450 #6P1300 T200"));
  Leg.println(F("#8P1500 #9P1480 #10P1500 T200"));

  // RIGHT LEGS
  Leg.println(F("#16P1400 #17P1400 #18P1500 T200"));
  Leg.println(F("#20P1350 #21P1350 #22P1420 T200"));
  Leg.println(F("#24P1400 #25P1400 #26P1300 T200"));

  delay(200);
}

void comboB () {
  // LEFT LEGS
  Leg.println(F("#0P970 #1P1750 #2P1880 T200"));
  Leg.println(F("#4P1050 #5P1980 #6P1770 T200"));
  Leg.println(F("#8P1100 #9P1880 #10P2000 T200"));

  // RIGHT LEGS
  Leg.println(F("#16P1950 #17P1020 #18P1030 T200"));
  Leg.println(F("#20P1800 #21P950 #22P920 T200"));
  Leg.println(F("#24P1800 #25P1000 #26P720 T200"));

  delay(200);
}
