int gameMineRunTicks = 0;

class runner {

  public:
    int positionY = 0;
    runner() {}

};

runner Runner = runner();

class mine {

  public:
    int minesColumns[48];
    mine() {
      for (int i = 0; i < 48; i += 2 ) {
        minesColumns[i] = 0;
        minesColumns[i + 1] = 23;
      }
    }

};

mine Mine = mine();

void gameMineRunSetup() {

  score = 0;
  Runner.positionY = 12;
  gameMineRunTicks = 0;

}

void gameMineRunLoop() {

  if (!digitalRead(buttonUp)) {
    Runner.positionY--;
  };
  if (!digitalRead(buttonDown)) {
    Runner.positionY++;
  };


  if (Runner.positionY < 0)Runner.positionY = 23;
  if (Runner.positionY > 23)Runner.positionY = 0;

  for (int i = 0; i < 46; i += 2) {
    Mine.minesColumns[i] = Mine.minesColumns[i + 2];
    Mine.minesColumns[i + 1] = Mine.minesColumns[i + 3];
  }
  Mine.minesColumns[46] = randomInteger(0, 23);
  Mine.minesColumns[47] = randomInteger(0, 23);

  clearScreen();
  drawTile(2, Runner.positionY);

  for (int i = 0; i < 24; i++) {

    drawTile(i, Mine.minesColumns[i * 2]);
    drawTile(i, Mine.minesColumns[i * 2 + 1]);

  }

  for (int i = 0; i < 2; i++) {
    if (Runner.positionY == Mine.minesColumns[i + 4]) {
      endGame();
    }
  }
  if (!(gameMineRunTicks % 10))score++;
  if (score > 999)score = 999;
  wait(tickDuration + 1);
  gameMineRunTicks++;
}