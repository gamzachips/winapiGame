#pragma once
#include "Scene.h"

class Ball;
class TilemapObject;
class Object;

class EditScene : public Scene
{
public:
	EditScene();
	virtual ~EditScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

protected:
	list<Object*> _objects;
};

