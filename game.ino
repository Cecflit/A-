class Game {
  public:
    Game() {};
    virtual ~Game() {}
  
    virtual void Setup() = 0;
    virtual void Loop() = 0;
};
