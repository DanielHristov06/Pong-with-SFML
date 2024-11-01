#include "Paddle.h"

Paddle::Paddle(float startX, float startY) : mPosition(sf::Vector2f(startX, startY)) {
	mShape.setSize(sf::Vector2f(mWidth, mHeight));
	mShape.setOrigin(sf::Vector2f(mShape.getSize().x / 2, mShape.getSize().y / 2));
	mShape.setFillColor(sf::Color::Blue);
	mShape.setOutlineThickness(3.f);
	mShape.setPosition(mPosition);
}

sf::RectangleShape Paddle::getShape() {
	return mShape;
}

sf::FloatRect Paddle::getPosition() {
	return mShape.getGlobalBounds();
}

void Paddle::moveUp() {
	mMovingUp = true;
}

void Paddle::moveDown(){ 
	mMovingDown = true;
}

void Paddle::stopUp() {
	mMovingUp = false;
}

void Paddle::stopDown() {
	mMovingDown = false;
}

void Paddle::Update(sf::Time dt) {
	mPosition.y = std::clamp(mPosition.y, mShape.getSize().y / 2, 720 - mShape.getSize().y / 2);

	if (mMovingUp) {
		mPosition.y -= mSpeed * dt.asSeconds();
	}

	if (mMovingDown) {
		mPosition.y += mSpeed * dt.asSeconds();
	}

	mShape.setPosition(mPosition);
}

void Paddle::Draw(sf::RenderWindow& window) {
	window.draw(getShape());
}