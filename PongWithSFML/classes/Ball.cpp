#include "Ball.h"

Ball::Ball(float startX, float startY) : mPosition(sf::Vector2f(startX, startY)){
	mBall.setSize(sf::Vector2f(10.f, 10.f));
	mBall.setPosition(mPosition);
}

sf::FloatRect Ball::getPosition(){
	return mBall.getGlobalBounds();
}

sf::RectangleShape Ball::getShape(){
	return mBall;
}

void Ball::bounceSides(){
	mDirectionX *= -1;
}

void Ball::bounceTop(){
	mDirectionY *= -1;
}

void Ball::miss(){
	mPosition.x = 1280 / 2;
	mPosition.y = 720 / 2;
}

void Ball::hitBall(){

}

void Ball::Update(sf::Time dt){
	mPosition.x += mDirectionX * mSpeed * dt.asSeconds();
	mPosition.y += mDirectionY * mSpeed * dt.asSeconds();

	mBall.setPosition(mPosition);
}