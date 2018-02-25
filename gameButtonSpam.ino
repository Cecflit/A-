float gameButtonSpamTime = 0;
bool gameButtonSpamPressed = false;

void gameButtonSpamSetup() {

  gameButtonSpamTime = 24.99;
  gameButtonSpamPressed = false;
  score = 0;
  while (digitalRead(buttonLeft) && digitalRead(buttonRight) && digitalRead(buttonUp) && digitalRead(buttonDown)) {

    delay(5);

  }

}

void gameButtonSpamLoop() {

  gameButtonSpamLetPress();
  wait(tickDuration + 1);
  gameButtonSpamTime -= 0.006;
  gameButtonSpamDrawTimer();
  if (gameButtonSpamTime <= 0.012)endGame();

}

void gameButtonSpamLetPress() {

  if (!gameButtonSpamPressed && (!digitalRead(buttonLeft) || !digitalRead(buttonRight) || !digitalRead(buttonUp) || !digitalRead(buttonDown))) {

    gameButtonSpamPressed = true;

  }

  if (gameButtonSpamPressed && (digitalRead(buttonLeft) && digitalRead(buttonRight) && digitalRead(buttonUp) && digitalRead(buttonDown))) {

    gameButtonSpamPressed = false;
    score++;
    if (score > 999)score = 999;

  }

}

void gameButtonSpamDrawTimer() {

  for (int i = -1; i < 24 - floor(gameButtonSpamTime); i++) {

    if (i >= 0) {

      for (int j = 0; j < 24; j++) {

        drawTile(j, 23 - i);

      }

    }

  }

}
