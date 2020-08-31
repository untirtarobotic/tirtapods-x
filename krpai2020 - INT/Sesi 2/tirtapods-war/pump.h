#define PIN_PUMP 9

namespace pump {
  void setup () {
    pinMode(PIN_PUMP, OUTPUT);
  }

  void extinguish (unsigned int ms) {
    digitalWrite(PIN_PUMP, HIGH);
    delay(ms);
    digitalWrite(PIN_PUMP, LOW);
    delay(1000);
  }

  void activate (bool active = true) {
    if (active) digitalWrite(PIN_PUMP, HIGH);
    else digitalWrite(PIN_PUMP, LOW);
  }

  void menyebar() {
    digitalWrite(PIN_PUMP, HIGH);
  }
  void menyebarstop() {
    digitalWrite(PIN_PUMP, LOW);
  }
}
