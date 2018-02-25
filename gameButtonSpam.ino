float gameButtonSpamTime = 0;
bool gameButtonSpamPressed = false;

void gameButtonSpamSetup() {
  
  gameButtonSpamTime = 24.99;
  gameButtonSpamDrawTimer();
  gameButtonSpamPressed = false;
  score = 0;
  while (digitalRead(buttonLeft) && digitalRead(buttonRight) && digitalRead(buttonUp) && digitalRead(buttonDown)) {

    wait(1);

  }

}

void gameButtonSpamLoop() {

  gameButtonSpamLetPress();
  wait(tickDuration + 1);
  clearScreen();
  gameButtonSpamTime -= 0.6;
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

  for (int i = 0; i </* 24 - */int(gameButtonSpamTime); i++) {

  drawTile(0, 0);


    for (int j = 0; j < 24; j++) {

      drawTile(j, i);

    }



  }

}
