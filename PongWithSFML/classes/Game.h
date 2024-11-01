#pragma once

#include "SFML/Graphics.hpp"
#include "Ball.h"

class Game
{
private:
	const int mWidth;
	const int mHeight;

public:
	sf::RenderWindow window;

	sf::Event e;

	sf::Clock clock;
	sf::Time dt;

	Ball ball;

	Game();

	void handleBall();

	void Run();
};