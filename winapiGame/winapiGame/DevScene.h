#pragma once
#include "Scene.h"

class Ball;

class DevScene : public Scene
{
public:
	DevScene();
	virtual ~DevScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

protected:
	Ball* _ball;
};

