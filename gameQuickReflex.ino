const byte gameQuickReflexQstX[16] = {9, 9, 10, 11, 12, 13, 14, 14, 14, 14, 13, 12, 11, 11, 11, 11};
const byte gameQuickReflexQstY[16] = {7, 8, 6, 5, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 17};
byte gameQuickReflexSequence[5] = {};

void gameQuickReflexSetup() {

  score = 0;

}

void gameQuickReflexLoop() {

  gameQuickReflexNewSequence();
  gameQuickReflexShowSequence();
  gameQuickReflexLetGuess();

}

//uses function gameArrowMatchDrawArrow from gameArrowMatch

void gameQuickReflexLetGuess() {

  for (int i = 0; i < 5; i++) {

    if (gameQuickReflexSequence[i] == 0) {

      while (digitalRead(buttonUp) && digitalRead(buttonDown) && digitalRead(buttonLeft) && digitalRead(buttonRight)) {

        wait(1);

      }

      if (!digitalRead(buttonDown) || !digitalRead(buttonLeft) || !digitalRead(buttonRight))endGame();
      if (!digitalRead(buttonUp)) {

        while (!digitalRead(buttonUp)) {

          wait(1);

        }

        score++;
        playSound(2);

      }

    }

    if (gameQuickReflexSequence[i] == 1) {

      while (digitalRead(buttonUp) && digitalRead(buttonDown) && digitalRead(buttonLeft) && digitalRead(buttonRight)) {

        wait(1);

      }

      if (!digitalRead(buttonUp) || !digitalRead(buttonLeft) || !digitalRead(buttonRight))endGame();
      if (!digitalRead(buttonDown)) {

        while (!digitalRead(buttonDown)) {

          wait(1);

        }

        score++;
        playSound(2);

      }

    }

    if (gameQuickReflexSequence[i] == 2) {

      while (digitalRead(buttonUp) && digitalRead(buttonDown) && digitalRead(buttonLeft) && digitalRead(buttonRight)) {

        wait(1);

      }

      if (!digitalRead(buttonUp) || !digitalRead(buttonDown) || !digitalRead(buttonRight))endGame();
      if (!digitalRead(buttonLeft)) {

        while (!digitalRead(buttonLeft)) {

          wait(1);

        }

        score++;
        playSound(2);

      }

    }

    if (gameQuickReflexSequence[i] == 3) {

      while (digitalRead(buttonUp) && digitalRead(buttonDown) && digitalRead(buttonLeft) && digitalRead(buttonRight)) {

        wait(1);

      }

      if (!digitalRead(buttonUp) || !digitalRead(buttonDown) || !digitalRead(buttonLeft))endGame();
      if (!digitalRead(buttonRight)) {

        while (!digitalRead(buttonRight)) {

          wait(1);

        }

        score++;
        playSound(2);

      }

    }

  }

}

void gameQuickReflexNewSequence() {

  for (byte i = 0; i < 5; i++) {

    gameQuickReflexSequence[i] = randomInteger(0, 4);

  }

}

void gameQuickReflexShowSequence() {

  clearScreen();

  for (byte i = 0; i < 5; i++) {
    wait(tickDuration + 5);
    gameArrowMatchDrawArrow(gameQuickReflexSequence[i]);
    wait(5*(tickDuration + 1));
    gameArrowMatchDrawArrow(gameQuickReflexSequence[i]);
  }

  for (int i = 0; i < 16; i++) {

    drawTile(gameQuickReflexQstX[i], gameQuickReflexQstY[i]);

  }

  wait(1);

}
