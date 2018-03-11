class GameTetris : public Game {
  private:

    bool LoopCounter = false;
    byte Next;

    class tetromino {

      public:
        byte bricksX[4];
        byte bricksY[4];
    };

    const tetromino bricks[7] = {{{0, 1, 2, 3}, {0, 0, 0, 0}}, {{0, 0, 1, 1}, {0, 1, 0, 1}}, {{0, 0, 0, 1}, {0, 1, 2, 2}}, {{1, 1, 1, 0}, {0, 1, 2, 2}}, {{0, 0, 1, 1}, {0, 1, 1, 2}}, {{1, 1, 0, 0}, {0, 1, 1, 2}}, {{0, 1, 1, 2}, {0, 0, 1, 0}}};
    tetromino falling;

  public:

    GameTetris() :
      Game(),
      LoopCounter(false),
      Next(randomInteger(0, 7)),
      falling()
    {
      clearScreen();
      score = 0;
      DrawScene();
      drawNew();
      New();
      Drop();
    }

    ~GameTetris() {}

    void Loop() {

      Drop();
      LetMove();
      if (LoopCounter)Move();
      Drop();
      wait(tickDuration + 1);
      LoopCounter = !LoopCounter;

    }

  private:

    void drawNew() {
      for (byte i = 0; i < 4; i++) {
        toggleTile(bricks[Next].bricksX[i] + 18, bricks[Next].bricksY[i] + 10);
      }
    }

    void Rotate() {

      char tetrisX[4];
      char tetrisY[4];
      char minX = 127;
      char maxX = -128;
      char minY = 127;
      char maxY = -128;
      char midX, midY;
      for (byte i = 0; i < 4; i++) {
        tetrisX[i] = falling.bricksX[i];
        tetrisY[i] = falling.bricksY[i];
        if (tetrisX[i] < minX) minX = tetrisX[i];
        if (tetrisX[i] > maxX) maxX = tetrisX[i];
        if (tetrisY[i] < minY) minY = tetrisY[i];
        if (tetrisY[i] > maxY) maxY = tetrisY[i];
      }
      midX = (minX + maxX) / 2;
      midY = (minY + maxY) / 2;
      byte movement = (minX + maxX) % 2;
      for (byte i = 0; i < 4; i++) {
        tetrisX[i] -= midX;
        tetrisY[i] -= midY;
        char p = tetrisX[i];
        tetrisX[i] = (-tetrisY[i] + midX) + movement;
        tetrisY[i] = (p + midY);
        if ((tetrisX[i] < 0) || (tetrisX[i] >= 16)) return;
        if ((tetrisY[i] < 0) || (tetrisY[i] >= 24)) return;
        if (arr[(byte)tetrisX[i]][(byte)tetrisY[i]]) return;
        if (arr[(byte)tetrisX[i]][(byte)tetrisY[i] + 1]) return;
      }
      for (byte i = 0; i < 4; i++) {
        falling.bricksX[i] = tetrisX[i];
        falling.bricksY[i] = tetrisY[i];
      }
      DetectCollision();
    }

    void Move() {

      DetectCollision();
      for (byte i = 0; i < 4; i++) {
        falling.bricksY[i]++;
      }

    }

    void CheckRows() {

      for (byte i = 0; i < 24; i++) {
        bool found = false;
        for (byte j = 0; j < 16; j++) {
          if (!arr[j][i]) {
            found = true;
            break;
          }
        }
        if (found)continue;

        for (char j = i; j >= 0; j--) {
          for (byte k = 0; k < 16; k++) {
            if (j > 0) {
              arr[k][(byte)j] = arr[k][(byte)j - 1];
            } else {
              arr[k][(byte)j] = 0;
            }
          }
        }
        score++;
        if (score > 999)score = 999;
        playSound(3);
      }

    }

    void New() {

      byte ran = Next;
      drawNew();
      Next = randomInteger(0, 7);
      drawNew();
      for (byte i = 0; i < 4; i++) {
        falling.bricksX[i] = bricks[ran].bricksX[i] + 6;
        falling.bricksY[i] = bricks[ran].bricksY[i];
        if (arr[falling.bricksX[i]][falling.bricksY[i]])endGame();
      }

    }

    void LetMove() {

      if (!digitalRead(buttonLeft)) {

        if (CanMoveLeft()) {
          for (byte i = 0; i < 4; i++) {
            falling.bricksX[i]--;
          }
          DetectCollision();
        }

      }

      if (!digitalRead(buttonRight)) {

        if (CanMoveRight()) {
          for (byte i = 0; i < 4; i++) {
            falling.bricksX[i]++;
          }
          DetectCollision();
        }

      }

      if (!digitalRead(buttonUp)) {
        if (CanRotate())Rotate();
      }

      if (!digitalRead(buttonDown)) {
        Move();
      }


    }

    void DetectCollision() {

      for (byte i = 0; i < 4; i++) {
        if (falling.bricksY[i] == 23) {
          Drop();
          New();
        } else if (arr[falling.bricksX[i]][falling.bricksY[i] + 1]) {
          Drop();
          New();
        }
      }

      CheckRows();
    }

    void DrawScene() {

      for (byte i = 0; i < 24; i++) {
        drawTile(16, i);
      }

    }

    void Drop() {

      for (byte i = 0; i < 4; i++) {
        toggleTile(falling.bricksX[i], falling.bricksY[i]);
      }

    }

    bool CanMoveLeft() {

      for (byte i = 0; i < 4; i++) {
        if (!falling.bricksX[i])return false;
        if (arr[falling.bricksX[i] - 1][falling.bricksY[i]])return false;
      }
      return true;

    }

    bool CanMoveRight() {

      for (byte i = 0; i < 4; i++) {
        if (falling.bricksX[i] > 14)return false;
        if (arr[falling.bricksX[i] + 1][falling.bricksY[i]])return false;
      }
      return true;

    }

    bool CanRotate() {
      return true;
    }

};
