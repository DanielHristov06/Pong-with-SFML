#pragma once

#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Paddle.h"
#include "CpuPaddle.h"
#include <sstream>

class Game {
private:
	const int mWidth;
	const int mHeight;

	int score1;
	int score2;

public:
	sf::RenderWindow window;

	sf::Event e;

	sf::Clock clock;
	sf::Time dt;

	Ball ball;
	Paddle paddle;
	CpuPaddle bot;

	sf::Font font;
	sf::Text hud;
	std::stringstream ss;

	sf::Text hud2;
	std::stringstream ss2;

	sf::RectangleShape line;

	Game();

	void handleBall(Paddle& paddle, CpuPaddle& bot);
	void handlePaddle();

	void Draw();

	void Run();
};