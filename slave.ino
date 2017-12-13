void slave() {
  if (raspiGetValue(0) == 0) {
    return;
  }
  if (raspiIsUpdated()) {
    switch (raspiGetValue(0)) {
      case 0:
        break;
      case 1:
        runCtrlSet(STP, 0, 0);
        break;
      case 2:
        runCtrlSet(STR, raspiGetValue(1), raspiGetValue(2));
        break;
      case 3:
        runCtrlSet(ROT, raspiGetValue(3), raspiGetValue(4));
        break;
      case 100:
        softwareReset();
        break;
      default:
        break;
    }
  }
  runCtrlExecute();
  velCtrlExecute();
}

