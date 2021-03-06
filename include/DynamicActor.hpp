#ifndef DYNAMICACTOR_HPP
#define DYNAMICACTOR_HPP

#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "Actor.hpp"
#include "AnimatedSprite.hpp"
#include "MoveEvent.hpp"

/*
 * Dynamic actor class. All dynamic actors inherit from the dynamic actor class.
 */
class DynamicActor : public Actor {
	public:
		DynamicActor();
		DynamicActor(sf::Color activeColor, float health, float damage, sf::Vector2f startPos, int speed);
		float getHealth();
		virtual void attack(DynamicActor &enemy) {};
		void changeColor(sf::Color color);
		sf::Color getColor();
		void setHealth(float health);
		void setPosition(sf::Vector2f pos);
		sf::Vector2f getPosition();
		float getDamage();
		void draw(sf::RenderWindow *window);
		void setAnimation(Animation &leftAnimation, Animation &rightAnimation, Animation &upAnimation, Animation &downAnimation);
		sf::FloatRect getGlobalBounds();
        void setKnockback(bool b);
        bool getKnockback();
		void move(int x, int y, float deltaTime);
		int getSpeed();
		void updateAttackClock(float deltaTime);
		bool canAttack();

	protected:
        AnimatedSprite m_animatedSprite;
        Animation m_MobWalkingDown;
        Animation m_MobWalkingUp;
        Animation m_MobWalkingRight;
        Animation m_MobWalkingLeft;
        float m_attackClock;
        bool m_canAttack;

	private:
        sf::Color m_activeColor;
		float m_health;
		float m_damage; // Attack damage
		sf::Vector2f m_position;
        bool m_knockback;
		int m_speed;


};


#endif
