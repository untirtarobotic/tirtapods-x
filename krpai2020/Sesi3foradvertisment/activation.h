#define PIN_START 42
#define PIN_STOP 40
// #define PIN_SOUND_ACTIVATION 23

namespace activation {
  bool isON = false;
  bool isMenu = false;
  bool isMenuChanged = false;
  unsigned short int activeMenu = 31;
  bool isLowMove = false;
  bool isStartPushed = false;

  void setup () {
    pinMode(PIN_START, INPUT_PULLUP);
    pinMode(PIN_STOP, INPUT_PULLUP);
    // pinMode(PIN_SOUND_ACTIVATION, INPUT);
  }

  String debugSoundActivation () {
    String text = "Sound Act: ";
    // text.concat(digitalRead(PIN_SOUND_ACTIVATION) == LOW);
    return text;
  }

  void update () {
    unsigned int beginRecord = millis();
    unsigned int currentStopRecord = millis();
    unsigned int currentStartRecord = millis();
    bool startIsPressed = false;
    bool stopIsPressed = false;

    while (digitalRead(PIN_STOP) == LOW) {
      currentStopRecord = millis();
      stopIsPressed = true;
    }

    if (digitalRead(PIN_START) == LOW) {
      isStartPushed = true;
    } else {
      isStartPushed = false;
    }

    while (digitalRead(PIN_START) == LOW && !isMenu) {
      currentStartRecord = millis();
      startIsPressed = true;
    }

    if (startIsPressed) {
      if (currentStartRecord - beginRecord > 1000) {
        isLowMove = !isLowMove;
      }

      isON = true;
    }
  
    if (stopIsPressed) {
      isON = false;

      if (currentStopRecord - beginRecord > 2000) {
        isMenu = !isMenu;
        activeMenu = 31;
        isMenuChanged = true;
      } else if (isMenu) {
        isMenuChanged = true;

        if (activeMenu >= 4) {
          activeMenu = 0;
        } else {
          activeMenu = activeMenu + 1;
        }
      } else {
        isMenuChanged = false;
      }
    } else {
      isMenuChanged = false;
    }

//    if (digitalRead(PIN_SOUND_ACTIVATION) == LOW && !isMenu) {
//      isON = true;
//      isLowMove = false;
//    }
  }
}
