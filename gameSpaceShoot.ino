byte gameSpaceShootLoopCounter;

class ship {

  public:
    int positionX = 0;
    int bulletCoordinates[24][2] = {};
    ship() {}

};

ship Ship = ship();

class asteroid {

  public:
    int coordinates[24][2] = {};
    asteroid() {}

};

asteroid Asteroid = asteroid();

void gameSpaceShootSetup() {
  gameSpaceShootLoopCounter = 0;
  score = 0;
  Ship.positionX = randomInteger(2, 20);
  for (int i = 0; i < 24; i++) {

    Ship.bulletCoordinates[i][0] = 23;
    Ship.bulletCoordinates[i][1] = 23;

    Asteroid.coordinates[i][0] = randomInteger(0, 23);
    Asteroid.coordinates[i][1] = randomInteger(-12, 5);
  }

  clearScreen();
  gameSpaceShootDrawScene();

}

void gameSpaceShootLoop() {

  gameSpaceShootDrawScene();

  gameSpaceShootLetMove();
  gameSpaceShootLoopCounter++;


  for (int i = 0; i < 24; i++) {

    if (Ship.bulletCoordinates[i][1] != 23) {

      Ship.bulletCoordinates[i][1]--;
      if (Ship.bulletCoordinates[i][1] < 0) {

        Ship.bulletCoordinates[i][0] = 23;
        Ship.bulletCoordinates[i][1] = 23;

      }

    }

    for (int j = 0; j < 24; j++) {

      if (Ship.bulletCoordinates[i][1] != 23) {
        if (Asteroid.coordinates[j][0] == Ship.bulletCoordinates[i][0] && Asteroid.coordinates[j][1] == Ship.bulletCoordinates[i][1]) {

          score++;
          Asteroid.coordinates[j][0] = randomInteger(0, 23);
          Asteroid.coordinates[j][1] = 0;
          Ship.bulletCoordinates[i][0] = 23;
          Ship.bulletCoordinates[i][1] = 23;

        }
      }
    }

  }

  if (gameSpaceShootLoopCounter > 5) {
    gameSpaceShootLoopCounter = 0;
    for (int i = 0; i < 23; i++) {

      Asteroid.coordinates[i][1]++;

      if (Asteroid.coordinates[i][1] == 23)endGame();
      if (Asteroid.coordinates[i][0] == Ship.positionX && Asteroid.coordinates[i][1] == 21)endGame();

    }
  }

  gameSpaceShootDrawScene();

  wait(tickDuration + 1);


}

void gameSpaceShootLetMove() {

  if (!digitalRead(buttonLeft)) {
    Ship.positionX--;
  }
  if (!digitalRead(buttonRight)) {
    Ship.positionX++;
  }
  if (!digitalRead(buttonUp)) {
    gameSpaceShootFire();
  }

  if (Ship.positionX > 23)Ship.positionX = 0;
  if (Ship.positionX < 0)Ship.positionX = 23;

}

void gameSpaceShootFire() {

  for (int i = 0; i < 24; i++) {

    if (Ship.bulletCoordinates[i][1] == 23) {
      Ship.bulletCoordinates[i][0] = Ship.positionX;
      Ship.bulletCoordinates[i][1] = 21;
      break;
    }

  }

}

void gameSpaceShootDrawScene() {

  for (int i = 0; i < 23; i++) {

    if (Asteroid.coordinates[i][1] >= 0)toggleTile(Asteroid.coordinates[i][0], Asteroid.coordinates[i][1]);
    if (Ship.bulletCoordinates[i][1] != 23)toggleTile(Ship.bulletCoordinates[i][0], Ship.bulletCoordinates[i][1]);

  }
  toggleTile(Ship.positionX, 23);
  toggleTile(Ship.positionX, 22);
  if (Ship.positionX && Ship.positionX < 23) {
    toggleTile(Ship.positionX - 1, 23);
    toggleTile(Ship.positionX + 1, 23);
  } else if (!Ship.positionX) {

    toggleTile(1, 23);
    toggleTile(23, 23);

  } else {

    toggleTile(22, 23);
    toggleTile(0, 23);

  }

}
