class GameFlappyPixel : public Game {

  private:
  class bird {
    public:
      char positionY;
      bird() {}
  };

  class pipe {
    public:
      char positionX;
      byte holeSize;
      byte holeTopPosition;
      pipe() {}
  };

  bird Bird = bird();
  pipe Pipe0 = pipe();
  pipe Pipe1 = pipe();
  pipe Pipe2 = pipe();

  public:
    GameFlappyPixel():
      Game(),
      Bird(),
      Pipe0(),
      Pipe1(),
      Pipe2()
      {
        score = 0;
        Bird.positionY = 12;
        Pipe0.positionX = 7;
        Pipe1.positionX = 15;
        Pipe2.positionX = 23;
        Pipe0.holeSize = 5;
        Pipe1.holeSize = 5;
        Pipe2.holeSize = 5;
        Pipe0.holeTopPosition = 9;
        Pipe1.holeTopPosition = 10;
        Pipe2.holeTopPosition = 11;
        clearScreen();
      }

  ~GameFlappyPixel() {}

  void Loop() {
    
    moveObjects();
    drawScene();
    if(checkCollision()) {
      drawScene();
      endGame();   
    }
    if(Pipe0.positionX == 1 || Pipe1.positionX == 1 || Pipe2.positionX == 1) {
      playSound(2);
      score++;
      if(score > 999)score = 999;
    }
    quickWait((5*tickDuration) + 1);
    clearScreen();
    moveObjects(false);
    drawScene();
    if(checkCollision()) {
      drawScene();
      endGame();
    }
    quickWait((5*tickDuration) + 1);
    clearScreen();
        
  }

  private:      

  void moveObjects(bool pp = true) {

    if(pp) {
      Pipe0.positionX--;
      Pipe1.positionX--;
      Pipe2.positionX--;
    if(Pipe0.positionX < 0) {
      Pipe0.positionX = 23;
      Pipe0.holeSize = randomInteger(3, 7);
      Pipe0.holeTopPosition = randomInteger(0, 24 - Pipe0.holeSize);
    }
    if(Pipe1.positionX < 0) {
      Pipe1.positionX = 23;
      Pipe1.holeSize = randomInteger(3, 7);
      Pipe1.holeTopPosition = randomInteger(0, 24 - Pipe1.holeSize);
    }
    if(Pipe2.positionX < 0) {
      Pipe2.positionX = 23;
      Pipe2.holeSize = randomInteger(3, 7);
      Pipe2.holeTopPosition = randomInteger(0, 24 - Pipe2.holeSize);
    }}
    if(checkButton()) {
      Bird.positionY--;
      if(Bird.positionY < 0)Bird.positionY = 0;
    } else {
      Bird.positionY++;
      if(Bird.positionY > 23) {
        drawScene();
        endGame();
      }
    }
    
  }

  void drawScene() {

    for(byte i = 0; i < 24; i++) {
      drawTile(Pipe0.positionX, i);
      drawTile(Pipe1.positionX, i);
      drawTile(Pipe2.positionX, i);
    }

    for(byte i = 0; i < Pipe0.holeSize; i++) {
      clearTile(Pipe0.positionX, Pipe0.holeTopPosition + i);
    }
    for(byte i = 0; i < Pipe1.holeSize; i++) {
      clearTile(Pipe1.positionX, Pipe1.holeTopPosition + i);
    }
    for(byte i = 0; i < Pipe2.holeSize; i++) {
      clearTile(Pipe2.positionX, Pipe2.holeTopPosition + i);
    }
    drawTile(2, Bird.positionY);
    
  }

  bool checkCollision() {

    if((Pipe0.positionX == 2 && (Bird.positionY < Pipe0.holeTopPosition || Bird.positionY >= Pipe0.holeTopPosition + Pipe0.holeSize)) || (Pipe1.positionX == 2 && (Bird.positionY < Pipe1.holeTopPosition || Bird.positionY >= Pipe1.holeTopPosition + Pipe1.holeSize)) || (Pipe2.positionX == 2 && (Bird.positionY < Pipe2.holeTopPosition || Bird.positionY >= Pipe2.holeTopPosition + Pipe2.holeSize)))return true;
    return false;

    
  }

  bool checkButton() {

    if(!(digitalRead(buttonUp)) || !(digitalRead(buttonDown)) || !digitalRead(buttonLeft) || !digitalRead(buttonRight))return true;
    return false;
    
  }
  
};

