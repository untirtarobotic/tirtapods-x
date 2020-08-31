#include <Wire.h>
#include <LiquidCrystal_I2C.h>

namespace lcd {
  enum MessageID {
    CUSTOM,
    BLANK,
    STANDBY,
    NORMALIZING,
    MOVING_FORWARD,
    ROCK_AND_ROLL,
    MOVING_BACKWARD,
    SHIFTING_RIGHT,
    SHIFTING_LEFT,
    ROTATING_CW,
    ROTATING_CCW,
    TURNING_RIGHT,
    TURNING_LEFT,
    EXTINGUISHING,
    WALL_ON_RIGHT,
    WALL_ON_FRONT,
    WALL_ON_LEFT,
    THERE_IS_OBSTACLE,
    FIRE_ON_RIGHT,
    FIRE_ON_CENTER,
    FIRE_ON_LEFT,
    PATH_ON_RIGHT,
    PATH_ON_FRONT,
    PATH_ON_LEFT,
    NO_PATH,
    FOUND_SRWR,
    FOUND_SLWR,
    LINE_DETECTED
  };

  MessageID state_activeMessageIDs[2] = { BLANK, BLANK };

  LiquidCrystal_I2C lcd(0x27, 16, 2);

  void setup () {
    lcd.begin();
    lcd.backlight();
  }

  void justPrint (String firstRow, String secondRow = "") {
    state_activeMessageIDs[0] = CUSTOM;
    state_activeMessageIDs[1] = CUSTOM;

    lcd.setCursor(0, 0);                          // set cursor to first column at selected row
    lcd.print(firstRow);                          // clear selected row
    lcd.setCursor(0, 1);                          // set cursor back to first column
    lcd.print(secondRow);                         // clear selected row
  }

  void clean () {
    lcd.setCursor(0, 0);                          // set cursor to first column at selected row
    lcd.print(F("                     "));        // clear selected row
    lcd.setCursor(0, 1);                          // set cursor back to first column
    lcd.print(F("                     "));        // clear selected row
  }

  void message (int row, MessageID id) {
    if (row != 0 && row != 1) return;             // valid row is 0 and 1

    if (id != state_activeMessageIDs[row]) {
      state_activeMessageIDs[row] = id;           // update state
      lcd.setCursor(0, row);                      // set cursor to first column at selected row
      lcd.print(F("                     "));      // clear selected row
      lcd.setCursor(0, row);                      // set cursor back to first column
    } else {
      return;                                     // terminate because of no update
    }

    switch (id) {
      case BLANK:
        lcd.print(F(""));
        break;
      case STANDBY:
        lcd.print(F("Standby      ^_^"));
        break;
      case NORMALIZING:
        lcd.print(F("Normalizing legs"));
        break;
      case MOVING_FORWARD:
        lcd.print(F("Moving forward v"));
        break;
      case ROCK_AND_ROLL:
        lcd.print(F("Rock & Roll"));
        break;
      case MOVING_BACKWARD:
        lcd.print(F("Moving backward^"));
        break;
      case SHIFTING_RIGHT:
        lcd.print(F("Shifting right <"));
        break;
      case SHIFTING_LEFT:
        lcd.print(F("Shifting left  >"));
        break;
      case ROTATING_CW:
        lcd.print(F("Rotating CW    <"));
        break;
      case ROTATING_CCW:
        lcd.print(F("Rotating CCW   >"));
        break;
      case TURNING_RIGHT:
        lcd.print(F("Turning right  <"));
        break;
      case TURNING_LEFT:
        lcd.print(F("Turning left   >"));
        break;
      case EXTINGUISHING:
        lcd.print(F("Extinguishing  |"));
        break;
      case WALL_ON_RIGHT:
        lcd.print(F("Wall on right"));
        break;
      case WALL_ON_FRONT:
        lcd.print(F("Wall on front"));
        break;
      case WALL_ON_LEFT:
        lcd.print(F("Wall on left"));
        break;
      case THERE_IS_OBSTACLE:
        lcd.print(F("There's obstacle"));
        break;
      case FIRE_ON_RIGHT:
        lcd.print(F("Fire on right"));
        break;
      case FIRE_ON_CENTER:
        lcd.print(F("Fire on center"));
        break;
      case FIRE_ON_LEFT:
        lcd.print(F("Fire on left"));
        break;
      case PATH_ON_RIGHT:
        lcd.print(F("Path on right"));
        break;
      case PATH_ON_FRONT:
        lcd.print(F("Path on front"));
        break;
      case PATH_ON_LEFT:
        lcd.print(F("Path on left"));
        break;
      case NO_PATH:
        lcd.print(F("No path"));
        break;
      case FOUND_SRWR:
        lcd.print(F("Found SRWR"));
        break;
      case FOUND_SLWR:
        lcd.print(F("Found SLWR"));
        break;
      case LINE_DETECTED:
        lcd.print(F("Line detected"));
        break;
    }
  }
}
