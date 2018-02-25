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

  score = 0;
  Ship.positionX = randomInteger(2, 20);
  for (int i = 0; i < 24; i++) {

    Ship.bulletCoordinates[i][0] = 23;
    Ship.bulletCoordinates[i][1] = 23;

    Asteroid.coordinates[i][0] = randomInteger(0, 23);
    Asteroid.coordinates[i][1] = randomInteger(0, 5);

  }

}

void gameSpaceShootLoop() {

  gameSpaceShootLetMove();
  if (Ship.positionX > 23)Ship.positionX = 0;
  if (Ship.positionX < 0)Ship.positionX = 23;
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

  for (int i = 0; i < 23; i++) {

    Asteroid.coordinates[i][1]++;

    for (int j = 0; j < 24; j++) {

      if (Ship.bulletCoordinates[j][1] != 23) {
        if (Asteroid.coordinates[i][0] == Ship.bulletCoordinates[j][0] && Asteroid.coordinates[i][1] == Ship.bulletCoordinates[j][1]) {

          score++;
          if (score > 999)score = 999;
          Asteroid.coordinates[i][0] = randomInteger(0, 23);
          Asteroid.coordinates[i][1] = 0;
          Ship.bulletCoordinates[j][0] = 23;
          Ship.bulletCoordinates[j][1] = 23;

        }
      }
    }

    if (Asteroid.coordinates[i][1] == 23)endGame();
    if (Asteroid.coordinates[i][0] == Ship.positionX && Asteroid.coordinates[i][1] == 21)endGame();

  }

  for (int i = 0; i < 23; i++) {

    drawTile(Asteroid.coordinates[i][0], Asteroid.coordinates[i][1]);
    if (Ship.bulletCoordinates[i][1] != 23)drawTile(Ship.bulletCoordinates[i][0], Ship.bulletCoordinates[i][1]);

  }
  clearScreen();
  drawTile(Ship.positionX, 23);
  drawTile(Ship.positionX, 22);
  if (Ship.positionX && Ship.positionX < 23) {
    drawTile(Ship.positionX - 1, 23);
    drawTile(Ship.positionX + 1, 23);
  } else if (!Ship.positionX) {

    drawTile(1, 23);
    drawTile(23, 23);

  } else {

    drawTile(22, 23);
    drawTile(0, 23);

  }

  gameSpaceShootLetMove();

  wait(tickDuration + 1);

  for (int i = 0; i < 23; i++) {

    drawTile(Asteroid.coordinates[i][0], Asteroid.coordinates[i][1]);
    if (Ship.bulletCoordinates[i][1] != 23)drawTile(Ship.bulletCoordinates[i][0], Ship.bulletCoordinates[i][1]);

  }

  drawTile(Ship.positionX, 23);
  drawTile(Ship.positionX, 22);
  if (Ship.positionX && Ship.positionX < 23) {
    drawTile(Ship.positionX - 1, 23);
    drawTile(Ship.positionX + 1, 23);
  } else if (!Ship.positionX) {

    drawTile(1, 23);
    drawTile(23, 23);

  } else {

    drawTile(22, 23);
    drawTile(0, 23);

  }

  wait(tickDuration + 1);

}

void gameSpaceShootLetMove() {

  if (!digitalRead(buttonLeft)) {
    Runner.positionY--;
  }
  if (!digitalRead(buttonRight)) {
    Runner.positionY++;
  }
  if (!digitalRead(buttonUp)) {
    gameSpaceShootFire();
  }

}

void gameSpaceShootFire() {

  for (int i = 0; i < 24; i++) {

    if (Ship.bulletCoordinates[i][1] == 23) {
      Ship.bulletCoordinates[i][0] = Ship.positionX;
      Ship.bulletCoordinates[i][1] = 21;
    }

    if (i == 23 && Ship.bulletCoordinates[i][1] == 23) {

      Ship.bulletCoordinates[0][0] = Ship.positionX;
      Ship.bulletCoordinates[0][1] = 21;

    }

  }

}
