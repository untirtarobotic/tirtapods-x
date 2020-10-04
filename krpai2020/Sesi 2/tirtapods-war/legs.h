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
        com.println(F("#4P1526 #5P2168 #6P2145 #8P1450 #9P2288 #10P2224 #12P1237 #13P2035 #14P2144 #20P1374 #21P769 #22P800 #24P1400 #25P848 #26P650 #28P1476 #29P682 #30P702 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1526 #5P2168 #6P2145 #8P1450 #9P2288 #10P2224 #12P1237 #13P2035 #14P2144 #20P1374 #21P769 #22P800 #24P1400 #25P848 #26P650 #28P1476 #29P682 #30P702 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1526 #5P2168 #6P2145 #8P1450 #9P2288 #10P2224 #12P1237 #13P2035 #14P2144 #20P1374 #21P769 #22P800 #24P1400 #25P848 #26P650 #28P1476 #29P682 #30P702 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1526 #5P2168 #6P2145 #8P1450 #9P2288 #10P2224 #12P1237 #13P2035 #14P2144 #20P1374 #21P769 #22P800 #24P1400 #25P848 #26P650 #28P1476 #29P682 #30P702 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1526 #5P2168 #6P2145 #12P1237 #13P2035 #14P2144 #24P1400 #25P848 #26P650 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1526 #5P1833 #6P1942 #12P1237 #13P1667 #14P1948 #24P1400 #25P1215 #26P868 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#8P1450 #9P2288 #10P2224 #20P1374 #21P769 #22P800 #28P1476 #29P682 #30P702 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#8P1450 #9P1929 #10P1997 #20P1374 #21P1110 #22P1024 #28P1476 #29P1017 #30P918 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize_sync () {
    com.println(F("#4P1526 #5P2168 #6P2145 #12P1237 #13P2035 #14P2144 #24P1400 #25P848 #26P650 T200")); delay(200);
    com.println(F("#4P1526 #5P1833 #6P1942 #12P1237 #13P1667 #14P1948 #24P1400 #25P1215 #26P868 T200")); delay(200);
    com.println(F("#8P1450 #9P2288 #10P2224 #20P1374 #21P769 #22P800 #28P1476 #29P682 #30P702 T200")); delay(200);
    com.println(F("#8P1450 #9P1929 #10P1997 #20P1374 #21P1110 #22P1024 #28P1476 #29P1017 #30P918 T200")); delay(200);
  }

  void ssc_forward_low () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P2191 #6P2208 #8P1322 #9P2283 #10P2208 #12P1325 #13P1992 #14P2060 #20P1472 #21P808 #22P896 #24P1266 #25P853 #26P665 #28P1599 #29P659 #30P635 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P2191 #6P2208 #8P1322 #9P2283 #10P2208 #12P1325 #13P1992 #14P2060 #20P1472 #21P808 #22P896 #24P1266 #25P853 #26P665 #28P1599 #29P659 #30P635 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2129 #6P2058 #8P1578 #9P2283 #10P2208 #12P1126 #13P2060 #14P2204 #20P1251 #21P745 #22P731 #24P1534 #25P853 #26P665 #28P1378 #29P721 #30P794 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P2129 #6P2058 #8P1578 #9P2283 #10P2208 #12P1126 #13P2060 #14P2204 #20P1251 #21P745 #22P731 #24P1534 #25P853 #26P665 #28P1378 #29P721 #30P794 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_higher () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1681 #6P1874 #8P1322 #9P2803 #10P2431 #12P1325 #13P1512 #14P1780 #20P1472 #21P451 #22P733 #24P1266 #25P1360 #26P991 #28P1599 #29P71 #30P379 T220"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1681 #6P1874 #8P1322 #9P1786 #10P1869 #12P1325 #13P1512 #14P1780 #20P1472 #21P1253 #22P1216 #24P1266 #25P1360 #26P991 #28P1599 #29P1169 #30P990 T220"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2480 #6P2206 #8P1578 #9P1786 #10P1869 #12P1126 #13P2707 #14P2436 #20P1251 #21P1265 #22P1099 #24P1534 #25P323 #26P451 #28P1378 #29P1157 #30P1103 T220"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P1693 #6P1767 #8P1578 #9P1786 #10P1869 #12P1126 #13P1500 #14P1883 #20P1251 #21P1265 #22P1099 #24P1534 #25P1360 #26P991 #28P1378 #29P1157 #30P1103 T220"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P2392 #10P2263 #12P1325 #13P1661 #14P1881 #20P1472 #21P723 #22P851 #24P1266 #25P1213 #26P879 #28P1599 #29P543 #30P576 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P1931 #10P1986 #12P1325 #13P1661 #14P1881 #20P1472 #21P1115 #22P1100 #24P1266 #25P1213 #26P879 #28P1599 #29P1023 #30P869 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2213 #6P2099 #8P1578 #9P1931 #10P1986 #12P1126 #13P2188 #14P2257 #20P1251 #21P1116 #22P973 #24P1534 #25P742 #26P612 #28P1378 #29P1022 #30P991 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P1828 #6P1872 #8P1578 #9P1931 #10P1986 #12P1126 #13P1660 #14P1992 #20P1251 #21P1116 #22P973 #24P1534 #25P1213 #26P879 #28P1378 #29P1022 #30P991 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_sync () {
    com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P2392 #10P2263 #12P1325 #13P1661 #14P1881 #20P1472 #21P723 #22P851 #24P1266 #25P1213 #26P879 #28P1599 #29P543 #30P576 T200")); delay(200);
    com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P1931 #10P1986 #12P1325 #13P1661 #14P1881 #20P1472 #21P1115 #22P1100 #24P1266 #25P1213 #26P879 #28P1599 #29P1023 #30P869 T200")); delay(200);
    com.println(F("#4P1428 #5P2213 #6P2099 #8P1578 #9P1931 #10P1986 #12P1126 #13P2188 #14P2257 #20P1251 #21P1116 #22P973 #24P1534 #25P742 #26P612 #28P1378 #29P1022 #30P991 T200")); delay(200);
    com.println(F("#4P1428 #5P1828 #6P1872 #8P1578 #9P1931 #10P1986 #12P1126 #13P1660 #14P1992 #20P1251 #21P1116 #22P973 #24P1534 #25P1213 #26P879 #28P1378 #29P1022 #30P991 T200")); delay(200);
  }

  void ssc_backward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1428 #5P1828 #6P1872 #8P1578 #9P2392 #10P2263 #12P1126 #13P1660 #14P1992 #20P1251 #21P627 #22P670 #24P1534 #25P1213 #26P879 #28P1378 #29P637 #30P751 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1428 #5P1828 #6P1872 #8P1578 #9P1931 #10P1986 #12P1126 #13P1660 #14P1992 #20P1251 #21P1116 #22P973 #24P1534 #25P1213 #26P879 #28P1378 #29P1022 #30P991 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1649 #5P2307 #6P2264 #8P1322 #9P1931 #10P1986 #12P1325 #13P2084 #14P2099 #20P1472 #21P1115 #22P1100 #24P1266 #25P742 #26P612 #28P1599 #29P1023 #30P869 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P1931 #10P1986 #12P1325 #13P1661 #14P1881 #20P1472 #21P1115 #22P1100 #24P1266 #25P1213 #26P879 #28P1599 #29P1023 #30P869 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_backward_sync () {
    com.println(F("#4P1428 #5P1828 #6P1872 #8P1578 #9P2392 #10P2263 #12P1126 #13P1660 #14P1992 #20P1251 #21P627 #22P670 #24P1534 #25P1213 #26P879 #28P1378 #29P637 #30P751 T200")); delay(200);
    com.println(F("#4P1428 #5P1828 #6P1872 #8P1578 #9P1931 #10P1986 #12P1126 #13P1660 #14P1992 #20P1251 #21P1116 #22P973 #24P1534 #25P1213 #26P879 #28P1378 #29P1022 #30P991 T200")); delay(200);
    com.println(F("#4P1649 #5P2307 #6P2264 #8P1322 #9P1931 #10P1986 #12P1325 #13P2084 #14P2099 #20P1472 #21P1115 #22P1100 #24P1266 #25P742 #26P612 #28P1599 #29P1023 #30P869 T200")); delay(200);
    com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P1931 #10P1986 #12P1325 #13P1661 #14P1881 #20P1472 #21P1115 #22P1100 #24P1266 #25P1213 #26P879 #28P1599 #29P1023 #30P869 T200")); delay(200);
  }

  void ssc_shiftRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1605 #5P1814 #6P1804 #8P1450 #9P2458 #10P2382 #12P1166 #13P1645 #14P1816 #20P1295 #21P772 #22P943 #24P1400 #25P1238 #26P813 #28P1555 #29P686 #30P839 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1605 #5P1814 #6P1804 #8P1450 #9P1906 #10P2054 #12P1166 #13P1645 #14P1816 #20P1295 #21P1130 #22P1175 #24P1400 #25P1238 #26P813 #28P1555 #29P1036 #30P1063 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1470 #5P2313 #6P2273 #8P1450 #9P1921 #10P1844 #12P1287 #13P2194 #14P2267 #20P1430 #21P1118 #22P967 #24P1400 #25P851 #26P798 #28P1420 #29P1024 #30P863 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1470 #5P1826 #6P1994 #8P1450 #9P1921 #10P1844 #12P1287 #13P1658 #14P1998 #20P1430 #21P1118 #22P967 #24P1400 #25P1222 #26P1016 #28P1420 #29P1024 #30P863 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1470 #5P1826 #6P1994 #8P1450 #9P2285 #10P2070 #12P1287 #13P1658 #14P1998 #20P1430 #21P621 #22P659 #24P1400 #25P1222 #26P1016 #28P1420 #29P537 #30P566 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1470 #5P1826 #6P1994 #8P1450 #9P1921 #10P1844 #12P1287 #13P1658 #14P1998 #20P1430 #21P1118 #22P967 #24P1400 #25P1222 #26P1016 #28P1420 #29P1024 #30P863 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1605 #5P2164 #6P2016 #8P1450 #9P1906 #10P2054 #12P1166 #13P2031 #14P2019 #20P1295 #21P1130 #22P1175 #24P1400 #25P675 #26P498 #28P1555 #29P1036 #30P1063 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1605 #5P1814 #6P1804 #8P1450 #9P1906 #10P2054 #12P1166 #13P1645 #14P1816 #20P1295 #21P1130 #22P1175 #24P1400 #25P1238 #26P813 #28P1555 #29P1036 #30P1063 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1695 #5P1831 #6P1891 #8P1322 #9P2283 #10P2208 #12P1407 #13P1666 #14P1955 #20P1205 #21P797 #22P871 #24P1534 #25P1213 #26P879 #28P1287 #29P678 #30P692 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1695 #5P1831 #6P1891 #8P1322 #9P1931 #10P1986 #12P1407 #13P1666 #14P1955 #20P1205 #21P1113 #22P1080 #24P1534 #25P1213 #26P879 #28P1287 #29P1017 #30P910 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1337 #5P2172 #6P2155 #8P1578 #9P1931 #10P1986 #12P1084 #13P2004 #14P2081 #20P1563 #21P1110 #22P1016 #24P1266 #25P853 #26P665 #28P1645 #29P1019 #30P972 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1337 #5P1833 #6P1949 #8P1578 #9P1931 #10P1986 #12P1084 #13P1664 #14P1899 #20P1563 #21P1110 #22P1016 #24P1266 #25P1213 #26P879 #28P1645 #29P1019 #30P972 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW_sync () {
    com.println(F("#4P1695 #5P1831 #6P1891 #8P1322 #9P2283 #10P2208 #12P1407 #13P1666 #14P1955 #20P1205 #21P797 #22P871 #24P1534 #25P1213 #26P879 #28P1287 #29P678 #30P692 T200")); delay(200);
    com.println(F("#4P1695 #5P1831 #6P1891 #8P1322 #9P1931 #10P1986 #12P1407 #13P1666 #14P1955 #20P1205 #21P1113 #22P1080 #24P1534 #25P1213 #26P879 #28P1287 #29P1017 #30P910 T200")); delay(200);
    com.println(F("#4P1337 #5P2172 #6P2155 #8P1578 #9P1931 #10P1986 #12P1084 #13P2004 #14P2081 #20P1563 #21P1110 #22P1016 #24P1266 #25P853 #26P665 #28P1645 #29P1019 #30P972 T200")); delay(200);
    com.println(F("#4P1337 #5P1833 #6P1949 #8P1578 #9P1931 #10P1986 #12P1084 #13P1664 #14P1899 #20P1563 #21P1110 #22P1016 #24P1266 #25P1213 #26P879 #28P1645 #29P1019 #30P972 T200")); delay(200);
  }

  void ssc_rotateCCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1337 #5P1833 #6P1949 #8P1578 #9P2283 #10P2208 #12P1084 #13P1664 #14P1899 #20P1563 #21P765 #22P790 #24P1266 #25P1213 #26P879 #28P1645 #29P710 #30P770 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1337 #5P1833 #6P1949 #8P1578 #9P1931 #10P1986 #12P1084 #13P1664 #14P1899 #20P1563 #21P1110 #22P1016 #24P1266 #25P1213 #26P879 #28P1645 #29P1019 #30P972 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1695 #5P2140 #6P2081 #8P1322 #9P1931 #10P1986 #12P1407 #13P2039 #14P2153 #20P1205 #21P1113 #22P1080 #24P1534 #25P853 #26P665 #28P1287 #29P1017 #30P910 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1695 #5P1831 #6P1891 #8P1322 #9P1931 #10P1986 #12P1407 #13P1666 #14P1955 #20P1205 #21P1113 #22P1080 #24P1534 #25P1213 #26P879 #28P1287 #29P1017 #30P910 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCW_sync () {
    com.println(F("#4P1337 #5P1833 #6P1949 #8P1578 #9P2283 #10P2208 #12P1084 #13P1664 #14P1899 #20P1563 #21P765 #22P790 #24P1266 #25P1213 #26P879 #28P1645 #29P710 #30P770 T200")); delay(200);
    com.println(F("#4P1337 #5P1833 #6P1949 #8P1578 #9P1931 #10P1986 #12P1084 #13P1664 #14P1899 #20P1563 #21P1110 #22P1016 #24P1266 #25P1213 #26P879 #28P1645 #29P1019 #30P972 T200")); delay(200);
    com.println(F("#4P1695 #5P2140 #6P2081 #8P1322 #9P1931 #10P1986 #12P1407 #13P2039 #14P2153 #20P1205 #21P1113 #22P1080 #24P1534 #25P853 #26P665 #28P1287 #29P1017 #30P910 T200")); delay(200);
    com.println(F("#4P1695 #5P1831 #6P1891 #8P1322 #9P1931 #10P1986 #12P1407 #13P1666 #14P1955 #20P1205 #21P1113 #22P1080 #24P1534 #25P1213 #26P879 #28P1287 #29P1017 #30P910 T200")); delay(200);
  }

  void ssc_rotateCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1586 #5P1833 #6P1930 #8P1407 #9P2288 #10P2222 #12P1293 #13P1666 #14P1955 #20P1314 #21P776 #22P817 #24P1445 #25P1214 #26P869 #28P1413 #29P678 #30P692 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1586 #5P1833 #6P1930 #8P1407 #9P1929 #10P1996 #12P1293 #13P1666 #14P1955 #20P1314 #21P1110 #22P1037 #24P1445 #25P1214 #26P869 #28P1413 #29P1017 #30P910 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1463 #5P2172 #6P2155 #8P1493 #9P1929 #10P1996 #12P1183 #13P2027 #14P2129 #20P1437 #21P1110 #22P1016 #24P1355 #25P848 #26P652 #28P1536 #29P1017 #30P931 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1463 #5P1833 #6P1949 #8P1493 #9P1929 #10P1996 #12P1183 #13P1667 #14P1936 #20P1437 #21P1110 #22P1016 #24P1355 #25P1214 #26P869 #28P1536 #29P1017 #30P931 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1463 #5P1833 #6P1949 #8P1493 #9P2288 #10P2222 #12P1183 #13P1667 #14P1936 #20P1437 #21P765 #22P790 #24P1355 #25P1214 #26P869 #28P1536 #29P689 #30P718 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1463 #5P1833 #6P1949 #8P1493 #9P1929 #10P1996 #12P1183 #13P1667 #14P1936 #20P1437 #21P1110 #22P1016 #24P1355 #25P1214 #26P869 #28P1536 #29P1017 #30P931 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1586 #5P2161 #6P2130 #8P1407 #9P1929 #10P1996 #12P1293 #13P2039 #14P2153 #20P1314 #21P1110 #22P1037 #24P1445 #25P848 #26P652 #28P1413 #29P1017 #30P910 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1586 #5P1833 #6P1930 #8P1407 #9P1929 #10P1996 #12P1293 #13P1666 #14P1955 #20P1314 #21P1110 #22P1037 #24P1445 #25P1214 #26P869 #28P1413 #29P1017 #30P910 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P2283 #10P2208 #12P1325 #13P1661 #14P1881 #20P1472 #21P808 #22P896 #24P1266 #25P1213 #26P879 #28P1599 #29P659 #30P635 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P1931 #10P1986 #12P1325 #13P1661 #14P1881 #20P1472 #21P1115 #22P1100 #24P1266 #25P1213 #26P879 #28P1599 #29P1023 #30P869 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1337 #5P2172 #6P2155 #8P1578 #9P1931 #10P1986 #12P1084 #13P2004 #14P2081 #20P1563 #21P1110 #22P1016 #24P1266 #25P853 #26P665 #28P1645 #29P1019 #30P972 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1337 #5P1833 #6P1949 #8P1578 #9P1931 #10P1986 #12P1084 #13P1664 #14P1899 #20P1563 #21P1110 #22P1016 #24P1266 #25P1213 #26P879 #28P1645 #29P1019 #30P972 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P2283 #10P2208 #12P1325 #13P1661 #14P1881 #20P1472 #21P808 #22P896 #24P1266 #25P1213 #26P879 #28P1599 #29P659 #30P635 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P1931 #10P1986 #12P1325 #13P1661 #14P1881 #20P1472 #21P1115 #22P1100 #24P1266 #25P1213 #26P879 #28P1599 #29P1023 #30P869 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1695 #5P2140 #6P2081 #8P1322 #9P1931 #10P1986 #12P1407 #13P2039 #14P2153 #20P1205 #21P1113 #22P1080 #24P1534 #25P853 #26P665 #28P1287 #29P1017 #30P910 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1695 #5P1831 #6P1891 #8P1322 #9P1931 #10P1986 #12P1407 #13P1666 #14P1955 #20P1205 #21P1113 #22P1080 #24P1534 #25P1213 #26P879 #28P1287 #29P1017 #30P910 T200"));
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
