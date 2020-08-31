#define PIN_PROXIMITY 8

namespace proxy {
  bool isDetectingSomething = false;

  void setup () {
    pinMode(PIN_PROXIMITY, INPUT);
  }

  String debug () {
    String text = "Proxy: ";
    text.concat(digitalRead(PIN_PROXIMITY) == LOW);
    return text;
  }

  void update () {
    isDetectingSomething = digitalRead(PIN_PROXIMITY) == LOW;
  }
}
