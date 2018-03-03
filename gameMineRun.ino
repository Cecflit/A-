int gameMineRunTicks = 0;

class runner {

  public:
    int positionX = 0;
    int positionY = 0;
    runner() {}

};

runner Runner = runner();

/*class mine {

  public:
    int minesColumns[48];
    mine() {
      for (int i = 0; i < 48; i += 2 ) {
        minesColumns[i] = 0;
        minesColumns[i + 1] = 23;
      }
    }

};*/

//mine Mine = mine();

void gameMineRunSetup() {

  score = 0;
  Runner.positionY = 12;
  Runner.positionX = 0;
  gameMineRunTicks = 0;
  
  clearScreen();
  for (int i = 0; i < 24; i++ ) {
    drawTile(i, 0);
    drawTile(i, 23);
  }

}

void gameMineRunLoop() {
  
  for (int i = 0; i < 24; i++) {
    clearTile(Runner.positionX, i); 
  }
  drawTile(Runner.positionX, randomInteger(0, 24));
  drawTile(Runner.positionX, randomInteger(0, 24));

  moveRunner();

  if (arr[Runner.positionX][Runner.positionY]) endGame();

  drawTile(Runner.positionX, Runner.positionY);

  /*for (int i = 0; i < 24; i++) {

    drawTile(i, Mine.minesColumns[i * 2]);
    drawTile(i, Mine.minesColumns[i * 2 + 1]);

  }*/

  /*for (int i = 0; i < 2; i++) {
    if (Runner.positionY == Mine.minesColumns[i + 4]) {
      endGame();
    }
  }*/
  if (!(gameMineRunTicks % 10))score++;
  if (score > 999)score = 999;
  
  for (short i = (tickDuration + 1) * 10; i; i--) {
    renderScreenXShift(23 - Runner.positionX);
  }
  gameMineRunTicks++;
}

void moveRunner() {

  //clearTile(2, Runner.positionY);
  if (!digitalRead(buttonUp)) {
    Runner.positionY--;
  };
  if (!digitalRead(buttonDown)) {
    Runner.positionY++;
  };
  Runner.positionX++;

  if (Runner.positionY < 0)Runner.positionY = 23;
  if (Runner.positionY > 23)Runner.positionY = 0;
  if (Runner.positionX > 23)Runner.positionX = 0;

  //drawTile(2, Runner.positionY);

}
