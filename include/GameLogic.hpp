#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

#include "Process.hpp"
#include "EventInterface.hpp"
#include "EventManager.hpp"
#include "EventListener.hpp"
#include "AnimatedSprite.hpp"
#include "EventType.hpp"
#include "Player.hpp"
#include "Mob.hpp"
#include "Greyscale.hpp"
#include "Actor.hpp"
#include "GameState.hpp"
#include "Macros.hpp"
#include "MoveEvent.hpp"
#include "LoadMapEvent.hpp"
#include "DoorEvent.hpp"
#include "AttackEvent.hpp"
#include "SpawnEvent.hpp"
#include "SwitchColorEvent.hpp"
#include "PathMapEvent.hpp"

#include <iostream>
#include <cmath>


class ChromaBlade;
class PlayerView;
class AIView;

class GameLogic : public Process {
public:
    GameLogic();
    void init();
    void update(float &deltaTime);
    void setCharPosition(sf::Vector2f position);
    void resetCharacter();
    void setGameApplication(ChromaBlade* game);
    void setAnimatedSprite(AnimatedSprite* sprite);
    void setView(PlayerView* view);
    void setListeners();
    std::vector<Actor*> getRocks();
    void clearActors();
    std::vector<DynamicActor*> getMobs();
    std::vector<DynamicActor*> getGreyscale();
    void setCollisionMapping(std::vector<sf::RectangleShape>, std::vector<sf::RectangleShape>);
    void setBoundaries(int xBound, int yBound);
    void toggleLevel();
    bool hasColor(sf::Color col);
    int getLevelsCleared();
    float getPlayerHealth();
    char** getPathMap();
    sf::Vector2i getNumNodes();

private:
    bool checkCollisions(sf::FloatRect fr, int extra);
    bool checkTileCollisions(const sf::FloatRect& fr);
    bool checkRockCollisions(const sf::FloatRect& fr);
    bool checkMobCollisions(const sf::FloatRect& fr);
    bool checkDoors(sf::FloatRect fr, int extra);
    bool checkPlayer(sf::FloatRect fr, int extra);
    bool checkPortals(const sf::FloatRect& fr, sf::Vector2f prev);
    void playerAttack(Direction dir);
    void moveMobs(float &deltaTime);
    void enemyAttack(DynamicActor* attacker);
    void spawnGreyscale();

    // Event triggered methods
    void moveChar(const EventInterface& event);
    void attack(const EventInterface& event);
    void spawn(const EventInterface& event);
    void useDoor(const EventInterface& event);
    void switchColor(const EventInterface& event);
    void unlockColor(GameState state);
    void pathMap(const EventInterface& event);


private:
    std::vector<sf::RectangleShape> m_collisionVector;
    std::vector<sf::RectangleShape> m_doors;
    std::vector<Actor*> m_rocks;
    std::vector<DynamicActor*> m_mobs;
    std::vector<DynamicActor*> m_greyscaleVec;
    std::vector<sf::Vector2i> m_redClearedRooms;
    std::vector<sf::Vector2i> m_yellowClearedRooms;
    std::vector<sf::Vector2i> m_blueClearedRooms;
    bool m_possibleMobColors[3] = {true, false, false}; // in the order of red, blue, yellow
    std::vector<sf::RectangleShape> m_portals;

    char **m_pathMap;
    sf::Vector2i m_numNodes;

    sf::RectangleShape m_redPortal;
    sf::RectangleShape m_bluePortal;
    sf::RectangleShape m_yellowPortal;
    sf::RectangleShape m_greyPortal;
    bool m_clearedLevels[3];

    int m_xBound;
    int m_yBound;

    int m_mobFactor = 0;

    sf::Vector2f m_dungeonReturnPosition;
    sf::Vector2f m_dungeonReturnCamera;
    bool m_inCombat;
    bool m_bossAvailable;
    bool m_isOnPortal;

    Player m_player;
    AnimatedSprite* m_sprite;
    ChromaBlade* m_game;
    PlayerView* m_view;
    std::vector<AIView*> m_aiviews;
    bool m_onDoor;
    bool m_levelToggled;
};

#endif
