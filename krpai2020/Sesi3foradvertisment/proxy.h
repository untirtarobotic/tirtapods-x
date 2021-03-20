#define PIN_PROXIMITY_B 8
#define PIN_PROXIMITY_A 23

namespace proxy {
  bool isDetectingSomething = false;
  bool isDetectingSomething2 = false;
  
  void setup () {
    pinMode(PIN_PROXIMITY_A,INPUT);
    pinMode(PIN_PROXIMITY_B,INPUT);
  }

  String debug () {
    String text = "";
    text.concat("A:");
    text.concat(digitalRead(PIN_PROXIMITY_A)== LOW);
    text.concat("B:");
    text.concat(digitalRead(PIN_PROXIMITY_B) == LOW);
    return text;
  }

  void update () {
    isDetectingSomething = digitalRead(PIN_PROXIMITY_B) == LOW;
    isDetectingSomething2 = digitalRead(PIN_PROXIMITY_A) == LOW;
  }
}
