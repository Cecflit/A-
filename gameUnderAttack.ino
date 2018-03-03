const byte def_01_67_1213_1819[6] = {21, 22, 23, 0, 1, 2};
const byte def_23_89_1415_2021[6] = {5, 6, 7, 8, 9, 10};
const byte def_45_1011_1617_2223[6] = {13, 14, 15, 16, 17, 18};
const byte def_victim[2] = {12, 13};
byte gameUnderAttackTicks = 0;

class rocket {
  public:
    char positionX[6] = {0, 1, 2, 3, 4, 5};
    char directionX = 1;

};

/*rocket Rocket01 = rocket();
rocket Rocket23 = rocket();
rocket Rocket45 = rocket();
rocket Rocket67 = rocket();
rocket Rocket89 = rocket();
rocket Rocket1011 = rocket();
rocket Rocket1213 = rocket();
rocket Rocket1415 = rocket();
rocket Rocket1617 = rocket();
rocket Rocket1819 = rocket();
rocket Rocket2021 = rocket();
rocket Rocket2223 = rocket();*/
rocket Rockets[12];

class victim {

  public:
    int positionY[2] = {0, 1};
    const byte positionX[2] = {11, 12};

};

victim Victim = victim();

void gameUnderAttackSetup() {

  gameUnderAttackTicks = 0;

 
  for (byte i = 0; i < 6; i++) {

    Rockets[0].positionX[i] = def_01_67_1213_1819[i];
    Rockets[1].positionX[i] = def_23_89_1415_2021[i];
    Rockets[2].positionX[i] = def_45_1011_1617_2223[i];
    Rockets[3].positionX[i] = def_01_67_1213_1819[i];
    Rockets[4].positionX[i] = def_23_89_1415_2021[i];
    Rockets[5].positionX[i] = def_45_1011_1617_2223[i];
    Rockets[6].positionX[i] = def_01_67_1213_1819[i];
    Rockets[7].positionX[i] = def_23_89_1415_2021[i];
    Rockets[8].positionX[i] = def_45_1011_1617_2223[i];
    Rockets[9].positionX[i] = def_01_67_1213_1819[i];
    Rockets[10].positionX[i] = def_23_89_1415_2021[i];
    Rockets[11].positionX[i] = def_45_1011_1617_2223[i];

    if (i >= 2)continue;

    Victim.positionY[i] = def_victim[i];

  }
  
  clearScreen();
  gameUnderAttackRenderScreen();
  gameUnderAttackRenderVictim();

}

void gameUnderAttackLoop() {

  gameUnderAttackRenderScreen();
  gameUnderAttackRenderVictim();

  gameUnderAttackLetMove();
  gameUnderAttackMoveRockets();

  gameUnderAttackRenderScreen();
  if (gameUnderAttackDetectCollision())endGame();
  gameUnderAttackRenderVictim();
  
  wait(tickDuration + 1);
  gameUnderAttackTicks++;
  
  if (gameUnderAttackTicks >= 10) {

    gameUnderAttackTicks = 0;
    score++;

  }


}

void gameUnderAttackLetMove() {

  for (byte i = 0;  i < 2; i++) {
    Victim.positionY[i] += gameUnderAttackDetectButton();
  }

}

void gameUnderAttackMoveRockets() {

  for (byte r = 0; r < 12; r++) for (byte i = 0; i < 6; i++) {

    if (r % 2) { 
      Rockets[r].positionX[i]++;
      if (Rockets[r].positionX[i] > 23)Rockets[r].positionX[i] = 0;
    } else {
      Rockets[r].positionX[i]--;
      if (Rockets[r].positionX[i] < 0)Rockets[r].positionX[i] = 23;
    }
    
    /*Rocket01.positionX[i]++;
    if (Rocket01.positionX[i] > 23)Rocket01.positionX[i] = 0;
    Rocket45.positionX[i]++;
    if (Rocket45.positionX[i] > 23)Rocket45.positionX[i] = 0;
    Rocket89.positionX[i]++;
    if (Rocket89.positionX[i] > 23)Rocket89.positionX[i] = 0;
    Rocket1213.positionX[i]++;
    if (Rocket1213.positionX[i] > 23)Rocket1213.positionX[i] = 0;
    Rocket1617.positionX[i]++;
    if (Rocket1617.positionX[i] > 23)Rocket1617.positionX[i] = 0;
    Rocket2021.positionX[i]++;
    if (Rocket2021.positionX[i] > 23)Rocket2021.positionX[i] = 0;
    Rocket23.positionX[i]--;
    if (Rocket23.positionX[i] < 0)Rocket23.positionX[i] = 23;
    Rocket67.positionX[i]--;
    if (Rocket67.positionX[i] < 0)Rocket67.positionX[i] = 23;
    Rocket1011.positionX[i]--;
    if (Rocket1011.positionX[i] < 0)Rocket1011.positionX[i] = 23;
    Rocket1415.positionX[i]--;
    if (Rocket1415.positionX[i] < 0)Rocket1415.positionX[i] = 23;
    Rocket1819.positionX[i]--;
    if (Rocket1819.positionX[i] < 0)Rocket1819.positionX[i] = 23;
    Rocket2223.positionX[i]--;
    if (Rocket2223.positionX[i] < 0)Rocket2223.positionX[i] = 23;*/
  }

}

void gameUnderAttackRenderScreen() {
  
  for (byte r = 0; r < 12; r++) for (byte i = 0; i < 6; i++) {

    toggleTile(Rockets[r].positionX[i], 2*r);
    toggleTile(Rockets[r].positionX[i], 2*r +1);
    /*drawTile(Rocket01.positionX[i], 0);
    drawTile(Rocket01.positionX[i], 1);
    drawTile(Rocket23.positionX[i], 2);
    drawTile(Rocket23.positionX[i], 3);
    drawTile(Rocket45.positionX[i], 4);
    drawTile(Rocket45.positionX[i], 5);
    drawTile(Rocket67.positionX[i], 6);
    drawTile(Rocket67.positionX[i], 7);
    drawTile(Rocket89.positionX[i], 8);
    drawTile(Rocket89.positionX[i], 9);
    drawTile(Rocket1011.positionX[i], 10);
    drawTile(Rocket1011.positionX[i], 11);
    drawTile(Rocket1213.positionX[i], 12);
    drawTile(Rocket1213.positionX[i], 13);
    drawTile(Rocket1415.positionX[i], 14);
    drawTile(Rocket1415.positionX[i], 15);
    drawTile(Rocket1617.positionX[i], 16);
    drawTile(Rocket1617.positionX[i], 17);
    drawTile(Rocket1819.positionX[i], 18);
    drawTile(Rocket1819.positionX[i], 19);
    drawTile(Rocket2021.positionX[i], 20);
    drawTile(Rocket2021.positionX[i], 21);
    drawTile(Rocket2223.positionX[i], 22);
    drawTile(Rocket2223.positionX[i], 23);*/

    /*if (i >= 2)continue;

    drawTile(11, Victim.positionY[i]);
    drawTile(12, Victim.positionY[i]);*/

  }
  
}

void gameUnderAttackRenderVictim() {
  
  toggleTile(11, Victim.positionY[0]);
  toggleTile(12, Victim.positionY[0]);
  toggleTile(11, Victim.positionY[1]);
  toggleTile(12, Victim.positionY[1]);
}

bool gameUnderAttackDetectCollision() {

  //0-1 12-13 >
  //2-3 14-15 <
  //4-5 16-17 >
  //6-7 18-19 <
  //8-9 20-21 >
  //10-11 22-23 <
  
  for (int i = 1; i >= 0; i--) {
    if (arr[11][Victim.positionY[i]] || arr[12][Victim.positionY[i]]) return true;
  }

  /*for (byte i = 0; i < 2; i++) {
    if (((Victim.positionY[i] < 2 || (Victim.positionY[i] >= 12 && Victim.positionY[i] <= 13)) && ((Rocket01.positionX[5] >= 11 && Rocket01.positionX[5] <= 17) || (Rocket1213.positionX[5] >= 11 && Rocket1213.positionX[5] <= 17))) || (((Victim.positionY[i] >= 2 && Victim.positionY[i] <= 3) || (Victim.positionY[i] >= 14 && Victim.positionY[i] <= 15)) && ((Rocket23.positionX[5] >= 11 && Rocket23.positionX[5] <= 17) || (Rocket1415.positionX[5] >= 11 && Rocket1415.positionX[5] <= 17))) || (((Victim.positionY[i] >= 4 && Victim.positionY[i] <= 5) || (Victim.positionY[i] >= 16 && Victim.positionY[i] <= 17)) && ((Rocket45.positionX[5] >= 11 && Rocket45.positionX[5] <= 17) || (Rocket1617.positionX[5] >= 11 && Rocket1617.positionX[5] <= 17))) || (((Victim.positionY[i] >= 6 && Victim.positionY[i] <= 7) || (Victim.positionY[i] >= 18 && Victim.positionY[i] <= 19)) && ((Rocket67.positionX[5] >= 11 && Rocket67.positionX[5] <= 17) || (Rocket1819.positionX[5] >= 11 && Rocket1819.positionX[5] <= 17))) || (((Victim.positionY[i] >= 8 && Victim.positionY[i] <= 9) || (Victim.positionY[i] >= 20 && Victim.positionY[i] <= 21)) && ((Rocket89.positionX[5] >= 11 && Rocket89.positionX[5] <= 17) || (Rocket2021.positionX[5] >= 11 && Rocket2021.positionX[5] <= 17))) || (((Victim.positionY[i] >= 10 && Victim.positionY[i] <= 11) || (Victim.positionY[i] > 22)) && ((Rocket1011.positionX[5] >= 11 && Rocket1011.positionX[5] <= 17) || (Rocket2223.positionX[5] >= 11 && Rocket2223.positionX[5] <= 17))))return true;
  }*/
  return false;
}

int gameUnderAttackDetectButton() {

  /*
     0=none
     -1=up
     1=down
  */
  return !digitalRead(buttonUp) ? -1 : !digitalRead(buttonDown) ? 1 : 0;

}
