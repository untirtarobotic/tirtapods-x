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
        com.println(F("#4P1588 #5P2151 #6P2045 #8P1400 #9P2247 #10P2080 #12P1287 #13P2018 #14P2095 #20P1374 #21P786 #22P856 #24P1400 #25P867 #26P690 #28P1426 #29P732 #30P800 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1588 #5P2151 #6P2045 #8P1400 #9P2247 #10P2080 #12P1287 #13P2018 #14P2095 #20P1374 #21P786 #22P856 #24P1400 #25P867 #26P690 #28P1426 #29P732 #30P800 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1588 #5P2151 #6P2045 #8P1400 #9P2247 #10P2080 #12P1287 #13P2018 #14P2095 #20P1374 #21P786 #22P856 #24P1400 #25P867 #26P690 #28P1426 #29P732 #30P800 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1588 #5P2151 #6P2045 #8P1400 #9P2247 #10P2080 #12P1287 #13P2018 #14P2095 #20P1374 #21P786 #22P856 #24P1400 #25P867 #26P690 #28P1426 #29P732 #30P800 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1588 #5P2151 #6P2045 #12P1287 #13P2018 #14P2095 #24P1400 #25P867 #26P690 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1588 #5P1850 #6P1842 #12P1287 #13P1683 #14P1892 #24P1400 #25P1198 #26P930 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#8P1400 #9P2247 #10P2080 #20P1374 #21P786 #22P856 #28P1426 #29P732 #30P800 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#8P1400 #9P1909 #10P1905 #20P1374 #21P1093 #22P1052 #28P1426 #29P1067 #30P1024 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize_sync () {
    com.println(F("#4P1588 #5P2151 #6P2045 #12P1287 #13P2018 #14P2095 #24P1400 #25P867 #26P690 T200")); delay(200);
    com.println(F("#4P1588 #5P1850 #6P1842 #12P1287 #13P1683 #14P1892 #24P1400 #25P1198 #26P930 T200")); delay(200);
    com.println(F("#8P1400 #9P2247 #10P2080 #20P1374 #21P786 #22P856 #28P1426 #29P732 #30P800 T200")); delay(200);
    com.println(F("#8P1400 #9P1909 #10P1905 #20P1374 #21P1093 #22P1052 #28P1426 #29P1067 #30P1024 T200")); delay(200);
  }

  void ssc_forward_low () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1724 #5P2172 #6P2108 #8P1286 #9P2242 #10P2068 #12P1375 #13P1979 #14P2008 #20P1472 #21P821 #22P940 #24P1272 #25P872 #26P706 #28P1549 #29P709 #30P731 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1724 #5P2172 #6P2108 #8P1286 #9P2242 #10P2068 #12P1375 #13P1979 #14P2008 #20P1472 #21P821 #22P940 #24P1272 #25P872 #26P706 #28P1549 #29P709 #30P731 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1480 #5P2117 #6P1958 #8P1514 #9P2242 #10P2068 #12P1176 #13P2041 #14P2158 #20P1251 #21P764 #22P796 #24P1528 #25P872 #26P706 #28P1328 #29P771 #30P896 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1480 #5P2117 #6P1958 #8P1514 #9P2242 #10P2068 #12P1176 #13P2041 #14P2158 #20P1251 #21P764 #22P796 #24P1528 #25P872 #26P706 #28P1328 #29P771 #30P896 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_higher () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1724 #5P1713 #6P1774 #8P1286 #9P2731 #10P2239 #12P1375 #13P1543 #14P1717 #20P1472 #21P499 #22P798 #24P1272 #25P1329 #26P1066 #28P1549 #29P121 #30P465 T220"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1724 #5P1713 #6P1774 #8P1286 #9P1775 #10P1807 #12P1375 #13P1543 #14P1717 #20P1472 #21P1222 #22P1220 #24P1272 #25P1329 #26P1066 #28P1549 #29P1219 #30P1099 T220"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1480 #5P2432 #6P2106 #8P1514 #9P1775 #10P1807 #12P1176 #13P2629 #14P2400 #20P1251 #21P1233 #22P1117 #24P1528 #25P393 #26P471 #28P1328 #29P1207 #30P1216 T220"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1480 #5P1724 #6P1667 #8P1514 #9P1775 #10P1807 #12P1176 #13P1531 #14P1824 #20P1251 #21P1233 #22P1117 #24P1528 #25P1329 #26P1066 #28P1328 #29P1207 #30P1216 T220"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P2345 #10P2110 #12P1375 #13P1678 #14P1822 #20P1472 #21P744 #22P901 #24P1272 #25P1196 #26P942 #28P1549 #29P593 #30P670 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P1911 #10P1897 #12P1375 #13P1678 #14P1822 #20P1472 #21P1098 #22P1119 #24P1272 #25P1196 #26P942 #28P1549 #29P1073 #30P973 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1480 #5P2191 #6P1999 #8P1514 #9P1911 #10P1897 #12P1176 #13P2157 #14P2214 #20P1251 #21P1099 #22P1008 #24P1528 #25P771 #26P649 #28P1328 #29P1072 #30P1100 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1480 #5P1845 #6P1772 #8P1514 #9P1911 #10P1897 #12P1176 #13P1677 #14P1938 #20P1251 #21P1099 #22P1008 #24P1528 #25P1196 #26P942 #28P1328 #29P1072 #30P1100 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_sync () {
    com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P2345 #10P2110 #12P1375 #13P1678 #14P1822 #20P1472 #21P744 #22P901 #24P1272 #25P1196 #26P942 #28P1549 #29P593 #30P670 T200")); delay(200);
    com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P1911 #10P1897 #12P1375 #13P1678 #14P1822 #20P1472 #21P1098 #22P1119 #24P1272 #25P1196 #26P942 #28P1549 #29P1073 #30P973 T200")); delay(200);
    com.println(F("#4P1480 #5P2191 #6P1999 #8P1514 #9P1911 #10P1897 #12P1176 #13P2157 #14P2214 #20P1251 #21P1099 #22P1008 #24P1528 #25P771 #26P649 #28P1328 #29P1072 #30P1100 T200")); delay(200);
    com.println(F("#4P1480 #5P1845 #6P1772 #8P1514 #9P1911 #10P1897 #12P1176 #13P1677 #14P1938 #20P1251 #21P1099 #22P1008 #24P1528 #25P1196 #26P942 #28P1328 #29P1072 #30P1100 T200")); delay(200);
  }

  void ssc_backward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1480 #5P1845 #6P1772 #8P1514 #9P2345 #10P2110 #12P1176 #13P1677 #14P1938 #20P1251 #21P657 #22P743 #24P1528 #25P1196 #26P942 #28P1328 #29P687 #30P851 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1480 #5P1845 #6P1772 #8P1514 #9P1911 #10P1897 #12P1176 #13P1677 #14P1938 #20P1251 #21P1099 #22P1008 #24P1528 #25P1196 #26P942 #28P1328 #29P1072 #30P1100 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1724 #5P2277 #6P2164 #8P1286 #9P1911 #10P1897 #12P1375 #13P2063 #14P2049 #20P1472 #21P1098 #22P1119 #24P1272 #25P771 #26P649 #28P1549 #29P1073 #30P973 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P1911 #10P1897 #12P1375 #13P1678 #14P1822 #20P1472 #21P1098 #22P1119 #24P1272 #25P1196 #26P942 #28P1549 #29P1073 #30P973 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_backward_sync () {
    com.println(F("#4P1480 #5P1845 #6P1772 #8P1514 #9P2345 #10P2110 #12P1176 #13P1677 #14P1938 #20P1251 #21P657 #22P743 #24P1528 #25P1196 #26P942 #28P1328 #29P687 #30P851 T200")); delay(200);
    com.println(F("#4P1480 #5P1845 #6P1772 #8P1514 #9P1911 #10P1897 #12P1176 #13P1677 #14P1938 #20P1251 #21P1099 #22P1008 #24P1528 #25P1196 #26P942 #28P1328 #29P1072 #30P1100 T200")); delay(200);
    com.println(F("#4P1724 #5P2277 #6P2164 #8P1286 #9P1911 #10P1897 #12P1375 #13P2063 #14P2049 #20P1472 #21P1098 #22P1119 #24P1272 #25P771 #26P649 #28P1549 #29P1073 #30P973 T200")); delay(200);
    com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P1911 #10P1897 #12P1375 #13P1678 #14P1822 #20P1472 #21P1098 #22P1119 #24P1272 #25P1196 #26P942 #28P1549 #29P1073 #30P973 T200")); delay(200);
  }

  void ssc_shiftRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1675 #5P1833 #6P1704 #8P1400 #9P2406 #10P2201 #12P1216 #13P1664 #14P1754 #20P1295 #21P789 #22P981 #24P1400 #25P1219 #26P870 #28P1505 #29P736 #30P943 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1675 #5P1833 #6P1704 #8P1400 #9P1888 #10P1949 #12P1216 #13P1664 #14P1754 #20P1295 #21P1111 #22P1184 #24P1400 #25P1219 #26P870 #28P1505 #29P1086 #30P1175 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1527 #5P2282 #6P2173 #8P1400 #9P1902 #10P1787 #12P1337 #13P2163 #14P2223 #20P1430 #21P1100 #22P1002 #24P1400 #25P870 #26P853 #28P1370 #29P1074 #30P967 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1527 #5P1843 #6P1894 #8P1400 #9P1902 #10P1787 #12P1337 #13P1676 #14P1944 #20P1430 #21P1100 #22P1002 #24P1400 #25P1205 #26P1092 #28P1370 #29P1074 #30P967 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1527 #5P1843 #6P1894 #8P1400 #9P2244 #10P1961 #12P1337 #13P1676 #14P1944 #20P1430 #21P652 #22P733 #24P1400 #25P1205 #26P1092 #28P1370 #29P587 #30P659 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1527 #5P1843 #6P1894 #8P1400 #9P1902 #10P1787 #12P1337 #13P1676 #14P1944 #20P1430 #21P1100 #22P1002 #24P1400 #25P1205 #26P1092 #28P1370 #29P1074 #30P967 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1675 #5P2148 #6P1916 #8P1400 #9P1888 #10P1949 #12P1216 #13P2014 #14P1966 #20P1295 #21P1111 #22P1184 #24P1400 #25P711 #26P523 #28P1505 #29P1086 #30P1175 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1675 #5P1833 #6P1704 #8P1400 #9P1888 #10P1949 #12P1216 #13P1664 #14P1754 #20P1295 #21P1111 #22P1184 #24P1400 #25P1219 #26P870 #28P1505 #29P1086 #30P1175 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1775 #5P1848 #6P1791 #8P1286 #9P2242 #10P2068 #12P1457 #13P1683 #14P1899 #20P1205 #21P811 #22P919 #24P1528 #25P1196 #26P942 #28P1237 #29P728 #30P790 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1775 #5P1848 #6P1791 #8P1286 #9P1911 #10P1897 #12P1457 #13P1683 #14P1899 #20P1205 #21P1096 #22P1101 #24P1528 #25P1196 #26P942 #28P1237 #29P1067 #30P1016 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1380 #5P2154 #6P2055 #8P1514 #9P1911 #10P1897 #12P1134 #13P1990 #14P2031 #20P1563 #21P1094 #22P1045 #24P1272 #25P872 #26P706 #28P1595 #29P1069 #30P1080 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1380 #5P1850 #6P1849 #8P1514 #9P1911 #10P1897 #12P1134 #13P1681 #14P1841 #20P1563 #21P1094 #22P1045 #24P1272 #25P1196 #26P942 #28P1595 #29P1069 #30P1080 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW_sync () {
    com.println(F("#4P1775 #5P1848 #6P1791 #8P1286 #9P2242 #10P2068 #12P1457 #13P1683 #14P1899 #20P1205 #21P811 #22P919 #24P1528 #25P1196 #26P942 #28P1237 #29P728 #30P790 T200")); delay(200);
    com.println(F("#4P1775 #5P1848 #6P1791 #8P1286 #9P1911 #10P1897 #12P1457 #13P1683 #14P1899 #20P1205 #21P1096 #22P1101 #24P1528 #25P1196 #26P942 #28P1237 #29P1067 #30P1016 T200")); delay(200);
    com.println(F("#4P1380 #5P2154 #6P2055 #8P1514 #9P1911 #10P1897 #12P1134 #13P1990 #14P2031 #20P1563 #21P1094 #22P1045 #24P1272 #25P872 #26P706 #28P1595 #29P1069 #30P1080 T200")); delay(200);
    com.println(F("#4P1380 #5P1850 #6P1849 #8P1514 #9P1911 #10P1897 #12P1134 #13P1681 #14P1841 #20P1563 #21P1094 #22P1045 #24P1272 #25P1196 #26P942 #28P1595 #29P1069 #30P1080 T200")); delay(200);
  }

  void ssc_rotateCCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1380 #5P1850 #6P1849 #8P1514 #9P2242 #10P2068 #12P1134 #13P1681 #14P1841 #20P1563 #21P782 #22P847 #24P1272 #25P1196 #26P942 #28P1595 #29P760 #30P871 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1380 #5P1850 #6P1849 #8P1514 #9P1911 #10P1897 #12P1134 #13P1681 #14P1841 #20P1563 #21P1094 #22P1045 #24P1272 #25P1196 #26P942 #28P1595 #29P1069 #30P1080 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1775 #5P2126 #6P1981 #8P1286 #9P1911 #10P1897 #12P1457 #13P2022 #14P2105 #20P1205 #21P1096 #22P1101 #24P1528 #25P872 #26P706 #28P1237 #29P1067 #30P1016 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1775 #5P1848 #6P1791 #8P1286 #9P1911 #10P1897 #12P1457 #13P1683 #14P1899 #20P1205 #21P1096 #22P1101 #24P1528 #25P1196 #26P942 #28P1237 #29P1067 #30P1016 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCW_sync () {
    com.println(F("#4P1380 #5P1850 #6P1849 #8P1514 #9P2242 #10P2068 #12P1134 #13P1681 #14P1841 #20P1563 #21P782 #22P847 #24P1272 #25P1196 #26P942 #28P1595 #29P760 #30P871 T200")); delay(200);
    com.println(F("#4P1380 #5P1850 #6P1849 #8P1514 #9P1911 #10P1897 #12P1134 #13P1681 #14P1841 #20P1563 #21P1094 #22P1045 #24P1272 #25P1196 #26P942 #28P1595 #29P1069 #30P1080 T200")); delay(200);
    com.println(F("#4P1775 #5P2126 #6P1981 #8P1286 #9P1911 #10P1897 #12P1457 #13P2022 #14P2105 #20P1205 #21P1096 #22P1101 #24P1528 #25P872 #26P706 #28P1237 #29P1067 #30P1016 T200")); delay(200);
    com.println(F("#4P1775 #5P1848 #6P1791 #8P1286 #9P1911 #10P1897 #12P1457 #13P1683 #14P1899 #20P1205 #21P1096 #22P1101 #24P1528 #25P1196 #26P942 #28P1237 #29P1067 #30P1016 T200")); delay(200);
  }

  void ssc_rotateCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1654 #5P1850 #6P1830 #8P1361 #9P2247 #10P2078 #12P1343 #13P1683 #14P1899 #20P1314 #21P792 #22P871 #24P1443 #25P1197 #26P931 #28P1363 #29P728 #30P790 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1654 #5P1850 #6P1830 #8P1361 #9P1909 #10P1904 #12P1343 #13P1683 #14P1899 #20P1314 #21P1093 #22P1064 #24P1443 #25P1197 #26P931 #28P1363 #29P1067 #30P1016 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1520 #5P2154 #6P2055 #8P1439 #9P1909 #10P1904 #12P1233 #13P2011 #14P2080 #20P1437 #21P1094 #22P1045 #24P1357 #25P867 #26P692 #28P1486 #29P1067 #30P1037 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1520 #5P1850 #6P1849 #8P1439 #9P1909 #10P1904 #12P1233 #13P1683 #14P1880 #20P1437 #21P1094 #22P1045 #24P1357 #25P1197 #26P931 #28P1486 #29P1067 #30P1037 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1520 #5P1850 #6P1849 #8P1439 #9P2247 #10P2078 #12P1233 #13P1683 #14P1880 #20P1437 #21P782 #22P847 #24P1357 #25P1197 #26P931 #28P1486 #29P739 #30P817 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1520 #5P1850 #6P1849 #8P1439 #9P1909 #10P1904 #12P1233 #13P1683 #14P1880 #20P1437 #21P1094 #22P1045 #24P1357 #25P1197 #26P931 #28P1486 #29P1067 #30P1037 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1654 #5P2145 #6P2030 #8P1361 #9P1909 #10P1904 #12P1343 #13P2022 #14P2105 #20P1314 #21P1093 #22P1064 #24P1443 #25P867 #26P692 #28P1363 #29P1067 #30P1016 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1654 #5P1850 #6P1830 #8P1361 #9P1909 #10P1904 #12P1343 #13P1683 #14P1899 #20P1314 #21P1093 #22P1064 #24P1443 #25P1197 #26P931 #28P1363 #29P1067 #30P1016 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P2242 #10P2068 #12P1375 #13P1678 #14P1822 #20P1472 #21P821 #22P940 #24P1272 #25P1196 #26P942 #28P1549 #29P709 #30P731 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P1911 #10P1897 #12P1375 #13P1678 #14P1822 #20P1472 #21P1098 #22P1119 #24P1272 #25P1196 #26P942 #28P1549 #29P1073 #30P973 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1380 #5P2154 #6P2055 #8P1514 #9P1911 #10P1897 #12P1134 #13P1990 #14P2031 #20P1563 #21P1094 #22P1045 #24P1272 #25P872 #26P706 #28P1595 #29P1069 #30P1080 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1380 #5P1850 #6P1849 #8P1514 #9P1911 #10P1897 #12P1134 #13P1681 #14P1841 #20P1563 #21P1094 #22P1045 #24P1272 #25P1196 #26P942 #28P1595 #29P1069 #30P1080 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P2242 #10P2068 #12P1375 #13P1678 #14P1822 #20P1472 #21P821 #22P940 #24P1272 #25P1196 #26P942 #28P1549 #29P709 #30P731 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1724 #5P1845 #6P1888 #8P1286 #9P1911 #10P1897 #12P1375 #13P1678 #14P1822 #20P1472 #21P1098 #22P1119 #24P1272 #25P1196 #26P942 #28P1549 #29P1073 #30P973 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1775 #5P2126 #6P1981 #8P1286 #9P1911 #10P1897 #12P1457 #13P2022 #14P2105 #20P1205 #21P1096 #22P1101 #24P1528 #25P872 #26P706 #28P1237 #29P1067 #30P1016 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1775 #5P1848 #6P1791 #8P1286 #9P1911 #10P1897 #12P1457 #13P1683 #14P1899 #20P1205 #21P1096 #22P1101 #24P1528 #25P1196 #26P942 #28P1237 #29P1067 #30P1016 T200"));
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
