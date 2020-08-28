#define PIN_FLAME_INDICATOR 44
#define PIN_PHOTODIODE_A A0
#define PIN_PHOTODIODE_B A1
#define PIN_PHOTODIODE_C A2
#define PIN_PHOTODIODE_D A3
#define PIN_PHOTODIODE_E A4

namespace flame {
  bool is_right = false;
  bool is_left = false;
  bool is_center = false;
  unsigned long int state_lastRecord = 0;
  bool state_isIndicatorOn = false;

  void setup () {
    pinMode(PIN_FLAME_INDICATOR, OUTPUT);
  }

  void blinkIndicator () {
    if (millis() > state_lastRecord + 199) {
      state_lastRecord = millis();
      state_isIndicatorOn = !state_isIndicatorOn;
      if (state_isIndicatorOn) {
        digitalWrite(PIN_FLAME_INDICATOR, LOW);
      } else {
        digitalWrite(PIN_FLAME_INDICATOR, HIGH);
      }
    }
  }

  void activateIndicator (bool active = true) {
    if (active) digitalWrite(PIN_FLAME_INDICATOR, HIGH);
    else digitalWrite(PIN_FLAME_INDICATOR, LOW);
  }

  void update () {
    unsigned int flame_a = analogRead(PIN_PHOTODIODE_A);
    unsigned int flame_b = analogRead(PIN_PHOTODIODE_B);
    unsigned int flame_c = analogRead(PIN_PHOTODIODE_C);
    unsigned int flame_d = analogRead(PIN_PHOTODIODE_D);
    unsigned int flame_e = analogRead(PIN_PHOTODIODE_E);

    is_right = flame_b > 800;
    is_center = flame_c > 800;
    is_left = flame_d > 800;

    activateIndicator(is_right || is_center || is_left);
  }

  String debug () {
    update();

    String text = "Flame F:";
    text.concat(analogRead(PIN_PHOTODIODE_C));
    text.concat("           ");
    return text;
  }

  String debug1 () {
    update();

    String text = "R:";
    text.concat(analogRead(PIN_PHOTODIODE_B));
    text.concat(" L:");
    text.concat(analogRead(PIN_PHOTODIODE_D));
    text.concat("         ");
    return text;
  }
}
