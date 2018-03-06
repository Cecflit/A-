class GamePowerCord {
  public:
    byte gamePowerCordOrientation;
    bool gamePowerCordLastPressed;
    byte gamePowerCordPass;
    
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
      gamePowerCordOrientation = randomInteger(0, 4);
      gamePowerCordLastPressed = !(digitalRead(buttonUp) && digitalRead(buttonDown) && digitalRead(buttonLeft) && digitalRead(buttonRight));
    
    }
    
    void gamePowerCordLoop() {
    
      randomSeed(micros());
      while (Moving.pos == Dormant.pos) {
        Moving.pos = randomInteger(0, 24);
        Dormant.pos = randomInteger(0, 24);
      }
      gamePowerCordOrientation = randomInteger(0, 4);
      gamePowerCordDrawLines();
    
      while (!gamePowerCordAnyPressed()) {
        //gamePowerCordRenderListen(false);
        wait(2 * (tickDuration + 1));
      }
      while (gamePowerCordAnyPressed()) {
        gamePowerCordRenderListen(false);
        wait(2 * (tickDuration + 1));
      }
      if (Moving.pos == Dormant.pos) {
        playSound(2);
        score++;
        if(score > 999)score = 999;
      } else {
        endGame();
      }
      if (score > 25) {
        while (score < 50) {
          gamePowerCordLoop25();
        }
        while (score >= 50 && score < 75) {
          gamePowerCordLoop50();
        }
        while (score >= 75) {
          gamePowerCordLoop75();
        }
      }
    
    }
    
    void gamePowerCordLoop25() {
    
      randomSeed(micros());
      while (Moving.pos == Dormant.pos) {
        Moving.pos = randomInteger(0, 24);
        Dormant.pos = randomInteger(0, 24);
      }
      gamePowerCordOrientation = randomInteger(0, 4);
      gamePowerCordDrawLines();
    
      while (!gamePowerCordAnyPressed()) {
        //gamePowerCordRenderListen(false);
        wait(tickDuration + 1);
      }
      while (gamePowerCordAnyPressed()) {
        gamePowerCordRenderListen(false);
        wait(tickDuration + 1);
      }
      if (Moving.pos == Dormant.pos) {
        playSound(2);
        score++;
        if(score > 999)score = 999;
      } else {
        endGame();
      }
    }
    
    void gamePowerCordLoop50() {
      randomSeed(micros());
      while (Moving.pos == Dormant.pos) {
        Moving.pos = randomInteger(0, 24);
        Dormant.pos = randomInteger(0, 24);
      }
      gamePowerCordOrientation = randomInteger(0, 4);
      gamePowerCordDrawLines();
    
      while (!gamePowerCordAnyPressed()) {
        //gamePowerCordRenderListen(true);
        wait(tickDuration + 1);
      }
      while (gamePowerCordAnyPressed()) {
        gamePowerCordRenderListen(true);
        wait(tickDuration + 1);
      }
      if (Moving.pos == Dormant.pos) {
        playSound(2);
        score++;
        if(score > 999)score = 999;
      } else {
        endGame();
      }
    }
    
    void gamePowerCordLoop75() {
      randomSeed(micros());
      while (Moving.pos == Dormant.pos) {
        Moving.pos = randomInteger(0, 24);
        Dormant.pos = randomInteger(0, 24);
      }
      gamePowerCordOrientation = randomInteger(0, 4);
      gamePowerCordDrawLines();
    
      while (!gamePowerCordAnyPressed()) {
        //gamePowerCordRenderListen(true);
        wait(tickDuration + 1);
      }
      while (gamePowerCordAnyPressed()) {
        gamePowerCordRenderListen(2);
        wait(tickDuration + 1);
      }
      if (Moving.pos == Dormant.pos) {
        playSound(2);
        score++;
        if(score > 999)score = 999;
      } else {
        endGame();
      }
    }
    
    bool gamePowerCordAnyPressed() {
    
      return !(digitalRead(buttonUp) && digitalRead(buttonDown) && digitalRead(buttonLeft) && digitalRead(buttonRight));
    
    }
    
    void gamePowerCordRenderListen(byte both) {
      gamePowerCordPass++;
      if (!both || both == 2 || (both == 1 && (gamePowerCordPass % 2))) {
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
      }
    
      if (both && !(gamePowerCordPass % 2)) {
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
    
      if (!gamePowerCordOrientation) {
    
        for (byte i = 0; i < 12; i++) {
    
          drawTile(i, Dormant.pos);
          drawTile(i + 12, Moving.pos);
    
        }
    
      } else if(gamePowerCordOrientation == 1) {
    
        for (byte i = 0; i < 12; i++) {
    
          drawTile(Dormant.pos, i);
          drawTile(Moving.pos, i + 12);
    
        }
      } else if(gamePowerCordOrientation == 2) {
    
        for (byte i = 0; i < 12; i++) {
    
          drawTile(Dormant.pos, i+12);
          drawTile(Moving.pos, i);
    
        }
      }  else if(gamePowerCordOrientation == 3) {
    
        for (byte i = 0; i < 12; i++) {
    
          drawTile(i+12, Dormant.pos);
          drawTile(i, Moving.pos);
    
        }
      }
    }
    
};
