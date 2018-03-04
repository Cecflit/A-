bool gameTetrisLoopCounter = false;

class tetromino {

  public:
    byte bricksX[4];
    byte bricksY[4];
};

const tetromino bricks[7] = {{{0, 1, 2, 3}, {0, 0, 0, 0}}, {{0, 0, 1, 1}, {0, 1, 0, 1}}, {{0, 0, 0, 1}, {0, 1, 2, 2}}, {{1, 1, 1, 0}, {0, 1, 2, 2}}, {{0, 0, 1, 1}, {0, 1, 1, 2}}, {{1, 1, 0, 0}, {0, 1, 1, 2}}, {{0, 1, 1, 2}, {0, 0, 1, 0}}};
tetromino falling;

void gameTetrisSetup() {

  clearScreen();
  score = 0;
  gameTetrisDrawScene();
  gameTetrisNew();
  gameTetrisDrop();
  
}

void gameTetrisLoop() {

  gameTetrisDrop();
  gameTetrisLetMove();
  if(gameTetrisLoopCounter)gameTetrisMove();
  gameTetrisDrop();
  wait(tickDuration + 1);
  gameTetrisLoopCounter = !gameTetrisLoopCounter;
  
}

void gameTetrisRotate() {

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
  midX = (minX + maxX)/2;
  midY = (minY + maxY)/2;
  byte movement = (minX + maxX)%2;
  for (byte i = 0; i < 4; i++) {
    tetrisX[i] -= midX;
    tetrisY[i] -= midY;
    char p = tetrisX[i];
    tetrisX[i] = (-tetrisY[i] + midX)+movement;
    tetrisY[i] = (p + midY);
    if ((tetrisX[i] < 0) || (tetrisX[i] >= 16)) return;
    if ((tetrisY[i] < 0) || (tetrisY[i] >= 24)) return;
    if (arr[(byte)tetrisX[i]][(byte)tetrisY[i]]) return;
    if (arr[(byte)tetrisX[i]][(byte)tetrisY[i]+1]) return;
  }
  for (byte i = 0; i < 4; i++) {
    falling.bricksX[i] = tetrisX[i];
    falling.bricksY[i] = tetrisY[i];
  }
  gameTetrisDetectCollision();
}

void gameTetrisMove() {

  for (byte i = 0; i < 4; i++) {
    falling.bricksY[i]++;
  }
  gameTetrisDetectCollision();
  
}

void gameTetrisCheckRows() {

  for (byte i = 0; i < 24; i++) {
    bool found = false;
    for (byte j = 0; j < 16; j++) {
      if(!arr[j][i]) {
        found = true;
        break;
      }
    }
    if(found)continue;

    for(char j = i; j >= 0; j--) {
      for(byte k = 0; k < 16; k++) {
        if(j > 0){
          arr[k][(byte)j] = arr[k][(byte)j-1];
        }else {
          arr[k][(byte)j] = 0;
        }
      }
    }
    score++;
    if(score > 999)score = 999;
    playSound(3);
  }
  
}

void gameTetrisNew() {

  byte ran = randomInteger(0, 7);
  for (byte i = 0; i < 4; i++) {
    falling.bricksX[i] = bricks[ran].bricksX[i] + 6;
    falling.bricksY[i] = bricks[ran].bricksY[i];
    if(arr[falling.bricksX[i]][falling.bricksY[i]])endGame();
  }
  
}

void gameTetrisLetMove() {

  if(!digitalRead(buttonLeft)) {
    
    if(gameTetrisCanMoveLeft()){
      for(byte i = 0; i < 4; i++) {
        falling.bricksX[i]--;
      }
      gameTetrisDetectCollision();
    }
    
  }
  
  if(!digitalRead(buttonRight)) {
    
    if(gameTetrisCanMoveRight()){
      for(byte i = 0; i < 4; i++) {
        falling.bricksX[i]++;
      }
      gameTetrisDetectCollision();
    }
    
  }
  
  if(!digitalRead(buttonUp)) {
    if(gameTetrisCanRotate())gameTetrisRotate();
  }
  
  if(!digitalRead(buttonDown)) {
    gameTetrisMove();
  }
  
  
}

void gameTetrisDetectCollision() {

  for (byte i = 0; i < 4; i++) {
    if(falling.bricksY[i] == 23){
      gameTetrisDrop();
      gameTetrisNew();
    }else if (arr[falling.bricksX[i]][falling.bricksY[i]+1]) {
      gameTetrisDrop();
      gameTetrisNew();
    }
  }
  
  gameTetrisCheckRows();
}

void gameTetrisDrawScene() {

  for(byte i = 0; i < 24; i++) {
    drawTile(16, i);
  }
  
}

void gameTetrisDrop() {
  
  for(byte i = 0; i < 4; i++) {
    toggleTile(falling.bricksX[i], falling.bricksY[i]);
  }
  
}

bool gameTetrisCanMoveLeft() {
  
  for(byte i = 0; i < 4; i++) {
    if(!falling.bricksX[i])return false;
    if(arr[falling.bricksX[i]-1][falling.bricksY[i]])return false;
  }
  return true;

}

bool gameTetrisCanMoveRight() {
  
  for(byte i = 0; i < 4; i++) {
    if(falling.bricksX[i] > 14)return false;
    if(arr[falling.bricksX[i]+1][falling.bricksY[i]])return false;
  }
  return true;

}

bool gameTetrisCanRotate() {
  return true;
}

