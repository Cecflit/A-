class GameJump : public Game {
  private:

    class Penguin {

      public:
        char positionX;
        char positionY;
        byte jumpCounter;
        Penguin() {}
    };
    byte loopCounter;
    byte biome; //0 = LAND; 1 = JUMPS
    Penguin Tux = Penguin();
    Penguin Jumpy = Penguin();

  public:

    GameJump() :
      loopCounter(0),
      biome(0)
    {
      score = 0;
      clearScreen();
      Tux.jumpCounter = 0;
      Jumpy.jumpCounter = 0;
      Jumpy.positionX = -1;
      Jumpy.positionY = 5;
      generateInit();
    }

    void Loop() {
      loopCounter++;
      if (loopCounter >= 60) {
        loopCounter = 0;
        //biome = randomInteger(0, 2);
      }
      letMove();
      moveJumpy();
      if (!(checkCollisionDown()) && !Tux.jumpCounter)moveDown();
      if (checkCollisionWithJumpy())endGame();
      if (checkCollisionWithCoin()) {
        score++;
        playSound(3);
      }
      drawScene();
      quickWait(tickDuration + 4);
    }

  private:

    void moveJumpy() {
      clearScene(true);
      if(Jumpy.jumpCounter && Jumpy.positionX >= 0) {
        Jumpy.positionY--;
        Jumpy.jumpCounter--;
      } else if (Jumpy.positionX >= 0 && (arr[(byte)Jumpy.positionX][(byte)Jumpy.positionY+1]) != 2) {
        Jumpy.positionY++;
      }
      if(Jumpy.positionX >= 0) {
        if(arr[(byte)Jumpy.positionX][(byte)Jumpy.positionY+1] == 2) {
          Jumpy.jumpCounter = 6;
        }
      }
    }

    void moveScreen() {

      clearScene();
      if (Jumpy.positionX >= 0)Jumpy.positionX--;
      for (byte i = 0; i < 23; i++) {
        for (byte j = 0; j < 24; j++) {
          arr[i][j] = arr[i + 1][j];
        }
      }
      drawScene();
      for (byte i = 0; i < 24; i++) {

        clearTile(23, i);

      }
      generate();
    }

    void generate() {

      generateColumn(23);
      if (!(randomInteger(0, 7)))placeCoin();

    }

    void generateColumn(byte column) {

      if (column) {

        char height;
        for (byte i = 0; i < 24; i++) {
          if (arr[column - 1][23 - i] != 2) {
            height = i - 1;
            break;
          } else {
            height = 23;
          }
        }

        if (!(randomInteger(0, 6)))height += (char)randomInteger(-6, 4);
        if (height > 15)height = 15;
        if (height < 1)height = 1;
        for (byte i = 0; i <= height; i++) {
          arr[column][23 - i] = 2;
        }

      } else {

        char height = randomInteger(5, 12);
        for (byte i = 0; i <= height; i++) {
          arr[0][23 - i] = 2;
        }

      }

      if (column == 23 && !(randomInteger(0, 11)) && Jumpy.positionX < 0 && !biome) {
        placeJumpy();
      }

    }

    void generateInit() {

      for (byte i = 0; i < 24; i++) {
        generateColumn(i);
      }
      placeTux();

    }

    void placeCoin() {

      for (byte i = 0; i < 24; i++) {
        if (arr[23][i] == 2) {
          arr[23][i - 1] = 5;
          break;
        }
      }

    }

    void moveLeft() {

      if (checkCollisionWithCoin(2)) {
        score++;
        playSound(3);
      }
      clearTile(Tux.positionX, Tux.positionY);
      Tux.positionX--;
      if (Tux.positionX < 0)Tux.positionX = 0;

    }

    void moveRight() {


      if (checkCollisionWithCoin(1)) {
        score++;
        playSound(3);
      }
      clearTile(Tux.positionX, Tux.positionY);
      Tux.positionX++;
      if (Tux.positionX > 8) {
        Tux.positionX = 8;
        moveScreen();
      }
    }

    void moveUp() {


      clearTile(Tux.positionX, Tux.positionY);
      Tux.positionY--;
      Tux.jumpCounter--;

    }

    void moveDown() {

      if (checkCollisionWithCoin(3)) {
        score++;
        playSound(3);
      }
      clearTile(Tux.positionX, Tux.positionY);
      Tux.positionY++;
      drawTile(Tux.positionX, Tux.positionY);

    }

    void letMove() {

      if (!(digitalRead(buttonLeft))) {

        if (!(checkCollisionLeft())) {
          moveLeft();
        }

      }

      if (!(digitalRead(buttonRight))) {

        if (!(checkCollisionRight())) {
          moveRight();
        }

      }

      if (!(digitalRead(buttonUp))) {
        if (arr[(byte)Tux.positionX][(byte)Tux.positionY + 1] == 2) {
          Tux.jumpCounter = 6;
          moveUp();
        } else if (Tux.jumpCounter) {
          moveUp();
        }
      } else {
        Tux.jumpCounter = 0;
      }

    }

    bool checkCollisionDown() {

      if (arr[(byte)Tux.positionX][(byte)Tux.positionY + 1] == 2) {
        return true;
      }

      return false;

    }

    bool checkCollisionLeft() {

      if (arr[(byte)Tux.positionX - 1][(byte)Tux.positionY] == 2 || Tux.positionX <= 0) {
        return true;
      }

      return false;

    }

    bool checkCollisionRight() {

      if (arr[(byte)Tux.positionX + 1][(byte)Tux.positionY] == 2) {
        return true;
      }

      return false;

    }

    bool checkCollisionWithCoin(byte a = 0) {

      if (!a) {
        if (arr[(byte)Tux.positionX][(byte)Tux.positionY] == 5) {
          return true;
        }

        return false;
      } else if (a == 1) {

        if (arr[(byte)Tux.positionX + 1][(byte)Tux.positionY] == 5) {
          return true;
        }

        return false;
      } else if (a == 2) {

        if (arr[(byte)Tux.positionX - 1][(byte)Tux.positionY] == 5) {
          return true;
        }

        return false;
      } else {

        if (arr[(byte)Tux.positionX][(byte)Tux.positionY + 1] == 5) {
          return true;
        }

        return false;
      }


    }

    bool checkCollisionWithJumpy() {

      if (Tux.positionX == Jumpy.positionX && Tux.positionY == Jumpy.positionY)return true;

      return false;

    }

    void placeTux() {

      Tux.positionX = 3;
      for (char i = 23; i; i--) {
        if ((arr[3][(byte)i]) != 2) {
          Tux.positionY = i - 2;
          break;
        }
      }

    }

    void placeJumpy() {

      Jumpy.positionX = 23;
      for (char i = 23; i > 0; i--) {
        if (!(arr[23][(byte)i])) {
          Jumpy.positionY = i - 1;
          break;
        }
      }

    }

    void drawScene(bool jmp = false) {

      if (Tux.positionY >= 0 && !jmp)drawTile(Tux.positionX, Tux.positionY);
      if(Jumpy.positionX >= 0 && Jumpy.positionY >= 0)drawTile(Jumpy.positionX, Jumpy.positionY);

    }

    void clearScene(bool jmp = false) {

      if (Tux.positionY >= 0 && !jmp)clearTile(Tux.positionX, Tux.positionY);
      if (Jumpy.positionX >= 0 && Jumpy.positionY >= 0)clearTile(Jumpy.positionX, Jumpy.positionY);

    }

};
