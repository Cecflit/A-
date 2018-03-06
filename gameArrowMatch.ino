class GameArrowMatch : public Game {
  public:
    
    char Arrow;
    char Timer;
    char InGameTime;
    bool LastHold;
    const byte UpX[66] = {11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 10, 10, 10, 13, 13, 13, 9, 9, 9, 14, 14, 14, 8, 8, 8, 15, 15, 15, 7, 7, 16, 16, 6, 17, 6, 17, 5, 5, 18, 18};
    const byte UpY[66] = { 3,  3,  4,  4,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20,  4,  5,  6,  4,  5,  6, 5, 6, 7, 5,  6,  7,  6, 7, 8, 6,  7,  8,  7, 8, 7,  8,  8, 8,  9, 9,  9, 10, 9, 10};
    const byte LeftX[66] = {3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 4, 5, 6, 4, 5, 6, 5, 6, 7, 5, 6, 7, 6, 7, 8, 6, 7, 8, 7, 8, 7, 8, 8, 9, 8, 9, 9, 10, 9, 10};
    const byte LeftY[66] = {11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 10, 10, 10, 13, 13, 13, 9, 9, 9, 14, 14, 14, 8, 8, 8, 15, 15, 15, 7, 7, 16, 16, 6, 6, 17, 17, 5, 5, 18, 18};
    const byte DownX[66] = {11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 11, 12, 10, 10, 10, 13, 13, 13, 9, 9, 9, 14, 14, 14, 8, 8, 8, 15, 15, 15, 7, 7, 16, 16, 6, 6, 17, 17, 5, 5, 18, 18};
    const byte DownY[66] = {3,  3,  4,  4,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9,  10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 17, 18, 19, 17, 18, 19, 16, 17, 18, 16, 17, 18, 15, 16, 17, 15, 16, 17, 15, 16, 15, 16, 14, 15, 14, 15, 13, 14, 13, 14};
    const byte RightX[66] = {3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 17, 18, 19, 17, 18, 19, 16, 17, 18, 16, 17, 18, 15, 16, 17, 15, 16, 17, 15, 16, 15, 16, 14, 15, 14, 15, 13, 14, 13, 14};
    //left Y also used as right Y
    
    void Setup() {
    
      Arrow = randomInteger(0, 3);
      Timer = 24;
      InGameTime = 0;
      LastHold = false;
      score = 0;
      clearScreen();
      NewArrow(false);
      DrawTime(Timer);
    
    }
    
    void Loop() {
    
      WaitWhileListening();
      InGameTime++;
      if (!(InGameTime % 2)) {
        Timer--;
        clearTile(Timer, 0);
      }
      if (!Timer)endGame();
      //clearScreen();
      //DrawArrow(Arrow);
    }
    
    void NewArrow(byte clear_screen) {
    
      if (clear_screen) {
        DrawArrow(Arrow);
      }
      Arrow = randomInteger(0, 4);
      DrawArrow(Arrow);
      //DrawTime(Timer);
    
    }
    
    void DrawArrow(byte arrow) {
    
      //clearScreen();
    
      //0up, 1down, 2left, 3right
      if (!arrow) {
    
        for (byte i = 0; i < 66; i++) {
    
          toggleTile(UpX[i], UpY[i]);
        }
    
      }
    
      if (arrow == 1) {
    
        for (byte i = 0; i < 66; i++) {
    
          toggleTile(DownX[i], DownY[i]);
        }
    
      }
    
      if (arrow == 2) {
    
        for (byte i = 0; i < 66; i++) {
    
          toggleTile(LeftX[i], LeftY[i]);
        }
    
      }
    
      if (arrow == 3) {
    
        for (byte i = 0; i < 66; i++) {
    
          toggleTile(RightX[i], LeftY[i]);
        }
    
      }
    }
    
    void LetTry() {
    
      if (!(digitalRead(buttonUp) && digitalRead(buttonDown) && digitalRead(buttonLeft) && digitalRead(buttonRight))) {
    
        if (!Arrow) {
    
          if (!digitalRead(buttonUp)) {
            LastHold = true;
          } else {
            endGame();
          }
    
    
        }
    
        if (Arrow == 1) {
    
          if (!digitalRead(buttonDown)) {
            LastHold = true;
          } else {
            endGame();
          }
    
    
        }
    
        if (Arrow == 2) {
    
          if (!digitalRead(buttonLeft)) {
            LastHold = true;
          } else {
            endGame();
          }
    
    
        }
    
        if (Arrow == 3) {
    
          if (!digitalRead(buttonRight)) {
            LastHold = true;
          } else {
            endGame();
          }
    
    
        }
    
      }
    
      if (LastHold && (digitalRead(buttonUp) && digitalRead(buttonDown) && digitalRead(buttonLeft) && digitalRead(buttonRight))) {
    
        LastHold = false;
        score++;
        NewArrow(true);
    
      }
    
    }
    
    void DrawTimer() {
    
      for (int i = 0; i < Timer; i++) {
    
        drawTile(i, 23);
    
      }
    
    }
    
    void WaitWhileListening() {
    
      for (int i = 0; i < (tickDuration + 1); i++) {
        LetTry();
        wait(1);
      }
    
    }
    
    void DrawTime(byte timer) {
    
      for(byte i = 0; i < timer; i++) {
    
          drawTile(i, 0);
        
        }
      
    }
    
};
