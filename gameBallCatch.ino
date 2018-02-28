byte gameBallCatchLoopCounter;

/*class fallBall {

  public:
    int positionX;
    int positionY;
    fallBall() {}

};*/

class paddle {

  public:
    int positionY = 0;
    int row = 23;
    paddle() {}

};

/*fallBall Ball0 = fallBall();
fallBall Ball1 = fallBall();
fallBall Ball2 = fallBall();
fallBall Ball3 = fallBall();
fallBall Ball4 = fallBall();*/

//uses class paddle written for gamePong, positionY is used as positionX
paddle Catcher = paddle();

void gameBallCatchSetup() {  
  gameBallCatchLoopCounter = 0;

  clearScreen();
  drawTile(12, 0);
  drawTile(12, 5);
  drawTile(12, 10);
  drawTile(12, 15);
  drawTile(12, 20);

  Catcher.positionY = 12;
  Catcher.row = 23;
  drawTile(Catcher.positionY, Catcher.row);
  drawTile(Catcher.positionY + 1, Catcher.row);
  drawTile(Catcher.positionY - 1, Catcher.row);

  score = 0;

}

void gameBallCatchLoop() {

  //clearScreen();
  gameBallCatchLetMove();
  gameBallCatchLoopCounter++;
  if(gameBallCatchLoopCounter >= 3) {
    gameBallCatchMoveBalls();
    gameBallCatchLoopCounter = 0;
  }
  //gameBallCatchDrawScreen();
  for (short i = (tickDuration + 1)*10; i; i--) {
    renderScreenYShift(23 - i);
  }
}

void gameBallCatchLetMove() {

  if (!digitalRead(buttonLeft) && Catcher.positionY > 1) {
    clearTile(Catcher.positionY + 1, Catcher.row);
    Catcher.positionY--;
    drawTile(Catcher.positionY - 1, Catcher.row);
  }
  if (!digitalRead(buttonRight) && Catcher.positionY < 22) {
    clearTile(Catcher.positionY - 1, Catcher.row);
    Catcher.positionY++;
    drawTile(Catcher.positionY + 1, Catcher.row);
  }
  
}

void gameBallCatchMoveBalls() {

  clearTile(Catcher.positionY, Catcher.row);
  clearTile(Catcher.positionY + 1, Catcher.row);
  clearTile(Catcher.positionY - 1, Catcher.row);

  Catcher.row--;
  if (Catcher.row < 0)Catcher.row = 23;

  /*Ball0.positionY++;
  Ball1.positionY++;
  Ball2.positionY++;
  Ball3.positionY++;
  Ball4.positionY++;

  if (Ball0.positionY == 23 && (Catcher.positionY == Ball0.positionX || Catcher.positionY - 1 == Ball0.positionX || Catcher.positionY + 1 == Ball0.positionX)) {
    Ball0.positionY = randomInteger(0, 1);
    Ball0.positionX = randomInteger(0, 23);
    score++;
  }
  if (Ball1.positionY == 23 && (Catcher.positionY == Ball1.positionX || Catcher.positionY - 1 == Ball1.positionX || Catcher.positionY + 1 == Ball1.positionX)) {
    Ball1.positionY = randomInteger(0, 1);
    Ball1.positionX = randomInteger(0, 23);
    score++;
  }
  if (Ball2.positionY == 23 && (Catcher.positionY == Ball2.positionX || Catcher.positionY - 1 == Ball2.positionX || Catcher.positionY + 1 == Ball2.positionX)) {
    Ball2.positionY = randomInteger(0, 1);
    Ball2.positionX = randomInteger(0, 23);
    score++;
  }
  if (Ball3.positionY == 23 && (Catcher.positionY == Ball3.positionX || Catcher.positionY - 1 == Ball3.positionX || Catcher.positionY + 1 == Ball3.positionX)) {
    Ball3.positionY = randomInteger(0, 1);
    Ball3.positionX = randomInteger(0, 23);
    score++;
  }
  if (Ball4.positionY == 23 && (Catcher.positionY == Ball4.positionX || Catcher.positionY - 1 == Ball4.positionX || Catcher.positionY + 1 == Ball4.positionX)) {
    Ball4.positionY = randomInteger(0, 1);
    Ball4.positionX = randomInteger(0, 23);
    score++;
  }*/

  for (int x = 0; x < Catcher.positionY - 1; x++) {
    if (arr[x][Catcher.row]) endGame();
  }
  for (int x = Catcher.positionY + 2; x < 24; x++) {
    if (arr[x][Catcher.row]) endGame();
  }
  for (int x = Catcher.positionY - 1; x < Catcher.positionY + 2; x++) {
    if (arr[x][Catcher.row]) {
      drawTile(randomInteger(0, 23), (randomInteger(1, 2) + Catcher.positionY)%24);
      score++;
      if (score >= 999) score = 999;
    }
  }

  drawTile(Catcher.positionY, Catcher.row);
  drawTile(Catcher.positionY + 1, Catcher.row);
  drawTile(Catcher.positionY - 1, Catcher.row);

  //if (Ball0.positionY == 23 || Ball1.positionY == 23 || Ball2.positionY == 23 || Ball3.positionY == 23 || Ball4.positionY == 23)endGame();
}
/*
void gameBallCatchDrawScreen() {

  drawTile(Ball0.positionX, Ball0.positionY);
  drawTile(Ball1.positionX, Ball1.positionY);
  drawTile(Ball2.positionX, Ball2.positionY);
  drawTile(Ball3.positionX, Ball3.positionY);
  drawTile(Ball4.positionX, Ball4.positionY);
  drawTile(Catcher.positionY, 23);
  drawTile(Catcher.positionY + 1, 23);
  drawTile(Catcher.positionY - 1, 23);

}*/
