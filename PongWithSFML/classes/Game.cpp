#include "Game.h"
#include <iostream>

Game::Game()
	: mWidth(1280),
	mHeight(720),
	score1(0),
	score2(0),
	window(sf::VideoMode(mWidth, mHeight), "Pong", sf::Style::Default),
	ball(mWidth / 2, mHeight / 2),
	paddle(32, mHeight / 2),
	bot(mWidth - 32, mHeight / 2),
	line(sf::Vector2f(2.f, (float)mHeight))
{
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	if (!font.loadFromFile("Fonts/Valorant Font.ttf")) {
		std::cerr << "Error loading font" << std::endl;
	}

	hud.setFont(font);
	hud.setFillColor(sf::Color::Blue);
	hud.setPosition((float)mWidth / 4, 0);
	hud.setCharacterSize(20);

	hud2.setFont(font);
	hud2.setFillColor(sf::Color::Blue);
	hud2.setPosition((float)mWidth / 2 + (float)mWidth / 4, 0);
	hud2.setCharacterSize(20);

	ss << "Score: " << score1;
	hud.setString(ss.str());

	ss2 << "Score: " << score2;
	hud2.setString(ss2.str());

	line.setPosition(sf::Vector2f(mWidth / 2 - 1, 0.f));
}

void Game::handleBall(Paddle& paddle, CpuPaddle& bot){
	if (ball.getPosition().intersects(paddle.getPosition()) || ball.getPosition().intersects(bot.getPosition())) {
		ball.bounceSides();
	}

	if (ball.getPosition().left < 0) {
		ball.miss();
		score2++;
		ss2.str("");
		ss2.clear();
		ss2 << "Score: " << score2;
		hud2.setString(ss2.str());
	}

	if (ball.getPosition().left + ball.getPosition().width > mWidth) {
		ball.miss();
		score1++;
		ss.str("");
		ss.clear();
		ss << "Score: " << score1;
		hud.setString(ss.str());
	}

	if (ball.getPosition().top < 0 || ball.getPosition().top + ball.getPosition().height > 720) {
		ball.bounceTop();
	}
}

void Game::handlePaddle() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) paddle.moveUp();
	else paddle.stopUp();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) paddle.moveDown();
	else paddle.stopDown();
}

void Game::Update() {
	ball.Update(dt);
	paddle.Update(dt);
	bot.Update(dt, ball);

	handleBall(paddle, bot);
	handlePaddle();
}

void Game::Draw() {
	window.clear(sf::Color(3, 144, 252));

	window.draw(line);

	ball.Draw(window);
	paddle.Draw(window);
	bot.Draw(window);

	window.draw(hud);
	window.draw(hud2);

	window.display();
}

void Game::Run(){
	while (window.isOpen()) {
		dt = clock.restart();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}

		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
		}

		Update();
		Draw();
	}
}