class GameJump : public Game {
  private:
  
  class Penguin {
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
    }

    void Loop() {

      loopCounter++;
      if(loopCounter >= 60) {
        loopCounter = 0;
        biome = randomInteger(0, 2);
      }
    }

  private:

    void moveScreen() {

      clearScene();
      Jumpy.positionX--;
      for(byte i = 0; i < 23; i++) {
        for(byte j = 0; j < 24; j++) {
          arr[][]
        }
      }
      generate();
    }

    void generate() {


      generateColumn(23);
      if(!(randomInteger(0, 5)))placeCoin();
      
    }

    void generateColumn(byte column) {

      if(column) {
        
      } else {
        
      }

      if(column == 23 && randomInteger(0, 2) && Jumpy.positionX < 0) {
        placeJumpy();
      }
      
    }

    void generateInit() {
      
      for(byte i = 0; i < 24; i++) {
        generateColumn(i);
      }
      placeTux();
      
    }

    void placeCoin() {

      for(byte i = 0; i < 24; i++) {
        if(arr[23][i] == 2) {
          arr[23][i-1] = 5;
          break;
        }
      }
      
    }

    void moveLeft() {

      Tux.positionX--;
      if(Tux.positionX < 0)Tux.positionX = 0;
      
    }

    void moveRight() {

      Tux.positionX++;

      if(Tux.positionX >= 8) {
        moveScreen();
      } else {
        
      }
      
    }

    void moveUp() {

      Tux.positionY--;
      Tux.jumpCounter--;
      
    }

    void moveDown() {

      Tux.positionY++;
      
    }

    void letMove() {

      if(!(digitalRead(buttonLeft))) {

        if(!(detectCollisionLeft)) {
          moveLeft();
        }
        
      }

      if(!(digitalRead(buttonRight))) {

        if(!(detectCollisionRight)) {
          moveRight();
        }
        
      }

      if(!(digitalRead(buttonUp))) {
        if(arr[Tux.positionX][Tux.positionY + 1] == 2){
          Tux.jumpCounter = 6;
          moveUp();
        } else {
          moveUp();
        }
      } else{
        Tux.jumpCounter = 0;
      }
      
    }

    byte checkCollisionDown() {

      if(arr[Tux.positionX][Tux.positionY + 1] == 2) {
        return true;
      }

      return false;
      
    }

    byte checkCollisionLeft() {

      if(arr[Tux.positionX - 1][Tux.positionY] == 2 || Tux.positionX <= 0){
        return true;
      }

      return false;
      
    }

    byte checkCollisionRight() {

      if(arr[Tux.positionX + 1][Tux.positionY] == 2){
        return true;
      }

      return false;
      
    }

    byte checkCollisionWithCoin() {

      if(arr[Tux.positionX][Tux.positionY] == 5){
        return true;
      }

      return false;
      
    }

    void placeTux() {

        Tux.positionX = 3;
        for (byte i = 23; i < 0; i--) {
          if(!(arr[3][i])) {
            Tux.positionY = i;
            break;
          }
        }
      
    }

    void placeJumpy() {

        Jumpy.positionX = 23;
        for (byte i = 23; i < 0; i--) {
          if(!(arr[23][i])) {
            Tux.positionY = i;
            break;
          }
        }
      
    }

    void drawScene() {

      if(Tux.positionY >= 0)drawTile(Tux.positionX, Tux.positionY);
      if(Jumpy.positionX >= 0 && Jumpy.positionY >= 0)drawTile(Jumpy.positionX, Jumpy.positionY);
      
    }

    void clearScene() {

      if(Tux.positionY >= 0)clearTile(Tux.positionX, Tux.positionY);
      if(Jumpy.positionX >= 0 && Jumpy.positionY >= 0)clearTile(Jumpy.positionX, Jumpy.positionY);
      
    }
    
}
