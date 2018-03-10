class Game {
  public:
    Game() {};
    ~Game() {}
  
    virtual void Setup() = 0;
    virtual void Loop() = 0;
};
