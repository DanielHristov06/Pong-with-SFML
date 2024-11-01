#include "Game.h"

Game::Game()
	: mWidth(1280),
	mHeight(720),
	window(sf::VideoMode(mWidth, mHeight), "Pong", sf::Style::Default),
	ball(mWidth / 2, mHeight / 2),
	paddle(32, mHeight / 2),
	bounceTimer(0.10f)
{
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
}

void Game::handleBall(Paddle& paddle){
	if (ball.getPosition().intersects(paddle.getPosition())) {
		if (bounceTimer < 0) {
			ball.bounceSides();
			bounceTimer = 0.10f;
		}
	}

	if (ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > mWidth) {
		ball.miss();
	}

	if (ball.getPosition().top < 0 || ball.getPosition().top + ball.getPosition().height > 720 && bounceTimer < 0) {
		ball.bounceTop();
		bounceTimer = 0.10f;
	}
}

void Game::handlePaddle() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) paddle.moveUp();
	else paddle.stopUp();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) paddle.moveDown();
	else paddle.stopDown();
}

void Game::Run(){
	while (window.isOpen()) {
		dt = clock.restart();
		bounceTimer -= dt.asSeconds();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}

		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();

		ball.Update(dt);
		ball.Draw(window);

		paddle.Update(dt);
		paddle.Draw(window);

		handleBall(paddle);
		handlePaddle();

		window.display();
	}
}