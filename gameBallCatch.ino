class GameBallCatch : public Game {
  private:

    byte LoopCounter;

    class fallBall {

      public:
        int positionX;
        int positionY;
        fallBall() {}

    };

    class paddle {

      public:
        int positionY = 0;
        paddle() {}

    };

    fallBall Ball0 = fallBall();
    fallBall Ball1 = fallBall();
    fallBall Ball2 = fallBall();
    fallBall Ball3 = fallBall();
    fallBall Ball4 = fallBall();

    //uses class paddle written for gamePong, positionY is used as positionX
    paddle Catcher = paddle();

  public:

    GameBallCatch() :
      Game(),
      LoopCounter(0),
      Ball0(),
      Ball1(),
      Ball2(),
      Ball3(),
      Ball4(),
      Catcher()
    {
      Ball0.positionX = 12;
      Ball0.positionY = 0;
      Ball1.positionX = 12;
      Ball1.positionY = 5;
      Ball2.positionX = 12;
      Ball2.positionY = 10;
      Ball3.positionX = 12;
      Ball3.positionY = 15;
      Ball4.positionX = 12;
      Ball4.positionY = 20;
      Catcher.positionY = 12;
      score = 0;
    }

    ~GameBallCatch() {}

    void Loop() {

      clearScreen();
      LetMove();
      LoopCounter++;
      if (LoopCounter >= 3) {
        MoveBalls();
        LoopCounter = 0;
      }
      DrawScreen();
      wait(tickDuration + 1);
    }

  private:

    void LetMove() {

      if (isKeyPressed(A2K_LEFT)) {
        Catcher.positionY--;
      }
      if (isKeyPressed(A2K_RIGHT)) {
        Catcher.positionY++;
      }
      resetKeyMap();
      
      if (Catcher.positionY < 1)Catcher.positionY = 1;
      if (Catcher.positionY > 22)Catcher.positionY = 22;

    }

    void MoveBalls() {

      Ball0.positionY++;
      Ball1.positionY++;
      Ball2.positionY++;
      Ball3.positionY++;
      Ball4.positionY++;

      if (Ball0.positionY == 23 && (Catcher.positionY == Ball0.positionX || Catcher.positionY - 1 == Ball0.positionX || Catcher.positionY + 1 == Ball0.positionX)) {
        Ball0.positionY = randomInteger(0, 1);
        Ball0.positionX = randomInteger(0, 23);
        score++;
      }
      if (Ball1.positionY == 23 && (Catcher.positionY == Ball1.positionX || Catcher.positionY - 1 == Ball1.positionX || Catcher.positionY + 1 == Ball1.positionX)) {
        Ball1.positionY = randomInteger(0, 1);
        Ball1.positionX = randomInteger(0, 23);
        score++;
      }
      if (Ball2.positionY == 23 && (Catcher.positionY == Ball2.positionX || Catcher.positionY - 1 == Ball2.positionX || Catcher.positionY + 1 == Ball2.positionX)) {
        Ball2.positionY = randomInteger(0, 1);
        Ball2.positionX = randomInteger(0, 23);
        score++;
      }
      if (Ball3.positionY == 23 && (Catcher.positionY == Ball3.positionX || Catcher.positionY - 1 == Ball3.positionX || Catcher.positionY + 1 == Ball3.positionX)) {
        Ball3.positionY = randomInteger(0, 1);
        Ball3.positionX = randomInteger(0, 23);
        score++;
      }
      if (Ball4.positionY == 23 && (Catcher.positionY == Ball4.positionX || Catcher.positionY - 1 == Ball4.positionX || Catcher.positionY + 1 == Ball4.positionX)) {
        Ball4.positionY = randomInteger(0, 1);
        Ball4.positionX = randomInteger(0, 23);
        score++;
      }



      if (Ball0.positionY == 23 || Ball1.positionY == 23 || Ball2.positionY == 23 || Ball3.positionY == 23 || Ball4.positionY == 23)endGame();
    }

    void DrawScreen() {

      drawTile(Ball0.positionX, Ball0.positionY);
      drawTile(Ball1.positionX, Ball1.positionY);
      drawTile(Ball2.positionX, Ball2.positionY);
      drawTile(Ball3.positionX, Ball3.positionY);
      drawTile(Ball4.positionX, Ball4.positionY);
      drawTile(Catcher.positionY, 23);
      drawTile(Catcher.positionY + 1, 23);
      drawTile(Catcher.positionY - 1, 23);

    }

};
