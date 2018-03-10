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
  Game* g;
  
  switch (game) {
    default:
    case 0:  g = new GameSnake; break;
    case 1:  g = new GameMineRun; break;
    case 2:  g = new GameSpaceShoot; break;
    case 3:  g = new GamePowerCord; break;
    case 4:  g = new GamePong; break;
    case 5:  g = new GameStreetCross; break;
    case 6:  g = new GameArrowMatch; break;
    case 7:  g = new GameBallCatch; break;
    case 8:  g = new GameQuickReflex; break;
    case 9:  g = new GameUnderAttack; break;
    case 10: g = new GameTetris; break;
  }
  
  //g->Setup();
  while (true) {
    g->Loop();
  }
  delete g;
  
}

