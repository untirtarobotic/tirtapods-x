#include <SoftwareSerial.h>

namespace legs {
  bool isNormalized = false;
  bool isStandby = false;

  enum MoveType {
    STANDBY,
    NORMALIZE,
    FORWARD,
    FORWARD_LOW,
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
        com.println(F("#4P1526 #5P2148 #6P1999 #8P1450 #9P2222 #10P2006 #12P1324 #13P2148 #14P1999 #20P1374 #21P752 #22P901 #24P1500 #25P828 #26P744 #28P1526 #29P752 #30P981 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1526 #5P2148 #6P1999 #8P1450 #9P2222 #10P2006 #12P1324 #13P2148 #14P1999 #20P1374 #21P752 #22P901 #24P1500 #25P828 #26P744 #28P1526 #29P752 #30P981 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1526 #5P2148 #6P1999 #8P1450 #9P2222 #10P2006 #12P1324 #13P2148 #14P1999 #20P1374 #21P752 #22P901 #24P1500 #25P828 #26P744 #28P1526 #29P752 #30P981 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1526 #5P2148 #6P1999 #8P1450 #9P2222 #10P2006 #12P1324 #13P2148 #14P1999 #20P1374 #21P752 #22P901 #24P1500 #25P828 #26P744 #28P1526 #29P752 #30P981 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1526 #5P2148 #6P1999 #12P1324 #13P2148 #14P1999 #24P1500 #25P828 #26P744 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1526 #5P1832 #6P1806 #12P1324 #13P1832 #14P1806 #24P1500 #25P1167 #26P951 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#8P1450 #9P2222 #10P2006 #20P1374 #21P752 #22P901 #28P1526 #29P752 #30P981 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#8P1450 #9P1883 #10P1799 #20P1374 #21P1068 #22P1094 #28P1526 #29P1068 #30P1206 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize_sync () {
    com.println(F("#4P1526 #5P2148 #6P1999 #12P1324 #13P2148 #14P1999 #24P1500 #25P828 #26P744 T200")); delay(200);
    com.println(F("#4P1526 #5P1832 #6P1806 #12P1324 #13P1832 #14P1806 #24P1500 #25P1167 #26P951 T200")); delay(200);
    com.println(F("#8P1450 #9P2222 #10P2006 #20P1374 #21P752 #22P901 #28P1526 #29P752 #30P981 T200")); delay(200);
    com.println(F("#8P1450 #9P1883 #10P1799 #20P1374 #21P1068 #22P1094 #28P1526 #29P1068 #30P1206 T200")); delay(200);
  }

  void ssc_forward_low () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P2175 #6P2065 #8P1308 #9P2216 #10P1990 #12P1422 #13P2106 #14P1909 #20P1472 #21P794 #22P991 #24P1358 #25P834 #26P760 #28P1649 #29P725 #30P905 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P2175 #6P2065 #8P1308 #9P2216 #10P1990 #12P1422 #13P2106 #14P1909 #20P1472 #21P794 #22P991 #24P1358 #25P834 #26P760 #28P1649 #29P725 #30P905 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2106 #6P1909 #8P1592 #9P2216 #10P1990 #12P1201 #13P2175 #14P2065 #20P1251 #21P725 #22P835 #24P1642 #25P834 #26P760 #28P1428 #29P794 #30P1085 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P2106 #6P1909 #8P1592 #9P2216 #10P1990 #12P1201 #13P2175 #14P2065 #20P1251 #21P725 #22P835 #24P1642 #25P834 #26P760 #28P1428 #29P794 #30P1085 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1832 #6P1856 #8P1308 #9P2216 #10P1990 #12P1422 #13P1820 #14P1731 #20P1472 #21P794 #22P991 #24P1358 #25P1167 #26P962 #28P1649 #29P725 #30P905 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1832 #6P1856 #8P1308 #9P1883 #10P1788 #12P1422 #13P1820 #14P1731 #20P1472 #21P1080 #22P1169 #24P1358 #25P1167 #26P962 #28P1649 #29P1068 #30P1147 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1428 #5P2106 #6P1909 #8P1592 #9P1883 #10P1788 #12P1201 #13P2175 #14P2065 #20P1251 #21P1068 #22P1044 #24P1642 #25P834 #26P760 #28P1428 #29P1080 #30P1292 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1428 #5P1820 #6P1731 #8P1592 #9P1883 #10P1788 #12P1201 #13P1832 #14P1856 #20P1251 #21P1068 #22P1044 #24P1642 #25P1167 #26P962 #28P1428 #29P1080 #30P1292 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_sync () {
    com.println(F("#4P1649 #5P1832 #6P1856 #8P1308 #9P2216 #10P1990 #12P1422 #13P1820 #14P1731 #20P1472 #21P794 #22P991 #24P1358 #25P1167 #26P962 #28P1649 #29P725 #30P905 T200")); delay(200);
    com.println(F("#4P1649 #5P1832 #6P1856 #8P1308 #9P1883 #10P1788 #12P1422 #13P1820 #14P1731 #20P1472 #21P1080 #22P1169 #24P1358 #25P1167 #26P962 #28P1649 #29P1068 #30P1147 T200")); delay(200);
    com.println(F("#4P1428 #5P2106 #6P1909 #8P1592 #9P1883 #10P1788 #12P1201 #13P2175 #14P2065 #20P1251 #21P1068 #22P1044 #24P1642 #25P834 #26P760 #28P1428 #29P1080 #30P1292 T200")); delay(200);
    com.println(F("#4P1428 #5P1820 #6P1731 #8P1592 #9P1883 #10P1788 #12P1201 #13P1832 #14P1856 #20P1251 #21P1068 #22P1044 #24P1642 #25P1167 #26P962 #28P1428 #29P1080 #30P1292 T200")); delay(200);
  }

  void ssc_backward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1428 #5P1820 #6P1731 #8P1592 #9P2216 #10P1990 #12P1201 #13P1832 #14P1856 #20P1251 #21P725 #22P835 #24P1642 #25P1167 #26P962 #28P1428 #29P794 #30P1085 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1428 #5P1820 #6P1731 #8P1592 #9P1883 #10P1788 #12P1201 #13P1832 #14P1856 #20P1251 #21P1068 #22P1044 #24P1642 #25P1167 #26P962 #28P1428 #29P1080 #30P1292 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1649 #5P2175 #6P2065 #8P1308 #9P1883 #10P1788 #12P1422 #13P2106 #14P1909 #20P1472 #21P1080 #22P1169 #24P1358 #25P834 #26P760 #28P1649 #29P1068 #30P1147 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1649 #5P1832 #6P1856 #8P1308 #9P1883 #10P1788 #12P1422 #13P1820 #14P1731 #20P1472 #21P1080 #22P1169 #24P1358 #25P1167 #26P962 #28P1649 #29P1068 #30P1147 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_backward_sync () {
    com.println(F("#4P1428 #5P1820 #6P1731 #8P1592 #9P2216 #10P1990 #12P1201 #13P1832 #14P1856 #20P1251 #21P725 #22P835 #24P1642 #25P1167 #26P962 #28P1428 #29P794 #30P1085 T200")); delay(200);
    com.println(F("#4P1428 #5P1820 #6P1731 #8P1592 #9P1883 #10P1788 #12P1201 #13P1832 #14P1856 #20P1251 #21P1068 #22P1044 #24P1642 #25P1167 #26P962 #28P1428 #29P1080 #30P1292 T200")); delay(200);
    com.println(F("#4P1649 #5P2175 #6P2065 #8P1308 #9P1883 #10P1788 #12P1422 #13P2106 #14P1909 #20P1472 #21P1080 #22P1169 #24P1358 #25P834 #26P760 #28P1649 #29P1068 #30P1147 T200")); delay(200);
    com.println(F("#4P1649 #5P1832 #6P1856 #8P1308 #9P1883 #10P1788 #12P1422 #13P1820 #14P1731 #20P1472 #21P1080 #22P1169 #24P1358 #25P1167 #26P962 #28P1649 #29P1068 #30P1147 T200")); delay(200);
  }

  void ssc_shiftRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1605 #5P1801 #6P1659 #8P1450 #9P2252 #10P2092 #12P1245 #13P1801 #14P1659 #20P1295 #21P835 #22P1073 #24P1500 #25P1180 #26P889 #28P1605 #29P835 #30P1181 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1605 #5P1801 #6P1659 #8P1450 #9P1870 #10P1861 #12P1245 #13P1801 #14P1659 #20P1295 #21P1099 #22P1241 #24P1500 #25P1180 #26P889 #28P1605 #29P1099 #30P1376 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1470 #5P2179 #6P2073 #8P1450 #9P1860 #10P1641 #12P1380 #13P2179 #14P2073 #20P1430 #21P1068 #22P1038 #24P1500 #25P917 #26P937 #28P1470 #29P1068 #30P1140 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1470 #5P1832 #6P1862 #8P1450 #9P1860 #10P1641 #12P1380 #13P1832 #14P1862 #20P1430 #21P1068 #22P1038 #24P1500 #25P1190 #26P1109 #28P1470 #29P1068 #30P1140 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1470 #5P1832 #6P1862 #8P1450 #9P2133 #10P1813 #12P1380 #13P1832 #14P1862 #20P1430 #21P721 #22P827 #24P1500 #25P1190 #26P1109 #28P1470 #29P721 #30P895 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1470 #5P1832 #6P1862 #8P1450 #9P1860 #10P1641 #12P1380 #13P1832 #14P1862 #20P1430 #21P1068 #22P1038 #24P1500 #25P1190 #26P1109 #28P1470 #29P1068 #30P1140 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1605 #5P2065 #6P1827 #8P1450 #9P1870 #10P1861 #12P1245 #13P2065 #14P1827 #20P1295 #21P1099 #22P1241 #24P1500 #25P798 #26P658 #28P1605 #29P1099 #30P1376 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1605 #5P1801 #6P1659 #8P1450 #9P1870 #10P1861 #12P1245 #13P1801 #14P1659 #20P1295 #21P1099 #22P1241 #24P1500 #25P1180 #26P889 #28P1605 #29P1099 #30P1376 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1695 #5P1824 #6P1751 #8P1308 #9P2216 #10P1990 #12P1513 #13P1833 #14P1813 #20P1205 #21P783 #22P968 #24P1642 #25P1167 #26P962 #28P1337 #29P748 #30P970 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1695 #5P1824 #6P1751 #8P1308 #9P1883 #10P1788 #12P1513 #13P1833 #14P1813 #20P1205 #21P1076 #22P1149 #24P1642 #25P1167 #26P962 #28P1337 #29P1067 #30P1197 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1337 #5P2152 #6P2009 #8P1592 #9P1883 #10P1788 #12P1155 #13P2117 #14P1932 #20P1563 #21P1067 #22P1087 #24P1358 #25P834 #26P760 #28P1695 #29P1076 #30P1269 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1337 #5P1833 #6P1813 #8P1592 #9P1883 #10P1788 #12P1155 #13P1824 #14P1751 #20P1563 #21P1067 #22P1087 #24P1358 #25P1167 #26P962 #28P1695 #29P1076 #30P1269 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW_sync () {
    com.println(F("#4P1695 #5P1824 #6P1751 #8P1308 #9P2216 #10P1990 #12P1513 #13P1833 #14P1813 #20P1205 #21P783 #22P968 #24P1642 #25P1167 #26P962 #28P1337 #29P748 #30P970 T200")); delay(200);
    com.println(F("#4P1695 #5P1824 #6P1751 #8P1308 #9P1883 #10P1788 #12P1513 #13P1833 #14P1813 #20P1205 #21P1076 #22P1149 #24P1642 #25P1167 #26P962 #28P1337 #29P1067 #30P1197 T200")); delay(200);
    com.println(F("#4P1337 #5P2152 #6P2009 #8P1592 #9P1883 #10P1788 #12P1155 #13P2117 #14P1932 #20P1563 #21P1067 #22P1087 #24P1358 #25P834 #26P760 #28P1695 #29P1076 #30P1269 T200")); delay(200);
    com.println(F("#4P1337 #5P1833 #6P1813 #8P1592 #9P1883 #10P1788 #12P1155 #13P1824 #14P1751 #20P1563 #21P1067 #22P1087 #24P1358 #25P1167 #26P962 #28P1695 #29P1076 #30P1269 T200")); delay(200);
  }

  void ssc_rotateCCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1337 #5P1833 #6P1813 #8P1592 #9P2216 #10P1990 #12P1155 #13P1824 #14P1751 #20P1563 #21P748 #22P891 #24P1358 #25P1167 #26P962 #28P1695 #29P783 #30P1058 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1337 #5P1833 #6P1813 #8P1592 #9P1883 #10P1788 #12P1155 #13P1824 #14P1751 #20P1563 #21P1067 #22P1087 #24P1358 #25P1167 #26P962 #28P1695 #29P1076 #30P1269 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1695 #5P2117 #6P1932 #8P1308 #9P1883 #10P1788 #12P1513 #13P2152 #14P2009 #20P1205 #21P1076 #22P1149 #24P1642 #25P834 #26P760 #28P1337 #29P1067 #30P1197 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1695 #5P1824 #6P1751 #8P1308 #9P1883 #10P1788 #12P1513 #13P1833 #14P1813 #20P1205 #21P1076 #22P1149 #24P1642 #25P1167 #26P962 #28P1337 #29P1067 #30P1197 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCW_sync () {
    com.println(F("#4P1337 #5P1833 #6P1813 #8P1592 #9P2216 #10P1990 #12P1155 #13P1824 #14P1751 #20P1563 #21P748 #22P891 #24P1358 #25P1167 #26P962 #28P1695 #29P783 #30P1058 T200")); delay(200);
    com.println(F("#4P1337 #5P1833 #6P1813 #8P1592 #9P1883 #10P1788 #12P1155 #13P1824 #14P1751 #20P1563 #21P1067 #22P1087 #24P1358 #25P1167 #26P962 #28P1695 #29P1076 #30P1269 T200")); delay(200);
    com.println(F("#4P1695 #5P2117 #6P1932 #8P1308 #9P1883 #10P1788 #12P1513 #13P2152 #14P2009 #20P1205 #21P1076 #22P1149 #24P1642 #25P834 #26P760 #28P1337 #29P1067 #30P1197 T200")); delay(200);
    com.println(F("#4P1695 #5P1824 #6P1751 #8P1308 #9P1883 #10P1788 #12P1513 #13P1833 #14P1813 #20P1205 #21P1076 #22P1149 #24P1642 #25P1167 #26P962 #28P1337 #29P1067 #30P1197 T200")); delay(200);
  }

  void ssc_rotateCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1586 #5P1831 #6P1793 #8P1402 #9P2221 #10P2004 #12P1387 #13P1833 #14P1813 #20P1314 #21P759 #22P917 #24P1548 #25P1167 #26P952 #28P1463 #29P748 #30P970 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1586 #5P1831 #6P1793 #8P1402 #9P1883 #10P1798 #12P1387 #13P1833 #14P1813 #20P1314 #21P1069 #22P1107 #24P1548 #25P1167 #26P952 #28P1463 #29P1067 #30P1197 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1463 #5P2152 #6P2009 #8P1498 #9P1883 #10P1798 #12P1264 #13P2141 #14P1983 #20P1437 #21P1067 #22P1087 #24P1452 #25P829 #26P746 #28P1586 #29P1069 #30P1221 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1463 #5P1833 #6P1813 #8P1498 #9P1883 #10P1798 #12P1264 #13P1831 #14P1793 #20P1437 #21P1067 #22P1087 #24P1452 #25P1167 #26P952 #28P1586 #29P1069 #30P1221 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1463 #5P1833 #6P1813 #8P1498 #9P2221 #10P2004 #12P1264 #13P1831 #14P1793 #20P1437 #21P748 #22P891 #24P1452 #25P1167 #26P952 #28P1586 #29P759 #30P1000 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1463 #5P1833 #6P1813 #8P1498 #9P1883 #10P1798 #12P1264 #13P1831 #14P1793 #20P1437 #21P1067 #22P1087 #24P1452 #25P1167 #26P952 #28P1586 #29P1069 #30P1221 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1586 #5P2141 #6P1983 #8P1402 #9P1883 #10P1798 #12P1387 #13P2152 #14P2009 #20P1314 #21P1069 #22P1107 #24P1548 #25P829 #26P746 #28P1463 #29P1067 #30P1197 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1586 #5P1831 #6P1793 #8P1402 #9P1883 #10P1798 #12P1387 #13P1833 #14P1813 #20P1314 #21P1069 #22P1107 #24P1548 #25P1167 #26P952 #28P1463 #29P1067 #30P1197 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1832 #6P1856 #8P1308 #9P2216 #10P1990 #12P1422 #13P1820 #14P1731 #20P1472 #21P794 #22P991 #24P1358 #25P1167 #26P962 #28P1649 #29P725 #30P905 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1832 #6P1856 #8P1308 #9P1883 #10P1788 #12P1422 #13P1820 #14P1731 #20P1472 #21P1080 #22P1169 #24P1358 #25P1167 #26P962 #28P1649 #29P1068 #30P1147 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1337 #5P2152 #6P2009 #8P1592 #9P1883 #10P1788 #12P1155 #13P2117 #14P1932 #20P1563 #21P1067 #22P1087 #24P1358 #25P834 #26P760 #28P1695 #29P1076 #30P1269 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1337 #5P1833 #6P1813 #8P1592 #9P1883 #10P1788 #12P1155 #13P1824 #14P1751 #20P1563 #21P1067 #22P1087 #24P1358 #25P1167 #26P962 #28P1695 #29P1076 #30P1269 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1649 #5P1832 #6P1856 #8P1308 #9P2216 #10P1990 #12P1422 #13P1820 #14P1731 #20P1472 #21P794 #22P991 #24P1358 #25P1167 #26P962 #28P1649 #29P725 #30P905 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1649 #5P1832 #6P1856 #8P1308 #9P1883 #10P1788 #12P1422 #13P1820 #14P1731 #20P1472 #21P1080 #22P1169 #24P1358 #25P1167 #26P962 #28P1649 #29P1068 #30P1147 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1695 #5P2117 #6P1932 #8P1308 #9P1883 #10P1788 #12P1513 #13P2152 #14P2009 #20P1205 #21P1076 #22P1149 #24P1642 #25P834 #26P760 #28P1337 #29P1067 #30P1197 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1695 #5P1824 #6P1751 #8P1308 #9P1883 #10P1788 #12P1513 #13P1833 #14P1813 #20P1205 #21P1076 #22P1149 #24P1642 #25P1167 #26P962 #28P1337 #29P1067 #30P1197 T200"));
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
