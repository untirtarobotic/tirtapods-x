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
        com.println(F("#4P1526 #5P2168 #6P2150 #8P1450 #9P2288 #10P2050 #12P1324 #13P2018 #14P2086 #20P1374 #21P786 #22P805 #24P1400 #25P848 #26P760 #28P1426 #29P732 #30P800 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1526 #5P2168 #6P2150 #8P1450 #9P2288 #10P2050 #12P1324 #13P2018 #14P2086 #20P1374 #21P786 #22P805 #24P1400 #25P848 #26P760 #28P1426 #29P732 #30P800 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1526 #5P2168 #6P2150 #8P1450 #9P2288 #10P2050 #12P1324 #13P2018 #14P2086 #20P1374 #21P786 #22P805 #24P1400 #25P848 #26P760 #28P1426 #29P732 #30P800 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1526 #5P2168 #6P2150 #8P1450 #9P2288 #10P2050 #12P1324 #13P2018 #14P2086 #20P1374 #21P786 #22P805 #24P1400 #25P848 #26P760 #28P1426 #29P732 #30P800 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1526 #5P2168 #6P2150 #12P1324 #13P2018 #14P2086 #24P1400 #25P848 #26P760 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1526 #5P1833 #6P1926 #12P1324 #13P1683 #14P1923 #24P1400 #25P1215 #26P956 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#8P1450 #9P2288 #10P2050 #20P1374 #21P786 #22P805 #28P1426 #29P732 #30P800 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#8P1450 #9P1929 #10P1832 #20P1374 #21P1093 #22P1008 #28P1426 #29P1067 #30P1024 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize_sync () {
    com.println(F("#4P1526 #5P2168 #6P2150 #12P1324 #13P2018 #14P2086 #24P1400 #25P848 #26P760 T200")); delay(200);
    com.println(F("#4P1526 #5P1833 #6P1926 #12P1324 #13P1683 #14P1923 #24P1400 #25P1215 #26P956 T200")); delay(200);
    com.println(F("#8P1450 #9P2288 #10P2050 #20P1374 #21P786 #22P805 #28P1426 #29P732 #30P800 T200")); delay(200);
    com.println(F("#8P1450 #9P1929 #10P1832 #20P1374 #21P1093 #22P1008 #28P1426 #29P1067 #30P1024 T200")); delay(200);
  }

  void ssc_forward_low () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P2191 #6P2219 #8P1322 #9P2283 #10P2035 #12P1422 #13P1979 #14P2017 #20P1472 #21P821 #22P892 #24P1266 #25P853 #26P773 #28P1549 #29P709 #30P731 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P2191 #6P2219 #8P1322 #9P2283 #10P2035 #12P1422 #13P1979 #14P2017 #20P1472 #21P821 #22P892 #24P1266 #25P853 #26P773 #28P1549 #29P709 #30P731 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2129 #6P2054 #8P1578 #9P2283 #10P2035 #12P1201 #13P2041 #14P2137 #20P1251 #21P764 #22P742 #24P1534 #25P853 #26P773 #28P1328 #29P771 #30P896 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P2129 #6P2054 #8P1578 #9P2283 #10P2035 #12P1201 #13P2041 #14P2137 #20P1251 #21P764 #22P742 #24P1534 #25P853 #26P773 #28P1328 #29P771 #30P896 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_higher () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1681 #6P1851 #8P1322 #9P2803 #10P2249 #12P1422 #13P1543 #14P1784 #20P1472 #21P499 #22P744 #24P1266 #25P1360 #26P1067 #28P1549 #29P121 #30P465 T220"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1681 #6P1851 #8P1322 #9P1786 #10P1709 #12P1422 #13P1543 #14P1784 #20P1472 #21P1222 #22P1183 #24P1266 #25P1360 #26P1067 #28P1549 #29P1219 #30P1099 T220"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2480 #6P2217 #8P1578 #9P1786 #10P1709 #12P1201 #13P2629 #14P2330 #20P1251 #21P1233 #22P1076 #24P1534 #25P323 #26P581 #28P1328 #29P1207 #30P1216 T220"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P1693 #6P1734 #8P1578 #9P1786 #10P1709 #12P1201 #13P1531 #14P1869 #20P1251 #21P1233 #22P1076 #24P1534 #25P1360 #26P1067 #28P1328 #29P1207 #30P1216 T220"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1827 #6P1977 #8P1322 #9P2392 #10P2088 #12P1422 #13P1678 #14P1868 #20P1472 #21P744 #22P851 #24P1266 #25P1213 #26P966 #28P1549 #29P593 #30P670 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1827 #6P1977 #8P1322 #9P1931 #10P1821 #12P1422 #13P1678 #14P1868 #20P1472 #21P1098 #22P1078 #24P1266 #25P1213 #26P966 #28P1549 #29P1073 #30P973 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2213 #6P2099 #8P1578 #9P1931 #10P1821 #12P1201 #13P2157 #14P2181 #20P1251 #21P1099 #22P962 #24P1534 #25P742 #26P726 #28P1328 #29P1072 #30P1100 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P1828 #6P1850 #8P1578 #9P1931 #10P1821 #12P1201 #13P1677 #14P1960 #20P1251 #21P1099 #22P962 #24P1534 #25P1213 #26P966 #28P1328 #29P1072 #30P1100 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_sync () {
    com.println(F("#4P1649 #5P1827 #6P1977 #8P1322 #9P2392 #10P2088 #12P1422 #13P1678 #14P1868 #20P1472 #21P744 #22P851 #24P1266 #25P1213 #26P966 #28P1549 #29P593 #30P670 T200")); delay(200);
    com.println(F("#4P1649 #5P1827 #6P1977 #8P1322 #9P1931 #10P1821 #12P1422 #13P1678 #14P1868 #20P1472 #21P1098 #22P1078 #24P1266 #25P1213 #26P966 #28P1549 #29P1073 #30P973 T200")); delay(200);
    com.println(F("#4P1428 #5P2213 #6P2099 #8P1578 #9P1931 #10P1821 #12P1201 #13P2157 #14P2181 #20P1251 #21P1099 #22P962 #24P1534 #25P742 #26P726 #28P1328 #29P1072 #30P1100 T200")); delay(200);
    com.println(F("#4P1428 #5P1828 #6P1850 #8P1578 #9P1931 #10P1821 #12P1201 #13P1677 #14P1960 #20P1251 #21P1099 #22P962 #24P1534 #25P1213 #26P966 #28P1328 #29P1072 #30P1100 T200")); delay(200);
  }

  void ssc_backward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1428 #5P1828 #6P1850 #8P1578 #9P2392 #10P2088 #12P1201 #13P1677 #14P1960 #20P1251 #21P657 #22P686 #24P1534 #25P1213 #26P966 #28P1328 #29P687 #30P851 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1428 #5P1828 #6P1850 #8P1578 #9P1931 #10P1821 #12P1201 #13P1677 #14P1960 #20P1251 #21P1099 #22P962 #24P1534 #25P1213 #26P966 #28P1328 #29P1072 #30P1100 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1649 #5P2307 #6P2280 #8P1322 #9P1931 #10P1821 #12P1422 #13P2063 #14P2050 #20P1472 #21P1098 #22P1078 #24P1266 #25P742 #26P726 #28P1549 #29P1073 #30P973 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1649 #5P1827 #6P1977 #8P1322 #9P1931 #10P1821 #12P1422 #13P1678 #14P1868 #20P1472 #21P1098 #22P1078 #24P1266 #25P1213 #26P966 #28P1549 #29P1073 #30P973 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_backward_sync () {
    com.println(F("#4P1428 #5P1828 #6P1850 #8P1578 #9P2392 #10P2088 #12P1201 #13P1677 #14P1960 #20P1251 #21P657 #22P686 #24P1534 #25P1213 #26P966 #28P1328 #29P687 #30P851 T200")); delay(200);
    com.println(F("#4P1428 #5P1828 #6P1850 #8P1578 #9P1931 #10P1821 #12P1201 #13P1677 #14P1960 #20P1251 #21P1099 #22P962 #24P1534 #25P1213 #26P966 #28P1328 #29P1072 #30P1100 T200")); delay(200);
    com.println(F("#4P1649 #5P2307 #6P2280 #8P1322 #9P1931 #10P1821 #12P1422 #13P2063 #14P2050 #20P1472 #21P1098 #22P1078 #24P1266 #25P742 #26P726 #28P1549 #29P1073 #30P973 T200")); delay(200);
    com.println(F("#4P1649 #5P1827 #6P1977 #8P1322 #9P1931 #10P1821 #12P1422 #13P1678 #14P1868 #20P1472 #21P1098 #22P1078 #24P1266 #25P1213 #26P966 #28P1549 #29P1073 #30P973 T200")); delay(200);
  }

  void ssc_shiftRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1605 #5P1814 #6P1775 #8P1450 #9P2458 #10P2202 #12P1245 #13P1664 #14P1814 #20P1295 #21P789 #22P934 #24P1400 #25P1238 #26P907 #28P1505 #29P736 #30P943 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1605 #5P1814 #6P1775 #8P1450 #9P1906 #10P1887 #12P1245 #13P1664 #14P1814 #20P1295 #21P1111 #22P1146 #24P1400 #25P1238 #26P907 #28P1505 #29P1086 #30P1175 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1470 #5P2313 #6P2291 #8P1450 #9P1921 #10P1684 #12P1380 #13P2163 #14P2189 #20P1430 #21P1100 #22P956 #24P1400 #25P851 #26P893 #28P1370 #29P1074 #30P967 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1470 #5P1826 #6P1983 #8P1450 #9P1921 #10P1684 #12P1380 #13P1676 #14P1965 #20P1430 #21P1100 #22P956 #24P1400 #25P1222 #26P1089 #28P1370 #29P1074 #30P967 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1470 #5P1826 #6P1983 #8P1450 #9P2285 #10P1902 #12P1380 #13P1676 #14P1965 #20P1430 #21P652 #22P677 #24P1400 #25P1222 #26P1089 #28P1370 #29P587 #30P659 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1470 #5P1826 #6P1983 #8P1450 #9P1921 #10P1684 #12P1380 #13P1676 #14P1965 #20P1430 #21P1100 #22P956 #24P1400 #25P1222 #26P1089 #28P1370 #29P1074 #30P967 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1605 #5P2164 #6P2007 #8P1450 #9P1906 #10P1887 #12P1245 #13P2014 #14P1982 #20P1295 #21P1111 #22P1146 #24P1400 #25P675 #26P623 #28P1505 #29P1086 #30P1175 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1605 #5P1814 #6P1775 #8P1450 #9P1906 #10P1887 #12P1245 #13P1664 #14P1814 #20P1295 #21P1111 #22P1146 #24P1400 #25P1238 #26P907 #28P1505 #29P1086 #30P1175 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1695 #5P1831 #6P1870 #8P1322 #9P2283 #10P2035 #12P1513 #13P1683 #14P1929 #20P1205 #21P811 #22P869 #24P1534 #25P1213 #26P966 #28P1237 #29P728 #30P790 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1695 #5P1831 #6P1870 #8P1322 #9P1931 #10P1821 #12P1513 #13P1683 #14P1929 #20P1205 #21P1096 #22P1059 #24P1534 #25P1213 #26P966 #28P1237 #29P1067 #30P1016 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1337 #5P2172 #6P2160 #8P1578 #9P1931 #10P1821 #12P1155 #13P1990 #14P2035 #20P1563 #21P1094 #22P1001 #24P1266 #25P853 #26P773 #28P1595 #29P1069 #30P1080 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1337 #5P1833 #6P1934 #8P1578 #9P1931 #10P1821 #12P1155 #13P1681 #14P1883 #20P1563 #21P1094 #22P1001 #24P1266 #25P1213 #26P966 #28P1595 #29P1069 #30P1080 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW_sync () {
    com.println(F("#4P1695 #5P1831 #6P1870 #8P1322 #9P2283 #10P2035 #12P1513 #13P1683 #14P1929 #20P1205 #21P811 #22P869 #24P1534 #25P1213 #26P966 #28P1237 #29P728 #30P790 T200")); delay(200);
    com.println(F("#4P1695 #5P1831 #6P1870 #8P1322 #9P1931 #10P1821 #12P1513 #13P1683 #14P1929 #20P1205 #21P1096 #22P1059 #24P1534 #25P1213 #26P966 #28P1237 #29P1067 #30P1016 T200")); delay(200);
    com.println(F("#4P1337 #5P2172 #6P2160 #8P1578 #9P1931 #10P1821 #12P1155 #13P1990 #14P2035 #20P1563 #21P1094 #22P1001 #24P1266 #25P853 #26P773 #28P1595 #29P1069 #30P1080 T200")); delay(200);
    com.println(F("#4P1337 #5P1833 #6P1934 #8P1578 #9P1931 #10P1821 #12P1155 #13P1681 #14P1883 #20P1563 #21P1094 #22P1001 #24P1266 #25P1213 #26P966 #28P1595 #29P1069 #30P1080 T200")); delay(200);
  }

  void ssc_rotateCCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1337 #5P1833 #6P1934 #8P1578 #9P2283 #10P2035 #12P1155 #13P1681 #14P1883 #20P1563 #21P782 #22P795 #24P1266 #25P1213 #26P966 #28P1595 #29P760 #30P871 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1337 #5P1833 #6P1934 #8P1578 #9P1931 #10P1821 #12P1155 #13P1681 #14P1883 #20P1563 #21P1094 #22P1001 #24P1266 #25P1213 #26P966 #28P1595 #29P1069 #30P1080 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1695 #5P2140 #6P2079 #8P1322 #9P1931 #10P1821 #12P1513 #13P2022 #14P2094 #20P1205 #21P1096 #22P1059 #24P1534 #25P853 #26P773 #28P1237 #29P1067 #30P1016 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1695 #5P1831 #6P1870 #8P1322 #9P1931 #10P1821 #12P1513 #13P1683 #14P1929 #20P1205 #21P1096 #22P1059 #24P1534 #25P1213 #26P966 #28P1237 #29P1067 #30P1016 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCW_sync () {
    com.println(F("#4P1337 #5P1833 #6P1934 #8P1578 #9P2283 #10P2035 #12P1155 #13P1681 #14P1883 #20P1563 #21P782 #22P795 #24P1266 #25P1213 #26P966 #28P1595 #29P760 #30P871 T200")); delay(200);
    com.println(F("#4P1337 #5P1833 #6P1934 #8P1578 #9P1931 #10P1821 #12P1155 #13P1681 #14P1883 #20P1563 #21P1094 #22P1001 #24P1266 #25P1213 #26P966 #28P1595 #29P1069 #30P1080 T200")); delay(200);
    com.println(F("#4P1695 #5P2140 #6P2079 #8P1322 #9P1931 #10P1821 #12P1513 #13P2022 #14P2094 #20P1205 #21P1096 #22P1059 #24P1534 #25P853 #26P773 #28P1237 #29P1067 #30P1016 T200")); delay(200);
    com.println(F("#4P1695 #5P1831 #6P1870 #8P1322 #9P1931 #10P1821 #12P1513 #13P1683 #14P1929 #20P1205 #21P1096 #22P1059 #24P1534 #25P1213 #26P966 #28P1237 #29P1067 #30P1016 T200")); delay(200);
  }

  void ssc_rotateCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1586 #5P1833 #6P1913 #8P1407 #9P2288 #10P2048 #12P1387 #13P1683 #14P1929 #20P1314 #21P792 #22P820 #24P1445 #25P1214 #26P957 #28P1363 #29P728 #30P790 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1586 #5P1833 #6P1913 #8P1407 #9P1929 #10P1831 #12P1387 #13P1683 #14P1929 #20P1314 #21P1093 #22P1020 #24P1445 #25P1214 #26P957 #28P1363 #29P1067 #30P1016 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1463 #5P2172 #6P2160 #8P1493 #9P1929 #10P1831 #12P1264 #13P2011 #14P2074 #20P1437 #21P1094 #22P1001 #24P1355 #25P848 #26P762 #28P1486 #29P1067 #30P1037 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1463 #5P1833 #6P1934 #8P1493 #9P1929 #10P1831 #12P1264 #13P1683 #14P1914 #20P1437 #21P1094 #22P1001 #24P1355 #25P1214 #26P957 #28P1486 #29P1067 #30P1037 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1463 #5P1833 #6P1934 #8P1493 #9P2288 #10P2048 #12P1264 #13P1683 #14P1914 #20P1437 #21P782 #22P795 #24P1355 #25P1214 #26P957 #28P1486 #29P739 #30P817 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1463 #5P1833 #6P1934 #8P1493 #9P1929 #10P1831 #12P1264 #13P1683 #14P1914 #20P1437 #21P1094 #22P1001 #24P1355 #25P1214 #26P957 #28P1486 #29P1067 #30P1037 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1586 #5P2161 #6P2133 #8P1407 #9P1929 #10P1831 #12P1387 #13P2022 #14P2094 #20P1314 #21P1093 #22P1020 #24P1445 #25P848 #26P762 #28P1363 #29P1067 #30P1016 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1586 #5P1833 #6P1913 #8P1407 #9P1929 #10P1831 #12P1387 #13P1683 #14P1929 #20P1314 #21P1093 #22P1020 #24P1445 #25P1214 #26P957 #28P1363 #29P1067 #30P1016 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1827 #6P1977 #8P1322 #9P2283 #10P2035 #12P1422 #13P1678 #14P1868 #20P1472 #21P821 #22P892 #24P1266 #25P1213 #26P966 #28P1549 #29P709 #30P731 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1827 #6P1977 #8P1322 #9P1931 #10P1821 #12P1422 #13P1678 #14P1868 #20P1472 #21P1098 #22P1078 #24P1266 #25P1213 #26P966 #28P1549 #29P1073 #30P973 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1337 #5P2172 #6P2160 #8P1578 #9P1931 #10P1821 #12P1155 #13P1990 #14P2035 #20P1563 #21P1094 #22P1001 #24P1266 #25P853 #26P773 #28P1595 #29P1069 #30P1080 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1337 #5P1833 #6P1934 #8P1578 #9P1931 #10P1821 #12P1155 #13P1681 #14P1883 #20P1563 #21P1094 #22P1001 #24P1266 #25P1213 #26P966 #28P1595 #29P1069 #30P1080 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1827 #6P1977 #8P1322 #9P2283 #10P2035 #12P1422 #13P1678 #14P1868 #20P1472 #21P821 #22P892 #24P1266 #25P1213 #26P966 #28P1549 #29P709 #30P731 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1827 #6P1977 #8P1322 #9P1931 #10P1821 #12P1422 #13P1678 #14P1868 #20P1472 #21P1098 #22P1078 #24P1266 #25P1213 #26P966 #28P1549 #29P1073 #30P973 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1695 #5P2140 #6P2079 #8P1322 #9P1931 #10P1821 #12P1513 #13P2022 #14P2094 #20P1205 #21P1096 #22P1059 #24P1534 #25P853 #26P773 #28P1237 #29P1067 #30P1016 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1695 #5P1831 #6P1870 #8P1322 #9P1931 #10P1821 #12P1513 #13P1683 #14P1929 #20P1205 #21P1096 #22P1059 #24P1534 #25P1213 #26P966 #28P1237 #29P1067 #30P1016 T200"));
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
