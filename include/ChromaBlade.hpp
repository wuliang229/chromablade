#ifndef CHROMABLADE
#define CHROMABLADE

#include <PlayerView.hpp>
#include <GameLogic.hpp>
#include <SFML/System/Clock.hpp>

class ChromaBlade{
public:
  ChromaBlade();
  void init();
  void run();
  void pause();
  void shutdown();
private: // functions
private: //vars and objs
  GameLogic gameLogic;
  PlayerView playerView;
  sf::RenderWindow window;
  sf::Clock fpsTimer;
};

#endif
