#define ULTRA_A_ECHO 36
#define ULTRA_A_TRIG 34
#define ULTRA_B_ECHO 51
#define ULTRA_B_TRIG 53
#define ULTRA_C_ECHO 41
#define ULTRA_C_TRIG 43
#define ULTRA_D_ECHO 31
#define ULTRA_D_TRIG 33
#define ULTRA_E_ECHO 28
#define ULTRA_E_TRIG 26

namespace ping {
  bool near_a = false;
  bool near_b = false;
  bool near_c = false;
  bool near_d = false;
  bool near_e = false;
  bool far_a = false;
  bool far_b = false;
  bool far_c = false;
  bool far_d = false;
  bool far_e = false;
  bool isOnSRWR = false;
  bool isOnSLWR = false;

  enum PingSensorType {
    PING_A,
    PING_B,
    PING_C,
    PING_D,
    PING_E
  };

  PingSensorType state_nextPingSensor = PING_A;

  void setup () {
    pinMode(ULTRA_A_TRIG, OUTPUT);
    pinMode(ULTRA_B_TRIG, OUTPUT);
    pinMode(ULTRA_C_TRIG, OUTPUT);
    pinMode(ULTRA_D_TRIG, OUTPUT);
    pinMode(ULTRA_E_TRIG, OUTPUT);
    pinMode(ULTRA_A_ECHO, INPUT);
    pinMode(ULTRA_B_ECHO, INPUT);
    pinMode(ULTRA_C_ECHO, INPUT);
    pinMode(ULTRA_D_ECHO, INPUT);
    pinMode(ULTRA_E_ECHO, INPUT);
  }

  unsigned int read_ping (int trigPin, int echoPin) {
    // ping only waits for pulse in for 5ms
    // more than that, will return integer 64

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    int duration = pulseIn(echoPin, HIGH, 5000);
    if (duration < 1) return 64;
    return (duration / 2) / 29.1;
  }

  String debug () {
    String text = "";

    int pingA = read_ping(ULTRA_A_TRIG, ULTRA_A_ECHO);
    int pingB = read_ping(ULTRA_B_TRIG, ULTRA_B_ECHO);

    text.concat("Ping A:");
    text.concat(pingA);
    text.concat(" B:");
    text.concat(pingB);
    text.concat("   ");

    return text;
  }

  String debug1 () {
    String text = "";

    int pingC = read_ping(ULTRA_C_TRIG, ULTRA_C_ECHO);
    int pingD = read_ping(ULTRA_D_TRIG, ULTRA_D_ECHO);
    int pingE = read_ping(ULTRA_E_TRIG, ULTRA_E_ECHO);

    text.concat("C:");
    text.concat(pingC);
    text.concat(" D:");
    text.concat(pingD);
    text.concat(" E:");
    text.concat(pingE);
    text.concat("   ");

    return text;
  }

  void update () {
    // this ping sensor using round robin method to spread and balance incoming request
    // on purpose to avoid unnecesary delay created everytime ping sensor waits for pulse-in
    // if you want to increase speed of update, then call "update()" multiple times
    // maximum update calls equals to number of sensors (five)

    unsigned int currentPingValue;
    unsigned int offset = 1;
    unsigned int offsetFar = 22;

    switch (state_nextPingSensor) {
      case PING_A:
        currentPingValue = read_ping(ULTRA_A_TRIG, ULTRA_A_ECHO);
        near_a = currentPingValue < (9 + offset);
        far_a = currentPingValue < (8 + offsetFar);
        isOnSRWR = currentPingValue < (14 + offset);
        state_nextPingSensor = PING_B;
        break;
      case PING_B:
        currentPingValue = read_ping(ULTRA_B_TRIG, ULTRA_B_ECHO);
        near_b = currentPingValue < (12 + offset);
        far_b = currentPingValue < (8 + offsetFar);
        state_nextPingSensor = PING_C;
        break;
      case PING_C:
        currentPingValue = read_ping(ULTRA_C_TRIG, ULTRA_C_ECHO);
        near_c = currentPingValue < (12 + offset);
        far_c = currentPingValue < (8 + offsetFar);
        state_nextPingSensor = PING_D;
        break;
      case PING_D:
        currentPingValue = read_ping(ULTRA_D_TRIG, ULTRA_D_ECHO);
        near_d = currentPingValue < (12 + offset);
        far_d = currentPingValue < (8 + offsetFar);
        state_nextPingSensor = PING_E;
        break;
      case PING_E:
        currentPingValue = read_ping(ULTRA_E_TRIG, ULTRA_E_ECHO);
        near_e = currentPingValue < (9 + offset);
        far_e = currentPingValue < (8 + offsetFar);
        isOnSLWR = currentPingValue < (14 + offset);
        state_nextPingSensor = PING_A;
        break;
    }
  }

  bool checkShouldFollowRight() {
    update();
    update();
    update();
    update();
    update();

    if (ping::far_a && ping::far_b) {
      return true;
    } else {
      return false;
    }
  }

  bool save2pump () {
    bool pingB = read_ping(ULTRA_B_TRIG, ULTRA_B_ECHO) < 20;
    bool pingC = read_ping(ULTRA_C_TRIG, ULTRA_C_ECHO) < 22;
    bool pingD = read_ping(ULTRA_D_TRIG, ULTRA_D_ECHO) < 20;

    if (pingB || (pingC && pingD)) return true;
    return false;
  }
}
