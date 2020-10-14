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
        com.println(F("#4P1526 #5P2124 #6P2145 #8P1450 #9P2296 #10P2144 #12P1237 #13P2001 #14P2160 #20P1374 #21P769 #22P800 #24P1400 #25P848 #26P646 #28P1471 #29P732 #30P705 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1526 #5P2124 #6P2145 #8P1450 #9P2296 #10P2144 #12P1237 #13P2001 #14P2160 #20P1374 #21P769 #22P800 #24P1400 #25P848 #26P646 #28P1471 #29P732 #30P705 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1526 #5P2124 #6P2145 #8P1450 #9P2296 #10P2144 #12P1237 #13P2001 #14P2160 #20P1374 #21P769 #22P800 #24P1400 #25P848 #26P646 #28P1471 #29P732 #30P705 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1526 #5P2124 #6P2145 #8P1450 #9P2296 #10P2144 #12P1237 #13P2001 #14P2160 #20P1374 #21P769 #22P800 #24P1400 #25P848 #26P646 #28P1471 #29P732 #30P705 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1526 #5P2124 #6P2145 #12P1237 #13P2001 #14P2160 #24P1400 #25P848 #26P646 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1526 #5P1777 #6P1942 #12P1237 #13P1700 #14P1981 #24P1400 #25P1215 #26P873 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#8P1450 #9P2296 #10P2144 #20P1374 #21P769 #22P800 #28P1471 #29P732 #30P705 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#8P1450 #9P1922 #10P1939 #20P1374 #21P1110 #22P1024 #28P1471 #29P1067 #30P908 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize_sync () {
    com.println(F("#4P1526 #5P2124 #6P2145 #12P1237 #13P2001 #14P2160 #24P1400 #25P848 #26P646 T100")); delay(200);
    com.println(F("#4P1526 #5P1777 #6P1942 #12P1237 #13P1700 #14P1981 #24P1400 #25P1215 #26P873 T100")); delay(200);
    com.println(F("#8P1450 #9P2296 #10P2144 #20P1374 #21P769 #22P800 #28P1471 #29P732 #30P705 T100")); delay(200);
    com.println(F("#8P1450 #9P1922 #10P1939 #20P1374 #21P1110 #22P1024 #28P1471 #29P1067 #30P908 T100")); delay(200);
  }

  void ssc_forward_low () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P2149 #6P2208 #8P1322 #9P2290 #10P2130 #12P1325 #13P1967 #14P2083 #20P1472 #21P808 #22P896 #24P1266 #25P853 #26P662 #28P1589 #29P709 #30P642 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P2149 #6P2208 #8P1322 #9P2290 #10P2130 #12P1325 #13P1967 #14P2083 #20P1472 #21P808 #22P896 #24P1266 #25P853 #26P662 #28P1589 #29P709 #30P642 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2085 #6P2058 #8P1578 #9P2290 #10P2130 #12P1126 #13P2022 #14P2215 #20P1251 #21P745 #22P731 #24P1534 #25P853 #26P662 #28P1377 #29P771 #30P792 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P2085 #6P2058 #8P1578 #9P2290 #10P2130 #12P1126 #13P2022 #14P2215 #20P1251 #21P745 #22P731 #24P1534 #25P853 #26P662 #28P1377 #29P771 #30P792 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_higher () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1619 #6P1874 #8P1322 #9P2831 #10P2331 #12P1325 #13P1574 #14P1827 #20P1472 #21P451 #22P733 #24P1266 #25P1360 #26P1001 #28P1589 #29P121 #30P400 T220"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1619 #6P1874 #8P1322 #9P1774 #10P1823 #12P1325 #13P1574 #14P1827 #20P1472 #21P1253 #22P1216 #24P1266 #25P1360 #26P1001 #28P1589 #29P1219 #30P976 T220"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2449 #6P2206 #8P1578 #9P1774 #10P1823 #12P1126 #13P2551 #14P2428 #20P1251 #21P1265 #22P1099 #24P1534 #25P323 #26P439 #28P1377 #29P1207 #30P1083 T220"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P1631 #6P1767 #8P1578 #9P1774 #10P1823 #12P1126 #13P1563 #14P1921 #20P1251 #21P1265 #22P1099 #24P1534 #25P1360 #26P1001 #28P1377 #29P1207 #30P1083 T220"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1770 #6P1988 #8P1322 #9P2093 #10P2031 #12P1325 #13P1695 #14P1920 #20P1472 #21P968 #22P994 #24P1266 #25P1213 #26P884 #28P1589 #29P906 #30P751 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1770 #6P1988 #8P1322 #9P1924 #10P1929 #12P1325 #13P1695 #14P1920 #20P1472 #21P1115 #22P1100 #24P1266 #25P1213 #26P884 #28P1589 #29P1073 #30P862 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P1922 #6P1969 #8P1578 #9P1924 #10P1929 #12P1126 #13P1844 #14P2119 #20P1251 #21P1116 #22P973 #24P1534 #25P1047 #26P771 #28P1377 #29P1072 #30P978 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P1771 #6P1872 #8P1578 #9P1924 #10P1929 #12P1126 #13P1695 #14P2021 #20P1251 #21P1116 #22P973 #24P1534 #25P1213 #26P884 #28P1377 #29P1072 #30P978 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_backward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1428 #5P1771 #6P1872 #8P1578 #9P2093 #10P2031 #12P1126 #13P1695 #14P2021 #20P1251 #21P947 #22P852 #24P1534 #25P1213 #26P884 #28P1377 #29P927 #30P881 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1428 #5P1771 #6P1872 #8P1578 #9P1924 #10P1929 #12P1126 #13P1695 #14P2021 #20P1251 #21P1116 #22P973 #24P1534 #25P1213 #26P884 #28P1377 #29P1072 #30P978 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1649 #5P1943 #6P2099 #8P1322 #9P1924 #10P1929 #12P1325 #13P1826 #14P2005 #20P1472 #21P1115 #22P1100 #24P1266 #25P1047 #26P771 #28P1589 #29P1073 #30P862 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1649 #5P1770 #6P1988 #8P1322 #9P1924 #10P1929 #12P1325 #13P1695 #14P1920 #20P1472 #21P1115 #22P1100 #24P1266 #25P1213 #26P884 #28P1589 #29P1073 #30P862 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1605 #5P1757 #6P1804 #8P1450 #9P2083 #10P2103 #12P1166 #13P1683 #14P1860 #20P1295 #21P992 #22P1074 #24P1400 #25P1238 #26P816 #28P1547 #29P951 #30P954 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1605 #5P1757 #6P1804 #8P1450 #9P1898 #10P1990 #12P1166 #13P1683 #14P1860 #20P1295 #21P1130 #22P1175 #24P1400 #25P1238 #26P816 #28P1547 #29P1086 #30P1046 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1470 #5P1943 #6P2105 #8P1450 #9P1914 #10P1800 #12P1287 #13P1844 #14P2125 #20P1430 #21P1118 #22P967 #24P1400 #25P1081 #26P929 #28P1418 #29P1074 #30P856 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1470 #5P1769 #6P1994 #8P1450 #9P1914 #10P1800 #12P1287 #13P1693 #14P2026 #20P1430 #21P1118 #22P967 #24P1400 #25P1222 #26P1026 #28P1418 #29P1074 #30P856 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1470 #5P1769 #6P1994 #8P1450 #9P2059 #10P1889 #12P1287 #13P1693 #14P2026 #20P1430 #21P947 #22P844 #24P1400 #25P1222 #26P1026 #28P1418 #29P907 #30P745 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1470 #5P1769 #6P1994 #8P1450 #9P1914 #10P1800 #12P1287 #13P1693 #14P2026 #20P1430 #21P1118 #22P967 #24P1400 #25P1222 #26P1026 #28P1418 #29P1074 #30P856 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1605 #5P1897 #6P1896 #8P1450 #9P1898 #10P1990 #12P1166 #13P1804 #14P1941 #20P1295 #21P1130 #22P1175 #24P1400 #25P1057 #26P692 #28P1547 #29P1086 #30P1046 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1605 #5P1757 #6P1804 #8P1450 #9P1898 #10P1990 #12P1166 #13P1683 #14P1860 #20P1295 #21P1130 #22P1175 #24P1400 #25P1238 #26P816 #28P1547 #29P1086 #30P1046 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1695 #5P1774 #6P1891 #8P1322 #9P2093 #10P2031 #12P1407 #13P1700 #14P1987 #20P1205 #21P962 #22P972 #24P1534 #25P1213 #26P884 #28P1289 #29P909 #30P796 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1695 #5P1774 #6P1891 #8P1322 #9P1924 #10P1929 #12P1407 #13P1700 #14P1987 #20P1205 #21P1113 #22P1080 #24P1534 #25P1213 #26P884 #28P1289 #29P1067 #30P901 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1337 #5P1941 #6P2054 #8P1578 #9P1924 #10P1929 #12P1084 #13P1830 #14P2023 #20P1563 #21P1110 #22P1016 #24P1266 #25P1047 #26P771 #28P1633 #29P1069 #30P959 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1337 #5P1776 #6P1949 #8P1578 #9P1924 #10P1929 #12P1084 #13P1698 #14P1936 #20P1563 #21P1110 #22P1016 #24P1266 #25P1213 #26P884 #28P1633 #29P1069 #30P959 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1337 #5P1776 #6P1949 #8P1578 #9P2093 #10P2031 #12P1084 #13P1698 #14P1936 #20P1563 #21P949 #22P901 #24P1266 #25P1213 #26P884 #28P1633 #29P922 #30P861 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1337 #5P1776 #6P1949 #8P1578 #9P1924 #10P1929 #12P1084 #13P1698 #14P1936 #20P1563 #21P1110 #22P1016 #24P1266 #25P1213 #26P884 #28P1633 #29P1069 #30P959 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1695 #5P1927 #6P1989 #8P1322 #9P1924 #10P1929 #12P1407 #13P1842 #14P2080 #20P1205 #21P1113 #22P1080 #24P1534 #25P1047 #26P771 #28P1289 #29P1067 #30P901 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1695 #5P1774 #6P1891 #8P1322 #9P1924 #10P1929 #12P1407 #13P1700 #14P1987 #20P1205 #21P1113 #22P1080 #24P1534 #25P1213 #26P884 #28P1289 #29P1067 #30P901 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1586 #5P1777 #6P1930 #8P1407 #9P2093 #10P2041 #12P1293 #13P1700 #14P1987 #20P1314 #21P953 #22P924 #24P1445 #25P1214 #26P874 #28P1411 #29P909 #30P796 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1586 #5P1777 #6P1930 #8P1407 #9P1922 #10P1938 #12P1293 #13P1700 #14P1987 #20P1314 #21P1110 #22P1037 #24P1445 #25P1214 #26P874 #28P1411 #29P1067 #30P901 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1463 #5P1941 #6P2054 #8P1493 #9P1922 #10P1938 #12P1183 #13P1839 #14P2061 #20P1437 #21P1110 #22P1016 #24P1355 #25P1047 #26P760 #28P1528 #29P1067 #30P920 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1463 #5P1776 #6P1949 #8P1493 #9P1922 #10P1938 #12P1183 #13P1700 #14P1970 #20P1437 #21P1110 #22P1016 #24P1355 #25P1214 #26P874 #28P1528 #29P1067 #30P920 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1463 #5P1776 #6P1949 #8P1493 #9P2093 #10P2041 #12P1183 #13P1700 #14P1970 #20P1437 #21P949 #22P901 #24P1355 #25P1214 #26P874 #28P1528 #29P912 #30P818 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1463 #5P1776 #6P1949 #8P1493 #9P1922 #10P1938 #12P1183 #13P1700 #14P1970 #20P1437 #21P1110 #22P1016 #24P1355 #25P1214 #26P874 #28P1528 #29P1067 #30P920 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1586 #5P1937 #6P2032 #8P1407 #9P1922 #10P1938 #12P1293 #13P1842 #14P2080 #20P1314 #21P1110 #22P1037 #24P1445 #25P1047 #26P760 #28P1411 #29P1067 #30P901 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1586 #5P1777 #6P1930 #8P1407 #9P1922 #10P1938 #12P1293 #13P1700 #14P1987 #20P1314 #21P1110 #22P1037 #24P1445 #25P1214 #26P874 #28P1411 #29P1067 #30P901 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1770 #6P1988 #8P1322 #9P2093 #10P2031 #12P1325 #13P1695 #14P1920 #20P1472 #21P968 #22P994 #24P1266 #25P1213 #26P884 #28P1589 #29P906 #30P751 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1770 #6P1988 #8P1322 #9P1924 #10P1929 #12P1325 #13P1695 #14P1920 #20P1472 #21P1115 #22P1100 #24P1266 #25P1213 #26P884 #28P1589 #29P1073 #30P862 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1337 #5P1941 #6P2054 #8P1578 #9P1924 #10P1929 #12P1084 #13P1830 #14P2023 #20P1563 #21P1110 #22P1016 #24P1266 #25P1047 #26P771 #28P1633 #29P1069 #30P959 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1337 #5P1776 #6P1949 #8P1578 #9P1924 #10P1929 #12P1084 #13P1698 #14P1936 #20P1563 #21P1110 #22P1016 #24P1266 #25P1213 #26P884 #28P1633 #29P1069 #30P959 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1770 #6P1988 #8P1322 #9P2093 #10P2031 #12P1325 #13P1695 #14P1920 #20P1472 #21P968 #22P994 #24P1266 #25P1213 #26P884 #28P1589 #29P906 #30P751 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1770 #6P1988 #8P1322 #9P1924 #10P1929 #12P1325 #13P1695 #14P1920 #20P1472 #21P1115 #22P1100 #24P1266 #25P1213 #26P884 #28P1589 #29P1073 #30P862 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1695 #5P1927 #6P1989 #8P1322 #9P1924 #10P1929 #12P1407 #13P1842 #14P2080 #20P1205 #21P1113 #22P1080 #24P1534 #25P1047 #26P771 #28P1289 #29P1067 #30P901 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1695 #5P1774 #6P1891 #8P1322 #9P1924 #10P1929 #12P1407 #13P1700 #14P1987 #20P1205 #21P1113 #22P1080 #24P1534 #25P1213 #26P884 #28P1289 #29P1067 #30P901 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  // END OF GENERATED


  void move (MoveType id) {
    if (millis() - state_lastMoveRecord > 99) {
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
