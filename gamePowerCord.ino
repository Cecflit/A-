class GamePowerCord : public Game {
  private:
    byte Orientation;
    bool LastPressed;
    byte Pass;

    class line {

      public:
        int pos = 0;
        bool forw = true;
        line() {}

    };

    line Moving = line();
    line Dormant = line();

  public:

    GamePowerCord() :
      Game(),
      Orientation(randomInteger(0, 4)),
      LastPressed(!(digitalRead(buttonUp) && digitalRead(buttonDown) && digitalRead(buttonLeft) && digitalRead(buttonRight))),
      Pass(0),
      Moving(),
      Dormant()
    {
      Dormant.forw = false;
      clearScreen();
      score = 0;
      Moving.pos = randomInteger(0, 24);
      Dormant.pos = randomInteger(0, 24);
    }

    ~GamePowerCord() {}

    void Loop() {

      randomSeed(micros());
      while (Moving.pos == Dormant.pos) {
        Moving.pos = randomInteger(0, 24);
        Dormant.pos = randomInteger(0, 24);
      }
      Orientation = randomInteger(0, 4);
      DrawLines();

      while (!AnyPressed()) {
        //RenderListen(false);
        wait(2 * (tickDuration + 1));
      }
      while (AnyPressed()) {
        RenderListen(false);
        wait(2 * (tickDuration + 1));
      }
      if (Moving.pos == Dormant.pos) {
        playSound(2);
        score++;
        if (score > 999)score = 999;
      } else {
        endGame();
      }
      if (score > 25) {
        while (score < 50) {
          Loop25();
        }
        while (score >= 50 && score < 75) {
          Loop50();
        }
        while (score >= 75) {
          Loop75();
        }
      }

    }

  private:

    void Loop25() {

      randomSeed(micros());
      while (Moving.pos == Dormant.pos) {
        Moving.pos = randomInteger(0, 24);
        Dormant.pos = randomInteger(0, 24);
      }
      Orientation = randomInteger(0, 4);
      DrawLines();

      while (!AnyPressed()) {
        wait(tickDuration + 1);
      }
      while (AnyPressed()) {
        RenderListen(false);
        wait(tickDuration + 1);
      }
      if (Moving.pos == Dormant.pos) {
        playSound(2);
        score++;
        if (score > 999)score = 999;
      } else {
        endGame();
      }
    }

    void Loop50() {
      randomSeed(micros());
      while (Moving.pos == Dormant.pos) {
        Moving.pos = randomInteger(0, 24);
        Dormant.pos = randomInteger(0, 24);
      }
      Orientation = randomInteger(0, 4);
      DrawLines();

      while (!AnyPressed()) {
        wait(tickDuration + 1);
      }
      while (AnyPressed()) {
        RenderListen(true);
        wait(tickDuration + 1);
      }
      if (Moving.pos == Dormant.pos) {
        playSound(2);
        score++;
        if (score > 999)score = 999;
      } else {
        endGame();
      }
    }

    void Loop75() {
      randomSeed(micros());
      while (Moving.pos == Dormant.pos) {
        Moving.pos = randomInteger(0, 24);
        Dormant.pos = randomInteger(0, 24);
      }
      Orientation = randomInteger(0, 4);
      DrawLines();

      while (!AnyPressed()) {
        wait(tickDuration + 1);
      }
      while (AnyPressed()) {
        RenderListen(2);
        wait(tickDuration + 1);
      }
      if (Moving.pos == Dormant.pos) {
        playSound(2);
        score++;
        if (score > 999)score = 999;
      } else {
        endGame();
      }
    }

    bool AnyPressed() {

      return !(digitalRead(buttonUp) && digitalRead(buttonDown) && digitalRead(buttonLeft) && digitalRead(buttonRight));

    }

    void RenderListen(byte both) {
      Pass++;
      if (!both || both == 2 || (both == 1 && (Pass % 2))) {
        if (Moving.forw) {
          Moving.pos++;
          if (Moving.pos >= 23) {
            Moving.forw = false;
            Moving.pos = 23;
          }
        } else {
          Moving.pos--;
          if (Moving.pos <= 0) {
            Moving.forw = true;
            Moving.pos = 0;
          }
        }
      }

      if (both && !(Pass % 2)) {
        if (Dormant.forw) {
          Dormant.pos++;
          if (Dormant.pos >= 23) {
            Dormant.forw = false;
            Dormant.pos = 23;
          }
        } else {
          Dormant.pos--;
          if (Dormant.pos <= 0) {
            Dormant.forw = true;
            Dormant.pos = 0;
          }
        }
      }

      DrawLines();
    }

    void RenderListen10() {

    }

    void DrawLines() {

      clearScreen();

      if (!Orientation) {

        for (byte i = 0; i < 12; i++) {

          drawTile(i, Dormant.pos);
          drawTile(i + 12, Moving.pos);

        }

      } else if (Orientation == 1) {

        for (byte i = 0; i < 12; i++) {

          drawTile(Dormant.pos, i);
          drawTile(Moving.pos, i + 12);

        }
      } else if (Orientation == 2) {

        for (byte i = 0; i < 12; i++) {

          drawTile(Dormant.pos, i + 12);
          drawTile(Moving.pos, i);

        }
      }  else if (Orientation == 3) {

        for (byte i = 0; i < 12; i++) {

          drawTile(i + 12, Dormant.pos);
          drawTile(i, Moving.pos);

        }
      }
    }

};
