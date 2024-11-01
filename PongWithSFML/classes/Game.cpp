#include "Game.h"

Game::Game() : mWidth(1280), mHeight(720), window(sf::VideoMode(mWidth, mHeight), "Pong", sf::Style::Default), ball(mWidth / 2, mHeight / 2){

}

void Game::handleBall(){
	if (ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > mWidth) {
		ball.miss();
	}

	if (ball.getPosition().top < 0 || ball.getPosition().top + ball.getPosition().height > 720) {
		ball.bounceTop();
	}
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

		handleBall();

		window.clear();

		ball.Update(dt);
		window.draw(ball.getShape());

		window.display();
	}
}