#pragma once
#include "SFML/Graphics.hpp"

class Ball
{
private:
	sf::Vector2f mPosition;
	sf::RectangleShape mBall;

	const float mSpeed = 500.f;
	float mDirectionX = 1.f;
	float mDirectionY = 1.f;

public:
	Ball(float startX, float startY);

	sf::FloatRect getPosition();

	sf::RectangleShape getShape();

	void bounceSides();

	void bounceTop();

	void miss();

	void hitBall();

	void Update(sf::Time dt);
};