#pragma once
#include "SFML/Graphics.hpp"

class Paddle {
private:
	sf::RectangleShape mShape;
	sf::Vector2f mPosition;
	float mSpeed = 1100.f;
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