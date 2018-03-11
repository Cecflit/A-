class GamePong : public Game {
  private:
    
    class ball {
    
      public:
        int positionX = 0;
        int positionY = 0;
        int directionX = 0;
        int directionY = 0;
        ball(int posX, int posY, int dirX, int dirY) :
          positionX(posX),
          positionY(posY),
          directionX(dirX),
          directionY(dirY)
        {}
    
    };
    
    class paddle {
    
      public:
        int positionY = 0;
        paddle(int y) :
          positionY(y)
        {}
    
    };
    
    
    paddle Paddle;
    ball Ball;
    
  public:
    
    GamePong() :
      Game(),
      Paddle(12),
      Ball(7, 8, 1, 1)
    {
      /*Paddle.positionY = 12;
      Ball.positionX = 7;
      Ball.positionY = 8;
      Ball.directionX = 1;
      Ball.directionY = 1;*/
      
      DrawScreen();
    }
    
    ~GamePong() {}
    
    void Setup() {
    
      /*Paddle.positionY = 12;
      Ball.positionX = 7;
      Ball.positionY = 8;
      Ball.directionX = 1;
      Ball.directionY = 1;
    
      DrawScreen();*/
    
    }
    
    void Loop() {
    
      LetMove();
      MoveBall();
      wait(tickDuration + 1);
    
    }
  
  private:
    
    void LetMove() {
    
      if (!digitalRead(buttonUp) && Paddle.positionY > 2) {
        clearTile(0, Paddle.positionY + 1);
        clearTile(23, Paddle.positionY + 1);
        Paddle.positionY--;
        drawTile(0, Paddle.positionY - 1);
        drawTile(23, Paddle.positionY - 1);
      }
      if (!digitalRead(buttonDown) && Paddle.positionY < 21) {
        clearTile(0, Paddle.positionY - 1);
        clearTile(23, Paddle.positionY - 1);
        Paddle.positionY++;
        drawTile(0, Paddle.positionY + 1);
        drawTile(23, Paddle.positionY + 1);
      }
    
    }
    
    void MoveBall() {
    
      clearTile(Ball.positionX, Ball.positionY);
    
      if ((Ball.positionX == 1 || Ball.positionX == 22) && (Paddle.positionY != Ball.positionY && Paddle.positionY - 1 != Ball.positionY && Paddle.positionY + 1 != Ball.positionY))endGame();
      if ((Ball.positionX == 1 || Ball.positionX == 22) && (Paddle.positionY == Ball.positionY || Paddle.positionY - 1 == Ball.positionY || Paddle.positionY + 1 == Ball.positionY)) {
    
        score++;
        if (Ball.positionY == Paddle.positionY) {
    
          Ball.directionY = 0;
          if (Ball.positionX == 1)Ball.directionX = 1;
          if (Ball.positionX == 22)Ball.directionX = -1;
          if (randomInteger(0, 20) == 4)Ball.directionY = 1;
          if (randomInteger(0, 20) == 4)Ball.directionY = -1;
    
        }
        if (Ball.positionY == Paddle.positionY - 1) {
    
          if (Ball.positionY > 1) {
            Ball.directionY = -1;
          } else Ball.directionY = 1;
          if (Ball.positionX == 1)Ball.directionX = 1;
          if (Ball.positionX == 22)Ball.directionX = -1;
    
        }
        if (Ball.positionY == Paddle.positionY + 1) {
    
          if (Ball.positionY < 22) {
            Ball.directionY = 1;
          } else Ball.directionY = -1;
          if (Ball.positionX == 1)Ball.directionX = 1;
          if (Ball.positionX == 22)Ball.directionX = -1;
        }
    
      }
    
      if (Ball.positionX > 1 && Ball.positionX < 22 && (Ball.positionY == 1 || Ball.positionY == 22)) {
    
        if (Ball.directionY == 1 && Ball.positionY == 22)Ball.directionY = -1;
        if (Ball.directionY == -1 && Ball.positionY == 1)Ball.directionY = 1;
    
      }
    
      Ball.positionX += Ball.directionX;
      Ball.positionY += Ball.directionY;
    
      drawTile(Ball.positionX, Ball.positionY);
    }
    
    void DrawScreen() {
    
      clearScreen();
      for (int i = 0; i < 24; i++) {
    
        drawTile(i, 0);
        drawTile(i, 23);
    
      }
    
      drawTile(Ball.positionX, Ball.positionY);
      drawTile(0, Paddle.positionY);
      drawTile(0, Paddle.positionY - 1);
      drawTile(0, Paddle.positionY + 1);
      drawTile(23, Paddle.positionY);
      drawTile(23, Paddle.positionY - 1);
      drawTile(23, Paddle.positionY + 1);
    
    }
};
