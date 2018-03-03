int score = 0;
int tickDuration = 10;

const byte litPixelsX_snake[49] = {3, 4, 6, 9, 12, 15, 17, 19, 20, 21, 2,  6,  7,  9,  9,  11, 13, 15, 17, 19, 3,  6,  8,  11, 13, 15, 16, 19, 20, 4,  6,  9,  11, 12, 13, 15, 17, 19,  2,  3,  6,  9, 11, 13, 15, 17, 19, 20, 21};
const byte litPixelsY_snake[49] = {9, 9, 9, 9, 9,  9,  9,  9,  9,  9,  10, 10, 10, 10, 11, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13};

const byte litPixelsX_minerun[73] = {4, 8, 10, 12, 15, 17, 18, 19, 4, 5, 7, 8, 10, 12, 13, 15, 17, 4, 6, 8, 10, 12, 14, 15, 17, 18, 4, 8, 10, 12, 15, 17, 4, 8, 10, 12, 15, 17, 18, 19, 6, 7, 10, 12, 14, 17, 6, 8, 10, 12, 14, 15, 17, 6, 7, 10, 12, 14, 16, 17, 6, 8, 10, 12, 14, 17, 6, 8, 10, 11, 12, 14, 17};
const byte litPixelsY_minerun[73] = {6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16};

const byte litPixelsX_spaceshoot[83] = {3, 4, 6, 7, 11, 15, 16, 18, 19, 20, 2, 6, 8, 10, 12, 14, 18, 3, 6, 7, 10, 12, 14, 18, 19, 4, 6, 10, 11, 12, 14, 18, 2, 3, 6, 10, 12, 15, 16, 18, 19, 20, 3, 4, 6, 8, 11, 15, 18, 19, 20, 2, 6, 8, 10, 12, 14, 16, 19, 3, 6, 7, 8, 10, 12, 14, 16, 19, 4, 6, 8, 10, 12, 14, 16, 19, 2, 3, 6, 8, 11, 15, 19};
const byte litPixelsY_spaceshoot[83] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16};

const byte litPixelsX_powercord[83] = {1,  2,  6,  9, 13, 15, 16, 17, 19, 20,  1,  3,  5,  7,  9, 13, 15, 19, 21,  1,  2,  5,  7,  9, 11, 13, 15, 16, 19, 20,  1,  5,  7,  9, 11, 13, 15, 19, 21,  1,  6, 10, 12, 15, 16, 17, 19, 21,  5,  6,  9, 12, 13, 16, 17,  4,  8, 10, 12, 14, 16, 18,  4, 8,  10, 12, 13, 16, 18,  4,  8, 10, 12, 14, 16, 18,  5,  6,  9, 12, 14, 16, 17};
const byte litPixelsY_powercord[83] = {6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  9,  9,  9,  9,  9,  9,  9,  9,  9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16};

const byte litPixelsX_pong[40] = {3, 4, 8, 11, 14, 17, 18, 19, 3,  5,  7,  9,  11, 12, 14, 16, 3,  4,  7,  9,  11, 13, 14, 16, 18, 19, 3, 7, 9, 11, 14, 16, 19, 3, 8, 11, 14, 17, 18, 19};
const byte litPixelsY_pong[40] = {9, 9, 9, 9,  9,  9,  9,  9,  10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13};

const byte litPixelsX_streetcross[90] = {1, 2, 4, 5, 6, 8, 9, 12, 13, 14, 16, 17, 18, 20, 21, 22, 0, 5, 8, 10, 12, 16, 21, 1, 5, 8, 9, 12, 13, 16, 17, 21, 2, 5, 8, 10, 12, 16, 21, 0, 1, 5, 8, 10, 12, 13, 14, 16, 17, 18, 21, 3, 4, 6, 7, 11, 15, 16, 19, 20, 2, 6, 8, 10, 12, 14, 18, 2, 6, 7, 10, 12, 15, 19, 2, 6, 8, 10, 12, 16, 20, 3, 4, 6, 8, 11, 14, 15, 18, 19};
const byte litPixelsY_streetcross[90] = {6, 6, 6, 6, 6, 6, 6, 6,  6,  6,  6,  6,  6,  6,  6,  6,  7, 7, 7,  7,  7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16, 16};

const byte litPixelsX_arrowmatch[98] = {2, 5, 6, 9, 10, 14, 17, 21, 1, 3, 5, 7, 9, 11, 13, 15, 17, 21, 1, 3, 5, 6, 9, 10, 13, 15, 17, 19, 21, 1, 2, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 1,  3,  5,  7,  9,  11, 14, 18, 20, 1,  5,  8,  11, 12, 13, 16, 17, 19, 21, 1,  2,  4,  5,  7,  9,  12, 15, 19, 21,  1,  3,  5,  7,  9, 12, 15, 19, 20, 21, 1,  5,  7,  8,  9,  12, 15, 19, 21, 1,  5,  7,  9,  12, 16, 17, 19, 21};
const byte litPixelsY_arrowmatch[98] = {6, 6, 6, 6, 6,  6,  6,  6,  7, 7, 7, 7, 7, 7,  7,  7,  7,  7,  8, 8, 8, 8, 8, 8,  8,  8,  8,  8,  8,  9, 9, 9, 9, 9, 9, 9,  9,  9,  9,  9,  9,  10, 10, 10, 10, 10, 10, 10, 10, 10, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16, 16};

const byte litPixelsX_ballcatch[76] = {4, 5, 9, 12, 16, 4, 6, 8, 10, 12, 16, 4, 5, 8, 10, 12, 16, 4, 6, 8, 9, 10, 12, 16, 4, 5, 8, 10, 12, 13, 14, 16, 17, 18, 3, 4, 7, 10, 11, 12, 15, 16, 18, 20, 2, 6, 8, 11, 14, 18, 20, 2, 6, 8, 11, 14, 18, 19, 20, 2, 6, 7, 8, 11, 14, 18, 20, 3, 4, 6, 8, 11, 15, 16, 18, 20};
const byte litPixelsY_ballcatch[76] = {6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16, 16};

const byte litPixelsX_quickreflex[97] = {4, 8, 10, 12, 15, 16, 18, 20, 3, 5, 8, 10, 12, 14, 18, 20, 3, 5, 8, 10, 12, 14, 18, 19, 3, 5, 8, 10, 12, 14, 18, 20, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 0, 1, 4, 5, 6, 8, 9, 10, 12, 16, 17, 18, 20, 22, 0, 2, 4, 8, 12, 16, 20, 22, 0, 1, 4, 5, 8, 9, 12, 16, 17, 21, 0, 2, 4, 8, 12, 16, 20, 22, 0, 2, 4, 5, 6, 8, 12, 13, 14, 16, 17, 18, 20, 22};
const byte litPixelsY_quickreflex[97] = {6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16};

const byte litPixelsX_underattack[104] = {2, 4, 6, 9, 11, 12, 15, 16, 17, 19, 20, 2, 4, 6, 7, 9, 11, 13, 15, 19, 21, 2, 4, 6, 8, 9, 11, 13, 15, 16, 19, 20, 2, 4, 6, 9, 11, 13, 15, 19, 21, 2, 3, 4, 6, 9, 11, 12, 15, 16, 17, 19, 21, 1, 4, 5, 6, 8, 9, 10, 13, 17, 18, 20, 22, 0, 2, 5, 9, 12, 14, 16, 20, 22, 0, 2, 5, 9, 12, 14, 16, 20, 21, 0, 1, 2, 5, 9, 12, 13, 14, 16, 20, 22, 0, 2, 5, 9, 12, 14, 17, 18, 20, 22};
const byte litPixelsY_underattack[104] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16};

const byte buttonUp = 48; //digital pin 48
const byte buttonDown = 49; //digital pin 49
const byte buttonLeft = 50; //digital pin 50
const byte buttonRight = 51; //digital pin 51
const byte speaker = 52; //digital pin 52
const byte extraGround = 53; //digital pin 53
byte arr[24][24] = {};
byte game = 0;

void setup() {

  pinMode(speaker, OUTPUT);
  pinMode(extraGround, OUTPUT);
  digitalWrite(extraGround, 0);
  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
  pinMode(buttonLeft, INPUT_PULLUP);
  pinMode(buttonRight, INPUT_PULLUP);

  for (byte i = 0; i < 24; i++) {

    pinMode(i, OUTPUT);
    pinMode(i + 24, OUTPUT);

  }
}

void loop() {
  unrenderScreen();

  while (digitalRead(buttonUp)) {
  drawLogo(game);

    if (!digitalRead(buttonLeft))tickDuration++;
    if (!digitalRead(buttonRight))tickDuration--;
    if (!digitalRead(buttonDown)) {
      game++;
      playSound(2);
      if (game > 9)game = 0;
    }
    if (tickDuration < 0)tickDuration = 0;
    if (tickDuration > 24)tickDuration = 24;
    wait(10);

  }

  randomSeed(micros());

  playSound(1);

  if (game == 0) {

    gameSnakeSetup();
    while (true) {
      gameSnakeLoop();
    }

    //loop snake
  }

  if (game == 1) {

    gameMineRunSetup();
    while (true) {
      gameMineRunLoop();
    }

    //loop minerun
  }

  if (game == 2) {

    gameSpaceShootSetup();
    while (true) {
      gameSpaceShootLoop();
    }

    //loop spaceshoot
  }

  if (game == 3) {

    gamePowerCordSetup();
    while (true) {
      gamePowerCordLoop();
    }

    //loop powercord
  }

  if (game == 4) {

    gamePongSetup();
    while (true) {
      gamePongLoop();
    }

    //loop pong
  }

  if (game == 5) {

    gameStreetCrossSetup();
    while (true) {
      gameStreetCrossLoop();
    }

    //loop streetcross
  }

  if (game == 6) {

    gameArrowMatchSetup();
    while (true) {
      gameArrowMatchLoop();
    }

    //loop arrowmatch
  }

  if (game == 7) {

    gameBallCatchSetup();
    while (true) {
      gameBallCatchLoop();
    }

    //loop ballcatch
  }

  if (game == 8) {

    gameQuickReflexSetup();
    while (true) {
      gameQuickReflexLoop();
    }

    //loop quickreflex
  }

  if (game == 9) {

    gameUnderAttackSetup();
    while (true) {
      gameUnderAttackLoop();
    }

    //loop underattack
  }

}

void drawTile(int x, int y) {

  arr[x][y] = true;

}

void clearTile(int x, int y) {

  arr[x][y] = false;

}

void clearScreen() { //including pin data

  for (byte i = 0; i < 24; i++) {
    for (byte j = 0; j < 24; j++) {
      arr[i][j] = 0;
    }
  }
}

void unrenderScreen() { //flashes the screen

  for (byte i = 0; i < 24; i++) {
    for (byte j = 0; j < 24; j++) {
      digitalWrite(i, HIGH);
      digitalWrite(j + 24, LOW);
    }
  }
}

void renderScreen() {

  for (byte i = 0; i < 24; i++) {
    digitalWrite(i, LOW);
    for (byte j = 0; j < 24; j++) {
      if (arr[i][j]) {
        digitalWrite(j + 24, HIGH);
      }
    }
    delayMicroseconds(10);
    for (byte j = 0; j < 24; j++) {
      if (arr[i][j]) {
        digitalWrite(j + 24, LOW);
      }
    }
    digitalWrite(i, HIGH);
  }
}


void endGame() {

  playSound(0);
  flashScreen();
  clearScreen();
  viewScore();
  resetGame();

}

void resetGame() {

  clearScreen();
  score = 0;
  reboot();

}

void drawLogo(byte game) {


  switch (game) {

    case 0 :  //Snake

      clearScreen();

      for (byte i = 0; i < 49; i++) {

        drawTile(litPixelsX_snake[i], litPixelsY_snake[i]);

      }

      break;

    case 1 : //Mine Run

      clearScreen();

      for (byte i = 0; i < 73; i++) {

        drawTile(litPixelsX_minerun[i], litPixelsY_minerun[i]);

      }

      break;


    case 2 :  //SpaceShoot

      clearScreen();

      for (byte i = 0; i < 83; i++) {

        drawTile(litPixelsX_spaceshoot[i], litPixelsY_spaceshoot[i]);

      }

      break;

    case 3 :  //PowerCord

      clearScreen();

      for (byte i = 0; i < 83; i++) {

        drawTile(litPixelsX_powercord[i], litPixelsY_powercord[i]);

      }

      break;

    case 4 :  //Pong

      clearScreen();

      for (byte i = 0; i < 40; i++) {

        drawTile(litPixelsX_pong[i], litPixelsY_pong[i]);

      }

      break;

    case 5 :  //StreetCross

      clearScreen();

      for (byte i = 0; i < 90; i++) {

        drawTile(litPixelsX_streetcross[i], litPixelsY_streetcross[i]);

      }

      break;

    case 6 :  //ArrowMatch

      clearScreen();

      for (byte i = 0; i < 98; i++) {

        drawTile(litPixelsX_arrowmatch[i], litPixelsY_arrowmatch[i]);

      }

      break;

    case 7 :  //BallCatch

      clearScreen();

      for (byte i = 0; i < 76; i++) {

        drawTile(litPixelsX_ballcatch[i], litPixelsY_ballcatch[i]);

      }

      break;

    case 8 :  //Quick Reflex

      clearScreen();

      for (byte i = 0; i < 97; i++) {

        drawTile(litPixelsX_quickreflex[i], litPixelsY_quickreflex[i]);

      }

      break;

    case 9 :  //Under Attack

      clearScreen();

      for (byte i = 0; i < 104; i++) {

        drawTile(litPixelsX_underattack[i], litPixelsY_underattack[i]);

      }

      break;

  }

  drawTickDuration();
  renderScreen();

}

void drawTickDuration() {

  for (byte i = 0; i < 24 - tickDuration; i++) {

    drawTile(i, 23);

  }

}

void flashScreen() {
  for (byte i = 0; i < 5; i++) {
    delay(240);
    wait(4);
  }
}

void viewScore() {
  //set the LEDs to show the score

  if (score < 10) {

    //Will render a specific digit
    renderScore(0, 1);
    renderScore(0, 2);
    renderScore(score, 3);

  } else if (score > 9 && score < 100) {

    byte digit1 = score % 10;
    byte digit2 = (score - digit1) / 10;

    //Will render two specific digits
    renderScore(0, 1);
    renderScore(digit2, 2);
    renderScore(digit1, 3);


  } else {

    byte digit1 = score % 10;
    byte digit2 = (score % 100 - digit1) / 10;
    byte digit3 = (score - (score % 100)) / 100;

    //Will render three specific digits
    renderScore(digit3, 1);
    renderScore(digit2, 2);
    renderScore(digit1, 3);


  }

  while (digitalRead(buttonDown)) {
    wait(1);
  }
}

void renderScore(byte digit, byte slot) {

  switch (digit) {

    case 0:

      switch (slot) {

        case 1:

          drawTile(6, 9);
          drawTile(7, 9);
          drawTile(8, 9);
          drawTile(6, 10);
          drawTile(8, 10);
          drawTile(6, 11);
          drawTile(8, 11);
          drawTile(6, 12);
          drawTile(8, 12);
          drawTile(6, 13);
          drawTile(7, 13);
          drawTile(8, 13);

          break;
        case 2:

          drawTile(10, 9);
          drawTile(11, 9);
          drawTile(12, 9);
          drawTile(10, 10);
          drawTile(12, 10);
          drawTile(10, 11);
          drawTile(12, 11);
          drawTile(10, 12);
          drawTile(12, 12);
          drawTile(10, 13);
          drawTile(11, 13);
          drawTile(12, 13);

          break;
        case 3:

          drawTile(14, 9);
          drawTile(15, 9);
          drawTile(16, 9);
          drawTile(14, 10);
          drawTile(16, 10);
          drawTile(14, 11);
          drawTile(16, 11);
          drawTile(14, 12);
          drawTile(16, 12);
          drawTile(14, 13);
          drawTile(15, 13);
          drawTile(16, 13);

          break;

      }

      break;

    case 1:

      switch (slot) {

        case 1:

          drawTile(8, 9);
          drawTile(8, 10);
          drawTile(8, 11);
          drawTile(8, 12);
          drawTile(8, 13);

          break;
        case 2:

          drawTile(12, 9);
          drawTile(12, 10);
          drawTile(12, 11);
          drawTile(12, 12);
          drawTile(12, 13);

          break;
        case 3:

          drawTile(16, 9);
          drawTile(16, 10);
          drawTile(16, 11);
          drawTile(16, 12);
          drawTile(16, 13);

          break;

      }

      break;

    case 2:

      switch (slot) {

        case 1:

          drawTile(6, 9);
          drawTile(7, 9);
          drawTile(8, 9);
          drawTile(8, 10);
          drawTile(6, 11);
          drawTile(7, 11);
          drawTile(8, 11);
          drawTile(6, 12);
          drawTile(6, 13);
          drawTile(7, 13);
          drawTile(8, 13);

          break;
        case 2:

          drawTile(10, 9);
          drawTile(11, 9);
          drawTile(12, 9);
          drawTile(12, 10);
          drawTile(10, 11);
          drawTile(11, 11);
          drawTile(12, 11);
          drawTile(10, 12);
          drawTile(10, 13);
          drawTile(11, 13);
          drawTile(12, 13);

          break;
        case 3:

          drawTile(14, 9);
          drawTile(15, 9);
          drawTile(16, 9);
          drawTile(16, 10);
          drawTile(14, 11);
          drawTile(15, 11);
          drawTile(16, 11);
          drawTile(14, 12);
          drawTile(14, 13);
          drawTile(15, 13);
          drawTile(16, 13);

          break;

      }

      break;

    case 3:

      switch (slot) {

        case 1:

          drawTile(6, 9);
          drawTile(7, 9);
          drawTile(8, 9);
          drawTile(8, 10);
          drawTile(6, 11);
          drawTile(7, 11);
          drawTile(8, 11);
          drawTile(8, 12);
          drawTile(6, 13);
          drawTile(7, 13);
          drawTile(8, 13);

          break;
        case 2:

          drawTile(10, 9);
          drawTile(11, 9);
          drawTile(12, 9);
          drawTile(12, 10);
          drawTile(10, 11);
          drawTile(11, 11);
          drawTile(12, 11);
          drawTile(12, 12);
          drawTile(10, 13);
          drawTile(11, 13);
          drawTile(12, 13);

          break;
        case 3:

          drawTile(14, 9);
          drawTile(15, 9);
          drawTile(16, 9);
          drawTile(16, 10);
          drawTile(14, 11);
          drawTile(15, 11);
          drawTile(16, 11);
          drawTile(16, 12);
          drawTile(14, 13);
          drawTile(15, 13);
          drawTile(16, 13);

          break;

      }

      break;

    case 4:

      switch (slot) {

        case 1:

          drawTile(6, 9);
          drawTile(8, 9);
          drawTile(6, 10);
          drawTile(8, 10);
          drawTile(6, 11);
          drawTile(7, 11);
          drawTile(8, 11);
          drawTile(8, 12);
          drawTile(8, 13);

          break;
        case 2:

          drawTile(10, 9);
          drawTile(12, 9);
          drawTile(10, 10);
          drawTile(12, 10);
          drawTile(10, 11);
          drawTile(11, 11);
          drawTile(12, 11);
          drawTile(12, 12);
          drawTile(12, 13);

          break;
        case 3:

          drawTile(14, 9);
          drawTile(16, 9);
          drawTile(14, 10);
          drawTile(16, 10);
          drawTile(14, 11);
          drawTile(15, 11);
          drawTile(16, 11);
          drawTile(16, 12);
          drawTile(16, 13);

          break;

      }

      break;

    case 5:

      switch (slot) {

        case 1:

          drawTile(6, 9);
          drawTile(7, 9);
          drawTile(8, 9);
          drawTile(6, 10);
          drawTile(6, 11);
          drawTile(7, 11);
          drawTile(8, 11);
          drawTile(8, 12);
          drawTile(6, 13);
          drawTile(7, 13);
          drawTile(8, 13);

          break;
        case 2:

          drawTile(10, 9);
          drawTile(11, 9);
          drawTile(12, 9);
          drawTile(10, 10);
          drawTile(10, 11);
          drawTile(11, 11);
          drawTile(12, 11);
          drawTile(12, 12);
          drawTile(10, 13);
          drawTile(11, 13);
          drawTile(12, 13);

          break;
        case 3:

          drawTile(14, 9);
          drawTile(15, 9);
          drawTile(16, 9);
          drawTile(14, 10);
          drawTile(14, 11);
          drawTile(15, 11);
          drawTile(16, 11);
          drawTile(16, 12);
          drawTile(14, 13);
          drawTile(15, 13);
          drawTile(16, 13);

          break;

      }

      break;

    case 6:

      switch (slot) {

        case 1:

          drawTile(6, 9);
          drawTile(7, 9);
          drawTile(8, 9);
          drawTile(6, 10);
          drawTile(6, 11);
          drawTile(7, 11);
          drawTile(8, 11);
          drawTile(6, 12);
          drawTile(8, 12);
          drawTile(6, 13);
          drawTile(7, 13);
          drawTile(8, 13);

          break;
        case 2:

          drawTile(10, 9);
          drawTile(11, 9);
          drawTile(12, 9);
          drawTile(10, 10);
          drawTile(10, 11);
          drawTile(11, 11);
          drawTile(12, 11);
          drawTile(10, 12);
          drawTile(12, 12);
          drawTile(10, 13);
          drawTile(11, 13);
          drawTile(12, 13);

          break;
        case 3:

          drawTile(14, 9);
          drawTile(15, 9);
          drawTile(16, 9);
          drawTile(14, 10);
          drawTile(14, 11);
          drawTile(15, 11);
          drawTile(16, 11);
          drawTile(14, 12);
          drawTile(16, 12);
          drawTile(14, 13);
          drawTile(15, 13);
          drawTile(16, 13);

          break;

      }

      break;

    case 7:

      switch (slot) {

        case 1:

          drawTile(6, 9);
          drawTile(7, 9);
          drawTile(8, 9);
          drawTile(8, 10);
          drawTile(8, 11);
          drawTile(8, 12);
          drawTile(8, 13);

          break;
        case 2:

          drawTile(10, 9);
          drawTile(11, 9);
          drawTile(12, 9);
          drawTile(12, 10);
          drawTile(12, 11);
          drawTile(12, 12);
          drawTile(12, 13);

          break;
        case 3:

          drawTile(14, 9);
          drawTile(15, 9);
          drawTile(16, 9);
          drawTile(16, 10);
          drawTile(16, 11);
          drawTile(16, 12);
          drawTile(16, 13);

          break;

      }

      break;

    case 8:

      switch (slot) {

        case 1:

          drawTile(6, 9);
          drawTile(7, 9);
          drawTile(8, 9);
          drawTile(6, 10);
          drawTile(8, 10);
          drawTile(6, 11);
          drawTile(7, 11);
          drawTile(8, 11);
          drawTile(6, 12);
          drawTile(8, 12);
          drawTile(6, 13);
          drawTile(7, 13);
          drawTile(8, 13);

          break;
        case 2:

          drawTile(10, 9);
          drawTile(11, 9);
          drawTile(12, 9);
          drawTile(10, 10);
          drawTile(12, 10);
          drawTile(10, 11);
          drawTile(11, 11);
          drawTile(12, 11);
          drawTile(10, 12);
          drawTile(12, 12);
          drawTile(10, 13);
          drawTile(11, 13);
          drawTile(12, 13);

          break;
        case 3:

          drawTile(14, 9);
          drawTile(15, 9);
          drawTile(16, 9);
          drawTile(14, 10);
          drawTile(16, 10);
          drawTile(14, 11);
          drawTile(15, 11);
          drawTile(16, 11);
          drawTile(14, 12);
          drawTile(16, 12);
          drawTile(14, 13);
          drawTile(15, 13);
          drawTile(16, 13);

          break;

      }

      break;

    case 9:

      switch (slot) {

        case 1:

          drawTile(6, 9);
          drawTile(7, 9);
          drawTile(8, 9);
          drawTile(6, 10);
          drawTile(8, 10);
          drawTile(6, 11);
          drawTile(7, 11);
          drawTile(8, 11);
          drawTile(8, 12);
          drawTile(6, 13);
          drawTile(7, 13);
          drawTile(8, 13);

          break;
        case 2:

          drawTile(10, 9);
          drawTile(11, 9);
          drawTile(12, 9);
          drawTile(10, 10);
          drawTile(12, 10);
          drawTile(10, 11);
          drawTile(11, 11);
          drawTile(12, 11);
          drawTile(12, 12);
          drawTile(10, 13);
          drawTile(11, 13);
          drawTile(12, 13);

          break;
        case 3:

          drawTile(14, 9);
          drawTile(15, 9);
          drawTile(16, 9);
          drawTile(14, 10);
          drawTile(16, 10);
          drawTile(14, 11);
          drawTile(15, 11);
          drawTile(16, 11);
          drawTile(16, 12);
          drawTile(14, 13);
          drawTile(15, 13);
          drawTile(16, 13);

          break;

      }

      break;

  }

}

void wait(short time) {

  for (short i = 0; i < time * 10; i++) {

    renderScreen();

  }

}

int randomInteger(int min_, int max_) {

  return floor(random(min_, max_));

  

}

void reboot() {

  asm volatile ("  jmp 0");

}

void playSound(byte sound) {

  if (!sound) { //Game Over

    tone(speaker, 400, 150);
    delay(150);
    tone(speaker, 300, 150);
    delay(150);
    tone(speaker, 200, 150);
    delay(150);
    tone(speaker, 100, 650);
    delay(655);

  }

  if (sound == 1) { //Select Game

    tone(speaker, 200, 150);
    delay(150);
    tone(speaker, 300, 10);
    delay(10);
    tone(speaker, 350, 10);
    delay(10);
    tone(speaker, 400, 10);
    delay(10);
    tone(speaker, 450, 10);
    delay(10);
    tone(speaker, 500, 10);
    delay(10);
    tone(speaker, 550, 10);
    delay(10);
    tone(speaker, 600, 10);
    delay(10);
    tone(speaker, 700, 10);
    delay(10);
    tone(speaker, 800, 10);
    delay(10);
    tone(speaker, 1000, 10);
    delay(10);
    tone(speaker, 1200, 10);
    delay(10);
    tone(speaker, 1500, 10);
    delay(15);

  }

  if (sound == 2) { //Correct Arrow

    tone(speaker, 1600, 50);

  }

  if (sound == 3) { //Snake Food Eat

    tone(speaker, 2147, 129);

  }

}
