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
  Leg.println("#4P1400 #5P1430 #6P1580 T200"); //coxa, femur,tibia
  Leg.println("#8P1450 #9P1520 #10P1500 T200");
  Leg.println(F("#12P1350 #13P1350 #14P1680 T200"));

  // RIGHT LEGS
  Leg.println(F("#20P1500 #21P1410 #22P1380 T200"));
  Leg.println(F("#24P1400 #25P1600 #26P1250 T200"));
  Leg.println(F("#28P1350 #29P1400 #30P1250 T200"));

  delay(200);
}

void newComboB () {
  // LEFT LEGS
  Leg.println("#4P900 #5P1950 #6P2050 T200");
  Leg.println("#8P1000 #9P2080 #10P2030 T200");
  Leg.println(F("#12P900 #13P1850 #14P2150 T200"));

  // RIGHT LEGS
  Leg.println(F("#20P2000 #21P940 #22P850 T200"));
  Leg.println(F("#24P1870 #25P1040 #26P750 T200"));
  Leg.println(F("#28P1830 #29P900 #30P750 T200"));

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
