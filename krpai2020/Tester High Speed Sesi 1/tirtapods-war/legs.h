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
        com.println(F("#4P1526 #5P2151 #6P2045 #8P1450 #9P2247 #10P1940 #12P1324 #13P2001 #14P2091 #20P1374 #21P786 #22P856 #24P1400 #25P867 #26P710 #28P1426 #29P732 #30P800 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1526 #5P2151 #6P2045 #8P1450 #9P2247 #10P1940 #12P1324 #13P2001 #14P2091 #20P1374 #21P786 #22P856 #24P1400 #25P867 #26P710 #28P1426 #29P732 #30P800 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1526 #5P2151 #6P2045 #8P1450 #9P2247 #10P1940 #12P1324 #13P2001 #14P2091 #20P1374 #21P786 #22P856 #24P1400 #25P867 #26P710 #28P1426 #29P732 #30P800 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1526 #5P2151 #6P2045 #8P1450 #9P2247 #10P1940 #12P1324 #13P2001 #14P2091 #20P1374 #21P786 #22P856 #24P1400 #25P867 #26P710 #28P1426 #29P732 #30P800 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1526 #5P2151 #6P2045 #12P1324 #13P2001 #14P2091 #24P1400 #25P867 #26P710 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1526 #5P1850 #6P1842 #12P1324 #13P1700 #14P1908 #24P1400 #25P1198 #26P906 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#8P1450 #9P2247 #10P1940 #20P1374 #21P786 #22P856 #28P1426 #29P732 #30P800 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#8P1450 #9P1909 #10P1744 #20P1374 #21P1093 #22P1052 #28P1426 #29P1067 #30P1024 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize_sync () {
    com.println(F("#4P1526 #5P2151 #6P2045 #12P1324 #13P2001 #14P2091 #24P1400 #25P867 #26P710 T100")); delay(100);
    com.println(F("#4P1526 #5P1850 #6P1842 #12P1324 #13P1700 #14P1908 #24P1400 #25P1198 #26P906 T100")); delay(100);
    com.println(F("#8P1450 #9P2247 #10P1940 #20P1374 #21P786 #22P856 #28P1426 #29P732 #30P800 T100")); delay(100);
    com.println(F("#8P1450 #9P1909 #10P1744 #20P1374 #21P1093 #22P1052 #28P1426 #29P1067 #30P1024 T100")); delay(100);
  }

  void ssc_forward_low () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P2172 #6P2108 #8P1322 #9P2242 #10P1927 #12P1422 #13P1967 #14P2012 #20P1472 #21P821 #22P940 #24P1272 #25P872 #26P723 #28P1549 #29P709 #30P731 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P2172 #6P2108 #8P1322 #9P2242 #10P1927 #12P1422 #13P1967 #14P2012 #20P1472 #21P821 #22P940 #24P1272 #25P872 #26P723 #28P1549 #29P709 #30P731 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2117 #6P1958 #8P1578 #9P2242 #10P1927 #12P1201 #13P2022 #14P2148 #20P1251 #21P764 #22P796 #24P1528 #25P872 #26P723 #28P1328 #29P771 #30P896 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P2117 #6P1958 #8P1578 #9P2242 #10P1927 #12P1201 #13P2022 #14P2148 #20P1251 #21P764 #22P796 #24P1528 #25P872 #26P723 #28P1328 #29P771 #30P896 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_higher () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1713 #6P1774 #8P1322 #9P2731 #10P2119 #12P1422 #13P1574 #14P1750 #20P1472 #21P499 #22P798 #24P1272 #25P1329 #26P1017 #28P1549 #29P121 #30P465 T220"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1713 #6P1774 #8P1322 #9P1775 #10P1633 #12P1422 #13P1574 #14P1750 #20P1472 #21P1222 #22P1220 #24P1272 #25P1329 #26P1017 #28P1549 #29P1219 #30P1099 T220"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2432 #6P2106 #8P1578 #9P1775 #10P1633 #12P1201 #13P2551 #14P2365 #20P1251 #21P1233 #22P1117 #24P1528 #25P393 #26P531 #28P1328 #29P1207 #30P1216 T220"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P1724 #6P1667 #8P1578 #9P1775 #10P1633 #12P1201 #13P1563 #14P1846 #20P1251 #21P1233 #22P1117 #24P1528 #25P1329 #26P1017 #28P1328 #29P1207 #30P1216 T220"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1682 #5P1850 #6P1826 #8P1338 #9P2128 #10P1805 #12P1374 #13P1683 #14P1787 #20P1424 #21P921 #22P1051 #24P1288 #25P1195 #26P977 #28P1582 #29P830 #30P875 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1682 #5P1850 #6P1826 #8P1338 #9P1912 #10P1673 #12P1374 #13P1683 #14P1787 #20P1424 #21P1110 #22P1180 #24P1288 #25P1195 #26P977 #28P1582 #29P1067 #30P1041 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1476 #5P1956 #6P1800 #8P1562 #9P1912 #10P1673 #12P1168 #13P1913 #14P2030 #20P1218 #21P1093 #22P1067 #24P1512 #25P983 #26P845 #28P1376 #29P1085 #30P1171 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1476 #5P1833 #6P1708 #8P1562 #9P1912 #10P1673 #12P1168 #13P1700 #14P1893 #20P1218 #21P1093 #22P1067 #24P1512 #25P1195 #26P977 #28P1376 #29P1085 #30P1171 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_sync () {
    com.println(F("#4P1682 #5P1850 #6P1826 #8P1338 #9P2128 #10P1805 #12P1374 #13P1683 #14P1787 #20P1424 #21P921 #22P1051 #24P1288 #25P1195 #26P977 #28P1582 #29P830 #30P875 T100")); delay(100);
    com.println(F("#4P1682 #5P1850 #6P1826 #8P1338 #9P1912 #10P1673 #12P1374 #13P1683 #14P1787 #20P1424 #21P1110 #22P1180 #24P1288 #25P1195 #26P977 #28P1582 #29P1067 #30P1041 T100")); delay(100);
    com.println(F("#4P1476 #5P1956 #6P1800 #8P1562 #9P1912 #10P1673 #12P1168 #13P1913 #14P2030 #20P1218 #21P1093 #22P1067 #24P1512 #25P983 #26P845 #28P1376 #29P1085 #30P1171 T100")); delay(100);
    com.println(F("#4P1476 #5P1833 #6P1708 #8P1562 #9P1912 #10P1673 #12P1168 #13P1700 #14P1893 #20P1218 #21P1093 #22P1067 #24P1512 #25P1195 #26P977 #28P1376 #29P1085 #30P1171 T100")); delay(100);
  }

  void ssc_backward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1476 #5P1833 #6P1708 #8P1562 #9P2128 #10P1805 #12P1168 #13P1700 #14P1893 #20P1218 #21P875 #22P922 #24P1512 #25P1195 #26P977 #28P1376 #29P879 #30P1023 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1476 #5P1833 #6P1708 #8P1562 #9P1912 #10P1673 #12P1168 #13P1700 #14P1893 #20P1218 #21P1093 #22P1067 #24P1512 #25P1195 #26P977 #28P1376 #29P1085 #30P1171 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1682 #5P2063 #6P1977 #8P1338 #9P1912 #10P1673 #12P1374 #13P1869 #14P1909 #20P1424 #21P1110 #22P1180 #24P1288 #25P983 #26P845 #28P1582 #29P1067 #30P1041 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1682 #5P1850 #6P1826 #8P1338 #9P1912 #10P1673 #12P1374 #13P1683 #14P1787 #20P1424 #21P1110 #22P1180 #24P1288 #25P1195 #26P977 #28P1582 #29P1067 #30P1041 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_backward_sync () {
    com.println(F("#4P1476 #5P1833 #6P1708 #8P1562 #9P2128 #10P1805 #12P1168 #13P1700 #14P1893 #20P1218 #21P875 #22P922 #24P1512 #25P1195 #26P977 #28P1376 #29P879 #30P1023 T100")); delay(100);
    com.println(F("#4P1476 #5P1833 #6P1708 #8P1562 #9P1912 #10P1673 #12P1168 #13P1700 #14P1893 #20P1218 #21P1093 #22P1067 #24P1512 #25P1195 #26P977 #28P1376 #29P1085 #30P1171 T100")); delay(100);
    com.println(F("#4P1682 #5P2063 #6P1977 #8P1338 #9P1912 #10P1673 #12P1374 #13P1869 #14P1909 #20P1424 #21P1110 #22P1180 #24P1288 #25P983 #26P845 #28P1582 #29P1067 #30P1041 T100")); delay(100);
    com.println(F("#4P1682 #5P1850 #6P1826 #8P1338 #9P1912 #10P1673 #12P1374 #13P1683 #14P1787 #20P1424 #21P1110 #22P1180 #24P1288 #25P1195 #26P977 #28P1582 #29P1067 #30P1041 T100")); delay(100);
  }

  void ssc_shiftRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1605 #5P1833 #6P1704 #8P1450 #9P2153 #10P1956 #12P1245 #13P1683 #14P1784 #20P1295 #21P922 #22P1055 #24P1400 #25P1219 #26P857 #28P1505 #29P881 #30P1027 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1605 #5P1833 #6P1704 #8P1450 #9P1888 #10P1793 #12P1245 #13P1683 #14P1784 #20P1295 #21P1111 #22P1184 #24P1400 #25P1219 #26P857 #28P1505 #29P1086 #30P1175 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1470 #5P2080 #6P2061 #8P1450 #9P1902 #10P1611 #12P1380 #13P1930 #14P2105 #20P1430 #21P1100 #22P1002 #24P1400 #25P1010 #26P915 #28P1370 #29P1074 #30P967 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1470 #5P1843 #6P1894 #8P1450 #9P1902 #10P1611 #12P1380 #13P1693 #14P1954 #20P1430 #21P1100 #22P1002 #24P1400 #25P1205 #26P1039 #28P1370 #29P1074 #30P967 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1470 #5P1843 #6P1894 #8P1450 #9P2101 #10P1735 #12P1380 #13P1693 #14P1954 #20P1430 #21P859 #22P842 #24P1400 #25P1205 #26P1039 #28P1370 #29P811 #30P783 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1470 #5P1843 #6P1894 #8P1450 #9P1902 #10P1611 #12P1380 #13P1693 #14P1954 #20P1430 #21P1100 #22P1002 #24P1400 #25P1205 #26P1039 #28P1370 #29P1074 #30P967 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1605 #5P2017 #6P1839 #8P1450 #9P1888 #10P1793 #12P1245 #13P1867 #14P1905 #20P1295 #21P1111 #22P1184 #24P1400 #25P959 #26P694 #28P1505 #29P1086 #30P1175 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1605 #5P1833 #6P1704 #8P1450 #9P1888 #10P1793 #12P1245 #13P1683 #14P1784 #20P1295 #21P1111 #22P1184 #24P1400 #25P1219 #26P857 #28P1505 #29P1086 #30P1175 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1695 #5P1848 #6P1791 #8P1338 #9P2053 #10P1763 #12P1513 #13P1700 #14P1914 #20P1205 #21P960 #22P1006 #24P1512 #25P1195 #26P977 #28P1237 #29P909 #30P901 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1695 #5P1848 #6P1791 #8P1338 #9P1912 #10P1673 #12P1513 #13P1700 #14P1914 #20P1205 #21P1096 #22P1101 #24P1512 #25P1195 #26P977 #28P1237 #29P1067 #30P1016 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1337 #5P1992 #6P1954 #8P1562 #9P1912 #10P1673 #12P1155 #13P1830 #14P1950 #20P1563 #21P1094 #22P1045 #24P1288 #25P1057 #26P887 #28P1595 #29P1069 #30P1080 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1337 #5P1850 #6P1849 #8P1562 #9P1912 #10P1673 #12P1155 #13P1698 #14P1862 #20P1563 #21P1094 #22P1045 #24P1288 #25P1195 #26P977 #28P1595 #29P1069 #30P1080 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW_sync () {
    com.println(F("#4P1695 #5P1848 #6P1791 #8P1338 #9P2053 #10P1763 #12P1513 #13P1700 #14P1914 #20P1205 #21P960 #22P1006 #24P1512 #25P1195 #26P977 #28P1237 #29P909 #30P901 T100")); delay(100);
    com.println(F("#4P1695 #5P1848 #6P1791 #8P1338 #9P1912 #10P1673 #12P1513 #13P1700 #14P1914 #20P1205 #21P1096 #22P1101 #24P1512 #25P1195 #26P977 #28P1237 #29P1067 #30P1016 T100")); delay(100);
    com.println(F("#4P1337 #5P1992 #6P1954 #8P1562 #9P1912 #10P1673 #12P1155 #13P1830 #14P1950 #20P1563 #21P1094 #22P1045 #24P1288 #25P1057 #26P887 #28P1595 #29P1069 #30P1080 T100")); delay(100);
    com.println(F("#4P1337 #5P1850 #6P1849 #8P1562 #9P1912 #10P1673 #12P1155 #13P1698 #14P1862 #20P1563 #21P1094 #22P1045 #24P1288 #25P1195 #26P977 #28P1595 #29P1069 #30P1080 T100")); delay(100);
  }

  void ssc_rotateCCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1337 #5P1850 #6P1849 #8P1562 #9P2053 #10P1763 #12P1155 #13P1698 #14P1862 #20P1563 #21P948 #22P944 #24P1288 #25P1195 #26P977 #28P1595 #29P922 #30P972 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1337 #5P1850 #6P1849 #8P1562 #9P1912 #10P1673 #12P1155 #13P1698 #14P1862 #20P1563 #21P1094 #22P1045 #24P1288 #25P1195 #26P977 #28P1595 #29P1069 #30P1080 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1695 #5P1980 #6P1889 #8P1338 #9P1912 #10P1673 #12P1513 #13P1842 #14P2009 #20P1205 #21P1096 #22P1101 #24P1512 #25P1057 #26P887 #28P1237 #29P1067 #30P1016 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1695 #5P1848 #6P1791 #8P1338 #9P1912 #10P1673 #12P1513 #13P1700 #14P1914 #20P1205 #21P1096 #22P1101 #24P1512 #25P1195 #26P977 #28P1237 #29P1067 #30P1016 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCW_sync () {
    com.println(F("#4P1337 #5P1850 #6P1849 #8P1562 #9P2053 #10P1763 #12P1155 #13P1698 #14P1862 #20P1563 #21P948 #22P944 #24P1288 #25P1195 #26P977 #28P1595 #29P922 #30P972 T100")); delay(100);
    com.println(F("#4P1337 #5P1850 #6P1849 #8P1562 #9P1912 #10P1673 #12P1155 #13P1698 #14P1862 #20P1563 #21P1094 #22P1045 #24P1288 #25P1195 #26P977 #28P1595 #29P1069 #30P1080 T100")); delay(100);
    com.println(F("#4P1695 #5P1980 #6P1889 #8P1338 #9P1912 #10P1673 #12P1513 #13P1842 #14P2009 #20P1205 #21P1096 #22P1101 #24P1512 #25P1057 #26P887 #28P1237 #29P1067 #30P1016 T100")); delay(100);
    com.println(F("#4P1695 #5P1848 #6P1791 #8P1338 #9P1912 #10P1673 #12P1513 #13P1700 #14P1914 #20P1205 #21P1096 #22P1101 #24P1512 #25P1195 #26P977 #28P1237 #29P1067 #30P1016 T100")); delay(100);
  }

  void ssc_rotateCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1622 #5P1844 #6P1761 #8P1412 #9P2055 #10P1772 #12P1387 #13P1700 #14P1914 #20P1278 #21P968 #22P1037 #24P1438 #25P1194 #26P969 #28P1363 #29P909 #30P901 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1622 #5P1844 #6P1761 #8P1412 #9P1913 #10P1681 #12P1387 #13P1700 #14P1914 #20P1278 #21P1100 #22P1129 #24P1438 #25P1194 #26P969 #28P1363 #29P1067 #30P1016 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1463 #5P1992 #6P1954 #8P1488 #9P1913 #10P1681 #12P1228 #13P1822 #14P1922 #20P1437 #21P1094 #22P1045 #24P1362 #25P1055 #26P878 #28P1522 #29P1074 #30P1113 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1463 #5P1850 #6P1849 #8P1488 #9P1913 #10P1681 #12P1228 #13P1694 #14P1835 #20P1437 #21P1094 #22P1045 #24P1362 #25P1194 #26P969 #28P1522 #29P1074 #30P1113 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1463 #5P1850 #6P1849 #8P1493 #9P2064 #10P1841 #12P1264 #13P1700 #14P1897 #20P1437 #21P948 #22P944 #24P1357 #25P1197 #26P907 #28P1486 #29P912 #30P924 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1463 #5P1850 #6P1849 #8P1493 #9P1909 #10P1743 #12P1264 #13P1700 #14P1897 #20P1437 #21P1094 #22P1045 #24P1357 #25P1197 #26P907 #28P1486 #29P1067 #30P1037 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1586 #5P1989 #6P1932 #8P1407 #9P1909 #10P1743 #12P1387 #13P1842 #14P2009 #20P1314 #21P1093 #22P1064 #24P1443 #25P1046 #26P809 #28P1363 #29P1067 #30P1016 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1586 #5P1850 #6P1830 #8P1407 #9P1909 #10P1743 #12P1387 #13P1700 #14P1914 #20P1314 #21P1093 #22P1064 #24P1443 #25P1197 #26P907 #28P1363 #29P1067 #30P1016 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1682 #5P1850 #6P1826 #8P1338 #9P2053 #10P1763 #12P1374 #13P1683 #14P1787 #20P1424 #21P985 #22P1092 #24P1288 #25P1195 #26P977 #28P1582 #29P913 #30P929 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1682 #5P1850 #6P1826 #8P1338 #9P1912 #10P1673 #12P1374 #13P1683 #14P1787 #20P1424 #21P1110 #22P1180 #24P1288 #25P1195 #26P977 #28P1582 #29P1067 #30P1041 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1337 #5P1992 #6P1954 #8P1562 #9P1912 #10P1673 #12P1155 #13P1830 #14P1950 #20P1563 #21P1094 #22P1045 #24P1288 #25P1057 #26P887 #28P1595 #29P1069 #30P1080 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1337 #5P1850 #6P1849 #8P1562 #9P1912 #10P1673 #12P1155 #13P1698 #14P1862 #20P1563 #21P1094 #22P1045 #24P1288 #25P1195 #26P977 #28P1595 #29P1069 #30P1080 T100"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1682 #5P1850 #6P1826 #8P1338 #9P2053 #10P1763 #12P1374 #13P1683 #14P1787 #20P1424 #21P985 #22P1092 #24P1288 #25P1195 #26P977 #28P1582 #29P913 #30P929 T100"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1682 #5P1850 #6P1826 #8P1338 #9P1912 #10P1673 #12P1374 #13P1683 #14P1787 #20P1424 #21P1110 #22P1180 #24P1288 #25P1195 #26P977 #28P1582 #29P1067 #30P1041 T100"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1695 #5P1980 #6P1889 #8P1338 #9P1912 #10P1673 #12P1513 #13P1842 #14P2009 #20P1205 #21P1096 #22P1101 #24P1512 #25P1057 #26P887 #28P1237 #29P1067 #30P1016 T100"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1695 #5P1848 #6P1791 #8P1338 #9P1912 #10P1673 #12P1513 #13P1700 #14P1914 #20P1205 #21P1096 #22P1101 #24P1512 #25P1195 #26P977 #28P1237 #29P1067 #30P1016 T100"));
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
