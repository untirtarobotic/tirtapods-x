#define PIN_LINE_SENSOR A8
#define PIN_LINE_SENSOR2 A9

namespace line {
  bool isDetected = false;

  void setup () {
    pinMode(PIN_LINE_SENSOR, INPUT);
    pinMode(PIN_LINE_SENSOR2, INPUT);
  }

  void update () {
    if (analogRead(PIN_LINE_SENSOR) >= 900 || analogRead(PIN_LINE_SENSOR2) >= 900) {
      isDetected = true;
    } else {
      isDetected = false;
    }
  }

  String debug () {
    String text = "Line F: ";
    text.concat(analogRead(PIN_LINE_SENSOR));
    text.concat("         ");
    return text;
  }

  String debug1 () {
    String text = "Line C: ";
    text.concat(analogRead(PIN_LINE_SENSOR2));
    text.concat("         ");
    return text;
  }
}
