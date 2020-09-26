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
        com.println(F("#4P1526 #5P2168 #6P2145 #8P1450 #9P2288 #10P2260 #12P1324 #13P2035 #14P2150 #20P1374 #21P782 #22P800 #24P1400 #25P862 #26P696 #28P1426 #29P732 #30P755 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1526 #5P2168 #6P2145 #8P1450 #9P2288 #10P2260 #12P1324 #13P2035 #14P2150 #20P1374 #21P782 #22P800 #24P1400 #25P862 #26P696 #28P1426 #29P732 #30P755 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1526 #5P2168 #6P2145 #8P1450 #9P2288 #10P2260 #12P1324 #13P2035 #14P2150 #20P1374 #21P782 #22P800 #24P1400 #25P862 #26P696 #28P1426 #29P732 #30P755 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1526 #5P2168 #6P2145 #8P1450 #9P2288 #10P2260 #12P1324 #13P2035 #14P2150 #20P1374 #21P782 #22P800 #24P1400 #25P862 #26P696 #28P1426 #29P732 #30P755 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1526 #5P2168 #6P2145 #12P1324 #13P2035 #14P2150 #24P1400 #25P862 #26P696 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1526 #5P1833 #6P1942 #12P1324 #13P1667 #14P1926 #24P1400 #25P1221 #26P923 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#8P1450 #9P2288 #10P2260 #20P1374 #21P782 #22P800 #28P1426 #29P732 #30P755 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#8P1450 #9P1929 #10P2020 #20P1374 #21P1117 #22P1024 #28P1426 #29P1067 #30P958 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize_sync () {
    com.println(F("#4P1526 #5P2168 #6P2145 #12P1324 #13P2035 #14P2150 #24P1400 #25P862 #26P696 T200")); delay(200);
    com.println(F("#4P1526 #5P1833 #6P1942 #12P1324 #13P1667 #14P1926 #24P1400 #25P1221 #26P923 T200")); delay(200);
    com.println(F("#8P1450 #9P2288 #10P2260 #20P1374 #21P782 #22P800 #28P1426 #29P732 #30P755 T200")); delay(200);
    com.println(F("#8P1450 #9P1929 #10P2020 #20P1374 #21P1117 #22P1024 #28P1426 #29P1067 #30P958 T200")); delay(200);
  }

  void ssc_forward_low () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P2191 #6P2208 #8P1322 #9P2283 #10P2244 #12P1422 #13P1992 #14P2054 #20P1472 #21P821 #22P896 #24P1272 #25P867 #26P712 #28P1549 #29P709 #30P692 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P2191 #6P2208 #8P1322 #9P2283 #10P2244 #12P1422 #13P1992 #14P2054 #20P1472 #21P821 #22P896 #24P1272 #25P867 #26P712 #28P1549 #29P709 #30P692 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2129 #6P2058 #8P1578 #9P2283 #10P2244 #12P1201 #13P2060 #14P2219 #20P1251 #21P759 #22P731 #24P1528 #25P867 #26P712 #28P1328 #29P771 #30P842 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P2129 #6P2058 #8P1578 #9P2283 #10P2244 #12P1201 #13P2060 #14P2219 #20P1251 #21P759 #22P731 #24P1528 #25P867 #26P712 #28P1328 #29P771 #30P842 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_higher () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1681 #6P1874 #8P1322 #9P2803 #10P2479 #12P1422 #13P1512 #14P1734 #20P1472 #21P470 #22P733 #24P1272 #25P1364 #26P1051 #28P1549 #29P121 #30P450 T220"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1681 #6P1874 #8P1322 #9P1786 #10P1884 #12P1422 #13P1512 #14P1734 #20P1472 #21P1257 #22P1216 #24P1272 #25P1364 #26P1051 #28P1549 #29P1219 #30P1026 T220"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2480 #6P2206 #8P1578 #9P1786 #10P1884 #12P1201 #13P2707 #14P2485 #20P1251 #21P1269 #22P1099 #24P1528 #25P347 #26P489 #28P1328 #29P1207 #30P1133 T220"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P1693 #6P1767 #8P1578 #9P1786 #10P1884 #12P1201 #13P1500 #14P1851 #20P1251 #21P1269 #22P1099 #24P1528 #25P1364 #26P1051 #28P1328 #29P1207 #30P1133 T220"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P2392 #10P2301 #12P1422 #13P1661 #14P1850 #20P1472 #21P737 #22P851 #24P1272 #25P1219 #26P934 #28P1549 #29P593 #30P636 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P1931 #10P2008 #12P1422 #13P1661 #14P1850 #20P1472 #21P1122 #22P1100 #24P1272 #25P1219 #26P934 #28P1549 #29P1073 #30P912 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2213 #6P2099 #8P1578 #9P1931 #10P2008 #12P1201 #13P2188 #14P2280 #20P1251 #21P1123 #22P973 #24P1528 #25P758 #26P657 #28P1328 #29P1072 #30P1028 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P1828 #6P1872 #8P1578 #9P1931 #10P2008 #12P1201 #13P1660 #14P1977 #20P1251 #21P1123 #22P973 #24P1528 #25P1219 #26P934 #28P1328 #29P1072 #30P1028 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_sync () {
    com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P2392 #10P2301 #12P1422 #13P1661 #14P1850 #20P1472 #21P737 #22P851 #24P1272 #25P1219 #26P934 #28P1549 #29P593 #30P636 T200")); delay(200);
    com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P1931 #10P2008 #12P1422 #13P1661 #14P1850 #20P1472 #21P1122 #22P1100 #24P1272 #25P1219 #26P934 #28P1549 #29P1073 #30P912 T200")); delay(200);
    com.println(F("#4P1428 #5P2213 #6P2099 #8P1578 #9P1931 #10P2008 #12P1201 #13P2188 #14P2280 #20P1251 #21P1123 #22P973 #24P1528 #25P758 #26P657 #28P1328 #29P1072 #30P1028 T200")); delay(200);
    com.println(F("#4P1428 #5P1828 #6P1872 #8P1578 #9P1931 #10P2008 #12P1201 #13P1660 #14P1977 #20P1251 #21P1123 #22P973 #24P1528 #25P1219 #26P934 #28P1328 #29P1072 #30P1028 T200")); delay(200);
  }

  void ssc_backward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1428 #5P1828 #6P1872 #8P1578 #9P2392 #10P2301 #12P1201 #13P1660 #14P1977 #20P1251 #21P643 #22P670 #24P1528 #25P1219 #26P934 #28P1328 #29P687 #30P801 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1428 #5P1828 #6P1872 #8P1578 #9P1931 #10P2008 #12P1201 #13P1660 #14P1977 #20P1251 #21P1123 #22P973 #24P1528 #25P1219 #26P934 #28P1328 #29P1072 #30P1028 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1649 #5P2307 #6P2264 #8P1322 #9P1931 #10P2008 #12P1422 #13P2084 #14P2099 #20P1472 #21P1122 #22P1100 #24P1272 #25P758 #26P657 #28P1549 #29P1073 #30P912 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P1931 #10P2008 #12P1422 #13P1661 #14P1850 #20P1472 #21P1122 #22P1100 #24P1272 #25P1219 #26P934 #28P1549 #29P1073 #30P912 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_backward_sync () {
    com.println(F("#4P1428 #5P1828 #6P1872 #8P1578 #9P2392 #10P2301 #12P1201 #13P1660 #14P1977 #20P1251 #21P643 #22P670 #24P1528 #25P1219 #26P934 #28P1328 #29P687 #30P801 T200")); delay(200);
    com.println(F("#4P1428 #5P1828 #6P1872 #8P1578 #9P1931 #10P2008 #12P1201 #13P1660 #14P1977 #20P1251 #21P1123 #22P973 #24P1528 #25P1219 #26P934 #28P1328 #29P1072 #30P1028 T200")); delay(200);
    com.println(F("#4P1649 #5P2307 #6P2264 #8P1322 #9P1931 #10P2008 #12P1422 #13P2084 #14P2099 #20P1472 #21P1122 #22P1100 #24P1272 #25P758 #26P657 #28P1549 #29P1073 #30P912 T200")); delay(200);
    com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P1931 #10P2008 #12P1422 #13P1661 #14P1850 #20P1472 #21P1122 #22P1100 #24P1272 #25P1219 #26P934 #28P1549 #29P1073 #30P912 T200")); delay(200);
  }

  void ssc_shiftRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1605 #5P1814 #6P1804 #8P1450 #9P2458 #10P2427 #12P1245 #13P1645 #14P1775 #20P1295 #21P786 #22P943 #24P1400 #25P1244 #26P866 #28P1505 #29P736 #30P884 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1605 #5P1814 #6P1804 #8P1450 #9P1906 #10P2080 #12P1245 #13P1645 #14P1775 #20P1295 #21P1136 #22P1175 #24P1400 #25P1244 #26P866 #28P1505 #29P1086 #30P1096 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1470 #5P2313 #6P2273 #8P1450 #9P1921 #10P1858 #12P1380 #13P2194 #14P2291 #20P1430 #21P1124 #22P967 #24P1400 #25P865 #26P850 #28P1370 #29P1074 #30P906 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1470 #5P1826 #6P1994 #8P1450 #9P1921 #10P1858 #12P1380 #13P1658 #14P1983 #20P1430 #21P1124 #22P967 #24P1400 #25P1229 #26P1076 #28P1370 #29P1074 #30P906 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1470 #5P1826 #6P1994 #8P1450 #9P2285 #10P2097 #12P1380 #13P1658 #14P1983 #20P1430 #21P637 #22P659 #24P1400 #25P1229 #26P1076 #28P1370 #29P587 #30P627 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1470 #5P1826 #6P1994 #8P1450 #9P1921 #10P1858 #12P1380 #13P1658 #14P1983 #20P1430 #21P1124 #22P967 #24P1400 #25P1229 #26P1076 #28P1370 #29P1074 #30P906 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1605 #5P2164 #6P2016 #8P1450 #9P1906 #10P2080 #12P1245 #13P2031 #14P2007 #20P1295 #21P1136 #22P1175 #24P1400 #25P692 #26P538 #28P1505 #29P1086 #30P1096 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1605 #5P1814 #6P1804 #8P1450 #9P1906 #10P2080 #12P1245 #13P1645 #14P1775 #20P1295 #21P1136 #22P1175 #24P1400 #25P1244 #26P866 #28P1505 #29P1086 #30P1096 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1695 #5P1831 #6P1891 #8P1322 #9P2283 #10P2244 #12P1513 #13P1666 #14P1934 #20P1205 #21P810 #22P871 #24P1528 #25P1219 #26P934 #28P1237 #29P728 #30P745 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1695 #5P1831 #6P1891 #8P1322 #9P1931 #10P2008 #12P1513 #13P1666 #14P1934 #20P1205 #21P1119 #22P1080 #24P1528 #25P1219 #26P934 #28P1237 #29P1067 #30P951 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1337 #5P2172 #6P2155 #8P1578 #9P1931 #10P2008 #12P1155 #13P2004 #14P2079 #20P1563 #21P1117 #22P1016 #24P1272 #25P867 #26P712 #28P1595 #29P1069 #30P1009 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1337 #5P1833 #6P1949 #8P1578 #9P1931 #10P2008 #12P1155 #13P1664 #14P1870 #20P1563 #21P1117 #22P1016 #24P1272 #25P1219 #26P934 #28P1595 #29P1069 #30P1009 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW_sync () {
    com.println(F("#4P1695 #5P1831 #6P1891 #8P1322 #9P2283 #10P2244 #12P1513 #13P1666 #14P1934 #20P1205 #21P810 #22P871 #24P1528 #25P1219 #26P934 #28P1237 #29P728 #30P745 T200")); delay(200);
    com.println(F("#4P1695 #5P1831 #6P1891 #8P1322 #9P1931 #10P2008 #12P1513 #13P1666 #14P1934 #20P1205 #21P1119 #22P1080 #24P1528 #25P1219 #26P934 #28P1237 #29P1067 #30P951 T200")); delay(200);
    com.println(F("#4P1337 #5P2172 #6P2155 #8P1578 #9P1931 #10P2008 #12P1155 #13P2004 #14P2079 #20P1563 #21P1117 #22P1016 #24P1272 #25P867 #26P712 #28P1595 #29P1069 #30P1009 T200")); delay(200);
    com.println(F("#4P1337 #5P1833 #6P1949 #8P1578 #9P1931 #10P2008 #12P1155 #13P1664 #14P1870 #20P1563 #21P1117 #22P1016 #24P1272 #25P1219 #26P934 #28P1595 #29P1069 #30P1009 T200")); delay(200);
  }

  void ssc_rotateCCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1337 #5P1833 #6P1949 #8P1578 #9P2283 #10P2244 #12P1155 #13P1664 #14P1870 #20P1563 #21P778 #22P790 #24P1272 #25P1219 #26P934 #28P1595 #29P760 #30P819 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1337 #5P1833 #6P1949 #8P1578 #9P1931 #10P2008 #12P1155 #13P1664 #14P1870 #20P1563 #21P1117 #22P1016 #24P1272 #25P1219 #26P934 #28P1595 #29P1069 #30P1009 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1695 #5P2140 #6P2081 #8P1322 #9P1931 #10P2008 #12P1513 #13P2039 #14P2160 #20P1205 #21P1119 #22P1080 #24P1528 #25P867 #26P712 #28P1237 #29P1067 #30P951 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1695 #5P1831 #6P1891 #8P1322 #9P1931 #10P2008 #12P1513 #13P1666 #14P1934 #20P1205 #21P1119 #22P1080 #24P1528 #25P1219 #26P934 #28P1237 #29P1067 #30P951 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCW_sync () {
    com.println(F("#4P1337 #5P1833 #6P1949 #8P1578 #9P2283 #10P2244 #12P1155 #13P1664 #14P1870 #20P1563 #21P778 #22P790 #24P1272 #25P1219 #26P934 #28P1595 #29P760 #30P819 T200")); delay(200);
    com.println(F("#4P1337 #5P1833 #6P1949 #8P1578 #9P1931 #10P2008 #12P1155 #13P1664 #14P1870 #20P1563 #21P1117 #22P1016 #24P1272 #25P1219 #26P934 #28P1595 #29P1069 #30P1009 T200")); delay(200);
    com.println(F("#4P1695 #5P2140 #6P2081 #8P1322 #9P1931 #10P2008 #12P1513 #13P2039 #14P2160 #20P1205 #21P1119 #22P1080 #24P1528 #25P867 #26P712 #28P1237 #29P1067 #30P951 T200")); delay(200);
    com.println(F("#4P1695 #5P1831 #6P1891 #8P1322 #9P1931 #10P2008 #12P1513 #13P1666 #14P1934 #20P1205 #21P1119 #22P1080 #24P1528 #25P1219 #26P934 #28P1237 #29P1067 #30P951 T200")); delay(200);
  }

  void ssc_rotateCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1586 #5P1833 #6P1930 #8P1407 #9P2288 #10P2258 #12P1387 #13P1666 #14P1934 #20P1314 #21P789 #22P817 #24P1443 #25P1221 #26P924 #28P1363 #29P728 #30P745 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1586 #5P1833 #6P1930 #8P1407 #9P1929 #10P2019 #12P1387 #13P1666 #14P1934 #20P1314 #21P1117 #22P1037 #24P1443 #25P1221 #26P924 #28P1363 #29P1067 #30P951 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1463 #5P2172 #6P2155 #8P1493 #9P1929 #10P2019 #12P1264 #13P2027 #14P2133 #20P1437 #21P1117 #22P1016 #24P1357 #25P862 #26P698 #28P1486 #29P1067 #30P970 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1463 #5P1833 #6P1949 #8P1493 #9P1929 #10P2019 #12P1264 #13P1667 #14P1913 #20P1437 #21P1117 #22P1016 #24P1357 #25P1221 #26P924 #28P1486 #29P1067 #30P970 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1463 #5P1833 #6P1949 #8P1493 #9P2288 #10P2258 #12P1264 #13P1667 #14P1913 #20P1437 #21P778 #22P790 #24P1357 #25P1221 #26P924 #28P1486 #29P739 #30P770 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1463 #5P1833 #6P1949 #8P1493 #9P1929 #10P2019 #12P1264 #13P1667 #14P1913 #20P1437 #21P1117 #22P1016 #24P1357 #25P1221 #26P924 #28P1486 #29P1067 #30P970 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1586 #5P2161 #6P2130 #8P1407 #9P1929 #10P2019 #12P1387 #13P2039 #14P2160 #20P1314 #21P1117 #22P1037 #24P1443 #25P862 #26P698 #28P1363 #29P1067 #30P951 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1586 #5P1833 #6P1930 #8P1407 #9P1929 #10P2019 #12P1387 #13P1666 #14P1934 #20P1314 #21P1117 #22P1037 #24P1443 #25P1221 #26P924 #28P1363 #29P1067 #30P951 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P2283 #10P2244 #12P1422 #13P1661 #14P1850 #20P1472 #21P821 #22P896 #24P1272 #25P1219 #26P934 #28P1549 #29P709 #30P692 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P1931 #10P2008 #12P1422 #13P1661 #14P1850 #20P1472 #21P1122 #22P1100 #24P1272 #25P1219 #26P934 #28P1549 #29P1073 #30P912 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1337 #5P2172 #6P2155 #8P1578 #9P1931 #10P2008 #12P1155 #13P2004 #14P2079 #20P1563 #21P1117 #22P1016 #24P1272 #25P867 #26P712 #28P1595 #29P1069 #30P1009 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1337 #5P1833 #6P1949 #8P1578 #9P1931 #10P2008 #12P1155 #13P1664 #14P1870 #20P1563 #21P1117 #22P1016 #24P1272 #25P1219 #26P934 #28P1595 #29P1069 #30P1009 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P2283 #10P2244 #12P1422 #13P1661 #14P1850 #20P1472 #21P821 #22P896 #24P1272 #25P1219 #26P934 #28P1549 #29P709 #30P692 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1827 #6P1988 #8P1322 #9P1931 #10P2008 #12P1422 #13P1661 #14P1850 #20P1472 #21P1122 #22P1100 #24P1272 #25P1219 #26P934 #28P1549 #29P1073 #30P912 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1695 #5P2140 #6P2081 #8P1322 #9P1931 #10P2008 #12P1513 #13P2039 #14P2160 #20P1205 #21P1119 #22P1080 #24P1528 #25P867 #26P712 #28P1237 #29P1067 #30P951 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1695 #5P1831 #6P1891 #8P1322 #9P1931 #10P2008 #12P1513 #13P1666 #14P1934 #20P1205 #21P1119 #22P1080 #24P1528 #25P1219 #26P934 #28P1237 #29P1067 #30P951 T200"));
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
