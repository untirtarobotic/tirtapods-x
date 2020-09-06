#define PIN_PROXIMITY 8

namespace proxy {
  bool isDetectingSomething = false;
  int CounterStairs = 0;

  void setup () {
    pinMode(PIN_PROXIMITY, INPUT);
  }

  String debug () {
    String text = "Proxy: ";
    text.concat(digitalRead(PIN_PROXIMITY) == LOW);
    return text;
  }

  void update () {
    if(digitalRead(PIN_PROXIMITY) == LOW && CounterStairs == 0){
    isDetectingSomething;
    CounterStairs = 1;
    }
  }
}
