class GameArrowMatch {
  public:
    
    char gameArrowMatchArrow;
    char gameArrowMatchTimer;
    char gameArrowMatchInGameTime;
    bool gameArrowMatchLastHold;
    const byte gameArrowMatchUpX[66] = {11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 10, 10, 10, 13, 13, 13, 9, 9, 9, 14, 14, 14, 8, 8, 8, 15, 15, 15, 7, 7, 16, 16, 6, 17, 6, 17, 5, 5, 18, 18};
    const byte gameArrowMatchUpY[66] = { 3,  3,  4,  4,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20,  4,  5,  6,  4,  5,  6, 5, 6, 7, 5,  6,  7,  6, 7, 8, 6,  7,  8,  7, 8, 7,  8,  8, 8,  9, 9,  9, 10, 9, 10};
    const byte gameArrowMatchLeftX[66] = {3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 4, 5, 6, 4, 5, 6, 5, 6, 7, 5, 6, 7, 6, 7, 8, 6, 7, 8, 7, 8, 7, 8, 8, 9, 8, 9, 9, 10, 9, 10};
    const byte gameArrowMatchLeftY[66] = {11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 10, 10, 10, 13, 13, 13, 9, 9, 9, 14, 14, 14, 8, 8, 8, 15, 15, 15, 7, 7, 16, 16, 6, 6, 17, 17, 5, 5, 18, 18};
    const byte gameArrowMatchDownX[66] = {11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 10, 10, 10, 13, 13, 13, 9, 9, 9, 14, 14, 14, 8, 8, 8, 15, 15, 15, 7, 7, 16, 16, 6, 6, 17, 17, 5, 5, 18, 18};
    const byte gameArrowMatchDownY[66] = {3,  3,  4,  4,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9,  10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 17, 18, 19, 17, 18, 19, 16, 17, 18, 16, 17, 18, 15, 16, 17, 15, 16, 17, 15, 16, 15, 16, 14, 15, 14, 15, 13, 14, 13, 14};
    const byte gameArrowMatchRightX[66] = {3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 17, 18, 19, 17, 18, 19, 16, 17, 18, 16, 17, 18, 15, 16, 17, 15, 16, 17, 15, 16, 15, 16, 14, 15, 14, 15, 13, 14, 13, 14};
    //left Y also used as right Y
    
    void gameArrowMatchSetup() {
    
      gameArrowMatchArrow = randomInteger(0, 3);
      gameArrowMatchTimer = 24;
      gameArrowMatchInGameTime = 0;
      gameArrowMatchLastHold = false;
      score = 0;
      clearScreen();
      gameArrowMatchNewArrow(false);
      gameArrowMatchDrawTime(gameArrowMatchTimer);
    
    }
    
    void gameArrowMatchLoop() {
    
      gameArrowMatchWaitWhileListening();
      gameArrowMatchInGameTime++;
      if (!(gameArrowMatchInGameTime % 2)) {
        gameArrowMatchTimer--;
        clearTile(gameArrowMatchTimer, 0);
      }
      if (!gameArrowMatchTimer)endGame();
      //clearScreen();
      //gameArrowMatchDrawArrow(gameArrowMatchArrow);
    }
    
    void gameArrowMatchNewArrow(byte clear_screen) {
    
      if (clear_screen) {
        gameArrowMatchDrawArrow(gameArrowMatchArrow);
      }
      gameArrowMatchArrow = randomInteger(0, 4);
      gameArrowMatchDrawArrow(gameArrowMatchArrow);
      //gameArrowMatchDrawTime(gameArrowMatchTimer);
    
    }
    
    void gameArrowMatchDrawArrow(byte arrow) {
    
      //clearScreen();
    
      //0up, 1down, 2left, 3right
      if (!arrow) {
    
        for (byte i = 0; i < 66; i++) {
    
          toggleTile(gameArrowMatchUpX[i], gameArrowMatchUpY[i]);
        }
    
      }
    
      if (arrow == 1) {
    
        for (byte i = 0; i < 66; i++) {
    
          toggleTile(gameArrowMatchDownX[i], gameArrowMatchDownY[i]);
        }
    
      }
    
      if (arrow == 2) {
    
        for (byte i = 0; i < 66; i++) {
    
          toggleTile(gameArrowMatchLeftX[i], gameArrowMatchLeftY[i]);
        }
    
      }
    
      if (arrow == 3) {
    
        for (byte i = 0; i < 66; i++) {
    
          toggleTile(gameArrowMatchRightX[i], gameArrowMatchLeftY[i]);
        }
    
      }
    }
    
    void gameArrowMatchLetTry() {
    
      if (!(digitalRead(buttonUp) && digitalRead(buttonDown) && digitalRead(buttonLeft) && digitalRead(buttonRight))) {
    
        if (!gameArrowMatchArrow) {
    
          if (!digitalRead(buttonUp)) {
            gameArrowMatchLastHold = true;
          } else {
            endGame();
          }
    
    
        }
    
        if (gameArrowMatchArrow == 1) {
    
          if (!digitalRead(buttonDown)) {
            gameArrowMatchLastHold = true;
          } else {
            endGame();
          }
    
    
        }
    
        if (gameArrowMatchArrow == 2) {
    
          if (!digitalRead(buttonLeft)) {
            gameArrowMatchLastHold = true;
          } else {
            endGame();
          }
    
    
        }
    
        if (gameArrowMatchArrow == 3) {
    
          if (!digitalRead(buttonRight)) {
            gameArrowMatchLastHold = true;
          } else {
            endGame();
          }
    
    
        }
    
      }
    
      if (gameArrowMatchLastHold && (digitalRead(buttonUp) && digitalRead(buttonDown) && digitalRead(buttonLeft) && digitalRead(buttonRight))) {
    
        gameArrowMatchLastHold = false;
        score++;
        gameArrowMatchNewArrow(true);
    
      }
    
    }
    
    void gameArrowMatchDrawTimer() {
    
      for (int i = 0; i < gameArrowMatchTimer; i++) {
    
        drawTile(i, 23);
    
      }
    
    }
    
    void gameArrowMatchWaitWhileListening() {
    
      for (int i = 0; i < (tickDuration + 1); i++) {
        gameArrowMatchLetTry();
        wait(1);
      }
    
    }
    
    void gameArrowMatchDrawTime(byte timer) {
    
      for(byte i = 0; i < timer; i++) {
    
          drawTile(i, 0);
        
        }
      
    }
    
};
