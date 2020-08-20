#include <SoftwareSerial.h>

namespace legs {
  bool isNormalized = false;
  bool isStandby = false;

  enum MoveType {
    STANDBY,
    NORMALIZE,
    FORWARD,
    FORWARD_LOW,
    FORWARD_HIGHER,
    BACKWARD,
    SHIFT_RIGHT,
    SHIFT_LEFT,
    ROTATE_CW,
    ROTATE_CCW,
    ROTATE_CW_LESS,
    ROTATE_CCW_LESS,
    TURN_RIGHT,
    TURN_LEFT
  };

  MoveType state_currentMove = NORMALIZE;
  unsigned short int state_step2keep = 0;
  unsigned long int state_lastMoveRecord = 0;
  unsigned short int state_nextStep = 0;
  bool state_isComboAUp = true;
  bool state_isComboBUp = true;
  unsigned short int state_endStep = 3;

  SoftwareSerial com(19, 18); // RX, TX

  void setup () {
    com.begin(9600);
  }


    // START OF CODE GENERATED

  void ssc_standby () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1588 #5P2151 #6P2045 #8P1400 #9P2247 #10P2090 #12P1287 #13P2001 #14P2091 #20P1374 #21P786 #22P856 #24P1400 #25P867 #26P704 #28P1426 #29P732 #30P800 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1588 #5P2151 #6P2045 #8P1400 #9P2247 #10P2090 #12P1287 #13P2001 #14P2091 #20P1374 #21P786 #22P856 #24P1400 #25P867 #26P704 #28P1426 #29P732 #30P800 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1588 #5P2151 #6P2045 #8P1400 #9P2247 #10P2090 #12P1287 #13P2001 #14P2091 #20P1374 #21P786 #22P856 #24P1400 #25P867 #26P704 #28P1426 #29P732 #30P800 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1588 #5P2151 #6P2045 #8P1400 #9P2247 #10P2090 #12P1287 #13P2001 #14P2091 #20P1374 #21P786 #22P856 #24P1400 #25P867 #26P704 #28P1426 #29P732 #30P800 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1588 #5P2151 #6P2045 #12P1287 #13P2001 #14P2091 #24P1400 #25P867 #26P704 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1588 #5P1850 #6P1842 #12P1287 #13P1700 #14P1908 #24P1400 #25P1198 #26P914 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#8P1400 #9P2247 #10P2090 #20P1374 #21P786 #22P856 #28P1426 #29P732 #30P800 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#8P1400 #9P1909 #10P1894 #20P1374 #21P1093 #22P1052 #28P1426 #29P1067 #30P1024 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize_sync () {
    com.println(F("#4P1588 #5P2151 #6P2045 #12P1287 #13P2001 #14P2091 #24P1400 #25P867 #26P704 T200")); delay(200);
    com.println(F("#4P1588 #5P1850 #6P1842 #12P1287 #13P1700 #14P1908 #24P1400 #25P1198 #26P914 T200")); delay(200);
    com.println(F("#8P1400 #9P2247 #10P2090 #20P1374 #21P786 #22P856 #28P1426 #29P732 #30P800 T200")); delay(200);
    com.println(F("#8P1400 #9P1909 #10P1894 #20P1374 #21P1093 #22P1052 #28P1426 #29P1067 #30P1024 T200")); delay(200);
  }

  void ssc_forward_low () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1724 #5P2172 #6P2108 #8P1286 #9P2242 #10P2077 #12P1375 #13P1967 #14P2012 #20P1472 #21P821 #22P940 #24P1258 #25P872 #26P718 #28P1549 #29P709 #30P731 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1724 #5P2172 #6P2108 #8P1286 #9P2242 #10P2077 #12P1375 #13P1967 #14P2012 #20P1472 #21P821 #22P940 #24P1258 #25P872 #26P718 #28P1549 #29P709 #30P731 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1480 #5P2117 #6P1958 #8P1514 #9P2242 #10P2077 #12P1176 #13P2022 #14P2148 #20P1251 #21P764 #22P796 #24P1542 #25P872 #26P718 #28P1328 #29P771 #30P896 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1480 #5P2117 #6P1958 #8P1514 #9P2242 #10P2077 #12P1176 #13P2022 #14P2148 #20P1251 #21P764 #22P796 #24P1542 #25P872 #26P718 #28P1328 #29P771 #30P896 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_higher () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P2731 #10P2269 #12P1375 #13P1695 #14P1845 #20P1472 #21P499 #22P798 #24P1258 #25P1196 #26P924 #28P1549 #29P121 #30P465 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P1911 #10P1884 #12P1375 #13P1695 #14P1845 #20P1472 #21P1098 #22P1119 #24P1258 #25P1196 #26P924 #28P1549 #29P1073 #30P973 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1480 #5P2432 #6P2106 #8P1514 #9P1911 #10P1884 #12P1176 #13P2551 #14P2365 #20P1251 #21P1099 #22P1008 #24P1542 #25P393 #26P513 #28P1328 #29P1072 #30P1100 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1480 #5P1845 #6P1772 #8P1514 #9P1911 #10P1884 #12P1176 #13P1695 #14P1949 #20P1251 #21P1099 #22P1008 #24P1542 #25P1196 #26P924 #28P1328 #29P1072 #30P1100 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P2242 #10P2077 #12P1375 #13P1695 #14P1845 #20P1472 #21P821 #22P940 #24P1258 #25P1196 #26P924 #28P1549 #29P709 #30P731 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P1911 #10P1884 #12P1375 #13P1695 #14P1845 #20P1472 #21P1098 #22P1119 #24P1258 #25P1196 #26P924 #28P1549 #29P1073 #30P973 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1480 #5P2117 #6P1958 #8P1514 #9P1911 #10P1884 #12P1176 #13P2022 #14P2148 #20P1251 #21P1099 #22P1008 #24P1542 #25P872 #26P718 #28P1328 #29P1072 #30P1100 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1480 #5P1845 #6P1772 #8P1514 #9P1911 #10P1884 #12P1176 #13P1695 #14P1949 #20P1251 #21P1099 #22P1008 #24P1542 #25P1196 #26P924 #28P1328 #29P1072 #30P1100 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_sync () {
    com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P2242 #10P2077 #12P1375 #13P1695 #14P1845 #20P1472 #21P821 #22P940 #24P1258 #25P1196 #26P924 #28P1549 #29P709 #30P731 T200")); delay(200);
    com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P1911 #10P1884 #12P1375 #13P1695 #14P1845 #20P1472 #21P1098 #22P1119 #24P1258 #25P1196 #26P924 #28P1549 #29P1073 #30P973 T200")); delay(200);
    com.println(F("#4P1480 #5P2117 #6P1958 #8P1514 #9P1911 #10P1884 #12P1176 #13P2022 #14P2148 #20P1251 #21P1099 #22P1008 #24P1542 #25P872 #26P718 #28P1328 #29P1072 #30P1100 T200")); delay(200);
    com.println(F("#4P1480 #5P1845 #6P1772 #8P1514 #9P1911 #10P1884 #12P1176 #13P1695 #14P1949 #20P1251 #21P1099 #22P1008 #24P1542 #25P1196 #26P924 #28P1328 #29P1072 #30P1100 T200")); delay(200);
  }

  void ssc_backward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1480 #5P1845 #6P1772 #8P1514 #9P2242 #10P2077 #12P1176 #13P1695 #14P1949 #20P1251 #21P764 #22P796 #24P1542 #25P1196 #26P924 #28P1328 #29P771 #30P896 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1480 #5P1845 #6P1772 #8P1514 #9P1911 #10P1884 #12P1176 #13P1695 #14P1949 #20P1251 #21P1099 #22P1008 #24P1542 #25P1196 #26P924 #28P1328 #29P1072 #30P1100 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1724 #5P2172 #6P2108 #8P1286 #9P1911 #10P1884 #12P1375 #13P1967 #14P2012 #20P1472 #21P1098 #22P1119 #24P1258 #25P872 #26P718 #28P1549 #29P1073 #30P973 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P1911 #10P1884 #12P1375 #13P1695 #14P1845 #20P1472 #21P1098 #22P1119 #24P1258 #25P1196 #26P924 #28P1549 #29P1073 #30P973 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_backward_sync () {
    com.println(F("#4P1480 #5P1845 #6P1772 #8P1514 #9P2242 #10P2077 #12P1176 #13P1695 #14P1949 #20P1251 #21P764 #22P796 #24P1542 #25P1196 #26P924 #28P1328 #29P771 #30P896 T200")); delay(200);
    com.println(F("#4P1480 #5P1845 #6P1772 #8P1514 #9P1911 #10P1884 #12P1176 #13P1695 #14P1949 #20P1251 #21P1099 #22P1008 #24P1542 #25P1196 #26P924 #28P1328 #29P1072 #30P1100 T200")); delay(200);
    com.println(F("#4P1724 #5P2172 #6P2108 #8P1286 #9P1911 #10P1884 #12P1375 #13P1967 #14P2012 #20P1472 #21P1098 #22P1119 #24P1258 #25P872 #26P718 #28P1549 #29P1073 #30P973 T200")); delay(200);
    com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P1911 #10P1884 #12P1375 #13P1695 #14P1845 #20P1472 #21P1098 #22P1119 #24P1258 #25P1196 #26P924 #28P1549 #29P1073 #30P973 T200")); delay(200);
  }

  void ssc_shiftRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1675 #5P1833 #6P1704 #8P1400 #9P2268 #10P2164 #12P1216 #13P1683 #14P1784 #20P1295 #21P856 #22P1017 #24P1400 #25P1219 #26P861 #28P1505 #29P809 #30P984 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1675 #5P1833 #6P1704 #8P1400 #9P1888 #10P1943 #12P1216 #13P1683 #14P1784 #20P1295 #21P1111 #22P1184 #24P1400 #25P1219 #26P861 #28P1505 #29P1086 #30P1175 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1527 #5P2175 #6P2117 #8P1400 #9P1902 #10P1761 #12P1337 #13P2025 #14P2155 #20P1430 #21P1100 #22P1002 #24P1400 #25P941 #26P883 #28P1370 #29P1074 #30P967 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1527 #5P1843 #6P1894 #8P1400 #9P1902 #10P1761 #12P1337 #13P1693 #14P1954 #20P1430 #21P1100 #22P1002 #24P1400 #25P1205 #26P1055 #28P1370 #29P1074 #30P967 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1527 #5P1843 #6P1894 #8P1400 #9P2172 #10P1922 #12P1337 #13P1693 #14P1954 #20P1430 #21P761 #22P788 #24P1400 #25P1205 #26P1055 #28P1370 #29P706 #30P722 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1527 #5P1843 #6P1894 #8P1400 #9P1902 #10P1761 #12P1337 #13P1693 #14P1954 #20P1430 #21P1100 #22P1002 #24P1400 #25P1205 #26P1055 #28P1370 #29P1074 #30P967 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1675 #5P2082 #6P1879 #8P1400 #9P1888 #10P1943 #12P1216 #13P1932 #14P1941 #20P1295 #21P1111 #22P1184 #24P1400 #25P847 #26P625 #28P1505 #29P1086 #30P1175 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1675 #5P1833 #6P1704 #8P1400 #9P1888 #10P1943 #12P1216 #13P1683 #14P1784 #20P1295 #21P1111 #22P1184 #24P1400 #25P1219 #26P861 #28P1505 #29P1086 #30P1175 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1775 #5P1848 #6P1791 #8P1286 #9P2242 #10P2077 #12P1457 #13P1700 #14P1914 #20P1205 #21P811 #22P919 #24P1542 #25P1196 #26P924 #28P1237 #29P728 #30P790 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1775 #5P1848 #6P1791 #8P1286 #9P1911 #10P1884 #12P1457 #13P1700 #14P1914 #20P1205 #21P1096 #22P1101 #24P1542 #25P1196 #26P924 #28P1237 #29P1067 #30P1016 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1380 #5P2154 #6P2055 #8P1514 #9P1911 #10P1884 #12P1134 #13P1976 #14P2033 #20P1563 #21P1094 #22P1045 #24P1258 #25P872 #26P718 #28P1595 #29P1069 #30P1080 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1380 #5P1850 #6P1849 #8P1514 #9P1911 #10P1884 #12P1134 #13P1698 #14P1862 #20P1563 #21P1094 #22P1045 #24P1258 #25P1196 #26P924 #28P1595 #29P1069 #30P1080 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW_sync () {
    com.println(F("#4P1775 #5P1848 #6P1791 #8P1286 #9P2242 #10P2077 #12P1457 #13P1700 #14P1914 #20P1205 #21P811 #22P919 #24P1542 #25P1196 #26P924 #28P1237 #29P728 #30P790 T200")); delay(200);
    com.println(F("#4P1775 #5P1848 #6P1791 #8P1286 #9P1911 #10P1884 #12P1457 #13P1700 #14P1914 #20P1205 #21P1096 #22P1101 #24P1542 #25P1196 #26P924 #28P1237 #29P1067 #30P1016 T200")); delay(200);
    com.println(F("#4P1380 #5P2154 #6P2055 #8P1514 #9P1911 #10P1884 #12P1134 #13P1976 #14P2033 #20P1563 #21P1094 #22P1045 #24P1258 #25P872 #26P718 #28P1595 #29P1069 #30P1080 T200")); delay(200);
    com.println(F("#4P1380 #5P1850 #6P1849 #8P1514 #9P1911 #10P1884 #12P1134 #13P1698 #14P1862 #20P1563 #21P1094 #22P1045 #24P1258 #25P1196 #26P924 #28P1595 #29P1069 #30P1080 T200")); delay(200);
  }

  void ssc_rotateCCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1380 #5P1850 #6P1849 #8P1514 #9P2242 #10P2077 #12P1134 #13P1698 #14P1862 #20P1563 #21P782 #22P847 #24P1258 #25P1196 #26P924 #28P1595 #29P760 #30P871 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1380 #5P1850 #6P1849 #8P1514 #9P1911 #10P1884 #12P1134 #13P1698 #14P1862 #20P1563 #21P1094 #22P1045 #24P1258 #25P1196 #26P924 #28P1595 #29P1069 #30P1080 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1775 #5P2126 #6P1981 #8P1286 #9P1911 #10P1884 #12P1457 #13P2004 #14P2099 #20P1205 #21P1096 #22P1101 #24P1542 #25P872 #26P718 #28P1237 #29P1067 #30P1016 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1775 #5P1848 #6P1791 #8P1286 #9P1911 #10P1884 #12P1457 #13P1700 #14P1914 #20P1205 #21P1096 #22P1101 #24P1542 #25P1196 #26P924 #28P1237 #29P1067 #30P1016 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCW_sync () {
    com.println(F("#4P1380 #5P1850 #6P1849 #8P1514 #9P2242 #10P2077 #12P1134 #13P1698 #14P1862 #20P1563 #21P782 #22P847 #24P1258 #25P1196 #26P924 #28P1595 #29P760 #30P871 T200")); delay(200);
    com.println(F("#4P1380 #5P1850 #6P1849 #8P1514 #9P1911 #10P1884 #12P1134 #13P1698 #14P1862 #20P1563 #21P1094 #22P1045 #24P1258 #25P1196 #26P924 #28P1595 #29P1069 #30P1080 T200")); delay(200);
    com.println(F("#4P1775 #5P2126 #6P1981 #8P1286 #9P1911 #10P1884 #12P1457 #13P2004 #14P2099 #20P1205 #21P1096 #22P1101 #24P1542 #25P872 #26P718 #28P1237 #29P1067 #30P1016 T200")); delay(200);
    com.println(F("#4P1775 #5P1848 #6P1791 #8P1286 #9P1911 #10P1884 #12P1457 #13P1700 #14P1914 #20P1205 #21P1096 #22P1101 #24P1542 #25P1196 #26P924 #28P1237 #29P1067 #30P1016 T200")); delay(200);
  }

  void ssc_rotateCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1654 #5P1850 #6P1830 #8P1361 #9P2247 #10P2088 #12P1343 #13P1700 #14P1914 #20P1314 #21P792 #22P871 #24P1448 #25P1197 #26P915 #28P1363 #29P728 #30P790 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1654 #5P1850 #6P1830 #8P1361 #9P1909 #10P1893 #12P1343 #13P1700 #14P1914 #20P1314 #21P1093 #22P1064 #24P1448 #25P1197 #26P915 #28P1363 #29P1067 #30P1016 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1520 #5P2154 #6P2055 #8P1439 #9P1909 #10P1893 #12P1233 #13P1995 #14P2077 #20P1437 #21P1094 #22P1045 #24P1352 #25P867 #26P706 #28P1486 #29P1067 #30P1037 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1520 #5P1850 #6P1849 #8P1439 #9P1909 #10P1893 #12P1233 #13P1700 #14P1897 #20P1437 #21P1094 #22P1045 #24P1352 #25P1197 #26P915 #28P1486 #29P1067 #30P1037 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1520 #5P1850 #6P1849 #8P1439 #9P2247 #10P2088 #12P1233 #13P1700 #14P1897 #20P1437 #21P782 #22P847 #24P1352 #25P1197 #26P915 #28P1486 #29P739 #30P817 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1520 #5P1850 #6P1849 #8P1439 #9P1909 #10P1893 #12P1233 #13P1700 #14P1897 #20P1437 #21P1094 #22P1045 #24P1352 #25P1197 #26P915 #28P1486 #29P1067 #30P1037 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1654 #5P2145 #6P2030 #8P1361 #9P1909 #10P1893 #12P1343 #13P2004 #14P2099 #20P1314 #21P1093 #22P1064 #24P1448 #25P867 #26P706 #28P1363 #29P1067 #30P1016 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1654 #5P1850 #6P1830 #8P1361 #9P1909 #10P1893 #12P1343 #13P1700 #14P1914 #20P1314 #21P1093 #22P1064 #24P1448 #25P1197 #26P915 #28P1363 #29P1067 #30P1016 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P2242 #10P2077 #12P1375 #13P1695 #14P1845 #20P1472 #21P821 #22P940 #24P1258 #25P1196 #26P924 #28P1549 #29P709 #30P731 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P1911 #10P1884 #12P1375 #13P1695 #14P1845 #20P1472 #21P1098 #22P1119 #24P1258 #25P1196 #26P924 #28P1549 #29P1073 #30P973 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1380 #5P2154 #6P2055 #8P1514 #9P1911 #10P1884 #12P1134 #13P1976 #14P2033 #20P1563 #21P1094 #22P1045 #24P1258 #25P872 #26P718 #28P1595 #29P1069 #30P1080 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1380 #5P1850 #6P1849 #8P1514 #9P1911 #10P1884 #12P1134 #13P1698 #14P1862 #20P1563 #21P1094 #22P1045 #24P1258 #25P1196 #26P924 #28P1595 #29P1069 #30P1080 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P2242 #10P2077 #12P1375 #13P1695 #14P1845 #20P1472 #21P821 #22P940 #24P1258 #25P1196 #26P924 #28P1549 #29P709 #30P731 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P1911 #10P1884 #12P1375 #13P1695 #14P1845 #20P1472 #21P1098 #22P1119 #24P1258 #25P1196 #26P924 #28P1549 #29P1073 #30P973 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1775 #5P2126 #6P1981 #8P1286 #9P1911 #10P1884 #12P1457 #13P2004 #14P2099 #20P1205 #21P1096 #22P1101 #24P1542 #25P872 #26P718 #28P1237 #29P1067 #30P1016 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1775 #5P1848 #6P1791 #8P1286 #9P1911 #10P1884 #12P1457 #13P1700 #14P1914 #20P1205 #21P1096 #22P1101 #24P1542 #25P1196 #26P924 #28P1237 #29P1067 #30P1016 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  // END OF GENERATED


  void move (MoveType id) {
    if (millis() - state_lastMoveRecord > 199) {
      state_lastMoveRecord = millis();

      if (state_currentMove != NORMALIZE || (state_currentMove == NORMALIZE && (state_isComboAUp || state_isComboBUp))) {
        isNormalized = false;
      }

      if (state_currentMove != STANDBY) {
        isStandby = false;
      }

      if (state_step2keep > 0) {
        state_step2keep = state_step2keep - 1;
      } else {
        state_currentMove = id;
      }

      switch (state_currentMove) {
        case STANDBY:
          ssc_standby();
          break;
        case NORMALIZE:
          ssc_normalize();
          break;
        case FORWARD:
          ssc_forward();
          break;
        case FORWARD_LOW:
          ssc_forward_low();
          break;
        case FORWARD_HIGHER:
          ssc_forward_higher();
          break;
        case BACKWARD:
          ssc_backward();
          break;
        case SHIFT_RIGHT:
          ssc_shiftRight();
          break;
        case SHIFT_LEFT:
          ssc_shiftLeft();
          break;
        case ROTATE_CW:
          ssc_rotateCW();
          break;
        case ROTATE_CCW:
          ssc_rotateCCW();
          break;
        case ROTATE_CW_LESS:
          ssc_rotateCWLess();
          break;
        case ROTATE_CCW_LESS:
          ssc_rotateCCWLess();
          break;
        case TURN_RIGHT:
          ssc_turnRight();
          break;
        case TURN_LEFT:
          ssc_turnLeft();
          break;
      }
    }
  }

  void keep (int num) {
    if (state_step2keep < 1) {
      state_step2keep = num;
    }
  }

  void force () {
    state_step2keep = 0;
  }

  void standby () {
    move(STANDBY);
    if (state_currentMove == STANDBY) isStandby = true;
  }

  void normalize () {
    if (state_currentMove != NORMALIZE) {
      if (state_isComboAUp) {
        state_nextStep = 1;
      } else if (state_isComboBUp) {
        state_nextStep = 3;
      }
    }

    move(NORMALIZE);

    if (state_currentMove == NORMALIZE && !state_isComboAUp && !state_isComboBUp) {
      isNormalized = true;
    }
  }

  void forward (bool low = false) {
    if (low) move(FORWARD_LOW);
    else move(FORWARD);
  }

  void forwardHigher (){
    move(FORWARD_HIGHER);
  }
  
  void backward () {
    move(BACKWARD);
  }

  void shiftRight () {
    move(SHIFT_RIGHT);
  }

  void shiftLeft () {
    move(SHIFT_LEFT);
  }

  void rotateCW (unsigned int keep = 0) {
    if (keep > 0) {
      unsigned int startCounter = millis();
      unsigned int currentCounter = millis();
      while ((currentCounter - startCounter) < keep) {
        move(ROTATE_CW);
        currentCounter = millis();
      }
    } else {
      move(ROTATE_CW);
    }
  }

  void rotateCCW (unsigned int keep = 0) {
    if (keep > 0) {
      unsigned int startCounter = millis();
      unsigned int currentCounter = millis();
      while ((currentCounter - startCounter) < keep) {
        move(ROTATE_CCW);
        currentCounter = millis();
      }
    } else {
      move(ROTATE_CCW);
    }
  }

  void rotateCWLess () {
    move(ROTATE_CW_LESS);
  }

  void rotateCCWLess () {
    move(ROTATE_CCW_LESS);
  }

  void turnRight () {
    move(TURN_RIGHT);
  }

  void turnLeft () {
    move(TURN_LEFT);
  }
}
