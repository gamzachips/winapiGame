#pragma once
#include "Scene.h"

class Ball;
class TilemapActor;

class DevScene : public Scene
{
public:
	DevScene();
	virtual ~DevScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

protected:
	Ball* _ball = nullptr;
	TilemapActor* _tilemapActor = nullptr;
};

