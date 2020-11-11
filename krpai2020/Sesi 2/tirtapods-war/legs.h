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
        com.println(F("#4P1638 #5P2108 #6P2142 #8P1400 #9P2288 #10P2238 #12P1262 #13P1948 #14P2225 #20P1487 #21P832 #22P805 #24P1450 #25P852 #26P540 #28P1418 #29P822 #30P859 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1638 #5P2108 #6P2142 #8P1400 #9P2288 #10P2238 #12P1262 #13P1948 #14P2225 #20P1487 #21P832 #22P805 #24P1450 #25P852 #26P540 #28P1418 #29P822 #30P859 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1638 #5P2108 #6P2142 #8P1400 #9P2288 #10P2238 #12P1262 #13P1948 #14P2225 #20P1487 #21P832 #22P805 #24P1450 #25P852 #26P540 #28P1418 #29P822 #30P859 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1638 #5P2108 #6P2142 #8P1400 #9P2288 #10P2238 #12P1262 #13P1948 #14P2225 #20P1487 #21P832 #22P805 #24P1450 #25P852 #26P540 #28P1418 #29P822 #30P859 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1638 #5P2108 #6P2142 #12P1262 #13P1948 #14P2225 #24P1450 #25P852 #26P540 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1638 #5P1793 #6P1954 #12P1262 #13P1613 #14P2022 #24P1450 #25P1211 #26P780 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#8P1400 #9P2288 #10P2238 #20P1487 #21P832 #22P805 #28P1418 #29P822 #30P859 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#8P1400 #9P1929 #10P2024 #20P1487 #21P1167 #22P1008 #28P1418 #29P1137 #30P1042 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize_sync () {
    com.println(F("#4P1638 #5P2108 #6P2142 #12P1262 #13P1948 #14P2225 #24P1450 #25P852 #26P540 T200")); delay(200);
    com.println(F("#4P1638 #5P1793 #6P1954 #12P1262 #13P1613 #14P2022 #24P1450 #25P1211 #26P780 T200")); delay(200);
    com.println(F("#8P1400 #9P2288 #10P2238 #20P1487 #21P832 #22P805 #28P1418 #29P822 #30P859 T200")); delay(200);
    com.println(F("#8P1400 #9P1929 #10P2024 #20P1487 #21P1167 #22P1008 #28P1418 #29P1137 #30P1042 T200")); delay(200);
  }

  void ssc_forward_low () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1774 #5P2130 #6P2200 #8P1252 #9P2283 #10P2223 #12P1370 #13P1909 #14P2138 #20P1575 #21P871 #22P892 #24P1308 #25P857 #26P556 #28P1534 #29P800 #30P802 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1774 #5P2130 #6P2200 #8P1252 #9P2283 #10P2223 #12P1370 #13P1909 #14P2138 #20P1575 #21P871 #22P892 #24P1308 #25P857 #26P556 #28P1534 #29P800 #30P802 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1530 #5P2072 #6P2062 #8P1548 #9P2283 #10P2223 #12P1126 #13P1971 #14P2288 #20P1376 #21P809 #22P742 #24P1592 #25P857 #26P556 #28P1326 #29P858 #30P938 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1530 #5P2072 #6P2062 #8P1548 #9P2283 #10P2223 #12P1126 #13P1971 #14P2288 #20P1376 #21P809 #22P742 #24P1592 #25P857 #26P556 #28P1326 #29P858 #30P938 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_higher () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1774 #5P1651 #6P1892 #8P1252 #9P2803 #10P2433 #12P1370 #13P1473 #14P1847 #20P1575 #21P520 #22P744 #24P1308 #25P1354 #26P916 #28P1534 #29P247 #30P585 T240"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1774 #5P1651 #6P1892 #8P1252 #9P1786 #10P1903 #12P1370 #13P1473 #14P1847 #20P1575 #21P1307 #22P1183 #24P1308 #25P1354 #26P916 #28P1534 #29P1279 #30P1104 T240"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1530 #5P2401 #6P2198 #8P1548 #9P1786 #10P1903 #12P1126 #13P2559 #14P2530 #20P1376 #21P1319 #22P1076 #24P1592 #25P337 #26P321 #28P1326 #29P1269 #30P1200 T240"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1530 #5P1661 #6P1794 #8P1548 #9P1786 #10P1903 #12P1126 #13P1461 #14P1954 #20P1376 #21P1319 #22P1076 #24P1592 #25P1354 #26P916 #28P1326 #29P1269 #30P1200 T240"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1774 #5P1788 #6P1997 #8P1252 #9P2392 #10P2275 #12P1370 #13P1608 #14P1952 #20P1575 #21P787 #22P851 #24P1308 #25P1209 #26P792 #28P1534 #29P691 #30P752 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1774 #5P1788 #6P1997 #8P1252 #9P1931 #10P2014 #12P1370 #13P1608 #14P1952 #20P1575 #21P1172 #22P1078 #24P1308 #25P1209 #26P792 #28P1534 #29P1142 #30P1001 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1530 #5P2150 #6P2100 #8P1548 #9P1931 #10P2014 #12P1126 #13P2087 #14P2344 #20P1376 #21P1173 #22P962 #24P1592 #25P748 #26P499 #28P1326 #29P1141 #30P1105 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1530 #5P1789 #6P1891 #8P1548 #9P1931 #10P2014 #12P1126 #13P1607 #14P2068 #20P1376 #21P1173 #22P962 #24P1592 #25P1209 #26P792 #28P1326 #29P1141 #30P1105 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_sync () {
    com.println(F("#4P1774 #5P1788 #6P1997 #8P1252 #9P2392 #10P2275 #12P1370 #13P1608 #14P1952 #20P1575 #21P787 #22P851 #24P1308 #25P1209 #26P792 #28P1534 #29P691 #30P752 T200")); delay(200);
    com.println(F("#4P1774 #5P1788 #6P1997 #8P1252 #9P1931 #10P2014 #12P1370 #13P1608 #14P1952 #20P1575 #21P1172 #22P1078 #24P1308 #25P1209 #26P792 #28P1534 #29P1142 #30P1001 T200")); delay(200);
    com.println(F("#4P1530 #5P2150 #6P2100 #8P1548 #9P1931 #10P2014 #12P1126 #13P2087 #14P2344 #20P1376 #21P1173 #22P962 #24P1592 #25P748 #26P499 #28P1326 #29P1141 #30P1105 T200")); delay(200);
    com.println(F("#4P1530 #5P1789 #6P1891 #8P1548 #9P1931 #10P2014 #12P1126 #13P1607 #14P2068 #20P1376 #21P1173 #22P962 #24P1592 #25P1209 #26P792 #28P1326 #29P1141 #30P1105 T200")); delay(200);
  }

  void ssc_backward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1530 #5P1789 #6P1891 #8P1548 #9P2392 #10P2275 #12P1126 #13P1607 #14P2068 #20P1376 #21P693 #22P686 #24P1592 #25P1209 #26P792 #28P1326 #29P780 #30P900 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1530 #5P1789 #6P1891 #8P1548 #9P1931 #10P2014 #12P1126 #13P1607 #14P2068 #20P1376 #21P1173 #22P962 #24P1592 #25P1209 #26P792 #28P1326 #29P1141 #30P1105 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1774 #5P2239 #6P2251 #8P1252 #9P1931 #10P2014 #12P1370 #13P1993 #14P2179 #20P1575 #21P1172 #22P1078 #24P1308 #25P748 #26P499 #28P1534 #29P1142 #30P1001 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1774 #5P1788 #6P1997 #8P1252 #9P1931 #10P2014 #12P1370 #13P1608 #14P1952 #20P1575 #21P1172 #22P1078 #24P1308 #25P1209 #26P792 #28P1534 #29P1142 #30P1001 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_backward_sync () {
    com.println(F("#4P1530 #5P1789 #6P1891 #8P1548 #9P2392 #10P2275 #12P1126 #13P1607 #14P2068 #20P1376 #21P693 #22P686 #24P1592 #25P1209 #26P792 #28P1326 #29P780 #30P900 T200")); delay(200);
    com.println(F("#4P1530 #5P1789 #6P1891 #8P1548 #9P1931 #10P2014 #12P1126 #13P1607 #14P2068 #20P1376 #21P1173 #22P962 #24P1592 #25P1209 #26P792 #28P1326 #29P1141 #30P1105 T200")); delay(200);
    com.println(F("#4P1774 #5P2239 #6P2251 #8P1252 #9P1931 #10P2014 #12P1370 #13P1993 #14P2179 #20P1575 #21P1172 #22P1078 #24P1308 #25P748 #26P499 #28P1534 #29P1142 #30P1001 T200")); delay(200);
    com.println(F("#4P1774 #5P1788 #6P1997 #8P1252 #9P1931 #10P2014 #12P1370 #13P1608 #14P1952 #20P1575 #21P1172 #22P1078 #24P1308 #25P1209 #26P792 #28P1534 #29P1142 #30P1001 T200")); delay(200);
  }

  void ssc_shiftRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1725 #5P1775 #6P1828 #8P1400 #9P2458 #10P2387 #12P1175 #13P1594 #14P1884 #20P1416 #21P836 #22P934 #24P1450 #25P1234 #26P720 #28P1493 #29P825 #30P976 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1725 #5P1775 #6P1828 #8P1400 #9P1906 #10P2078 #12P1175 #13P1594 #14P1884 #20P1416 #21P1186 #22P1146 #24P1450 #25P1234 #26P720 #28P1493 #29P1155 #30P1166 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1577 #5P2244 #6P2260 #8P1400 #9P1921 #10P1880 #12P1323 #13P2093 #14P2353 #20P1537 #21P1174 #22P956 #24P1450 #25P855 #26P703 #28P1366 #29P1144 #30P996 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1577 #5P1786 #6P2002 #8P1400 #9P1921 #10P1880 #12P1323 #13P1606 #14P2074 #20P1537 #21P1174 #22P956 #24P1450 #25P1219 #26P942 #28P1366 #29P1144 #30P996 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1577 #5P1786 #6P2002 #8P1400 #9P2285 #10P2093 #12P1323 #13P1606 #14P2074 #20P1537 #21P687 #22P677 #24P1450 #25P1219 #26P942 #28P1366 #29P686 #30P744 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1577 #5P1786 #6P2002 #8P1400 #9P1921 #10P1880 #12P1323 #13P1606 #14P2074 #20P1537 #21P1174 #22P956 #24P1450 #25P1219 #26P942 #28P1366 #29P1144 #30P996 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1725 #5P2105 #6P2022 #8P1400 #9P1906 #10P2078 #12P1175 #13P1944 #14P2096 #20P1416 #21P1186 #22P1146 #24P1450 #25P682 #26P373 #28P1493 #29P1155 #30P1166 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1725 #5P1775 #6P1828 #8P1400 #9P1906 #10P2078 #12P1175 #13P1594 #14P1884 #20P1416 #21P1186 #22P1146 #24P1450 #25P1234 #26P720 #28P1493 #29P1155 #30P1166 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftLeftHigher () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1577 #5P1649 #6P1897 #8P1400 #9P2527 #10P2189 #12P1323 #13P1459 #14P1959 #20P1537 #21P185 #22P479 #24P1450 #25P1351 #26P1056 #28P1366 #29P214 #30P566 T240"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1577 #5P1649 #6P1897 #8P1400 #9P1789 #10P1778 #12P1323 #13P1459 #14P1959 #20P1537 #21P1321 #22P1071 #24P1450 #25P1351 #26P1056 #28P1366 #29P1281 #30P1099 T240"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1725 #5P2317 #6P2107 #8P1400 #9P1756 #10P1961 #12P1175 #13P2170 #14P2188 #20P1416 #21P1316 #22P1248 #24P1450 #25PNaN #26PNaN #28P1493 #29P1277 #30P1258 T240"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1725 #5P1653 #6P1734 #8P1400 #9P1756 #10P1961 #12P1175 #13P1464 #14P1782 #20P1416 #21P1316 #22P1248 #24P1450 #25P1384 #26P851 #28P1493 #29P1277 #30P1258 T240"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1825 #5P1791 #6P1907 #8P1252 #9P2283 #10P2223 #12P1470 #13P1613 #14P2029 #20P1334 #21P860 #22P869 #24P1592 #25P1209 #26P792 #28P1240 #29P819 #30P851 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1825 #5P1791 #6P1907 #8P1252 #9P1931 #10P2014 #12P1470 #13P1613 #14P2029 #20P1334 #21P1169 #22P1059 #24P1592 #25P1209 #26P792 #28P1240 #29P1137 #30P1036 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1430 #5P2111 #6P2151 #8P1548 #9P1931 #10P2014 #12P1075 #13P1920 #14P2161 #20P1657 #21P1167 #22P1001 #24P1308 #25P857 #26P556 #28P1577 #29P1139 #30P1088 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1430 #5P1793 #6P1961 #8P1548 #9P1931 #10P2014 #12P1075 #13P1611 #14P1971 #20P1657 #21P1167 #22P1001 #24P1308 #25P1209 #26P792 #28P1577 #29P1139 #30P1088 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW_sync () {
    com.println(F("#4P1825 #5P1791 #6P1907 #8P1252 #9P2283 #10P2223 #12P1470 #13P1613 #14P2029 #20P1334 #21P860 #22P869 #24P1592 #25P1209 #26P792 #28P1240 #29P819 #30P851 T200")); delay(200);
    com.println(F("#4P1825 #5P1791 #6P1907 #8P1252 #9P1931 #10P2014 #12P1470 #13P1613 #14P2029 #20P1334 #21P1169 #22P1059 #24P1592 #25P1209 #26P792 #28P1240 #29P1137 #30P1036 T200")); delay(200);
    com.println(F("#4P1430 #5P2111 #6P2151 #8P1548 #9P1931 #10P2014 #12P1075 #13P1920 #14P2161 #20P1657 #21P1167 #22P1001 #24P1308 #25P857 #26P556 #28P1577 #29P1139 #30P1088 T200")); delay(200);
    com.println(F("#4P1430 #5P1793 #6P1961 #8P1548 #9P1931 #10P2014 #12P1075 #13P1611 #14P1971 #20P1657 #21P1167 #22P1001 #24P1308 #25P1209 #26P792 #28P1577 #29P1139 #30P1088 T200")); delay(200);
  }

  void ssc_rotateCCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1430 #5P1793 #6P1961 #8P1548 #9P2283 #10P2223 #12P1075 #13P1611 #14P1971 #20P1657 #21P828 #22P795 #24P1308 #25P1209 #26P792 #28P1577 #29P849 #30P917 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1430 #5P1793 #6P1961 #8P1548 #9P1931 #10P2014 #12P1075 #13P1611 #14P1971 #20P1657 #21P1167 #22P1001 #24P1308 #25P1209 #26P792 #28P1577 #29P1139 #30P1088 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1825 #5P2081 #6P2082 #8P1252 #9P1931 #10P2014 #12P1470 #13P1952 #14P2235 #20P1334 #21P1169 #22P1059 #24P1592 #25P857 #26P556 #28P1240 #29P1137 #30P1036 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1825 #5P1791 #6P1907 #8P1252 #9P1931 #10P2014 #12P1470 #13P1613 #14P2029 #20P1334 #21P1169 #22P1059 #24P1592 #25P1209 #26P792 #28P1240 #29P1137 #30P1036 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCW_sync () {
    com.println(F("#4P1430 #5P1793 #6P1961 #8P1548 #9P2283 #10P2223 #12P1075 #13P1611 #14P1971 #20P1657 #21P828 #22P795 #24P1308 #25P1209 #26P792 #28P1577 #29P849 #30P917 T200")); delay(200);
    com.println(F("#4P1430 #5P1793 #6P1961 #8P1548 #9P1931 #10P2014 #12P1075 #13P1611 #14P1971 #20P1657 #21P1167 #22P1001 #24P1308 #25P1209 #26P792 #28P1577 #29P1139 #30P1088 T200")); delay(200);
    com.println(F("#4P1825 #5P2081 #6P2082 #8P1252 #9P1931 #10P2014 #12P1470 #13P1952 #14P2235 #20P1334 #21P1169 #22P1059 #24P1592 #25P857 #26P556 #28P1240 #29P1137 #30P1036 T200")); delay(200);
    com.println(F("#4P1825 #5P1791 #6P1907 #8P1252 #9P1931 #10P2014 #12P1470 #13P1613 #14P2029 #20P1334 #21P1169 #22P1059 #24P1592 #25P1209 #26P792 #28P1240 #29P1137 #30P1036 T200")); delay(200);
  }

  void ssc_rotateCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1704 #5P1793 #6P1943 #8P1350 #9P2288 #10P2236 #12P1330 #13P1613 #14P2029 #20P1433 #21P839 #22P820 #24P1498 #25P1211 #26P781 #28P1360 #29P819 #30P851 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1704 #5P1793 #6P1943 #8P1350 #9P1929 #10P2023 #12P1330 #13P1613 #14P2029 #20P1433 #21P1167 #22P1020 #24P1498 #25P1211 #26P781 #28P1360 #29P1137 #30P1036 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1570 #5P2111 #6P2151 #8P1450 #9P1929 #10P2023 #12P1196 #13P1941 #14P2210 #20P1543 #21P1167 #22P1001 #24P1402 #25P852 #26P542 #28P1474 #29P1137 #30P1053 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1570 #5P1793 #6P1961 #8P1450 #9P1929 #10P2023 #12P1196 #13P1613 #14P2010 #20P1543 #21P1167 #22P1001 #24P1402 #25P1211 #26P781 #28P1474 #29P1137 #30P1053 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1570 #5P1793 #6P1961 #8P1450 #9P2288 #10P2236 #12P1196 #13P1613 #14P2010 #20P1543 #21P828 #22P795 #24P1402 #25P1211 #26P781 #28P1474 #29P828 #30P873 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1570 #5P1793 #6P1961 #8P1450 #9P1929 #10P2023 #12P1196 #13P1613 #14P2010 #20P1543 #21P1167 #22P1001 #24P1402 #25P1211 #26P781 #28P1474 #29P1137 #30P1053 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1704 #5P2102 #6P2127 #8P1350 #9P1929 #10P2023 #12P1330 #13P1952 #14P2235 #20P1433 #21P1167 #22P1020 #24P1498 #25P852 #26P542 #28P1360 #29P1137 #30P1036 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1704 #5P1793 #6P1943 #8P1350 #9P1929 #10P2023 #12P1330 #13P1613 #14P2029 #20P1433 #21P1167 #22P1020 #24P1498 #25P1211 #26P781 #28P1360 #29P1137 #30P1036 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1774 #5P1788 #6P1997 #8P1252 #9P2283 #10P2223 #12P1370 #13P1608 #14P1952 #20P1575 #21P871 #22P892 #24P1308 #25P1209 #26P792 #28P1534 #29P800 #30P802 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1774 #5P1788 #6P1997 #8P1252 #9P1931 #10P2014 #12P1370 #13P1608 #14P1952 #20P1575 #21P1172 #22P1078 #24P1308 #25P1209 #26P792 #28P1534 #29P1142 #30P1001 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1430 #5P2111 #6P2151 #8P1548 #9P1931 #10P2014 #12P1075 #13P1920 #14P2161 #20P1657 #21P1167 #22P1001 #24P1308 #25P857 #26P556 #28P1577 #29P1139 #30P1088 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1430 #5P1793 #6P1961 #8P1548 #9P1931 #10P2014 #12P1075 #13P1611 #14P1971 #20P1657 #21P1167 #22P1001 #24P1308 #25P1209 #26P792 #28P1577 #29P1139 #30P1088 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1774 #5P1788 #6P1997 #8P1252 #9P2283 #10P2223 #12P1370 #13P1608 #14P1952 #20P1575 #21P871 #22P892 #24P1308 #25P1209 #26P792 #28P1534 #29P800 #30P802 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1774 #5P1788 #6P1997 #8P1252 #9P1931 #10P2014 #12P1370 #13P1608 #14P1952 #20P1575 #21P1172 #22P1078 #24P1308 #25P1209 #26P792 #28P1534 #29P1142 #30P1001 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1825 #5P2081 #6P2082 #8P1252 #9P1931 #10P2014 #12P1470 #13P1952 #14P2235 #20P1334 #21P1169 #22P1059 #24P1592 #25P857 #26P556 #28P1240 #29P1137 #30P1036 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1825 #5P1791 #6P1907 #8P1252 #9P1931 #10P2014 #12P1470 #13P1613 #14P2029 #20P1334 #21P1169 #22P1059 #24P1592 #25P1209 #26P792 #28P1240 #29P1137 #30P1036 T200"));
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
