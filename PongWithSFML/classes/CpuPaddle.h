#pragma once

#include "Paddle.h"
#include "Ball.h"

class CpuPaddle : public Paddle {
public:
	CpuPaddle(float startX, float startY);
	void Update(sf::Time dt, Ball& ball);
};