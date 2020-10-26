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
    SHIFT_LEFTHIGHER,
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
        com.println(F("#4P1526 #5P2191 #6P2171 #8P1450 #9P2296 #10P2144 #12P1237 #13P2001 #14P2189 #20P1374 #21P769 #22P800 #24P1400 #25P848 #26P646 #28P1471 #29P732 #30P705 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1526 #5P2191 #6P2171 #8P1450 #9P2296 #10P2144 #12P1237 #13P2001 #14P2189 #20P1374 #21P769 #22P800 #24P1400 #25P848 #26P646 #28P1471 #29P732 #30P705 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1526 #5P2191 #6P2171 #8P1450 #9P2296 #10P2144 #12P1237 #13P2001 #14P2189 #20P1374 #21P769 #22P800 #24P1400 #25P848 #26P646 #28P1471 #29P732 #30P705 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1526 #5P2191 #6P2171 #8P1450 #9P2296 #10P2144 #12P1237 #13P2001 #14P2189 #20P1374 #21P769 #22P800 #24P1400 #25P848 #26P646 #28P1471 #29P732 #30P705 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1526 #5P2191 #6P2171 #12P1237 #13P2001 #14P2189 #24P1400 #25P848 #26P646 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1526 #5P1810 #6P1943 #12P1237 #13P1700 #14P2014 #24P1400 #25P1215 #26P873 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#8P1450 #9P2296 #10P2144 #20P1374 #21P769 #22P800 #28P1471 #29P732 #30P705 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#8P1450 #9P1922 #10P1939 #20P1374 #21P1110 #22P1024 #28P1471 #29P1067 #30P908 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize_sync () {
    com.println(F("#4P1526 #5P2191 #6P2171 #12P1237 #13P2001 #14P2189 #24P1400 #25P848 #26P646 T200")); delay(200);
    com.println(F("#4P1526 #5P1810 #6P1943 #12P1237 #13P1700 #14P2014 #24P1400 #25P1215 #26P873 T200")); delay(200);
    com.println(F("#8P1450 #9P2296 #10P2144 #20P1374 #21P769 #22P800 #28P1471 #29P732 #30P705 T200")); delay(200);
    com.println(F("#8P1450 #9P1922 #10P1939 #20P1374 #21P1110 #22P1024 #28P1471 #29P1067 #30P908 T200")); delay(200);
  }

  void ssc_forward_low () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P2218 #6P2241 #8P1322 #9P2290 #10P2130 #12P1325 #13P1967 #14P2114 #20P1472 #21P808 #22P896 #24P1266 #25P853 #26P662 #28P1589 #29P709 #30P642 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P2218 #6P2241 #8P1322 #9P2290 #10P2130 #12P1325 #13P1967 #14P2114 #20P1472 #21P808 #22P896 #24P1266 #25P853 #26P662 #28P1589 #29P709 #30P642 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2148 #6P2073 #8P1578 #9P2290 #10P2130 #12P1126 #13P2022 #14P2243 #20P1251 #21P745 #22P731 #24P1534 #25P853 #26P662 #28P1377 #29P771 #30P792 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P2148 #6P2073 #8P1578 #9P2290 #10P2130 #12P1126 #13P2022 #14P2243 #20P1251 #21P745 #22P731 #24P1534 #25P853 #26P662 #28P1377 #29P771 #30P792 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_higher () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1637 #6P1866 #8P1322 #9P2831 #10P2331 #12P1325 #13P1574 #14P1864 #20P1472 #21P451 #22P733 #24P1266 #25P1360 #26P1001 #28P1589 #29P121 #30P400 T220"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1637 #6P1866 #8P1322 #9P1774 #10P1823 #12P1325 #13P1574 #14P1864 #20P1472 #21P1253 #22P1216 #24P1266 #25P1360 #26P1001 #28P1589 #29P1219 #30P976 T220"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2547 #6P2239 #8P1578 #9P1774 #10P1823 #12P1126 #13P2551 #14P2451 #20P1251 #21P1265 #22P1099 #24P1534 #25P323 #26P439 #28P1377 #29P1207 #30P1083 T220"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P1650 #6P1747 #8P1578 #9P1774 #10P1823 #12P1126 #13P1563 #14P1955 #20P1251 #21P1265 #22P1099 #24P1534 #25P1360 #26P1001 #28P1377 #29P1207 #30P1083 T220"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1803 #6P1994 #8P1322 #9P2404 #10P2179 #12P1325 #13P1695 #14P1954 #20P1472 #21P723 #22P851 #24P1266 #25P1213 #26P884 #28P1589 #29P593 #30P586 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1803 #6P1994 #8P1322 #9P1924 #10P1929 #12P1325 #13P1695 #14P1954 #20P1472 #21P1115 #22P1100 #24P1266 #25P1213 #26P884 #28P1589 #29P1073 #30P862 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2243 #6P2119 #8P1578 #9P1924 #10P1929 #12P1126 #13P2127 #14P2291 #20P1251 #21P1116 #22P973 #24P1534 #25P742 #26P607 #28P1377 #29P1072 #30P978 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P1804 #6P1865 #8P1578 #9P1924 #10P1929 #12P1126 #13P1695 #14P2054 #20P1251 #21P1116 #22P973 #24P1534 #25P1213 #26P884 #28P1377 #29P1072 #30P978 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_sync () {
    com.println(F("#4P1649 #5P1803 #6P1994 #8P1322 #9P2404 #10P2179 #12P1325 #13P1695 #14P1954 #20P1472 #21P723 #22P851 #24P1266 #25P1213 #26P884 #28P1589 #29P593 #30P586 T200")); delay(200);
    com.println(F("#4P1649 #5P1803 #6P1994 #8P1322 #9P1924 #10P1929 #12P1325 #13P1695 #14P1954 #20P1472 #21P1115 #22P1100 #24P1266 #25P1213 #26P884 #28P1589 #29P1073 #30P862 T200")); delay(200);
    com.println(F("#4P1428 #5P2243 #6P2119 #8P1578 #9P1924 #10P1929 #12P1126 #13P2127 #14P2291 #20P1251 #21P1116 #22P973 #24P1534 #25P742 #26P607 #28P1377 #29P1072 #30P978 T200")); delay(200);
    com.println(F("#4P1428 #5P1804 #6P1865 #8P1578 #9P1924 #10P1929 #12P1126 #13P1695 #14P2054 #20P1251 #21P1116 #22P973 #24P1534 #25P1213 #26P884 #28P1377 #29P1072 #30P978 T200")); delay(200);
  }

  void ssc_backward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1428 #5P1804 #6P1865 #8P1578 #9P2404 #10P2179 #12P1126 #13P1695 #14P2054 #20P1251 #21P627 #22P670 #24P1534 #25P1213 #26P884 #28P1377 #29P687 #30P751 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1428 #5P1804 #6P1865 #8P1578 #9P1924 #10P1929 #12P1126 #13P1695 #14P2054 #20P1251 #21P1116 #22P973 #24P1534 #25P1213 #26P884 #28P1377 #29P1072 #30P978 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1649 #5P2350 #6P2304 #8P1322 #9P1924 #10P1929 #12P1325 #13P2041 #14P2150 #20P1472 #21P1115 #22P1100 #24P1266 #25P742 #26P607 #28P1589 #29P1073 #30P862 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1649 #5P1803 #6P1994 #8P1322 #9P1924 #10P1929 #12P1325 #13P1695 #14P1954 #20P1472 #21P1115 #22P1100 #24P1266 #25P1213 #26P884 #28P1589 #29P1073 #30P862 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_backward_sync () {
    com.println(F("#4P1428 #5P1804 #6P1865 #8P1578 #9P2404 #10P2179 #12P1126 #13P1695 #14P2054 #20P1251 #21P627 #22P670 #24P1534 #25P1213 #26P884 #28P1377 #29P687 #30P751 T200")); delay(200);
    com.println(F("#4P1428 #5P1804 #6P1865 #8P1578 #9P1924 #10P1929 #12P1126 #13P1695 #14P2054 #20P1251 #21P1116 #22P973 #24P1534 #25P1213 #26P884 #28P1377 #29P1072 #30P978 T200")); delay(200);
    com.println(F("#4P1649 #5P2350 #6P2304 #8P1322 #9P1924 #10P1929 #12P1325 #13P2041 #14P2150 #20P1472 #21P1115 #22P1100 #24P1266 #25P742 #26P607 #28P1589 #29P1073 #30P862 T200")); delay(200);
    com.println(F("#4P1649 #5P1803 #6P1994 #8P1322 #9P1924 #10P1929 #12P1325 #13P1695 #14P1954 #20P1472 #21P1115 #22P1100 #24P1266 #25P1213 #26P884 #28P1589 #29P1073 #30P862 T200")); delay(200);
  }

  void ssc_shiftRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1605 #5P1788 #6P1789 #8P1450 #9P2472 #10P2287 #12P1166 #13P1683 #14P1896 #20P1295 #21P772 #22P943 #24P1400 #25P1238 #26P816 #28P1547 #29P736 #30P834 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1605 #5P1788 #6P1789 #8P1450 #9P1898 #10P1990 #12P1166 #13P1683 #14P1896 #20P1295 #21P1130 #22P1175 #24P1400 #25P1238 #26P816 #28P1547 #29P1086 #30P1046 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1470 #5P2357 #6P2314 #8P1450 #9P1914 #10P1800 #12P1287 #13P2132 #14P2299 #20P1430 #21P1118 #22P967 #24P1400 #25P851 #26P800 #28P1418 #29P1074 #30P856 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1470 #5P1801 #6P2001 #8P1450 #9P1914 #10P1800 #12P1287 #13P1693 #14P2059 #20P1430 #21P1118 #22P967 #24P1400 #25P1222 #26P1026 #28P1418 #29P1074 #30P856 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1470 #5P1801 #6P2001 #8P1450 #9P2293 #10P2005 #12P1287 #13P1693 #14P2059 #20P1430 #21P621 #22P659 #24P1400 #25P1222 #26P1026 #28P1418 #29P587 #30P577 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1470 #5P1801 #6P2001 #8P1450 #9P1914 #10P1800 #12P1287 #13P1693 #14P2059 #20P1430 #21P1118 #22P967 #24P1400 #25P1222 #26P1026 #28P1418 #29P1074 #30P856 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1605 #5P2187 #6P2025 #8P1450 #9P1898 #10P1990 #12P1166 #13P1998 #14P2077 #20P1295 #21P1130 #22P1175 #24P1400 #25P675 #26P488 #28P1547 #29P1086 #30P1046 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1605 #5P1788 #6P1789 #8P1450 #9P1898 #10P1990 #12P1166 #13P1683 #14P1896 #20P1295 #21P1130 #22P1175 #24P1400 #25P1238 #26P816 #28P1547 #29P1086 #30P1046 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftLeftHigher () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1470 #5P1635 #6P1872 #8P1450 #9P2459 #10P2069 #12P1287 #13P1561 #14P1960 #20P1430 #21P317 #22P524 #24P1400 #25P1357 #26P1134 #28P1418 #29P290 #30P454 T240"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1470 #5P1635 #6P1872 #8P1450 #9P1777 #10P1703 #12P1287 #13P1561 #14P1960 #20P1430 #21P1267 #22P1093 #24P1400 #25P1357 #26P1134 #28P1418 #29P1221 #30P971 T240"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1605 #5P2359 #6P2098 #8P1450 #9P1742 #10P1878 #12P1166 #13P2133 #14P2133 #20P1295 #21P1262 #22P1287 #24P1400 #25PNaN #26PNaN #28P1547 #29P1216 #30P1148 T240"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1605 #5P1640 #6P1675 #8P1450 #9P1742 #10P1878 #12P1166 #13P1566 #14P1808 #20P1295 #21P1262 #22P1287 #24P1400 #25P1391 #26P940 #28P1547 #29P1216 #30P1148 T240"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1695 #5P1807 #6P1886 #8P1322 #9P2290 #10P2130 #12P1407 #13P1700 #14P2020 #20P1205 #21P797 #22P871 #24P1534 #25P1213 #26P884 #28P1289 #29P728 #30P695 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1695 #5P1807 #6P1886 #8P1322 #9P1924 #10P1929 #12P1407 #13P1700 #14P2020 #20P1205 #21P1113 #22P1080 #24P1534 #25P1213 #26P884 #28P1289 #29P1067 #30P901 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1337 #5P2196 #6P2182 #8P1578 #9P1924 #10P1929 #12P1084 #13P1976 #14P2133 #20P1563 #21P1110 #22P1016 #24P1266 #25P853 #26P662 #28P1633 #29P1069 #30P959 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1337 #5P1810 #6P1951 #8P1578 #9P1924 #10P1929 #12P1084 #13P1698 #14P1970 #20P1563 #21P1110 #22P1016 #24P1266 #25P1213 #26P884 #28P1633 #29P1069 #30P959 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW_sync () {
    com.println(F("#4P1695 #5P1807 #6P1886 #8P1322 #9P2290 #10P2130 #12P1407 #13P1700 #14P2020 #20P1205 #21P797 #22P871 #24P1534 #25P1213 #26P884 #28P1289 #29P728 #30P695 T200")); delay(200);
    com.println(F("#4P1695 #5P1807 #6P1886 #8P1322 #9P1924 #10P1929 #12P1407 #13P1700 #14P2020 #20P1205 #21P1113 #22P1080 #24P1534 #25P1213 #26P884 #28P1289 #29P1067 #30P901 T200")); delay(200);
    com.println(F("#4P1337 #5P2196 #6P2182 #8P1578 #9P1924 #10P1929 #12P1084 #13P1976 #14P2133 #20P1563 #21P1110 #22P1016 #24P1266 #25P853 #26P662 #28P1633 #29P1069 #30P959 T200")); delay(200);
    com.println(F("#4P1337 #5P1810 #6P1951 #8P1578 #9P1924 #10P1929 #12P1084 #13P1698 #14P1970 #20P1563 #21P1110 #22P1016 #24P1266 #25P1213 #26P884 #28P1633 #29P1069 #30P959 T200")); delay(200);
  }

  void ssc_rotateCCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1337 #5P1810 #6P1951 #8P1578 #9P2290 #10P2130 #12P1084 #13P1698 #14P1970 #20P1563 #21P765 #22P790 #24P1266 #25P1213 #26P884 #28P1633 #29P760 #30P769 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1337 #5P1810 #6P1951 #8P1578 #9P1924 #10P1929 #12P1084 #13P1698 #14P1970 #20P1563 #21P1110 #22P1016 #24P1266 #25P1213 #26P884 #28P1633 #29P1069 #30P959 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1695 #5P2159 #6P2098 #8P1322 #9P1924 #10P1929 #12P1407 #13P2004 #14P2197 #20P1205 #21P1113 #22P1080 #24P1534 #25P853 #26P662 #28P1289 #29P1067 #30P901 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1695 #5P1807 #6P1886 #8P1322 #9P1924 #10P1929 #12P1407 #13P1700 #14P2020 #20P1205 #21P1113 #22P1080 #24P1534 #25P1213 #26P884 #28P1289 #29P1067 #30P901 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCW_sync () {
    com.println(F("#4P1337 #5P1810 #6P1951 #8P1578 #9P2290 #10P2130 #12P1084 #13P1698 #14P1970 #20P1563 #21P765 #22P790 #24P1266 #25P1213 #26P884 #28P1633 #29P760 #30P769 T200")); delay(200);
    com.println(F("#4P1337 #5P1810 #6P1951 #8P1578 #9P1924 #10P1929 #12P1084 #13P1698 #14P1970 #20P1563 #21P1110 #22P1016 #24P1266 #25P1213 #26P884 #28P1633 #29P1069 #30P959 T200")); delay(200);
    com.println(F("#4P1695 #5P2159 #6P2098 #8P1322 #9P1924 #10P1929 #12P1407 #13P2004 #14P2197 #20P1205 #21P1113 #22P1080 #24P1534 #25P853 #26P662 #28P1289 #29P1067 #30P901 T200")); delay(200);
    com.println(F("#4P1695 #5P1807 #6P1886 #8P1322 #9P1924 #10P1929 #12P1407 #13P1700 #14P2020 #20P1205 #21P1113 #22P1080 #24P1534 #25P1213 #26P884 #28P1289 #29P1067 #30P901 T200")); delay(200);
  }

  void ssc_rotateCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1586 #5P1810 #6P1929 #8P1407 #9P2295 #10P2142 #12P1293 #13P1700 #14P2020 #20P1314 #21P776 #22P817 #24P1445 #25P1214 #26P874 #28P1411 #29P728 #30P695 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1586 #5P1810 #6P1929 #8P1407 #9P1922 #10P1938 #12P1293 #13P1700 #14P2020 #20P1314 #21P1110 #22P1037 #24P1445 #25P1214 #26P874 #28P1411 #29P1067 #30P901 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1463 #5P2196 #6P2182 #8P1493 #9P1922 #10P1938 #12P1183 #13P1995 #14P2176 #20P1437 #21P1110 #22P1016 #24P1355 #25P848 #26P648 #28P1528 #29P1067 #30P920 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1463 #5P1810 #6P1951 #8P1493 #9P1922 #10P1938 #12P1183 #13P1700 #14P2003 #20P1437 #21P1110 #22P1016 #24P1355 #25P1214 #26P874 #28P1528 #29P1067 #30P920 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1463 #5P1810 #6P1951 #8P1493 #9P2295 #10P2142 #12P1183 #13P1700 #14P2003 #20P1437 #21P765 #22P790 #24P1355 #25P1214 #26P874 #28P1528 #29P739 #30P720 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1463 #5P1810 #6P1951 #8P1493 #9P1922 #10P1938 #12P1183 #13P1700 #14P2003 #20P1437 #21P1110 #22P1016 #24P1355 #25P1214 #26P874 #28P1528 #29P1067 #30P920 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1586 #5P2184 #6P2153 #8P1407 #9P1922 #10P1938 #12P1293 #13P2004 #14P2197 #20P1314 #21P1110 #22P1037 #24P1445 #25P848 #26P648 #28P1411 #29P1067 #30P901 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1586 #5P1810 #6P1929 #8P1407 #9P1922 #10P1938 #12P1293 #13P1700 #14P2020 #20P1314 #21P1110 #22P1037 #24P1445 #25P1214 #26P874 #28P1411 #29P1067 #30P901 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1803 #6P1994 #8P1322 #9P2290 #10P2130 #12P1325 #13P1695 #14P1954 #20P1472 #21P808 #22P896 #24P1266 #25P1213 #26P884 #28P1589 #29P709 #30P642 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1803 #6P1994 #8P1322 #9P1924 #10P1929 #12P1325 #13P1695 #14P1954 #20P1472 #21P1115 #22P1100 #24P1266 #25P1213 #26P884 #28P1589 #29P1073 #30P862 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1337 #5P2196 #6P2182 #8P1578 #9P1924 #10P1929 #12P1084 #13P1976 #14P2133 #20P1563 #21P1110 #22P1016 #24P1266 #25P853 #26P662 #28P1633 #29P1069 #30P959 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1337 #5P1810 #6P1951 #8P1578 #9P1924 #10P1929 #12P1084 #13P1698 #14P1970 #20P1563 #21P1110 #22P1016 #24P1266 #25P1213 #26P884 #28P1633 #29P1069 #30P959 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1803 #6P1994 #8P1322 #9P2290 #10P2130 #12P1325 #13P1695 #14P1954 #20P1472 #21P808 #22P896 #24P1266 #25P1213 #26P884 #28P1589 #29P709 #30P642 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1803 #6P1994 #8P1322 #9P1924 #10P1929 #12P1325 #13P1695 #14P1954 #20P1472 #21P1115 #22P1100 #24P1266 #25P1213 #26P884 #28P1589 #29P1073 #30P862 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1695 #5P2159 #6P2098 #8P1322 #9P1924 #10P1929 #12P1407 #13P2004 #14P2197 #20P1205 #21P1113 #22P1080 #24P1534 #25P853 #26P662 #28P1289 #29P1067 #30P901 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1695 #5P1807 #6P1886 #8P1322 #9P1924 #10P1929 #12P1407 #13P1700 #14P2020 #20P1205 #21P1113 #22P1080 #24P1534 #25P1213 #26P884 #28P1289 #29P1067 #30P901 T200"));
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
        case SHIFT_LEFTHIGHER:
          ssc_shiftLeftHigher();
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

  void shiftLeftHigher () {
    move(SHIFT_LEFTHIGHER);
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
