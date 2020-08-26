#include "ping.h"
#include "proxy.h"
#include "flame.h"
#include "legs.h"
#include "pump.h"
#include "activation.h"
#include "lcd.h"
#include "line.h"

bool state_isInversed = true;
bool state_isInitialized = false;
unsigned int state_startTime = 0;
unsigned int state_lastSWR = 0;

int CurrentState = 0;
int CounterRead = 0;

bool avoidWall(bool inverse = false);
bool flameDetection();
bool avoid3Ladder(bool inverse = false);
bool getCloser2SRWR(bool inverse = false);
void traceRoute();
void traceRouteInversed();

void setup () {
  ping::setup();
  proxy::setup();
  flame::setup();
  legs::setup();
  pump::setup();
  activation::setup();
  lcd::setup();
  line::setup();

  Serial.begin(9600);
}

void loop () {
  activation::update();

  if (activation::isON) {
    if (activation::isLowMove) {
      lcd::justPrint("Path on front     ", "Moving forward + ");
      legs::forward(true);
      return;
    }

    if (!state_isInitialized) {
      state_startTime = millis();
      state_isInversed = ping::checkShouldFollowLeft();
      state_isInitialized = true;
    }

    ping::update();
    proxy::update();
    flame::update();
    line::update();
//
//    Serial.println(state_lastSWR);
//
//    if ((millis() - state_lastSWR) > 17000) {
//      Serial.println("called");
//      state_isInversed = !state_isInversed;
//    }

    if (state_isInversed) {
      if (ping::isOnSLWR) {
        state_lastSWR = millis();
      }
      if (detectLine()) return;
      if (!avoidWall(true)) return;
      if (flameDetection()) return;
      if (!avoid3Ladder(true)) return;
      if (!getCloser2SRWR(true)) return;
      traceRouteInverse();
    } else {
      if (ping::isOnSRWR) {
        state_lastSWR = millis();
      }
      if (detectLine()) return;
      if (!avoidWall()) return;
      if (flameDetection()) return;
      if (!avoid3Ladder()) return;
      if (!getCloser2SRWR()) return;
      traceRoute();
    }
  } else {
    if (state_isInitialized) state_isInitialized = false;

    if (activation::isMenu) {
      if (activation::isMenuChanged) lcd::clean();
      switch (activation::activeMenu) {
        case 0:
          lcd::justPrint(ping::debug(), ping::debug1());
          break;
        case 1:
          lcd::justPrint(flame::debug(), flame::debug1());
          break;
        case 2:
          lcd::justPrint(proxy::debug(), activation::debugSoundActivation());
          break;
        case 3:
          lcd::justPrint(line::debug(), line::debug1());
          break;
        case 4:
          lcd::justPrint("Press start to", "extinguish");
          pump::activate(activation::isStartPushed);
          break;
        default:
          lcd::justPrint("== DEBUG MODE ==", "Press stop again");
      }
    } else {
      standBy();
    }
  }
}

void standBy () {
  if (legs::isStandby) {
    lcd::message(0, lcd::STANDBY);
    lcd::message(1, lcd::BLANK);
    return;
  }

  if (legs::isNormalized) {
    legs::standby();
    return;
  }

  lcd::message(0, lcd::NORMALIZING);
  lcd::message(1, lcd::BLANK);
  legs::normalize();
}

bool avoid3Ladder (bool inverse = false) {
  if (proxy::isDetectingSomething && !ping::far_c) {
    lcd::message(0, lcd::THERE_IS_OBSTACLE);

    unsigned int startCounter = millis();
    unsigned int currentCounter = millis();

    if (!legs::isNormalized) {
      legs::normalize();
      return false;
    }

    while ((currentCounter - startCounter) <= 1600) {
      legs::rotateCWLess();
      ping::update();
      currentCounter = millis();

      if (ping::far_c) {
        return false;
      }
    }

    while ((currentCounter - startCounter) <= 4800) {
      legs::rotateCCWLess();
      ping::update();
      currentCounter = millis();

      if (ping::far_c) {
        return false;
      }
    }

    while ((currentCounter - startCounter) <= 6400) {
      legs::rotateCWLess();
      ping::update();
      currentCounter = millis();

      if (ping::far_c) {
        return false;
      }
    }

    if (inverse) {
      while ((currentCounter - startCounter) <= (7200 + 6 * 800)) {
        legs::forwardHigher();
        currentCounter = millis();
      }

    } else {
      while ((currentCounter - startCounter) <= (7200 + 6 * 800)) {
        legs::rotateCCW();
        currentCounter = millis();
      }
    }

    ping::update();
    ping::update();
    ping::update();
    ping::update();
    ping::update();

    return false;
  }

  return true;
}

bool detectLine() {
    if (line::isDetected && CounterRead == 0) {
      CounterRead = CounterRead + 1;
      lcd::message(0, lcd::LINE_DETECTED);
      unsigned int startCounter = millis();
      unsigned int currentCounter = millis();
      while ((currentCounter - startCounter) < 3000) {
        lcd::message(1, lcd::MOVING_FORWARD);
        currentCounter = millis();
        legs::forward();
      }
      while ((currentCounter - startCounter) < 5000) {
        lcd::message(1, lcd::ROTATING_CW);
        currentCounter = millis();
        legs::rotateCW();
      }
      while ((currentCounter - startCounter) < 6000) {
        lcd::message(1, lcd::NORMALIZING);
        currentCounter = millis();
        legs::normalize();
      }
      while ((currentCounter - startCounter) < 9000) {
        lcd::message(1, lcd::ROTATING_CCW);
        currentCounter = millis();
        legs::rotateCCW();
      }
      while ((currentCounter - startCounter) < 10000) {
        lcd::message(1, lcd::ROTATING_CCW);
        currentCounter = millis();
        legs::rotateCCW();
        pump::menyebar();
      }
      while ((currentCounter - startCounter) < 12000) {
        lcd::message(1, lcd::ROTATING_CCW);
        currentCounter = millis();
        legs::rotateCCW();
        pump::menyebarstop();
      }
      while ((currentCounter - startCounter) < 13000) {
        lcd::message(1, lcd::NORMALIZING);
        currentCounter = millis();
        legs::normalize();
      }
      unsigned int startFakeCounter = millis();
      unsigned int currentFakeCounter = millis();
      while ((currentFakeCounter - startFakeCounter) < 3000) {
        lcd::message(1, lcd::ROTATING_CW);
        currentFakeCounter = millis();
        legs::rotateCW();
      }
      while ((currentFakeCounter - startFakeCounter) < 4000) {
        lcd::message(1, lcd::NORMALIZING);
        currentFakeCounter = millis();
        legs::normalize();
      }
      while ((currentFakeCounter - startFakeCounter) < 10000) {
        lcd::message(1, lcd::ROTATING_CCW);
        currentFakeCounter = millis();
        legs::rotateCCW();
      }
      while ((currentFakeCounter - startFakeCounter) < 12000) {
        lcd::message(1, lcd::SHIFTING_RIGHT);
        currentFakeCounter = millis();
        legs::shiftRight();
      }
      while ((currentFakeCounter - startFakeCounter) < 13500) {
        lcd::message(1, lcd::ROTATING_CCW);
        currentFakeCounter = millis();
        legs::rotateCCW();
      }
      ping::update();
      ping::update();
      ping::update();
      ping::update();
      ping::update();
      return true;
  }
    if (line::isDetected && CounterRead == 2) {
      CounterRead = CounterRead + 1;
      lcd::message(0, lcd::LINE_DETECTED);
      unsigned int startCounter = millis();
      unsigned int currentCounter = millis();
      while ((currentCounter - startCounter) < 3000) {
        lcd::message(1, lcd::MOVING_FORWARD);
        currentCounter = millis();
        legs::forward();
      }
      while ((currentCounter - startCounter) < 5000) {
        lcd::message(1, lcd::ROTATING_CW);
        currentCounter = millis();
        legs::rotateCW();
      }
      while ((currentCounter - startCounter) < 6000) {
        lcd::message(1, lcd::NORMALIZING);
        currentCounter = millis();
        legs::normalize();
      }
      while ((currentCounter - startCounter) < 9000) {
        lcd::message(1, lcd::ROTATING_CCW);
        currentCounter = millis();
        legs::rotateCCW();
      }
      while ((currentCounter - startCounter) < 10000) {
        lcd::message(1, lcd::ROTATING_CCW);
        currentCounter = millis();
        legs::rotateCCW();
        pump::menyebar();
      }
      while ((currentCounter - startCounter) < 12000) {
        lcd::message(1, lcd::ROTATING_CCW);
        currentCounter = millis();
        legs::rotateCCW();
        pump::menyebarstop();
      }
      while ((currentCounter - startCounter) < 13000) {
        lcd::message(1, lcd::NORMALIZING);
        currentCounter = millis();
        legs::normalize();
      }
      unsigned int startFakeCounter = millis();
      unsigned int currentFakeCounter = millis();
      while ((currentFakeCounter - startFakeCounter) < 3000) {
        lcd::message(1, lcd::ROTATING_CW);
        currentFakeCounter = millis();
        legs::rotateCW();
      }
      while ((currentFakeCounter - startFakeCounter) < 4000) {
        lcd::message(1, lcd::NORMALIZING);
        currentFakeCounter = millis();
        legs::normalize();
      }
      while ((currentFakeCounter - startFakeCounter) < 9000) {
        lcd::message(1, lcd::ROTATING_CCW);
        currentFakeCounter = millis();
        legs::rotateCCW();
      }
      while ((currentFakeCounter - startFakeCounter) < 10000) {
        lcd::message(1, lcd::NORMALIZING);
        currentFakeCounter = millis();
        legs::normalize();
      }
      while ((currentFakeCounter - startFakeCounter) < 12000) {
        lcd::message(1, lcd::MOVING_FORWARD);
        currentFakeCounter = millis();
        legs::forward();
      }
      while ((currentFakeCounter - startFakeCounter) < 13500) {
        lcd::message(1, lcd::ROTATING_CCW);
        currentFakeCounter = millis();
        legs::rotateCCW();
      }
      while ((currentFakeCounter - startFakeCounter) < 14500) {
        lcd::message(1, lcd::SHIFTING_RIGHT);
        currentFakeCounter = millis();
        legs::shiftRight();
      }
      return true;
  }
    if (line::isDetected && CounterRead == 4) {
      CounterRead = CounterRead + 1;
      lcd::message(0, lcd::LINE_DETECTED);
      unsigned int startCounter = millis();
      unsigned int currentCounter = millis();
      while ((currentCounter - startCounter) < 3000) {
        lcd::message(1, lcd::MOVING_FORWARD);
        currentCounter = millis();
        legs::forward();
      }
      while ((currentCounter - startCounter) < 5000) {
        lcd::message(1, lcd::ROTATING_CW);
        currentCounter = millis();
        legs::rotateCW();
      }
      while ((currentCounter - startCounter) < 6000) {
        lcd::message(1, lcd::NORMALIZING);
        currentCounter = millis();
        legs::normalize();
      }
      while ((currentCounter - startCounter) < 9000) {
        lcd::message(1, lcd::ROTATING_CCW);
        currentCounter = millis();
        legs::rotateCCW();
      }
      while ((currentCounter - startCounter) < 10000) {
        lcd::message(1, lcd::ROTATING_CCW);
        currentCounter = millis();
        legs::rotateCCW();
        pump::menyebar();
      }
      while ((currentCounter - startCounter) < 12000) {
        lcd::message(1, lcd::ROTATING_CCW);
        currentCounter = millis();
        legs::rotateCCW();
        pump::menyebarstop();
      }
      while ((currentCounter - startCounter) < 13000) {
        lcd::message(1, lcd::NORMALIZING);
        currentCounter = millis();
        legs::normalize();
      }
      unsigned int startFakeCounter = millis();
      unsigned int currentFakeCounter = millis();
      while ((currentFakeCounter - startFakeCounter) < 3000) {
        lcd::message(1, lcd::ROTATING_CW);
        currentFakeCounter = millis();
        legs::rotateCW();
      }
      while ((currentFakeCounter - startFakeCounter) < 4000) {
        lcd::message(1, lcd::NORMALIZING);
        currentFakeCounter = millis();
        legs::normalize();
      }
      while ((currentFakeCounter - startFakeCounter) < 9000) {
        lcd::message(1, lcd::ROTATING_CCW);
        currentFakeCounter = millis();
        legs::rotateCCW();
      }
      while ((currentFakeCounter - startFakeCounter) < 10000) {
        lcd::message(1, lcd::NORMALIZING);
        currentFakeCounter = millis();
        legs::normalize();
      }
      while ((currentFakeCounter - startFakeCounter) < 13500) {
        lcd::message(1, lcd::MOVING_FORWARD);
        currentFakeCounter = millis();
        legs::forward();
      }
      while ((currentFakeCounter - startFakeCounter) < 15500) {
        lcd::message(1, lcd::ROTATING_CCW);
        currentFakeCounter = millis();
        legs::rotateCCW();
      }
      ping::update();
      ping::update();
      ping::update();
      ping::update();
      ping::update();
      return true;
  }
  if (line::isDetected && CounterRead == 5) {
    CounterRead = CounterRead + 1;
    lcd::message(0, lcd::LINE_DETECTED);
    unsigned int startCounter = millis();
    unsigned int currentCounter = millis();
    while ((currentCounter - startCounter) < 2000) {
      lcd::message(1, lcd::MOVING_FORWARD);
      currentCounter = millis();
      legs::forward();
    }
    while ((currentCounter - startCounter) < 3700) {
      lcd::message(1, lcd::ROTATING_CW);
      currentCounter = millis();
      legs::rotateCW();
    }
    while ((currentCounter - startCounter) < 4700) {
        lcd::message(1, lcd::NORMALIZING);
        currentCounter = millis();
        legs::normalize();
      }
    while ((currentCounter - startCounter) < 9000) {
      lcd::message(1, lcd::MOVING_FORWARD);
      currentCounter = millis();
      legs::forward();
    }
    unsigned int startFakeCounter = millis();
    unsigned int currentFakeCounter = millis();
    while ((currentFakeCounter - startFakeCounter) < 4000) {
      lcd::message(1, lcd::SHIFTING_RIGHT);
      currentFakeCounter = millis();
      legs::shiftRight();
    }
     while ((currentFakeCounter - startFakeCounter) < 6000) {
      lcd::message(1, lcd::ROTATING_CCW);
      currentFakeCounter = millis();
      legs::rotateCCW();
    }
    while ((currentFakeCounter - startFakeCounter) < 9000) {
      lcd::message(1, lcd::MOVING_FORWARD);
      currentFakeCounter = millis();
      legs::forward();
    }
    return true;
  }
  if (line::isDetected && CounterRead == 6) {
    CounterRead = CounterRead + 1;
    lcd::message(0, lcd::LINE_DETECTED);
    unsigned int startCounter = millis();
    unsigned int currentCounter = millis();
    while ((currentCounter - startCounter) < 3000) {
      lcd::message(1, lcd::MOVING_FORWARD);
      currentCounter = millis();
      legs::forward();
    }
    while ((currentCounter - startCounter) < 5000) {
      lcd::message(1, lcd::ROTATING_CW);
      currentCounter = millis();
      legs::rotateCW();
    }
    while ((currentCounter - startCounter) < 6000) {
        lcd::message(1, lcd::NORMALIZING);
        currentCounter = millis();
        legs::normalize();
      }
    while ((currentCounter - startCounter) < 9000) {
        lcd::message(1, lcd::ROTATING_CCW);
        currentCounter = millis();
        legs::rotateCCW();
      }
      while ((currentCounter - startCounter) < 10000) {
        lcd::message(1, lcd::ROTATING_CCW);
        currentCounter = millis();
        legs::rotateCCW();
        pump::menyebar();
      }
      while ((currentCounter - startCounter) < 11000) {
        lcd::message(1, lcd::ROTATING_CCW);
        currentCounter = millis();
        legs::rotateCCW();
        pump::menyebarstop();
      }
    while ((currentCounter - startCounter) < 12000) {
        lcd::message(1, lcd::NORMALIZING);
        currentCounter = millis();
        legs::normalize();
      }
    unsigned int startFakeCounter = millis();
    unsigned int currentFakeCounter = millis();
    while ((currentFakeCounter - startFakeCounter) < 3000) {
      lcd::message(1, lcd::ROTATING_CW);
      currentFakeCounter = millis();
      legs::rotateCW();
    }
    while ((currentFakeCounter - startFakeCounter) < 4000) {
        lcd::message(1, lcd::NORMALIZING);
        currentFakeCounter = millis();
        legs::normalize();
      }
    while ((currentFakeCounter - startFakeCounter) < 10000) {
      lcd::message(1, lcd::ROTATING_CCW);
      currentFakeCounter = millis();
      legs::rotateCCW();
    }
    while ((currentFakeCounter - startFakeCounter) < 11000) {
      lcd::message(1, lcd::SHIFTING_RIGHT);
      currentFakeCounter = millis();
      legs::shiftRight();
    }
    return true;
  }
  if (line::isDetected && CounterRead == 7 ) {
    CounterRead = CounterRead + 1;
    lcd::message(0, lcd::LINE_DETECTED);
    unsigned int startCounter = millis();
    unsigned int currentCounter = millis();
    while ((currentCounter - startCounter) < 2000) {
      lcd::message(1, lcd::MOVING_FORWARD);
      currentCounter = millis();
      legs::forward();
    }
    while ((currentCounter - startCounter) < 4000) {
      lcd::message(1, lcd::ROTATING_CCW);
      currentCounter = millis();
      legs::rotateCCW();
    }
    ping::update();
    ping::update();
    ping::update();
    ping::update();
    ping::update();
    return true;
  }
  if (line::isDetected && CounterRead !=0 && CounterRead !=5 && CounterRead !=7) {
    CounterRead = CounterRead + 1;
    lcd::message(0, lcd::LINE_DETECTED);
    unsigned int startCounter = millis();
    unsigned int currentCounter = millis();
    while ((currentCounter - startCounter) < 1000) {
      lcd::message(1, lcd::MOVING_FORWARD);
      currentCounter = millis();
      legs::forward();
    }
    return true;
  }

bool flameDetection () {
  if (flame::is_right && (ping::near_b || ping::near_a)) {
    lcd::message(0, lcd::FIRE_ON_RIGHT);
    lcd::message(1, lcd::SHIFTING_LEFT);
    legs::shiftLeft();
    return true;
  }

  if (flame::is_left && (ping::near_d || ping::near_e)) {
    lcd::message(0, lcd::FIRE_ON_LEFT);
    lcd::message(1, lcd::SHIFTING_RIGHT);
    legs::shiftRight();
    return true;
  }

  if (flame::is_right && !flame::is_left && !flame::is_center) {
    lcd::message(0, lcd::FIRE_ON_RIGHT);
    lcd::message(1, lcd::ROTATING_CW);
    legs::rotateCW();
    return true;
  }

  if (flame::is_left && !flame::is_right && !flame::is_center) {
    lcd::message(0, lcd::FIRE_ON_LEFT);
    lcd::message(1, lcd::ROTATING_CCW);
    legs::rotateCCW();
    return true;
  }

  if (flame::is_right && !flame::is_left && flame::is_center) {
    lcd::message(0, lcd::FIRE_ON_RIGHT);
    lcd::message(1, lcd::ROTATING_CW);
    legs::rotateCWLess();
    return true;
  }

  if (flame::is_left && !flame::is_right && flame::is_center) {
    lcd::message(0, lcd::FIRE_ON_LEFT);
    lcd::message(1, lcd::ROTATING_CCW);
    legs::rotateCCWLess();
    return true;
  }

  if (flame::is_center) {
    lcd::message(0, lcd::FIRE_ON_CENTER);

    if (ping::near_b) {
      lcd::message(1, lcd::ROTATING_CCW);
      legs::rotateCCWLess();
    } else if (ping::near_d) {
      lcd::message(1, lcd::ROTATING_CW);
      legs::rotateCWLess();
    } else {
      if (proxy::isDetectingSomething) {
        lcd::message(1, lcd::EXTINGUISHING);
        pump::extinguish(1000);

        unsigned int startCounter = millis();
        unsigned int currentCounter = millis();

        while ((currentCounter - startCounter) < 1650) {
          legs::backward();
        }
      } else {
        lcd::message(1, lcd::MOVING_FORWARD);
        legs::forward();
      }
    }

    return true;
  }

  return false;
}

bool getCloser2SRWR (bool inverse = false) {
  if (inverse) {
    if (ping::far_e && !ping::far_d && !ping::isOnSLWR) {
      lcd::message(0, lcd::FOUND_SLWR);
      lcd::message(1, lcd::SHIFTING_LEFT);
      legs::shiftLeft();
      return false;
    }
  } else {
    if (ping::far_a && !ping::far_b && !ping::isOnSRWR) {
      lcd::message(0, lcd::FOUND_SRWR);
      lcd::message(1, lcd::SHIFTING_RIGHT);
      legs::shiftRight();
      return false;
    }
  }

  return true;
}

void traceRoute () {
  if (!ping::far_a && !ping::far_b) {
    lcd::message(0, lcd::PATH_ON_RIGHT);
    lcd::message(1, lcd::TURNING_RIGHT);
    legs::turnRight();
  } else if (ping::far_a && !ping::far_c) {
    lcd::message(0, lcd::PATH_ON_FRONT);
    lcd::message(1, lcd::MOVING_FORWARD);
    legs::forward();
  } else if (ping::far_a && ping::far_c && !ping::far_e) {
    lcd::message(0, lcd::PATH_ON_LEFT);
    lcd::message(1, lcd::TURNING_LEFT);
    legs::turnLeft();
  } else {
    lcd::message(0, lcd::NO_PATH);
    lcd::message(1, lcd::ROTATING_CCW);
    legs::rotateCCW(1600);
    ping::update();
    ping::update();
    ping::update();
    ping::update();
    ping::update();
  }
}

void traceRouteInverse () {
  if (!ping::far_e && !ping::far_d) {
    lcd::message(0, lcd::PATH_ON_LEFT);
    lcd::message(1, lcd::TURNING_LEFT);
    legs::turnLeft();
  } else if (ping::far_e && !ping::far_c) {
    lcd::message(0, lcd::PATH_ON_FRONT);
    lcd::message(1, lcd::MOVING_FORWARD);
    legs::forward();
  } else if (ping::far_e && ping::far_c && !ping::far_a) {
    lcd::message(0, lcd::PATH_ON_RIGHT);
    lcd::message(1, lcd::TURNING_RIGHT);
    legs::turnRight();
  } else {
    lcd::message(0, lcd::NO_PATH);
    lcd::message(1, lcd::ROTATING_CW);
    legs::rotateCW(1600);
    ping::update();
    ping::update();
    ping::update();
    ping::update();
    ping::update();
  }
}
