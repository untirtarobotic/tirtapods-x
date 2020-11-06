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
        com.println(F("#4P1526 #5P2124 #6P2093 #8P1450 #9P2291 #10P2136 #12P1237 #13P2018 #14P2193 #20P1374 #21P782 #22P802 #24P1400 #25P829 #26P650 #28P1471 #29P732 #30P705 T50"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1526 #5P2124 #6P2093 #8P1450 #9P2291 #10P2136 #12P1237 #13P2018 #14P2193 #20P1374 #21P782 #22P802 #24P1400 #25P829 #26P650 #28P1471 #29P732 #30P705 T50"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1526 #5P2124 #6P2093 #8P1450 #9P2291 #10P2136 #12P1237 #13P2018 #14P2193 #20P1374 #21P782 #22P802 #24P1400 #25P829 #26P650 #28P1471 #29P732 #30P705 T50"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1526 #5P2124 #6P2093 #8P1450 #9P2291 #10P2136 #12P1237 #13P2018 #14P2193 #20P1374 #21P782 #22P802 #24P1400 #25P829 #26P650 #28P1471 #29P732 #30P705 T50"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1526 #5P2124 #6P2093 #12P1237 #13P2018 #14P2193 #24P1400 #25P829 #26P650 T50"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1526 #5P1777 #6P1901 #12P1237 #13P1683 #14P2001 #24P1400 #25P1232 #26P868 T50"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#8P1450 #9P2291 #10P2136 #20P1374 #21P782 #22P802 #28P1471 #29P732 #30P705 T50"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#8P1450 #9P1888 #10P1905 #20P1374 #21P1097 #22P1018 #28P1471 #29P1067 #30P908 T50"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_low () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P2149 #6P2152 #8P1322 #9P2285 #10P2120 #12P1325 #13P1979 #14P2111 #20P1472 #21P818 #22P894 #24P1266 #25P835 #26P665 #28P1589 #29P709 #30P642 T50"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P2149 #6P2152 #8P1322 #9P2285 #10P2120 #12P1325 #13P1979 #14P2111 #20P1472 #21P818 #22P894 #24P1266 #25P835 #26P665 #28P1589 #29P709 #30P642 T50"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2085 #6P2011 #8P1578 #9P2285 #10P2120 #12P1126 #13P2041 #14P2252 #20P1251 #21P760 #22P735 #24P1534 #25P835 #26P665 #28P1377 #29P771 #30P792 T50"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P2085 #6P2011 #8P1578 #9P2285 #10P2120 #12P1126 #13P2041 #14P2252 #20P1251 #21P760 #22P735 #24P1534 #25P835 #26P665 #28P1377 #29P771 #30P792 T50"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_higher () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1619 #6P1837 #8P1322 #9P2867 #10P2347 #12P1325 #13P1543 #14P1837 #20P1472 #21P489 #22P737 #24P1266 #25P1391 #26P991 #28P1589 #29P121 #30P400 T240"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1619 #6P1837 #8P1322 #9P1729 #10P1774 #12P1325 #13P1543 #14P1837 #20P1472 #21P1229 #22P1203 #24P1266 #25P1391 #26P991 #28P1589 #29P1219 #30P976 T240"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2449 #6P2150 #8P1578 #9P1729 #10P1774 #12P1126 #13P2629 #14P2479 #20P1251 #21P1239 #22P1090 #24P1534 #25P253 #26P451 #28P1377 #29P1207 #30P1083 T240"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P1631 #6P1737 #8P1578 #9P1729 #10P1774 #12P1126 #13P1531 #14P1937 #20P1251 #21P1239 #22P1090 #24P1534 #25P1391 #26P991 #28P1377 #29P1207 #30P1083 T240"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1770 #6P1945 #8P1322 #9P2407 #10P2176 #12P1325 #13P1678 #14P1936 #20P1472 #21P740 #22P851 #24P1266 #25P1230 #26P879 #28P1589 #29P593 #30P586 T50"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1770 #6P1945 #8P1322 #9P1890 #10P1893 #12P1325 #13P1678 #14P1936 #20P1472 #21P1101 #22P1091 #24P1266 #25P1230 #26P879 #28P1589 #29P1073 #30P862 T50"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2171 #6P2050 #8P1578 #9P1890 #10P1893 #12P1126 #13P2157 #14P2304 #20P1251 #21P1102 #22P969 #24P1534 #25P713 #26P612 #28P1377 #29P1072 #30P978 T50"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P1771 #6P1836 #8P1578 #9P1890 #10P1893 #12P1126 #13P1677 #14P2045 #20P1251 #21P1102 #22P969 #24P1534 #25P1230 #26P879 #28P1377 #29P1072 #30P978 T50"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_backward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1428 #5P1771 #6P1836 #8P1578 #9P2407 #10P2176 #12P1126 #13P1677 #14P2045 #20P1251 #21P651 #22P676 #24P1534 #25P1230 #26P879 #28P1377 #29P687 #30P751 T50"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1428 #5P1771 #6P1836 #8P1578 #9P1890 #10P1893 #12P1126 #13P1677 #14P2045 #20P1251 #21P1102 #22P969 #24P1534 #25P1230 #26P879 #28P1377 #29P1072 #30P978 T50"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1649 #5P2270 #6P2204 #8P1322 #9P1890 #10P1893 #12P1325 #13P2063 #14P2150 #20P1472 #21P1101 #22P1091 #24P1266 #25P713 #26P612 #28P1589 #29P1073 #30P862 T50"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1649 #5P1770 #6P1945 #8P1322 #9P1890 #10P1893 #12P1325 #13P1678 #14P1936 #20P1472 #21P1101 #22P1091 #24P1266 #25P1230 #26P879 #28P1589 #29P1073 #30P862 T50"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1605 #5P1757 #6P1772 #8P1450 #9P2481 #10P2297 #12P1166 #13P1664 #14P1872 #20P1295 #21P785 #22P939 #24P1400 #25P1257 #26P813 #28P1547 #29P736 #30P834 T50"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1605 #5P1757 #6P1772 #8P1450 #9P1863 #10P1963 #12P1166 #13P1664 #14P1872 #20P1295 #21P1115 #22P1163 #24P1400 #25P1257 #26P813 #28P1547 #29P1086 #30P1046 T50"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1470 #5P2275 #6P2213 #8P1450 #9P1880 #10P1748 #12P1287 #13P2163 #14P2313 #20P1430 #21P1104 #22P963 #24P1400 #25P832 #26P798 #28P1418 #29P1074 #30P856 T50"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1470 #5P1769 #6P1950 #8P1450 #9P1880 #10P1748 #12P1287 #13P1676 #14P2050 #20P1430 #21P1104 #22P963 #24P1400 #25P1240 #26P1016 #28P1418 #29P1074 #30P856 T50"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1470 #5P1769 #6P1950 #8P1450 #9P2288 #10P1979 #12P1287 #13P1676 #14P2050 #20P1430 #21P646 #22P666 #24P1400 #25P1240 #26P1016 #28P1418 #29P587 #30P577 T50"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1470 #5P1769 #6P1950 #8P1450 #9P1880 #10P1748 #12P1287 #13P1676 #14P2050 #20P1430 #21P1104 #22P963 #24P1400 #25P1240 #26P1016 #28P1418 #29P1074 #30P856 T50"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1605 #5P2121 #6P1971 #8P1450 #9P1863 #10P1963 #12P1166 #13P2014 #14P2071 #20P1295 #21P1115 #22P1163 #24P1400 #25P639 #26P498 #28P1547 #29P1086 #30P1046 T50"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1605 #5P1757 #6P1772 #8P1450 #9P1863 #10P1963 #12P1166 #13P1664 #14P1872 #20P1295 #21P1115 #22P1163 #24P1400 #25P1257 #26P813 #28P1547 #29P1086 #30P1046 T50"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftLeftHigher () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1470 #5P1617 #6P1842 #8P1450 #9P2558 #10P2082 #12P1287 #13P1529 #14P1942 #20P1430 #21P174 #22P456 #24P1400 #25P1388 #26P1119 #28P1418 #29P85 #30P379 T240"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1470 #5P1617 #6P1842 #8P1450 #9P1732 #10P1639 #12P1287 #13P1529 #14P1942 #20P1430 #21P1241 #22P1084 #24P1400 #25P1388 #26P1119 #28P1418 #29P1221 #30P971 T240"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1605 #5P2356 #6P2057 #8P1450 #9P1695 #10P1836 #12P1166 #13P2240 #14P2157 #20P1295 #21P1237 #22P1271 #24P1400 #25PNaN #26PNaN #28P1547 #29P1216 #30P1148 T240"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1605 #5P1621 #6P1676 #8P1450 #9P1695 #10P1836 #12P1166 #13P1534 #14P1776 #20P1295 #21P1237 #22P1271 #24P1400 #25P1425 #26P933 #28P1547 #29P1216 #30P1148 T240"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1695 #5P1774 #6P1853 #8P1322 #9P2285 #10P2120 #12P1407 #13P1683 #14P2008 #20P1205 #21P809 #22P870 #24P1534 #25P1230 #26P879 #28P1289 #29P728 #30P695 T50"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1695 #5P1774 #6P1853 #8P1322 #9P1890 #10P1893 #12P1407 #13P1683 #14P2008 #20P1205 #21P1099 #22P1072 #24P1534 #25P1230 #26P879 #28P1289 #29P1067 #30P901 T50"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1337 #5P2128 #6P2102 #8P1578 #9P1890 #10P1893 #12P1084 #13P1990 #14P2132 #20P1563 #21P1097 #22P1010 #24P1266 #25P835 #26P665 #28P1633 #29P1069 #30P959 T50"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1337 #5P1776 #6P1908 #8P1578 #9P1890 #10P1893 #12P1084 #13P1681 #14P1953 #20P1563 #21P1097 #22P1010 #24P1266 #25P1230 #26P879 #28P1633 #29P1069 #30P959 T50"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1337 #5P1776 #6P1908 #8P1578 #9P2285 #10P2120 #12P1084 #13P1681 #14P1953 #20P1563 #21P779 #22P792 #24P1266 #25P1230 #26P879 #28P1633 #29P760 #30P769 T50"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1337 #5P1776 #6P1908 #8P1578 #9P1890 #10P1893 #12P1084 #13P1681 #14P1953 #20P1563 #21P1097 #22P1010 #24P1266 #25P1230 #26P879 #28P1633 #29P1069 #30P959 T50"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1695 #5P2095 #6P2032 #8P1322 #9P1890 #10P1893 #12P1407 #13P2022 #14P2202 #20P1205 #21P1099 #22P1072 #24P1534 #25P835 #26P665 #28P1289 #29P1067 #30P901 T50"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1695 #5P1774 #6P1853 #8P1322 #9P1890 #10P1893 #12P1407 #13P1683 #14P2008 #20P1205 #21P1099 #22P1072 #24P1534 #25P1230 #26P879 #28P1289 #29P1067 #30P901 T50"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1586 #5P1777 #6P1890 #8P1407 #9P2290 #10P2134 #12P1293 #13P1683 #14P2008 #20P1314 #21P788 #22P818 #24P1445 #25P1232 #26P869 #28P1411 #29P728 #30P695 T50"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1586 #5P1777 #6P1890 #8P1407 #9P1888 #10P1903 #12P1293 #13P1683 #14P2008 #20P1314 #21P1097 #22P1031 #24P1445 #25P1232 #26P869 #28P1411 #29P1067 #30P901 T50"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1463 #5P2128 #6P2102 #8P1493 #9P1888 #10P1903 #12P1183 #13P2011 #14P2178 #20P1437 #21P1097 #22P1010 #24P1355 #25P830 #26P652 #28P1528 #29P1067 #30P920 T50"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1463 #5P1776 #6P1908 #8P1493 #9P1888 #10P1903 #12P1183 #13P1683 #14P1990 #20P1437 #21P1097 #22P1010 #24P1355 #25P1232 #26P869 #28P1528 #29P1067 #30P920 T50"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1463 #5P1776 #6P1908 #8P1493 #9P2290 #10P2134 #12P1183 #13P1683 #14P1990 #20P1437 #21P779 #22P792 #24P1355 #25P1232 #26P869 #28P1528 #29P739 #30P720 T50"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1463 #5P1776 #6P1908 #8P1493 #9P1888 #10P1903 #12P1183 #13P1683 #14P1990 #20P1437 #21P1097 #22P1010 #24P1355 #25P1232 #26P869 #28P1528 #29P1067 #30P920 T50"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1586 #5P2118 #6P2078 #8P1407 #9P1888 #10P1903 #12P1293 #13P2022 #14P2202 #20P1314 #21P1097 #22P1031 #24P1445 #25P830 #26P652 #28P1411 #29P1067 #30P901 T50"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1586 #5P1777 #6P1890 #8P1407 #9P1888 #10P1903 #12P1293 #13P1683 #14P2008 #20P1314 #21P1097 #22P1031 #24P1445 #25P1232 #26P869 #28P1411 #29P1067 #30P901 T50"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1770 #6P1945 #8P1322 #9P2285 #10P2120 #12P1325 #13P1678 #14P1936 #20P1472 #21P818 #22P894 #24P1266 #25P1230 #26P879 #28P1589 #29P709 #30P642 T50"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1770 #6P1945 #8P1322 #9P1890 #10P1893 #12P1325 #13P1678 #14P1936 #20P1472 #21P1101 #22P1091 #24P1266 #25P1230 #26P879 #28P1589 #29P1073 #30P862 T50"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1337 #5P2128 #6P2102 #8P1578 #9P1890 #10P1893 #12P1084 #13P1990 #14P2132 #20P1563 #21P1097 #22P1010 #24P1266 #25P835 #26P665 #28P1633 #29P1069 #30P959 T50"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1337 #5P1776 #6P1908 #8P1578 #9P1890 #10P1893 #12P1084 #13P1681 #14P1953 #20P1563 #21P1097 #22P1010 #24P1266 #25P1230 #26P879 #28P1633 #29P1069 #30P959 T50"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1770 #6P1945 #8P1322 #9P2285 #10P2120 #12P1325 #13P1678 #14P1936 #20P1472 #21P818 #22P894 #24P1266 #25P1230 #26P879 #28P1589 #29P709 #30P642 T50"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1770 #6P1945 #8P1322 #9P1890 #10P1893 #12P1325 #13P1678 #14P1936 #20P1472 #21P1101 #22P1091 #24P1266 #25P1230 #26P879 #28P1589 #29P1073 #30P862 T50"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1695 #5P2095 #6P2032 #8P1322 #9P1890 #10P1893 #12P1407 #13P2022 #14P2202 #20P1205 #21P1099 #22P1072 #24P1534 #25P835 #26P665 #28P1289 #29P1067 #30P901 T50"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1695 #5P1774 #6P1853 #8P1322 #9P1890 #10P1893 #12P1407 #13P1683 #14P2008 #20P1205 #21P1099 #22P1072 #24P1534 #25P1230 #26P879 #28P1289 #29P1067 #30P901 T50"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  // END OF GENERATED
  
  void move (MoveType id) {
    if (millis() - state_lastMoveRecord > 49) {
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
