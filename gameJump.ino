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
    Penguin OverJumpy = Penguin();

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
      OverJumpy.positionX = -1;
      OverJumpy.positionY = 4;
      generateInit();
    }

    void Loop() {
      if (loopCounter >= 60) {
        loopCounter = 0;
        biome = randomInteger(0, 2);
      }
      letMove();
      moveJumpy();
      if (!(checkCollisionDown()) && !Tux.jumpCounter) {
        moveDown();
        if (checkCollisionWithVoid())endGame();
      }
      if (checkCollisionWithJumpy() || checkCollisionWithVoid())endGame();
      if (checkCollisionWithCoin()) {
        score++;
        playSound(3);
      }
      drawScene();
      quickWait(2 * tickDuration + 1);
    }

  private:

    void moveJumpy() {
      clearScene(true);
      if (Jumpy.jumpCounter && Jumpy.positionX >= 0) {
        Jumpy.positionY--;
        Jumpy.jumpCounter--;
      } else if (Jumpy.positionX >= 0 && (arr[(byte)Jumpy.positionX][(byte)Jumpy.positionY + 1]) != 2) {
        Jumpy.positionY++;
      }
      if (Jumpy.positionX >= 0) {
        if (arr[(byte)Jumpy.positionX][(byte)Jumpy.positionY + 1] == 2) {
          Jumpy.jumpCounter = 5;
        }
      }
      OverJumpy.positionX = Jumpy.positionX;
      OverJumpy.positionY = Jumpy.positionY - 1;
    }

    void moveScreen() {

      loopCounter++;
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
      /*
         BIOMES::

         0 = LAND - no holes, no crazy terrain, no ceiling, 10% jumpies, 1/7 coins
         1 = JUMPS - mostly holes up to 5 pixels wide, no crazy terrain, no ceiling, 0% jumpies, 1/2 coins on land

      */
      if (!biome) {

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

          if (!(randomInteger(0, 6)))height += (char)randomInteger(-5, 5);
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

        if (column == 23 && !(randomInteger(0, 11)) && Jumpy.positionX < 0) {
          placeJumpy();
        }

      } else if (biome == 1) {

        char height;
        char width = getWidth();
        if (width < 0)width = 0;
        for (byte i = 1; i < 24; i++) {
          if (arr[23 - width - 1][i] == 2) {
            height = 24 - i;
            break;
          } else {
            height = 12;
          }
        }
        width = getWidth();
        if (!(randomInteger(0, 5)))height += (char)randomInteger(-2, 3);
        if (height > 15)height = 15;
        if (height < 3)height = 5;
        if ((width > 7) || ((width > 0 && width < 8) && !(randomInteger(0, 8))) || ((width < -5) && randomInteger(0, 15)) || (width < 0 && width >= -5)) {
          for (byte i = 0; i < height; i++) {
            arr[column][23 - i] = 2;
          }
        } else {
          for (byte i = 0; i < 24; i++) {
            arr[column][i] = 0;
          }
        }
          if (column == 23 && !(randomInteger(0, 11)) && Jumpy.positionX < 0 && width < -2 && arr[23][23] == 2) {
            placeJumpy();
        }

      }

    }

    char getWidth() {
      char res = 0;
      for (byte i = 1; i < 9; i++) {
        if (arr[23 - i][23] != 2) {
          res = i;
        } else {
          break;
        }
      }
      if (!res) {
        for (byte i = 1; i < 24; i++) {
          if (arr[23 - i][23] == 2) {
            res = 0 - i;
          } else {
            break;
          }
        }
      }
      return res;
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
      if (Tux.positionX == OverJumpy.positionX && Tux.positionY == OverJumpy.positionY)return true;
      return false;

    }

    bool checkCollisionWithVoid() {
      if (Tux.positionY >= 23)return true;
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
          Jumpy.positionY = i - randomInteger(1, 6);
          break;
        }
      }
      OverJumpy.positionX = Jumpy.positionX;
      OverJumpy.positionY = Jumpy.positionY - 1;
    }

    void drawScene(bool jmp = false) {

      if (Tux.positionY >= 0 && !jmp)drawTile(Tux.positionX, Tux.positionY);
      if (Jumpy.positionX >= 0 && Jumpy.positionY >= 0)drawTile(Jumpy.positionX, Jumpy.positionY);
      if (OverJumpy.positionX >= 0 && OverJumpy.positionY >= 0)drawTile(OverJumpy.positionX, OverJumpy.positionY);

    }

    void clearScene(bool jmp = false) {

      if (Tux.positionY >= 0 && !jmp)clearTile(Tux.positionX, Tux.positionY);
      if (Jumpy.positionX >= 0 && Jumpy.positionY >= 0)clearTile(Jumpy.positionX, Jumpy.positionY);
      if (OverJumpy.positionX >= 0 && OverJumpy.positionY >= 0)clearTile(OverJumpy.positionX, OverJumpy.positionY);

    }

};
