//lane0_ypos = 4; lane1_ypos = 9; lane2_ypos = 14; lane3_ypos = 19;

bool gameStreetCrossLastUp;

class vehicle {

  public:
    int lane;
    char positionX;
    vehicle () {}

};

vehicle Lane0_0 = vehicle();
vehicle Lane0_1 = vehicle();
vehicle Lane0_2 = vehicle();
vehicle Lane1_0 = vehicle();
vehicle Lane1_1 = vehicle();
vehicle Lane1_2 = vehicle();
vehicle Lane2_0 = vehicle();
vehicle Lane2_1 = vehicle();
vehicle Lane2_2 = vehicle();
vehicle Lane3_0 = vehicle();
vehicle Lane3_1 = vehicle();
vehicle Lane3_2 = vehicle();

class crosser {

  public:
    int positionX;
    int positionY;
    crosser () {}

};

crosser Crosser = crosser();

void gameStreetCrossSetup() {

  score = 0;
  gameStreetCrossLastUp = false;
  Lane0_0.lane = 4;
  Lane0_1.lane = 4;
  Lane0_2.lane = 4;
  Lane1_0.lane = 9;
  Lane1_1.lane = 9;
  Lane1_2.lane = 9;
  Lane2_0.lane = 14;
  Lane2_1.lane = 14;
  Lane2_2.lane = 14;
  Lane3_0.lane = 19;
  Lane3_1.lane = 19;
  Lane3_2.lane = 19;

  Lane0_0.positionX = 0;
  Lane0_1.positionX = 8;
  Lane0_2.positionX = 16;
  Lane1_0.positionX = 4;
  Lane1_1.positionX = 12;
  Lane1_2.positionX = 20;
  Lane2_0.positionX = 0;
  Lane2_1.positionX = 8;
  Lane2_2.positionX = 16;
  Lane3_0.positionX = 4;
  Lane3_1.positionX = 12;
  Lane3_2.positionX = 20;

  Crosser.positionX = 11;
  Crosser.positionY = 22;

}

void gameStreetCrossLoop() {

  gameStreetCrossLetMove();
  gameStreetCrossCheckScore();
  gameStreetCrossMoveVehicles();
  gameStreetCrossDrawScreen();
  gameStreetCrossCheckCollision();
  wait(tickDuration + 1);

}

void gameStreetCrossLetMove() {

  if (!digitalRead(buttonUp))Crosser.positionY--;
  if (!digitalRead(buttonDown))Crosser.positionY++;
  if (!digitalRead(buttonLeft))Crosser.positionX--;
  if (!digitalRead(buttonRight))Crosser.positionX++;

  if (Crosser.positionX < 0)Crosser.positionX = 23;
  if (Crosser.positionX > 23)Crosser.positionX = 0;
  if (Crosser.positionY < 0)Crosser.positionY = 0;
  if (Crosser.positionY > 23)Crosser.positionY = 23;

}

void gameStreetCrossMoveVehicles() {

  Lane0_0.positionX++;
  if (Lane0_0.positionX > 23)Lane0_0.positionX = 0;
  Lane0_1.positionX++;
  if (Lane0_1.positionX > 23)Lane0_1.positionX = 0;
  Lane0_2.positionX++;
  if (Lane0_2.positionX > 23)Lane0_2.positionX = 0;
  Lane1_0.positionX++;
  if (Lane1_0.positionX > 23)Lane1_0.positionX = 0;
  Lane1_1.positionX++;
  if (Lane1_1.positionX > 23)Lane1_1.positionX = 0;
  Lane1_2.positionX++;
  if (Lane1_2.positionX > 23)Lane1_2.positionX = 0;

  Lane2_0.positionX--;
  if (Lane2_0.positionX < 0)Lane2_0.positionX = 23;
  Lane2_1.positionX--;
  if (Lane2_1.positionX < 0)Lane2_1.positionX = 23;
  Lane2_2.positionX--;
  if (Lane2_2.positionX < 0)Lane2_2.positionX = 23;
  Lane3_0.positionX--;
  if (Lane3_0.positionX < 0)Lane3_0.positionX = 23;
  Lane3_1.positionX--;
  if (Lane3_1.positionX < 0)Lane3_1.positionX = 23;
  Lane3_2.positionX--;
  if (Lane3_2.positionX < 0)Lane3_2.positionX = 23;
}

void gameStreetCrossDrawScreen() {

  clearScreen();

  drawTile(Crosser.positionX, Crosser.positionY);
  drawTile(Lane0_0.positionX, Lane0_0.lane);
  drawTile(Lane0_1.positionX, Lane0_1.lane);
  drawTile(Lane0_2.positionX, Lane0_2.lane);
  drawTile(Lane1_0.positionX, Lane1_0.lane);
  drawTile(Lane1_1.positionX, Lane1_1.lane);
  drawTile(Lane1_2.positionX, Lane1_2.lane);
  drawTile(Lane2_0.positionX, Lane2_0.lane);
  drawTile(Lane2_1.positionX, Lane2_1.lane);
  drawTile(Lane2_2.positionX, Lane2_2.lane);
  drawTile(Lane3_0.positionX, Lane3_0.lane);
  drawTile(Lane3_1.positionX, Lane3_1.lane);
  drawTile(Lane3_2.positionX, Lane3_2.lane);

  if (Lane0_0.positionX < 23) {
    drawTile(Lane0_0.positionX + 1, Lane0_0.lane);
  } else drawTile(0, Lane0_0.lane);

  if (Lane0_1.positionX < 23) {
    drawTile(Lane0_1.positionX + 1, Lane0_1.lane);
  } else drawTile(0, Lane0_1.lane);

  if (Lane0_2.positionX < 23) {
    drawTile(Lane0_2.positionX + 1, Lane0_2.lane);
  } else drawTile(0, Lane0_2.lane);


  if (Lane1_0.positionX < 23) {
    drawTile(Lane1_0.positionX + 1, Lane1_0.lane);
  } else drawTile(0, Lane1_0.lane);

  if (Lane1_1.positionX < 23) {
    drawTile(Lane1_1.positionX + 1, Lane1_1.lane);
  } else drawTile(0, Lane1_1.lane);

  if (Lane1_2.positionX < 23) {
    drawTile(Lane1_2.positionX + 1, Lane1_2.lane);
  } else drawTile(0, Lane1_2.lane);

  if (Lane2_0.positionX < 23) {
    drawTile(Lane2_0.positionX + 1, Lane2_0.lane);
  } else drawTile(0, Lane2_0.lane);

  if (Lane2_1.positionX < 23) {
    drawTile(Lane2_1.positionX + 1, Lane2_1.lane);
  } else drawTile(0, Lane2_1.lane);

  if (Lane2_2.positionX < 23) {
    drawTile(Lane2_2.positionX + 1, Lane2_2.lane);
  } else drawTile(0, Lane2_2.lane);


  if (Lane3_0.positionX < 23) {
    drawTile(Lane3_0.positionX + 1, Lane3_0.lane);
  } else drawTile(0, Lane3_0.lane);

  if (Lane3_1.positionX < 23) {
    drawTile(Lane3_1.positionX + 1, Lane3_1.lane);
  } else drawTile(0, Lane3_1.lane);

  if (Lane3_2.positionX < 23) {
    drawTile(Lane3_2.positionX + 1, Lane3_2.lane);
  } else drawTile(0, Lane3_2.lane);
}

void gameStreetCrossCheckCollision() {

  if (Crosser.positionY == Lane0_0.lane) {

    //Check collision with vehicle Lane0_0

    if (Crosser.positionX == Lane0_0.positionX)endGame();
    if (Lane0_0.positionX < 23 && Crosser.positionX == Lane0_0.positionX + 1)endGame();
    if (Lane0_0.positionX == 23 && Crosser.positionX == 0)endGame();

    //Check collision with vehicle Lane0_1

    if (Crosser.positionX == Lane0_1.positionX)endGame();
    if (Lane0_1.positionX < 23 && Crosser.positionX == Lane0_1.positionX + 1)endGame();
    if (Lane0_1.positionX == 23 && Crosser.positionX == 0)endGame();

    //Check collision with vehicle Lane0_2

    if (Crosser.positionX == Lane0_2.positionX)endGame();
    if (Lane0_2.positionX < 23 && Crosser.positionX == Lane0_2.positionX + 1)endGame();
    if (Lane0_2.positionX == 23 && Crosser.positionX == 0)endGame();

  }

  if (Crosser.positionY == Lane1_0.lane) {

    //Check collision with vehicle Lane1_0

    if (Crosser.positionX == Lane1_0.positionX)endGame();
    if (Lane1_0.positionX < 23 && Crosser.positionX == Lane1_0.positionX + 1)endGame();
    if (Lane1_0.positionX == 23 && Crosser.positionX == 0)endGame();

    //Check collision with vehicle Lane1_1

    if (Crosser.positionX == Lane1_1.positionX)endGame();
    if (Lane1_1.positionX < 23 && Crosser.positionX == Lane1_1.positionX + 1)endGame();
    if (Lane1_1.positionX == 23 && Crosser.positionX == 0)endGame();

    //Check collision with vehicle Lane1_2

    if (Crosser.positionX == Lane1_2.positionX)endGame();
    if (Lane1_2.positionX < 23 && Crosser.positionX == Lane1_2.positionX + 1)endGame();
    if (Lane1_2.positionX == 23 && Crosser.positionX == 0)endGame();

  }

  if (Crosser.positionY == Lane2_0.lane) {

    //Check collision with vehicle Lane2_0

    if (Crosser.positionX == Lane2_0.positionX)endGame();
    if (Lane2_0.positionX < 23 && Crosser.positionX == Lane2_0.positionX + 1)endGame();
    if (Lane2_0.positionX == 23 && Crosser.positionX == 0)endGame();

    //Check collision with vehicle Lane2_1

    if (Crosser.positionX == Lane2_1.positionX)endGame();
    if (Lane2_1.positionX < 23 && Crosser.positionX == Lane2_1.positionX + 1)endGame();
    if (Lane2_1.positionX == 23 && Crosser.positionX == 0)endGame();

    //Check collision with vehicle Lane2_2

    if (Crosser.positionX == Lane2_2.positionX)endGame();
    if (Lane2_2.positionX < 23 && Crosser.positionX == Lane2_2.positionX + 1)endGame();
    if (Lane2_2.positionX == 23 && Crosser.positionX == 0)endGame();

  }

  if (Crosser.positionY == Lane3_0.lane) {

    //Check collision with vehicle Lane3_0

    if (Crosser.positionX == Lane3_0.positionX)endGame();
    if (Lane3_0.positionX < 23 && Crosser.positionX == Lane3_0.positionX + 1)endGame();
    if (Lane3_0.positionX == 23 && Crosser.positionX == 0)endGame();

    //Check collision with vehicle Lane3_1

    if (Crosser.positionX == Lane3_1.positionX)endGame();
    if (Lane3_1.positionX < 23 && Crosser.positionX == Lane3_1.positionX + 1)endGame();
    if (Lane3_1.positionX == 23 && Crosser.positionX == 0)endGame();

    //Check collision with vehicle Lane3_2

    if (Crosser.positionX == Lane3_2.positionX)endGame();
    if (Lane3_2.positionX < 23 && Crosser.positionX == Lane3_2.positionX + 1)endGame();
    if (Lane3_2.positionX == 23 && Crosser.positionX == 0)endGame();

  }
}

void gameStreetCrossCheckScore() {

  if (Crosser.positionY < Lane0_0.lane && !gameStreetCrossLastUp) {

    score++;
    playSound(3);
    gameStreetCrossLastUp = true;

  }

  if (Crosser.positionY > Lane3_0.lane && gameStreetCrossLastUp) {

    score++;
    playSound(3);
    gameStreetCrossLastUp = false;

  }

  if (score > 999)score = 999;

}
