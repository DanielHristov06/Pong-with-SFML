#include "CpuPaddle.h"

CpuPaddle::CpuPaddle(float startX, float startY) : Paddle(startX, startY) {
	
}

void CpuPaddle::Update(sf::Time dt, Ball& ball) {
	mPosition.y = std::clamp(mPosition.y, mShape.getSize().y / 2, 720 - mShape.getSize().y / 2);

	if (mShape.getPosition().y + (float)mHeight / 2 > ball.getPosition().top) {
		mPosition.y -= mSpeed * dt.asSeconds();
	}
	else if (mShape.getPosition().y + (float)mHeight / 2 <= ball.getPosition().top) {
		mPosition.y += mSpeed * dt.asSeconds();
	}

	mShape.setPosition(mPosition);
}