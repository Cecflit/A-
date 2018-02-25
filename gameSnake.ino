int lastLength = 0;

class snake {

  public:
    //int positionX = 0;
    //int positionY = 0;
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

void gameSnakeSetup() {

  lastLength = 0;
  score = 0;
  Snake.tail = 573;
  Snake.head = 0;
  Snake.directionX = 1;
  Snake.directionY = 0;
  /*for (int i = 0; i < 574; i++) {
    Snake.tailPiecesX[i] = { -1};
    Snake.tailPiecesY[i] = { -1};
  }*/
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

void gameSnakeLoop() {

  //Get tail length
  //lastLength = checkTailLength();

  //Direction change
  if (!digitalRead(buttonUp) && !Snake.directionY) {
    Snake.directionY = -1;
    Snake.directionX = 0;
  };
  if (!digitalRead(buttonDown) && !Snake.directionY) {
    Snake.directionY = 1;
    Snake.directionX = 0;
  };
  if (!digitalRead(buttonLeft) && !Snake.directionX) {
    Snake.directionY = 0;
    Snake.directionX = -1;
  };
  if (!digitalRead(buttonRight) && !Snake.directionX) {
    Snake.directionY = 0;
    Snake.directionX = 1;
  };

  //if (Snake.tail <= 1) clearTile(Snake.positionX, Snake.positionY);

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

    //clearTile(Food.positionX, Food.positionY);
    Food.positionX = randomInteger(0, 23);
    Food.positionY = randomInteger(0, 23);

  }
    growTail();
  } else {

    Snake.tail++;
    if (Snake.tail >= 524) Snake.tail = 0;
    
    //Collision detection
    if(arr[Snake.tailPiecesX[Snake.head]][Snake.tailPiecesY[Snake.head]])endGame();
  }

  //Tail move
  /*  Snake.tailPiecesX[573] = Snake.positionX;
    Snake.tailPiecesY[573] = Snake.positionY;
  for (int i = 573 - Snake.tail - 1; i < 573; i++) {
    Snake.tailPiecesX[i] = Snake.tailPiecesX[i+1];
    Snake.tailPiecesY[i] = Snake.tailPiecesY[i+1];
  }*/

/*
  for (int i = 0; i < Snake.tail; i++) {

    if (Snake.tailPiecesX[573 - i] == Snake.positionX && Snake.tailPiecesY[573 - i] == Snake.positionY)endGame();

  }
*/
  //Draw tiles
  //clearScreen();
  drawTile(Snake.tailPiecesX[Snake.head], Snake.tailPiecesY[Snake.head]);
  drawTile(Food.positionX, Food.positionY);

  /*for (int i = 0; i <= Snake.tail; i++) {

    drawTile(Snake.tailPiecesX[573 - i], Snake.tailPiecesY[573 - i]);

  }*/
  //if (Snake.head != Snake.tail) {
    clearTile(Snake.tailPiecesX[Snake.tail], Snake.tailPiecesY[Snake.tail]);
  //}
  //drawTile(Snake.tailPiecesX[573], Snake.tailPiecesY[573]);

  //Render stage / End tick
  wait(tickDuration + 1);
}

/*int checkTailLength() {

  for (int i = 0; i < 574; i++) {
    if (Snake.tailPiecesX[i] >= 0) {
      return 574 - i;
    }
  }
  return 0;

}*/

void growTail() {

  /*if (Snake.tail) {

    Snake.tailPiecesX[572 - Snake.tail] = Snake.tailPiecesX[573 - Snake.tail];
    Snake.tailPiecesY[572 - Snake.tail] = Snake.tailPiecesY[573 - Snake.tail];

  } else {*/

    //Snake.tailPiecesX[573] = Snake.positionX;
    //Snake.tailPiecesY[573] = Snake.positionY;
    //Snake.tail++;

  //}

  if (/*Snake.tail > 573*/ score >= 572) {

    score = 574;
    endGame();

  }

}
