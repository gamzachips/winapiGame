#pragma once
#include "Scene.h"

class Ball;
class TilemapObject;

class StageScene : public Scene
{
public:
	StageScene();
	virtual ~StageScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

protected:
	list<Object*> _objects;
};

