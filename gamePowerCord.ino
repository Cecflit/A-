bool gamePowerCordOrientation;
bool gamePowerCordLastPressed;
long gamePowerCordPass;

class line {

  public:
    int pos = 0;
    bool forw = true;
    line() {}

};

line Moving = line();
line Dormant = line();

void gamePowerCordSetup() {

  gamePowerCordPass = 0;
  Dormant.forw = false;
  clearScreen();
  score = 0;
  Moving.pos = randomInteger(0, 24);
  Dormant.pos = randomInteger(0, 24);
  gamePowerCordOrientation = randomInteger(0, 2);
  gamePowerCordLastPressed = !(digitalRead(buttonUp) && digitalRead(buttonDown) && digitalRead(buttonLeft) && digitalRead(buttonRight));

}

void gamePowerCordLoop() {

  randomSeed(micros());
  Moving.pos = randomInteger(0, 24);
  Dormant.pos = randomInteger(0, 24);
  gamePowerCordOrientation = randomInteger(0, 2);

  while (!gamePowerCordAnyPressed()) {
    gamePowerCordRenderListen(false);
    wait(2 * (tickDuration + 1));
  }
  while (gamePowerCordAnyPressed()) {
    gamePowerCordRenderListen(false);
    wait(2 * (tickDuration + 1));
  }
  if (Moving.pos == Dormant.pos) {
    playSound(2);
    score++;
  } else {
    endGame();
  }
  if (score > 24) {
    while (score < 50) {
      gamePowerCordLoop25();
    }
    while (score >= 50) {
      gamePowerCordLoop50();
    }
  }

}

void gamePowerCordLoop25() {

  randomSeed(micros());
  Moving.pos = randomInteger(0, 24);
  Dormant.pos = randomInteger(0, 24);
  gamePowerCordOrientation = randomInteger(0, 2);

  while (!gamePowerCordAnyPressed()) {
    gamePowerCordRenderListen(false);
    wait(tickDuration + 1);
  }
  while (gamePowerCordAnyPressed()) {
    gamePowerCordRenderListen(false);
    wait(tickDuration + 1);
  }
  if (Moving.pos == Dormant.pos) {
    playSound(2);
    score++;
  } else {
    endGame();
  }
}

void gamePowerCordLoop50() {
  randomSeed(micros());
  Moving.pos = randomInteger(0, 24);
  Dormant.pos = randomInteger(0, 24);
  gamePowerCordOrientation = randomInteger(0, 2);

  while (!gamePowerCordAnyPressed()) {
    gamePowerCordRenderListen(true);
    wait(tickDuration + 1);
  }
  while (gamePowerCordAnyPressed()) {
    gamePowerCordRenderListen(true);
    wait(tickDuration + 1);
  }
  if (Moving.pos == Dormant.pos) {
    playSound(2);
    score++;
  } else {
    endGame();
  }
}

bool gamePowerCordAnyPressed() {

  return !(digitalRead(buttonUp) && digitalRead(buttonDown) && digitalRead(buttonLeft) && digitalRead(buttonRight));

}

void gamePowerCordRenderListen(bool both) {
  gamePowerCordPass++;
  if (Moving.forw) {
    Moving.pos++;
    if (Moving.pos >= 23) {
      Moving.forw = false;
      Moving.pos = 23;
    }
  } else {
    Moving.pos--;
    if (Moving.pos <= 0) {
      Moving.forw = true;
      Moving.pos = 0;
    }
  }

  if (both && gamePowerCordPass % 2) {
    if (Dormant.forw) {
      Dormant.pos++;
      if (Dormant.pos >= 23) {
        Dormant.forw = false;
        Dormant.pos = 23;
      }
    } else {
      Dormant.pos--;
      if (Dormant.pos <= 0) {
        Dormant.forw = true;
        Dormant.pos = 0;
      }
    }
  }

  gamePowerCordDrawLines();
}

void gamePowerCordRenderListen10() {

}

void gamePowerCordDrawLines() {

  clearScreen();

  if (gamePowerCordOrientation) {

    for (byte i = 0; i < 12; i++) {

      drawTile(i, Dormant.pos);
      drawTile(i + 12, Moving.pos);

    }

  } else {

    for (byte i = 0; i < 12; i++) {

      drawTile(Dormant.pos, i);
      drawTile(Moving.pos, i + 12);

    }
  }
}
