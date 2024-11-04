#pragma once
#include "SFML/Graphics.hpp"

class Ball {
private:
	sf::Vector2f mPosition;
	sf::CircleShape mBall;

	const float mSpeed = 500.f;
	float mDirectionX = 1.f;
	float mDirectionY = 1.f;

public:
	Ball(float startX, float startY);

	sf::FloatRect getPosition();

	sf::CircleShape getShape();

	void bounceSides();

	void bounceTop();

	void miss();

	void Update(sf::Time dt);

	void Draw(sf::RenderWindow& window);
};