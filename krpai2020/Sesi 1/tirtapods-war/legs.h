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
        com.println(F("#4P1638 #5P2124 #6P2147 #8P1400 #9P2280 #10P2260 #12P1262 #13P1968 #14P2193 #20P1487 #21P832 #22P800 #24P1450 #25P848 #26P540 #28P1426 #29P849 #30P805 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1638 #5P2124 #6P2147 #8P1400 #9P2280 #10P2260 #12P1262 #13P1968 #14P2193 #20P1487 #21P832 #22P800 #24P1450 #25P848 #26P540 #28P1426 #29P849 #30P805 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1638 #5P2124 #6P2147 #8P1400 #9P2280 #10P2260 #12P1262 #13P1968 #14P2193 #20P1487 #21P832 #22P800 #24P1450 #25P848 #26P540 #28P1426 #29P849 #30P805 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1638 #5P2124 #6P2147 #8P1400 #9P2280 #10P2260 #12P1262 #13P1968 #14P2193 #20P1487 #21P832 #22P800 #24P1450 #25P848 #26P540 #28P1426 #29P849 #30P805 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1638 #5P2124 #6P2147 #12P1262 #13P1968 #14P2193 #24P1450 #25P848 #26P540 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1638 #5P1777 #6P1935 #12P1262 #13P1633 #14P2001 #24P1450 #25P1215 #26P780 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#8P1400 #9P2280 #10P2260 #20P1487 #21P832 #22P800 #28P1426 #29P849 #30P805 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#8P1400 #9P1898 #10P2020 #20P1487 #21P1167 #22P1024 #28P1426 #29P1150 #30P1008 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize_sync () {
    com.println(F("#4P1638 #5P2124 #6P2147 #12P1262 #13P1968 #14P2193 #24P1450 #25P848 #26P540 T200")); delay(200);
    com.println(F("#4P1638 #5P1777 #6P1935 #12P1262 #13P1633 #14P2001 #24P1450 #25P1215 #26P780 T200")); delay(200);
    com.println(F("#8P1400 #9P2280 #10P2260 #20P1487 #21P832 #22P800 #28P1426 #29P849 #30P805 T200")); delay(200);
    com.println(F("#8P1400 #9P1898 #10P2020 #20P1487 #21P1167 #22P1024 #28P1426 #29P1150 #30P1008 T200")); delay(200);
  }

  void ssc_forward_low () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1774 #5P2149 #6P2213 #8P1286 #9P2274 #10P2244 #12P1370 #13P1929 #14P2111 #20P1575 #21P871 #22P896 #24P1330 #25P853 #26P556 #28P1549 #29P828 #30P742 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1774 #5P2149 #6P2213 #8P1286 #9P2274 #10P2244 #12P1370 #13P1929 #14P2111 #20P1575 #21P871 #22P896 #24P1330 #25P853 #26P556 #28P1549 #29P828 #30P742 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1530 #5P2085 #6P2057 #8P1514 #9P2274 #10P2244 #12P1126 #13P1991 #14P2252 #20P1376 #21P809 #22P731 #24P1570 #25P853 #26P556 #28P1328 #29P883 #30P892 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1530 #5P2085 #6P2057 #8P1514 #9P2274 #10P2244 #12P1126 #13P1991 #14P2252 #20P1376 #21P809 #22P731 #24P1570 #25P853 #26P556 #28P1328 #29P883 #30P892 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_higher () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1774 #5P1619 #6P1865 #8P1286 #9P2825 #10P2479 #12P1370 #13P1493 #14P1837 #20P1575 #21P520 #22P733 #24P1330 #25P1360 #26P916 #28P1549 #29P299 #30P500 T240"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1774 #5P1619 #6P1865 #8P1286 #9P1747 #10P1884 #12P1370 #13P1493 #14P1837 #20P1575 #21P1307 #22P1216 #24P1330 #25P1360 #26P916 #28P1549 #29P1287 #30P1076 T240"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1530 #5P2449 #6P2211 #8P1514 #9P1747 #10P1884 #12P1126 #13P2579 #14P2479 #20P1376 #21P1319 #22P1099 #24P1570 #25P323 #26P321 #28P1328 #29P1276 #30P1183 T240"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1530 #5P1631 #6P1754 #8P1514 #9P1747 #10P1884 #12P1126 #13P1481 #14P1937 #20P1376 #21P1319 #22P1099 #24P1570 #25P1360 #26P916 #28P1328 #29P1276 #30P1183 T240"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1774 #5P1770 #6P1983 #8P1286 #9P2390 #10P2301 #12P1370 #13P1628 #14P1936 #20P1575 #21P787 #22P851 #24P1330 #25P1213 #26P792 #28P1549 #29P723 #30P686 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1774 #5P1770 #6P1983 #8P1286 #9P1900 #10P2008 #12P1370 #13P1628 #14P1936 #20P1575 #21P1172 #22P1100 #24P1330 #25P1213 #26P792 #28P1549 #29P1155 #30P962 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1530 #5P2171 #6P2099 #8P1514 #9P1900 #10P2008 #12P1126 #13P2107 #14P2304 #20P1376 #21P1173 #22P973 #24P1570 #25P742 #26P499 #28P1328 #29P1155 #30P1078 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1530 #5P1771 #6P1863 #8P1514 #9P1900 #10P2008 #12P1126 #13P1627 #14P2045 #20P1376 #21P1173 #22P973 #24P1570 #25P1213 #26P792 #28P1328 #29P1155 #30P1078 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_sync () {
    com.println(F("#4P1774 #5P1770 #6P1983 #8P1286 #9P2390 #10P2301 #12P1370 #13P1628 #14P1936 #20P1575 #21P787 #22P851 #24P1330 #25P1213 #26P792 #28P1549 #29P723 #30P686 T200")); delay(200);
    com.println(F("#4P1774 #5P1770 #6P1983 #8P1286 #9P1900 #10P2008 #12P1370 #13P1628 #14P1936 #20P1575 #21P1172 #22P1100 #24P1330 #25P1213 #26P792 #28P1549 #29P1155 #30P962 T200")); delay(200);
    com.println(F("#4P1530 #5P2171 #6P2099 #8P1514 #9P1900 #10P2008 #12P1126 #13P2107 #14P2304 #20P1376 #21P1173 #22P973 #24P1570 #25P742 #26P499 #28P1328 #29P1155 #30P1078 T200")); delay(200);
    com.println(F("#4P1530 #5P1771 #6P1863 #8P1514 #9P1900 #10P2008 #12P1126 #13P1627 #14P2045 #20P1376 #21P1173 #22P973 #24P1570 #25P1213 #26P792 #28P1328 #29P1155 #30P1078 T200")); delay(200);
  }

  void ssc_backward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1530 #5P1771 #6P1863 #8P1514 #9P2390 #10P2301 #12P1126 #13P1627 #14P2045 #20P1376 #21P693 #22P670 #24P1570 #25P1213 #26P792 #28P1328 #29P809 #30P851 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1530 #5P1771 #6P1863 #8P1514 #9P1900 #10P2008 #12P1126 #13P1627 #14P2045 #20P1376 #21P1173 #22P973 #24P1570 #25P1213 #26P792 #28P1328 #29P1155 #30P1078 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1774 #5P2270 #6P2271 #8P1286 #9P1900 #10P2008 #12P1370 #13P2013 #14P2150 #20P1575 #21P1172 #22P1100 #24P1330 #25P742 #26P499 #28P1549 #29P1155 #30P962 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1774 #5P1770 #6P1983 #8P1286 #9P1900 #10P2008 #12P1370 #13P1628 #14P1936 #20P1575 #21P1172 #22P1100 #24P1330 #25P1213 #26P792 #28P1549 #29P1155 #30P962 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_backward_sync () {
    com.println(F("#4P1530 #5P1771 #6P1863 #8P1514 #9P2390 #10P2301 #12P1126 #13P1627 #14P2045 #20P1376 #21P693 #22P670 #24P1570 #25P1213 #26P792 #28P1328 #29P809 #30P851 T200")); delay(200);
    com.println(F("#4P1530 #5P1771 #6P1863 #8P1514 #9P1900 #10P2008 #12P1126 #13P1627 #14P2045 #20P1376 #21P1173 #22P973 #24P1570 #25P1213 #26P792 #28P1328 #29P1155 #30P1078 T200")); delay(200);
    com.println(F("#4P1774 #5P2270 #6P2271 #8P1286 #9P1900 #10P2008 #12P1370 #13P2013 #14P2150 #20P1575 #21P1172 #22P1100 #24P1330 #25P742 #26P499 #28P1549 #29P1155 #30P962 T200")); delay(200);
    com.println(F("#4P1774 #5P1770 #6P1983 #8P1286 #9P1900 #10P2008 #12P1370 #13P1628 #14P1936 #20P1575 #21P1172 #22P1100 #24P1330 #25P1213 #26P792 #28P1549 #29P1155 #30P962 T200")); delay(200);
  }

  void ssc_shiftRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1725 #5P1757 #6P1793 #8P1400 #9P2459 #10P2427 #12P1175 #13P1614 #14P1872 #20P1416 #21P836 #22P943 #24P1450 #25P1238 #26P720 #28P1505 #29P852 #30P934 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1725 #5P1757 #6P1793 #8P1400 #9P1874 #10P2080 #12P1175 #13P1614 #14P1872 #20P1416 #21P1186 #22P1175 #24P1450 #25P1238 #26P720 #28P1505 #29P1167 #30P1146 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1577 #5P2275 #6P2280 #8P1400 #9P1890 #10P1858 #12P1323 #13P2113 #14P2313 #20P1537 #21P1174 #22P967 #24P1450 #25P851 #26P703 #28P1370 #29P1157 #30P956 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1577 #5P1769 #6P1989 #8P1400 #9P1890 #10P1858 #12P1323 #13P1626 #14P2050 #20P1537 #21P1174 #22P967 #24P1450 #25P1222 #26P942 #28P1370 #29P1157 #30P956 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1577 #5P1769 #6P1989 #8P1400 #9P2276 #10P2097 #12P1323 #13P1626 #14P2050 #20P1537 #21P687 #22P659 #24P1450 #25P1222 #26P942 #28P1370 #29P718 #30P677 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1577 #5P1769 #6P1989 #8P1400 #9P1890 #10P1858 #12P1323 #13P1626 #14P2050 #20P1537 #21P1174 #22P967 #24P1450 #25P1222 #26P942 #28P1370 #29P1157 #30P956 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1725 #5P2121 #6P2012 #8P1400 #9P1874 #10P2080 #12P1175 #13P1964 #14P2071 #20P1416 #21P1186 #22P1175 #24P1450 #25P675 #26P373 #28P1505 #29P1167 #30P1146 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1725 #5P1757 #6P1793 #8P1400 #9P1874 #10P2080 #12P1175 #13P1614 #14P1872 #20P1416 #21P1186 #22P1175 #24P1450 #25P1238 #26P720 #28P1505 #29P1167 #30P1146 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftLeftHigher () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1577 #5P1617 #6P1870 #8P1400 #9P2532 #10P2204 #12P1323 #13P1479 #14P1942 #20P1537 #21P185 #22P442 #24P1450 #25P1357 #26P1056 #28P1370 #29P266 #30P479 T240"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1577 #5P1617 #6P1870 #8P1400 #9P1750 #10P1744 #12P1323 #13P1479 #14P1942 #20P1537 #21P1321 #22P1093 #24P1450 #25P1357 #26P1056 #28P1370 #29P1289 #30P1071 T240"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1725 #5P2356 #6P2108 #8P1400 #9P1716 #10P1949 #12P1175 #13P2190 #14P2157 #20P1416 #21P1316 #22P1287 #24P1450 #25PNaN #26PNaN #28P1505 #29P1284 #30P1248 T240"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1725 #5P1621 #6P1687 #8P1400 #9P1716 #10P1949 #12P1175 #13P1484 #14P1776 #20P1416 #21P1316 #22P1287 #24P1450 #25P1391 #26P851 #28P1505 #29P1284 #30P1248 T240"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1825 #5P1774 #6P1882 #8P1286 #9P2274 #10P2244 #12P1470 #13P1633 #14P2008 #20P1334 #21P860 #22P871 #24P1570 #25P1213 #26P792 #28P1237 #29P846 #30P795 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1825 #5P1774 #6P1882 #8P1286 #9P1900 #10P2008 #12P1470 #13P1633 #14P2008 #20P1334 #21P1169 #22P1080 #24P1570 #25P1213 #26P792 #28P1237 #29P1150 #30P1001 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1430 #5P2128 #6P2157 #8P1514 #9P1900 #10P2008 #12P1075 #13P1940 #14P2132 #20P1657 #21P1167 #22P1016 #24P1330 #25P853 #26P556 #28P1595 #29P1152 #30P1059 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1430 #5P1776 #6P1943 #8P1514 #9P1900 #10P2008 #12P1075 #13P1631 #14P1953 #20P1657 #21P1167 #22P1016 #24P1330 #25P1213 #26P792 #28P1595 #29P1152 #30P1059 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW_sync () {
    com.println(F("#4P1825 #5P1774 #6P1882 #8P1286 #9P2274 #10P2244 #12P1470 #13P1633 #14P2008 #20P1334 #21P860 #22P871 #24P1570 #25P1213 #26P792 #28P1237 #29P846 #30P795 T200")); delay(200);
    com.println(F("#4P1825 #5P1774 #6P1882 #8P1286 #9P1900 #10P2008 #12P1470 #13P1633 #14P2008 #20P1334 #21P1169 #22P1080 #24P1570 #25P1213 #26P792 #28P1237 #29P1150 #30P1001 T200")); delay(200);
    com.println(F("#4P1430 #5P2128 #6P2157 #8P1514 #9P1900 #10P2008 #12P1075 #13P1940 #14P2132 #20P1657 #21P1167 #22P1016 #24P1330 #25P853 #26P556 #28P1595 #29P1152 #30P1059 T200")); delay(200);
    com.println(F("#4P1430 #5P1776 #6P1943 #8P1514 #9P1900 #10P2008 #12P1075 #13P1631 #14P1953 #20P1657 #21P1167 #22P1016 #24P1330 #25P1213 #26P792 #28P1595 #29P1152 #30P1059 T200")); delay(200);
  }

  void ssc_rotateCCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1430 #5P1776 #6P1943 #8P1514 #9P2274 #10P2244 #12P1075 #13P1631 #14P1953 #20P1657 #21P828 #22P790 #24P1330 #25P1213 #26P792 #28P1595 #29P874 #30P869 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1430 #5P1776 #6P1943 #8P1514 #9P1900 #10P2008 #12P1075 #13P1631 #14P1953 #20P1657 #21P1167 #22P1016 #24P1330 #25P1213 #26P792 #28P1595 #29P1152 #30P1059 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1825 #5P2095 #6P2080 #8P1286 #9P1900 #10P2008 #12P1470 #13P1972 #14P2202 #20P1334 #21P1169 #22P1080 #24P1570 #25P853 #26P556 #28P1237 #29P1150 #30P1001 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1825 #5P1774 #6P1882 #8P1286 #9P1900 #10P2008 #12P1470 #13P1633 #14P2008 #20P1334 #21P1169 #22P1080 #24P1570 #25P1213 #26P792 #28P1237 #29P1150 #30P1001 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCW_sync () {
    com.println(F("#4P1430 #5P1776 #6P1943 #8P1514 #9P2274 #10P2244 #12P1075 #13P1631 #14P1953 #20P1657 #21P828 #22P790 #24P1330 #25P1213 #26P792 #28P1595 #29P874 #30P869 T200")); delay(200);
    com.println(F("#4P1430 #5P1776 #6P1943 #8P1514 #9P1900 #10P2008 #12P1075 #13P1631 #14P1953 #20P1657 #21P1167 #22P1016 #24P1330 #25P1213 #26P792 #28P1595 #29P1152 #30P1059 T200")); delay(200);
    com.println(F("#4P1825 #5P2095 #6P2080 #8P1286 #9P1900 #10P2008 #12P1470 #13P1972 #14P2202 #20P1334 #21P1169 #22P1080 #24P1570 #25P853 #26P556 #28P1237 #29P1150 #30P1001 T200")); delay(200);
    com.println(F("#4P1825 #5P1774 #6P1882 #8P1286 #9P1900 #10P2008 #12P1470 #13P1633 #14P2008 #20P1334 #21P1169 #22P1080 #24P1570 #25P1213 #26P792 #28P1237 #29P1150 #30P1001 T200")); delay(200);
  }

  void ssc_rotateCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1704 #5P1777 #6P1923 #8P1361 #9P2279 #10P2258 #12P1330 #13P1633 #14P2008 #20P1433 #21P839 #22P817 #24P1490 #25P1214 #26P781 #28P1363 #29P846 #30P795 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1704 #5P1777 #6P1923 #8P1361 #9P1899 #10P2019 #12P1330 #13P1633 #14P2008 #20P1433 #21P1167 #22P1037 #24P1490 #25P1214 #26P781 #28P1363 #29P1150 #30P1001 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1570 #5P2128 #6P2157 #8P1439 #9P1899 #10P2019 #12P1196 #13P1961 #14P2178 #20P1543 #21P1167 #22P1016 #24P1410 #25P848 #26P542 #28P1486 #29P1150 #30P1020 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1570 #5P1776 #6P1943 #8P1439 #9P1899 #10P2019 #12P1196 #13P1633 #14P1990 #20P1543 #21P1167 #22P1016 #24P1410 #25P1214 #26P781 #28P1486 #29P1150 #30P1020 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1570 #5P1776 #6P1943 #8P1439 #9P2279 #10P2258 #12P1196 #13P1633 #14P1990 #20P1543 #21P828 #22P790 #24P1410 #25P1214 #26P781 #28P1486 #29P855 #30P820 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1570 #5P1776 #6P1943 #8P1439 #9P1899 #10P2019 #12P1196 #13P1633 #14P1990 #20P1543 #21P1167 #22P1016 #24P1410 #25P1214 #26P781 #28P1486 #29P1150 #30P1020 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1704 #5P2118 #6P2131 #8P1361 #9P1899 #10P2019 #12P1330 #13P1972 #14P2202 #20P1433 #21P1167 #22P1037 #24P1490 #25P848 #26P542 #28P1363 #29P1150 #30P1001 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1704 #5P1777 #6P1923 #8P1361 #9P1899 #10P2019 #12P1330 #13P1633 #14P2008 #20P1433 #21P1167 #22P1037 #24P1490 #25P1214 #26P781 #28P1363 #29P1150 #30P1001 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1774 #5P1770 #6P1983 #8P1286 #9P2274 #10P2244 #12P1370 #13P1628 #14P1936 #20P1575 #21P871 #22P896 #24P1330 #25P1213 #26P792 #28P1549 #29P828 #30P742 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1774 #5P1770 #6P1983 #8P1286 #9P1900 #10P2008 #12P1370 #13P1628 #14P1936 #20P1575 #21P1172 #22P1100 #24P1330 #25P1213 #26P792 #28P1549 #29P1155 #30P962 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1430 #5P2128 #6P2157 #8P1514 #9P1900 #10P2008 #12P1075 #13P1940 #14P2132 #20P1657 #21P1167 #22P1016 #24P1330 #25P853 #26P556 #28P1595 #29P1152 #30P1059 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1430 #5P1776 #6P1943 #8P1514 #9P1900 #10P2008 #12P1075 #13P1631 #14P1953 #20P1657 #21P1167 #22P1016 #24P1330 #25P1213 #26P792 #28P1595 #29P1152 #30P1059 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1774 #5P1770 #6P1983 #8P1286 #9P2274 #10P2244 #12P1370 #13P1628 #14P1936 #20P1575 #21P871 #22P896 #24P1330 #25P1213 #26P792 #28P1549 #29P828 #30P742 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1774 #5P1770 #6P1983 #8P1286 #9P1900 #10P2008 #12P1370 #13P1628 #14P1936 #20P1575 #21P1172 #22P1100 #24P1330 #25P1213 #26P792 #28P1549 #29P1155 #30P962 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1825 #5P2095 #6P2080 #8P1286 #9P1900 #10P2008 #12P1470 #13P1972 #14P2202 #20P1334 #21P1169 #22P1080 #24P1570 #25P853 #26P556 #28P1237 #29P1150 #30P1001 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1825 #5P1774 #6P1882 #8P1286 #9P1900 #10P2008 #12P1470 #13P1633 #14P2008 #20P1334 #21P1169 #22P1080 #24P1570 #25P1213 #26P792 #28P1237 #29P1150 #30P1001 T200"));
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
