#pragma once
#include "SFML/Graphics.hpp"

class Paddle {
protected:
	sf::RectangleShape mShape;
	sf::Vector2f mPosition;

	const float mSpeed = 1000.f;
	const int mWidth = 10;
	const int mHeight = 80;

	bool mMovingUp = false;
	bool mMovingDown = false;

public:
	Paddle(float startX, float startY);

	sf::RectangleShape getShape();
	sf::FloatRect getPosition();

	void moveUp();
	void moveDown();
	void stopUp();
	void stopDown();

	void Update(sf::Time dt);
	void Draw(sf::RenderWindow& window);
};