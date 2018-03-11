class Game {
  public:
    Game() {};
    virtual ~Game() {}

    virtual void Loop() = 0;
};
