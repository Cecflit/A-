#define CHARACT_A 10
#define CHARACT_B 11
#define CHARACT_C 12
#define CHARACT_D 13
#define CHARACT_E 14
#define CHARACT_F 15
#define CHARACT_G 16
#define CHARACT_H 17
#define CHARACT_I 18
#define CHARACT_J 19
#define CHARACT_K 20
#define CHARACT_L 21
#define CHARACT_M 22
#define CHARACT_N 23
#define CHARACT_O 24
#define CHARACT_P 25
#define CHARACT_Q 26
#define CHARACT_R 27
#define CHARACT_S 28
#define CHARACT_T 29
#define CHARACT_U 30
#define CHARACT_V 31
#define CHARACT_W 32
#define CHARACT_X 33
#define CHARACT_Y 34
#define CHARACT_Z 35

#define A2K_UP 1
#define A2K_DOWN 2
#define A2K_LEFT 4
#define A2K_RIGHT 8
#define A2K_ENTER 16

long fancyCounter = 0;
int score = 0;
char tickDuration = 6;
byte keyMap = 0;

//individual characters

const byte char0_x[12] = {0, 1, 2, 0, 2, 0, 2, 0, 2, 0, 1, 2};
const byte char0_y[12] = {0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 4};

const byte char1_x[5] = {0, 0, 0, 0, 0};
const byte char1_y[5] = {0, 1, 2, 3, 4};

const byte char2_x[11] = {0, 1, 2, 2, 0, 1, 2, 0, 0, 1, 2};
const byte char2_y[11] = {0, 0, 0, 1, 2, 2, 2, 3, 4, 4, 4};

const byte char3_x[10] = {0, 1, 2, 2, 1, 2, 2, 0, 1, 2};
const byte char3_y[10] = {0, 0, 0, 1, 2, 2, 3, 4, 4, 4};

const byte char4_x[9] = {0, 2, 0, 2, 0, 1, 2, 2, 2};
const byte char4_y[9] = {0, 0, 1, 1, 2, 2, 2, 3, 4};

const byte char5_x[11] = {0, 1, 2, 0, 0, 1, 2, 2, 0, 1, 2};
const byte char5_y[11] = {0, 0, 0, 1, 2, 2, 2, 3, 4, 4, 4};

const byte char6_x[12] = {0, 1, 2, 0, 0, 1, 2, 0, 2, 0, 1, 2};
const byte char6_y[12] = {0, 0, 0, 1, 2, 2, 2, 3, 3, 4, 4, 4};

const byte char7_x[7] = {0, 1, 2, 2, 2, 2, 2};
const byte char7_y[7] = {0, 0, 0, 1, 2, 3, 4};

const byte char8_x[13] = {0, 1, 2, 0, 2, 0, 1, 2, 0, 2, 0, 1, 2};
const byte char8_y[13] = {0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4};

const byte char9_x[12] = {0, 1, 2, 0, 2, 0, 1, 2, 2, 0, 1, 2};
const byte char9_y[12] = {0, 0, 0, 1, 1, 2, 2, 2, 3, 4, 4, 4};

const byte charA_x[10] = {1, 0, 2, 0, 2, 0, 1, 2, 0, 2};
const byte charA_y[10] = {0, 1, 1, 2, 2, 3, 3, 3, 4, 4};

const byte charB_x[10] = {0, 1, 0, 2, 0, 1, 0, 2, 0, 1};
const byte charB_y[10] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4};

const byte charC_x[7] = {1, 2, 0, 0, 0, 1, 2};
const byte charC_y[7] = {0, 0, 1, 2, 3, 4, 4};

const byte charD_x[10] = {0, 1, 0, 2, 0, 2, 0, 2, 0, 1};
const byte charD_y[10] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4};

const byte charE_x[10] = {0, 1, 2, 0, 0, 1, 0, 0, 1, 2};
const byte charE_y[10] = {0, 0, 0, 1, 2, 2, 3, 4, 4, 4};

const byte charF_x[8] = {0, 1, 2, 0, 0, 1, 0, 0};
const byte charF_y[8] = {0, 0, 0, 1, 2, 2, 3, 4};

const byte charG_x[12] = {1, 2, 3, 0, 0, 2, 3, 0, 3, 1, 2, 3};
const byte charG_y[12] = {0, 0, 0, 1, 2, 2, 2, 3, 3, 4, 4, 4};

const byte charH_x[11] = {0, 2, 0, 2, 0, 1, 2, 0, 2, 0, 2};
const byte charH_y[11] = {0, 0, 1, 1, 2, 2, 2, 3, 3, 4, 4};

const byte charJ_x[6] = {2, 2, 2, 0, 2, 1};
const byte charJ_y[6] = {0, 1, 2, 3, 3, 4};

const byte charK_x[10] = {0, 2, 0, 2, 0, 1, 0, 2, 0, 2};
const byte charK_y[10] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4};

const byte charL_x[7] = {0, 0, 0, 0, 0, 1, 2};
const byte charL_y[7] = {0, 1, 2, 3, 4, 4, 4};

const byte charM_x[13] = {0, 4, 0, 1, 3, 4, 0, 2, 4, 0, 4, 0, 4};
const byte charM_y[13] = {0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4};

const byte charN_x[12] = {0, 3, 0, 1, 3, 0, 2, 3, 0, 3, 0, 3};
const byte charN_y[12] = {0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4};

const byte charO_x[8] = {1, 0, 2, 0, 2, 0, 2, 1};
const byte charO_y[8] = {0, 1, 1, 2, 2, 3, 3, 4};

const byte charP_x[8] = {0, 1, 0, 2, 0, 1, 0, 0};
const byte charP_y[8] = {0, 0, 1, 1, 2, 2, 3, 4};

const byte charQ_x[10] = {1, 0, 2, 0, 2, 0, 2, 1, 2, 3};
const byte charQ_y[10] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 4};

const byte charR_x[10] = {0, 1, 0, 2, 0, 1, 0, 2, 0, 2};
const byte charR_y[10] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4};

const byte charS_x[7] = {1, 2, 0, 1, 2, 0, 1};
const byte charS_y[7] = {0, 0, 1, 2, 3, 4, 4};

const byte charT_x[7] = {0, 1, 2, 1, 1, 1, 1};
const byte charT_y[7] = {0, 0, 0, 1, 2, 3, 4};

const byte charU_x[11] = {0, 2, 0, 2, 0, 2, 0, 2, 0, 1, 2};
const byte charU_y[11] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 4};

const byte charV_x[9] = {0, 2, 0, 2, 0, 2, 0, 2, 1};
const byte charV_y[9] = {0, 0, 1, 1, 2, 2, 3, 3, 4};

const byte charW_x[12] = {0, 4, 0, 4, 0, 2, 4, 0, 2, 4, 1, 3};
const byte charW_y[12] = {0, 0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4};

const byte charX_x[9] = {0, 2, 0, 2, 1, 0, 2, 0, 2};
const byte charX_y[9] = {0, 0, 1, 1, 2, 3, 3, 4, 4};

const byte charY_x[9] = {0, 2, 0, 2, 0, 1, 2, 1, 1};
const byte charY_y[9] = {0, 0, 1, 1, 2, 2, 2, 3, 4};

const byte charZ_x[10] = {0, 1, 2, 2, 1, 0, 0, 1, 2};
const byte charZ_y[10] = {0, 0, 0, 1, 2, 3, 4, 4, 4};


const byte buttonUp = 48; //digital pin 48
const byte buttonDown = 49; //digital pin 49
const byte buttonLeft = 50; //digital pin 50
const byte buttonRight = 51; //digital pin 51
const byte speaker = 52; //digital pin 52
const byte buttonEnter = 53; //digital pin 53
byte arr[24][24] = {};
byte game = 0;

void setup() {

  pinMode(speaker, OUTPUT);
  pinMode(buttonEnter, INPUT_PULLUP);
  //digitalWrite(extraGround, 0);
  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
  pinMode(buttonLeft, INPUT_PULLUP);
  pinMode(buttonRight, INPUT_PULLUP);

  for (byte i = 0; i < 24; i++) {

    pinMode(i, OUTPUT);
    pinMode(i + 24, OUTPUT);

  }
}

void updateKeyMap() {
  if (!digitalRead(buttonUp)) {
    keyMap |= A2K_UP;
  }
  if (!digitalRead(buttonDown)) {
    keyMap |= A2K_DOWN;
  }
  if (!digitalRead(buttonLeft)) {
    keyMap |= A2K_LEFT;
  }
  if (!digitalRead(buttonRight)) {
    keyMap |= A2K_RIGHT;
  }
  if (!digitalRead(buttonEnter)) {
    keyMap |= A2K_ENTER;
  }
}

byte resetKeyMap() {
  keyMap = 0;
}

bool isKeyPressed(byte key) {
  return keyMap & key;
}

void drawTile(byte x, byte y, byte type = 1) {

  arr[x][y] = type;

}

void clearTile(byte x, byte y) {

  arr[x][y] = false;

}

void toggleTile(byte x, byte y) {

  arr[x][y] = !arr[x][y];

}

void clearScreen() { //including pin data

  for (byte i = 0; i < 24; i++) {
    for (byte j = 0; j < 24; j++) {
      arr[i][j] = 0;
    }
  }
}

void unrenderScreen() { //flashes the screen

  for (byte i = 0; i < 24; i++) {
    for (byte j = 0; j < 24; j++) {
      digitalWrite(i, HIGH);
      digitalWrite(j + 24, LOW);
    }
  }
}

void renderScreen() {

  for (byte i = 0; i < 24; i++) {
    digitalWrite(i, LOW);


    for (byte j = 0; j < 24; j++) {
      if (arr[i][j] == 1) {
        digitalWrite(j + 24, HIGH);
      }
      if (arr[i][j] == 2 && !(fancyCounter % 5)) {
        digitalWrite(j + 24, HIGH);
      }
      if (arr[i][j] == 3 && fancyCounter % 128 >= 64) {
        digitalWrite(j + 24, HIGH);
      }
      if (arr[i][j] == 4 && fancyCounter % 64 >= 32) {
        digitalWrite(j + 24, HIGH);
      }
      if (arr[i][j] == 5 && fancyCounter % 32 >= 16) {
        digitalWrite(j + 24, HIGH);
      }
    }


    delayMicroseconds(10);
    for (byte j = 0; j < 24; j++) {
      if (arr[i][j]) {
        digitalWrite(j + 24, LOW);
      }
    }
    digitalWrite(i, HIGH);
  }

  fancyCounter++;
}


void endGame() {

  playSound(0);
  flashScreen();
  clearScreen();
  viewScore();
  resetGame();

}

void resetGame() {

  clearScreen();
  score = 0;
  reboot();

}

void drawLogo(byte game) {

  switch (game) {

    case 0 :  //Snake

      drawCharacter(2, 9, CHARACT_S);
      drawCharacter(6, 9, CHARACT_N);
      drawCharacter(11, 9, CHARACT_A);
      drawCharacter(15, 9, CHARACT_K);
      drawCharacter(19, 9, CHARACT_E);

      break;

    case 1 : //Mine Run

      drawCharacter(4, 6, CHARACT_M);
      drawCharacter(10, 6, CHARACT_I);
      drawCharacter(12, 6, CHARACT_N);
      drawCharacter(17, 6, CHARACT_E);
      drawCharacter(6, 12, CHARACT_R);
      drawCharacter(10, 12, CHARACT_U);
      drawCharacter(14, 12, CHARACT_N);

      break;


    case 2 :  //SpaceShoot

      drawCharacter(2, 6, CHARACT_S);
      drawCharacter(6, 6, CHARACT_P);
      drawCharacter(10, 6, CHARACT_A);
      drawCharacter(14, 6, CHARACT_C);
      drawCharacter(18, 6, CHARACT_E);
      drawCharacter(2, 12, CHARACT_S);
      drawCharacter(6, 12, CHARACT_H);
      drawCharacter(10, 12, CHARACT_O);
      drawCharacter(14, 12, CHARACT_O);
      drawCharacter(18, 12, CHARACT_T);

      break;

    case 3 :  //PowerCord

      drawCharacter(1, 6, CHARACT_P);
      drawCharacter(5, 6, CHARACT_O);
      drawCharacter(9, 6, CHARACT_W);
      drawCharacter(15, 6, CHARACT_E);
      drawCharacter(19, 6, CHARACT_R);
      drawCharacter(4, 12, CHARACT_C);
      drawCharacter(8, 12, CHARACT_O);
      drawCharacter(12, 12, CHARACT_R);
      drawCharacter(16, 12, CHARACT_D);

      break;

    case 4 :  //Pong

      drawCharacter(3, 9, CHARACT_P);
      drawCharacter(7, 9, CHARACT_O);
      drawCharacter(11, 9, CHARACT_N);
      drawCharacter(16, 9, CHARACT_G);

      break;

    case 5 :  //StreetCross

      drawCharacter(0, 6, CHARACT_S);
      drawCharacter(4, 6, CHARACT_T);
      drawCharacter(8, 6, CHARACT_R);
      drawCharacter(12, 6, CHARACT_E);
      drawCharacter(16, 6, CHARACT_E);
      drawCharacter(20, 6, CHARACT_T);
      drawCharacter(2, 12, CHARACT_C);
      drawCharacter(6, 12, CHARACT_R);
      drawCharacter(10, 12, CHARACT_O);
      drawCharacter(14, 12, CHARACT_S);
      drawCharacter(18, 12, CHARACT_S);

      break;

    case 6 :  //ArrowMatch

      drawCharacter(1, 6, CHARACT_A);
      drawCharacter(5, 6, CHARACT_R);
      drawCharacter(9, 6, CHARACT_R);
      drawCharacter(13, 6, CHARACT_O);
      drawCharacter(17, 6, CHARACT_W);
      drawCharacter(1, 12, CHARACT_M);
      drawCharacter(7, 12, CHARACT_A);
      drawCharacter(11, 12, CHARACT_T);
      drawCharacter(15, 12, CHARACT_C);
      drawCharacter(19, 12, CHARACT_H);

      break;

    case 7 :  //BallCatch

      drawCharacter(4, 6, CHARACT_B);
      drawCharacter(8, 6, CHARACT_A);
      drawCharacter(12, 6, CHARACT_L);
      drawCharacter(16, 6, CHARACT_L);
      drawCharacter(2, 12, CHARACT_C);
      drawCharacter(6, 12, CHARACT_A);
      drawCharacter(10, 12, CHARACT_T);
      drawCharacter(14, 12, CHARACT_C);
      drawCharacter(18, 12, CHARACT_H);

      break;

    case 8 :  //Quick Reflex

      drawCharacter(2, 6, CHARACT_Q);
      drawCharacter(7, 6, CHARACT_U);
      drawCharacter(11, 6, CHARACT_I);
      drawCharacter(13, 6, CHARACT_C);
      drawCharacter(17, 6, CHARACT_K);
      drawCharacter(0, 12, CHARACT_R);
      drawCharacter(4, 12, CHARACT_E);
      drawCharacter(8, 12, CHARACT_F);
      drawCharacter(12, 12, CHARACT_L);
      drawCharacter(16, 12, CHARACT_E);
      drawCharacter(20, 12, CHARACT_X);

      break;

    case 9 :  //Under Attack

      drawCharacter(2, 6, CHARACT_U);
      drawCharacter(6, 6, CHARACT_N);
      drawCharacter(11, 6, CHARACT_D);
      drawCharacter(15, 6, CHARACT_E);
      drawCharacter(19, 6, CHARACT_R);
      drawCharacter(0, 12, CHARACT_A);
      drawCharacter(4, 12, CHARACT_T);
      drawCharacter(8, 12, CHARACT_T);
      drawCharacter(12, 12, CHARACT_A);
      drawCharacter(16, 12, CHARACT_C);
      drawCharacter(20, 12, CHARACT_K);

      break;

    case 10 :  //Tetris

      drawCharacter(1, 9, CHARACT_T);
      drawCharacter(5, 9, CHARACT_E);
      drawCharacter(9, 9, CHARACT_T);
      drawCharacter(13, 9, CHARACT_R);
      drawCharacter(17, 9, CHARACT_I);
      drawCharacter(19, 9, CHARACT_S);

      break;

  }
}

void drawTickDuration() {

  for (byte i = 0; i < 24 - tickDuration; i++) {

    drawTile(i, 23);

  }

}

void flashScreen() {
  for (byte i = 0; i < 5; i++) {
    delay(240);
    wait(4);
  }
}

void viewScore() {
  //set the LEDs to show the score

  if (score < 10) {

    //Will render a specific digit
    renderScore(0, 1);
    renderScore(0, 2);
    renderScore(score, 3);

  } else if (score > 9 && score < 100) {

    byte digit1 = score % 10;
    byte digit2 = (score - digit1) / 10;

    //Will render two specific digits
    renderScore(0, 1);
    renderScore(digit2, 2);
    renderScore(digit1, 3);


  } else {

    byte digit1 = score % 10;
    byte digit2 = (score % 100 - digit1) / 10;
    byte digit3 = (score - (score % 100)) / 100;

    //Will render three specific digits
    renderScore(digit3, 1);
    renderScore(digit2, 2);
    renderScore(digit1, 3);


  }

  while (digitalRead(buttonDown)) {
    wait(1);
  }
}


void renderScore(byte digit, byte slot) {

  switch (slot) {
    case 1:
      switch (digit) {
        case 0: drawCharacter(6, 9, 0); break;
        case 1: drawCharacter(8, 9, 1); break;
        case 2: drawCharacter(6, 9, 2); break;
        case 3: drawCharacter(6, 9, 3); break;
        case 4: drawCharacter(6, 9, 4); break;
        case 5: drawCharacter(6, 9, 5); break;
        case 6: drawCharacter(6, 9, 6); break;
        case 7: drawCharacter(6, 9, 7); break;
        case 8: drawCharacter(6, 9, 8); break;
        case 9: drawCharacter(6, 9, 9); break;
      }
      break;
    case 2:
      switch (digit) {
        case 0: drawCharacter(10, 9, 0); break;
        case 1: drawCharacter(12, 9, 1); break;
        case 2: drawCharacter(10, 9, 2); break;
        case 3: drawCharacter(10, 9, 3); break;
        case 4: drawCharacter(10, 9, 4); break;
        case 5: drawCharacter(10, 9, 5); break;
        case 6: drawCharacter(10, 9, 6); break;
        case 7: drawCharacter(10, 9, 7); break;
        case 8: drawCharacter(10, 9, 8); break;
        case 9: drawCharacter(10, 9, 9); break;
      }
      break;
    case 3:
      switch (digit) {
        case 0: drawCharacter(14, 9, 0); break;
        case 1: drawCharacter(16, 9, 1); break;
        case 2: drawCharacter(14, 9, 2); break;
        case 3: drawCharacter(14, 9, 3); break;
        case 4: drawCharacter(14, 9, 4); break;
        case 5: drawCharacter(14, 9, 5); break;
        case 6: drawCharacter(14, 9, 6); break;
        case 7: drawCharacter(14, 9, 7); break;
        case 8: drawCharacter(14, 9, 8); break;
        case 9: drawCharacter(14, 9, 9); break;
      }
      break;
  }

}

void wait(short time) {

  for (short i = 0; i < time * 10; i++) {

    updateKeyMap();
    renderScreen();

  }

}

int randomInteger(int min_, int max_) {

  return floor(random(min_, max_));



}

void reboot() {

  asm volatile ("  jmp 0");

}

void playSound(byte sound) {

  if (!sound) { //Game Over

    tone(speaker, 400, 150);
    delay(150);
    tone(speaker, 300, 150);
    delay(150);
    tone(speaker, 200, 150);
    delay(150);
    tone(speaker, 100, 650);
    delay(655);

  }

  if (sound == 1) { //Select Game

    tone(speaker, 200, 150);
    delay(150);
    tone(speaker, 300, 10);
    delay(10);
    tone(speaker, 350, 10);
    delay(10);
    tone(speaker, 400, 10);
    delay(10);
    tone(speaker, 450, 10);
    delay(10);
    tone(speaker, 500, 10);
    delay(10);
    tone(speaker, 550, 10);
    delay(10);
    tone(speaker, 600, 10);
    delay(10);
    tone(speaker, 700, 10);
    delay(10);
    tone(speaker, 800, 10);
    delay(10);
    tone(speaker, 1000, 10);
    delay(10);
    tone(speaker, 1200, 10);
    delay(10);
    tone(speaker, 1500, 10);
    delay(15);

  }

  if (sound == 2) { //Correct Arrow

    tone(speaker, 1600, 50);

  }

  if (sound == 3) { //Snake Food Eat

    tone(speaker, 2147, 129);

  }

}

void drawCharacter(byte _x, byte _y, byte ch) {

  if (ch == 18) ch = 1;

  switch (ch) {

    case 0: //0

      for (int i = 0; i < 12; i++) {
        toggleTile(char0_x[i] + _x, char0_y[i] + _y);
      }

      break;

    case 1: //1 / I

      for (int i = 0; i < 5; i++) {
        toggleTile(char1_x[i] + _x, char1_y[i] + _y);
      }

      break;

    case 2: //2

      for (int i = 0; i < 11; i++) {
        toggleTile(char2_x[i] + _x, char2_y[i] + _y);
      }

      break;

    case 3: //3

      for (int i = 0; i < 10; i++) {
        toggleTile(char3_x[i] + _x, char3_y[i] + _y);
      }

      break;

    case 4: //4

      for (int i = 0; i < 9; i++) {
        toggleTile(char4_x[i] + _x, char4_y[i] + _y);
      }

      break;

    case 5: //5

      for (int i = 0; i < 11; i++) {
        toggleTile(char5_x[i] + _x, char5_y[i] + _y);
      }

      break;

    case 6: //6

      for (int i = 0; i < 12; i++) {
        toggleTile(char6_x[i] + _x, char6_y[i] + _y);
      }

      break;

    case 7: //7

      for (int i = 0; i < 7; i++) {
        toggleTile(char7_x[i] + _x, char7_y[i] + _y);
      }

      break;

    case 8: //8

      for (int i = 0; i < 13; i++) {
        toggleTile(char8_x[i] + _x, char8_y[i] + _y);
      }

      break;

    case 9: //9

      for (int i = 0; i < 12; i++) {
        toggleTile(char9_x[i] + _x, char9_y[i] + _y);
      }

      break;

    case 10: //A

      for (int i = 0; i < 10; i++) {
        toggleTile(charA_x[i] + _x, charA_y[i] + _y);
      }

      break;

    case 11: //B

      for (int i = 0; i < 10; i++) {
        toggleTile(charB_x[i] + _x, charB_y[i] + _y);
      }

      break;

    case 12: //C

      for (int i = 0; i < 7; i++) {
        toggleTile(charC_x[i] + _x, charC_y[i] + _y);
      }

      break;

    case 13: //D

      for (int i = 0; i < 10; i++) {
        toggleTile(charD_x[i] + _x, charD_y[i] + _y);
      }

      break;

    case 14: //E

      for (int i = 0; i < 10; i++) {
        toggleTile(charE_x[i] + _x, charE_y[i] + _y);
      }

      break;

    case 15: //F

      for (int i = 0; i < 8; i++) {
        toggleTile(charF_x[i] + _x, charF_y[i] + _y);
      }

      break;

    case 16: //G

      for (int i = 0; i < 12; i++) {
        toggleTile(charG_x[i] + _x, charG_y[i] + _y);
      }

      break;

    case 17: //H

      for (int i = 0; i < 11; i++) {
        toggleTile(charH_x[i] + _x, charH_y[i] + _y);
      }

      break;

    case 19: //J

      for (int i = 0; i < 6; i++) {
        toggleTile(charJ_x[i] + _x, charJ_y[i] + _y);
      }

      break;

    case 20: //K

      for (int i = 0; i < 10; i++) {
        toggleTile(charK_x[i] + _x, charK_y[i] + _y);
      }

      break;

    case 21: //L

      for (int i = 0; i < 7; i++) {
        toggleTile(charL_x[i] + _x, charL_y[i] + _y);
      }

      break;

    case 22: //M

      for (int i = 0; i < 13; i++) {
        toggleTile(charM_x[i] + _x, charM_y[i] + _y);
      }

      break;

    case 23: //N

      for (int i = 0; i < 12; i++) {
        toggleTile(charN_x[i] + _x, charN_y[i] + _y);
      }

      break;

    case 24: //O

      for (int i = 0; i < 8; i++) {
        toggleTile(charO_x[i] + _x, charO_y[i] + _y);
      }

      break;

    case 25: //P

      for (int i = 0; i < 8; i++) {
        toggleTile(charP_x[i] + _x, charP_y[i] + _y);
      }

      break;

    case 26: //Q

      for (int i = 0; i < 10; i++) {
        toggleTile(charQ_x[i] + _x, charQ_y[i] + _y);
      }

      break;

    case 27: //R

      for (int i = 0; i < 10; i++) {
        toggleTile(charR_x[i] + _x, charR_y[i] + _y);
      }

      break;

    case 28: //S

      for (int i = 0; i < 7; i++) {
        toggleTile(charS_x[i] + _x, charS_y[i] + _y);
      }

      break;

    case 29: //T

      for (int i = 0; i < 7; i++) {
        toggleTile(charT_x[i] + _x, charT_y[i] + _y);
      }

      break;

    case 30: //U

      for (int i = 0; i < 11; i++) {
        toggleTile(charU_x[i] + _x, charU_y[i] + _y);
      }

      break;

    case 31: //V

      for (int i = 0; i < 9; i++) {
        toggleTile(charV_x[i] + _x, charV_y[i] + _y);
      }

      break;

    case 32: //W

      for (int i = 0; i < 12; i++) {
        toggleTile(charW_x[i] + _x, charW_y[i] + _y);
      }

      break;

    case 33: //X

      for (int i = 0; i < 9; i++) {
        toggleTile(charX_x[i] + _x, charX_y[i] + _y);
      }

      break;

    case 34: //Y

      for (int i = 0; i < 9; i++) {
        toggleTile(charY_x[i] + _x, charY_y[i] + _y);
      }

      break;

    case 35: //Z

      for (int i = 0; i < 10; i++) {
        toggleTile(charZ_x[i] + _x, charZ_y[i] + _y);
      }

      break;

  }

}
