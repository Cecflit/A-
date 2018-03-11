class GameQuickReflex : public Game {
  private:
    
    GameArrowMatch gam;
    
    const byte QstX[16] = {9, 9, 10, 11, 12, 13, 14, 14, 14, 14, 13, 12, 11, 11, 11, 11};
    const byte QstY[16] = {7, 8, 6, 5, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 17};
    byte Sequence[5] = {};
    
  public:
    
    GameQuickReflex() :
      Game(),
      gam()
    {
      score = 0;  
    }
    
    ~GameQuickReflex() {}
    
    void Setup() {
    
      //score = 0;
    
    }
    
    void Loop() {
    
      NewSequence();
      ShowSequence();
      LetGuess();
    
    }
    
  private:
    
    //uses function gameArrowMatchDrawArrow from gameArrowMatch
    
    void LetGuess() {
    
      for (int i = 0; i < 5; i++) {
    
        if (Sequence[i] == 0) {
    
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
    
        if (Sequence[i] == 1) {
    
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
    
        if (Sequence[i] == 2) {
    
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
    
        if (Sequence[i] == 3) {
    
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
    
    void NewSequence() {
    
      for (byte i = 0; i < 5; i++) {
    
        Sequence[i] = randomInteger(0, 4);
    
      }
    
    }
    
    void ShowSequence() {
    
      clearScreen();
    
      for (byte i = 0; i < 5; i++) {
        wait(tickDuration + 5);
        gam.DrawArrow(Sequence[i]);
        wait(5*(tickDuration + 1));
        gam.DrawArrow(Sequence[i]);
      }
    
      for (int i = 0; i < 16; i++) {
    
        drawTile(QstX[i], QstY[i]);
    
      }
    
      wait(1);
    
    }
    
};
