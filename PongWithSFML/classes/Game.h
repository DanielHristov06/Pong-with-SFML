#pragma once

#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Paddle.h"

class Game {
private:
	const int mWidth;
	const int mHeight;

	float bounceTimer;

public:
	sf::RenderWindow window;

	sf::Event e;

	sf::Clock clock;
	sf::Time dt;

	Ball ball;
	Paddle paddle;

	Game();

	void handleBall(Paddle& paddle);
	void handlePaddle();

	void Run();
};