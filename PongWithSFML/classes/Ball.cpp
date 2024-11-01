#include "Ball.h"

Ball::Ball(float startX, float startY){
	mPosition.x = startX;
	mPosition.y = startY;

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

void Ball::missBottom(){
	mPosition.x = 1280 / 2;
	mPosition.y = 0;
}

void Ball::hitBall(){

}

void Ball::Update(sf::Time dt){
	mPosition.x += mDirectionX * mSpeed * dt.asSeconds();
	mPosition.y += mDirectionY * mSpeed * dt.asSeconds();

	mBall.setPosition(mPosition);
}