#include <SoftwareSerial.h>

SoftwareSerial Leg(19, 18); // RX, TX

void setup() {
  Leg.begin(9600);
}

void loop() {
  newComboB();
}

void newComboA () {
  // LEFT LEGS
  Leg.println("#4P1400 #5P1500 #6P1600 T200");
  Leg.println("#8P1450 #9P1600 #10P1600 T200");
  Leg.println(F("#12P1450 #13P1300 #14P1550 T200"));

  // RIGHT LEGS
  Leg.println(F("#20P1500 #21P1450 #22P1400 T200"));
  Leg.println(F("#24P1400 #25P1550 #26P1320 T200"));
  Leg.println(F("#28P1300 #29P1350 #30P1280 T200"));

  delay(200);
}

void newComboB () {
  // LEFT LEGS
  Leg.println("#4P900 #5P2000 #6P2100 T200");
  Leg.println("#8P1000 #9P2100 #10P2150 T200");
  Leg.println(F("#12P950 #13P1850 #14P2100 T200"));

  // RIGHT LEGS
  Leg.println(F("#20P2000 #21P940 #22P850 T200"));
  Leg.println(F("#24P1870 #25P1040 #26P800 T200"));
  Leg.println(F("#28P1800 #29P850 #30P800 T200"));

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
