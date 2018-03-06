class GameStreetCross {
  public:
    
    bool LastUp;
    
    class vehicle {
    
      public:
        int lane;
        char positionX;
        vehicle () {}
    
    };
    
    vehicle Lane0_0 = vehicle();
    vehicle Lane0_1 = vehicle();
    vehicle Lane0_2 = vehicle();
    vehicle Lane1_0 = vehicle();
    vehicle Lane1_1 = vehicle();
    vehicle Lane1_2 = vehicle();
    vehicle Lane2_0 = vehicle();
    vehicle Lane2_1 = vehicle();
    vehicle Lane2_2 = vehicle();
    vehicle Lane3_0 = vehicle();
    vehicle Lane3_1 = vehicle();
    vehicle Lane3_2 = vehicle();
    
    class crosser {
    
      public:
        int positionX;
        int positionY;
        crosser () {}
    
    };
    
    crosser Crosser = crosser();
    
    void Setup() {
    
      score = 0;
      LastUp = false;
      Lane0_0.lane = 4;
      Lane0_1.lane = 4;
      Lane0_2.lane = 4;
      Lane1_0.lane = 9;
      Lane1_1.lane = 9;
      Lane1_2.lane = 9;
      Lane2_0.lane = 14;
      Lane2_1.lane = 14;
      Lane2_2.lane = 14;
      Lane3_0.lane = 19;
      Lane3_1.lane = 19;
      Lane3_2.lane = 19;
    
      Lane0_0.positionX = 0;
      Lane0_1.positionX = 8;
      Lane0_2.positionX = 16;
      Lane1_0.positionX = 4;
      Lane1_1.positionX = 12;
      Lane1_2.positionX = 20;
      Lane2_0.positionX = 0;
      Lane2_1.positionX = 8;
      Lane2_2.positionX = 16;
      Lane3_0.positionX = 4;
      Lane3_1.positionX = 12;
      Lane3_2.positionX = 20;
    
      Crosser.positionX = 11;
      Crosser.positionY = 22;
    
      clearScreen();
      DrawScreen();
    
    }
    
    void Loop() {
    
      clearTile(Crosser.positionX, Crosser.positionY);
      DrawScreen();
    
      LetMove();
      CheckScore();
      MoveVehicles();
    
      DrawScreen();
      CheckCollision();
      drawTile(Crosser.positionX, Crosser.positionY);
    
      wait(tickDuration + 1);
    
    }
    
    void LetMove() {
    
      if (!digitalRead(buttonUp))Crosser.positionY--;
      if (!digitalRead(buttonDown))Crosser.positionY++;
      if (!digitalRead(buttonLeft))Crosser.positionX--;
      if (!digitalRead(buttonRight))Crosser.positionX++;
    
      if (Crosser.positionX < 0)Crosser.positionX = 23;
      if (Crosser.positionX > 23)Crosser.positionX = 0;
      if (Crosser.positionY < 0)Crosser.positionY = 0;
      if (Crosser.positionY > 23)Crosser.positionY = 23;
    
    }
    
    void MoveVehicles() {
    
      Lane0_0.positionX++;
      if (Lane0_0.positionX > 23)Lane0_0.positionX = 0;
      Lane0_1.positionX++;
      if (Lane0_1.positionX > 23)Lane0_1.positionX = 0;
      Lane0_2.positionX++;
      if (Lane0_2.positionX > 23)Lane0_2.positionX = 0;
      Lane1_0.positionX++;
      if (Lane1_0.positionX > 23)Lane1_0.positionX = 0;
      Lane1_1.positionX++;
      if (Lane1_1.positionX > 23)Lane1_1.positionX = 0;
      Lane1_2.positionX++;
      if (Lane1_2.positionX > 23)Lane1_2.positionX = 0;
    
      Lane2_0.positionX--;
      if (Lane2_0.positionX < 0)Lane2_0.positionX = 23;
      Lane2_1.positionX--;
      if (Lane2_1.positionX < 0)Lane2_1.positionX = 23;
      Lane2_2.positionX--;
      if (Lane2_2.positionX < 0)Lane2_2.positionX = 23;
      Lane3_0.positionX--;
      if (Lane3_0.positionX < 0)Lane3_0.positionX = 23;
      Lane3_1.positionX--;
      if (Lane3_1.positionX < 0)Lane3_1.positionX = 23;
      Lane3_2.positionX--;
      if (Lane3_2.positionX < 0)Lane3_2.positionX = 23;
    }
    
    void DrawScreen() {
    
      toggleTile(Lane0_0.positionX, Lane0_0.lane);
      toggleTile(Lane0_1.positionX, Lane0_1.lane);
      toggleTile(Lane0_2.positionX, Lane0_2.lane);
      toggleTile(Lane1_0.positionX, Lane1_0.lane);
      toggleTile(Lane1_1.positionX, Lane1_1.lane);
      toggleTile(Lane1_2.positionX, Lane1_2.lane);
      toggleTile(Lane2_0.positionX, Lane2_0.lane);
      toggleTile(Lane2_1.positionX, Lane2_1.lane);
      toggleTile(Lane2_2.positionX, Lane2_2.lane);
      toggleTile(Lane3_0.positionX, Lane3_0.lane);
      toggleTile(Lane3_1.positionX, Lane3_1.lane);
      toggleTile(Lane3_2.positionX, Lane3_2.lane);
    
      if (Lane0_0.positionX < 23) {
        toggleTile(Lane0_0.positionX + 1, Lane0_0.lane);
      } else toggleTile(0, Lane0_0.lane);
    
      if (Lane0_1.positionX < 23) {
        toggleTile(Lane0_1.positionX + 1, Lane0_1.lane);
      } else toggleTile(0, Lane0_1.lane);
    
      if (Lane0_2.positionX < 23) {
        toggleTile(Lane0_2.positionX + 1, Lane0_2.lane);
      } else toggleTile(0, Lane0_2.lane);
    
    
      if (Lane1_0.positionX < 23) {
        toggleTile(Lane1_0.positionX + 1, Lane1_0.lane);
      } else toggleTile(0, Lane1_0.lane);
    
      if (Lane1_1.positionX < 23) {
        toggleTile(Lane1_1.positionX + 1, Lane1_1.lane);
      } else toggleTile(0, Lane1_1.lane);
    
      if (Lane1_2.positionX < 23) {
        toggleTile(Lane1_2.positionX + 1, Lane1_2.lane);
      } else toggleTile(0, Lane1_2.lane);
    
      if (Lane2_0.positionX < 23) {
        toggleTile(Lane2_0.positionX + 1, Lane2_0.lane);
      } else toggleTile(0, Lane2_0.lane);
    
      if (Lane2_1.positionX < 23) {
        toggleTile(Lane2_1.positionX + 1, Lane2_1.lane);
      } else toggleTile(0, Lane2_1.lane);
    
      if (Lane2_2.positionX < 23) {
        toggleTile(Lane2_2.positionX + 1, Lane2_2.lane);
      } else toggleTile(0, Lane2_2.lane);
    
    
      if (Lane3_0.positionX < 23) {
        toggleTile(Lane3_0.positionX + 1, Lane3_0.lane);
      } else toggleTile(0, Lane3_0.lane);
    
      if (Lane3_1.positionX < 23) {
        toggleTile(Lane3_1.positionX + 1, Lane3_1.lane);
      } else toggleTile(0, Lane3_1.lane);
    
      if (Lane3_2.positionX < 23) {
        toggleTile(Lane3_2.positionX + 1, Lane3_2.lane);
      } else toggleTile(0, Lane3_2.lane);
    }
    
    void CheckCollision() {
      
      if (arr[Crosser.positionX][Crosser.positionY]) endGame();
    
    }
    
    void CheckScore() {
    
      if (Crosser.positionY < Lane0_0.lane && !LastUp) {
    
        score++;
        playSound(3);
        LastUp = true;
    
      }
    
      if (Crosser.positionY > Lane3_0.lane && LastUp) {
    
        score++;
        playSound(3);
        LastUp = false;
    
      }
    
      if (score > 999)score = 999;
    
    }
    
};
