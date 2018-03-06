void loop() {
  unrenderScreen();
  clearScreen();
  drawLogo(game);
  drawTickDuration();

  while (digitalRead(buttonUp)) {

    if (!digitalRead(buttonLeft)) {
      if (tickDuration < 24) {
        clearTile(23 - tickDuration, 23);
        tickDuration++;
      }
    }
    if (!digitalRead(buttonRight)) {
      if (tickDuration) {
        tickDuration--;
        drawTile(23 - tickDuration, 23);
      }
    }
    if (!digitalRead(buttonDown)) {
      drawLogo(game);
      game++;
      playSound(2);
      if (game > 10)game = 0;
      drawLogo(game);
    }
    wait(10);

  }

  randomSeed(micros());

  playSound(1);

  if (game == 0) {

    GameSnake* g = new GameSnake;
    g->gameSnakeSetup();
    while (true) {
      g->gameSnakeLoop();
    }
    delete g;

    //loop snake
  }

  if (game == 1) {

    GameMineRun* g = new GameMineRun;
    g->gameMineRunSetup();
    while (true) {
      g->gameMineRunLoop();
    }
    delete g;

    //loop minerun
  }

  if (game == 2) {

    GameSpaceShoot* g = new GameSpaceShoot;
    g->gameSpaceShootSetup();
    while (true) {
      g->gameSpaceShootLoop();
    }
    delete g;

    //loop spaceshoot
  }

  if (game == 3) {

    GamePowerCord* g = new GamePowerCord;
    g->gamePowerCordSetup();
    while (true) {
      g->gamePowerCordLoop();
    }
    delete g;

    //loop powercord
  }

  if (game == 4) {

    GamePong* g = new GamePong;
    g->gamePongSetup();
    while (true) {
      g->gamePongLoop();
    }
    delete g;

    //loop pong
  }

  if (game == 5) {

    GameStreetCross* g = new GameStreetCross;
    g->gameStreetCrossSetup();
    while (true) {
      g->gameStreetCrossLoop();
    }
    delete g;

    //loop streetcross
  }

  if (game == 6) {

    GameArrowMatch* g = new GameArrowMatch;
    g->gameArrowMatchSetup();
    while (true) {
      g->gameArrowMatchLoop();
    }
    delete g;

    //loop arrowmatch
  }

  if (game == 7) {

    GameBallCatch* g = new GameBallCatch;
    g->gameBallCatchSetup();
    while (true) {
      g->gameBallCatchLoop();
    }
    delete g;

    //loop ballcatch
  }

  if (game == 8) {

    GameQuickReflex* g = new GameQuickReflex;
    g->gameQuickReflexSetup();
    while (true) {
      g->gameQuickReflexLoop();
    }
    delete g;

    //loop quickreflex
  }

  if (game == 9) {

    GameUnderAttack* g = new GameUnderAttack;
    g->gameUnderAttackSetup();
    while (true) {
      g->gameUnderAttackLoop();
    }
    delete g;

    //loop underattack
  }

  if (game == 10) {

    GameTetris* g = new GameTetris;
    g->gameTetrisSetup();
    while (true) {
      g->gameTetrisLoop();
    }
    delete g;

    //loop underattack
  }

}

