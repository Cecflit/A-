class GameSnake : public Game {
  private:

    class snake {

      public:
        int directionX = 1;
        int directionY = 0;
        int head = 0;
        int tail = 0;
        int tailPiecesX[574] = {};
        int tailPiecesY[574] = {};
        snake() {}
    };

    snake Snake = snake();

    class food {

      public:
        int positionX = 0;
        int positionY = 0;
        food() {}
    };

    food Food = food();

  public:

    GameSnake() :
      Game(),
      Snake(),
      Food()
    {
      score = 0;
      Snake.tail = 573;
      Snake.head = 0;
      Snake.directionX = 1;
      Snake.directionY = 0;
      Snake.tailPiecesX[Snake.head] = randomInteger(0, 23);
      Snake.tailPiecesY[Snake.head] = randomInteger(0, 23);
      Food.positionX = randomInteger(0, 23);
      Food.positionY = randomInteger(0, 23);

      while (arr[Food.positionX][Food.positionY]) {

        Food.positionX = randomInteger(0, 23);
        Food.positionY = randomInteger(0, 23);

      }
      clearScreen();
    }

    ~GameSnake() {}

    void Loop() {

      //Direction change
      if (isKeyPressed(A2K_UP) && !Snake.directionY) {
        Snake.directionY = -1;
        Snake.directionX = 0;
      };
      if (isKeyPressed(A2K_DOWN) && !Snake.directionY) {
        Snake.directionY = 1;
        Snake.directionX = 0;
      };
      if (isKeyPressed(A2K_LEFT) && !Snake.directionX) {
        Snake.directionY = 0;
        Snake.directionX = -1;
      };
      if (isKeyPressed(A2K_RIGHT) && !Snake.directionX) {
        Snake.directionY = 0;
        Snake.directionX = 1;
      };
      resetKeyMap();

      //Head move
      int head_ = Snake.head;
      Snake.head++;
      if (Snake.head >= 524) Snake.head = 0;
      //Snake.tail++;
      Snake.tailPiecesX[Snake.head] = Snake.tailPiecesX[head_] + Snake.directionX;
      Snake.tailPiecesY[Snake.head] = Snake.tailPiecesY[head_] + Snake.directionY;

      //Border check
      if (Snake.tailPiecesX[Snake.head] > 23)Snake.tailPiecesX[Snake.head] = 0;
      if (Snake.tailPiecesX[Snake.head] < 0)Snake.tailPiecesX[Snake.head] = 23;
      if (Snake.tailPiecesY[Snake.head] > 23)Snake.tailPiecesY[Snake.head] = 0;
      if (Snake.tailPiecesY[Snake.head] < 0)Snake.tailPiecesY[Snake.head] = 23;

      //Food eat check
      if (Snake.tailPiecesX[Snake.head] == Food.positionX && Snake.tailPiecesY[Snake.head] == Food.positionY) {
        score++;
        playSound(3);
        Food.positionX = randomInteger(0, 23);
        Food.positionY = randomInteger(0, 23);

        while (arr[Food.positionX][Food.positionY]) {

          Food.positionX = randomInteger(0, 23);
          Food.positionY = randomInteger(0, 23);

        }
        growTail();
      } else {

        Snake.tail++;
        if (Snake.tail >= 524) Snake.tail = 0;

        //Collision detection
        if (arr[Snake.tailPiecesX[Snake.head]][Snake.tailPiecesY[Snake.head]])endGame();
      }

      //Draw tiles
      drawTile(Snake.tailPiecesX[Snake.head], Snake.tailPiecesY[Snake.head]);
      drawTile(Food.positionX, Food.positionY);
      clearTile(Snake.tailPiecesX[Snake.tail], Snake.tailPiecesY[Snake.tail]);

      //Render stage / End tick
      wait(tickDuration + 1);
    }

  private:

    void growTail() {

      if (score >= 572) {
        score = 574;
        endGame();
      }
    }

};
