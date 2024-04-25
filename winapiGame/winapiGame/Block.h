#pragma once
#include "Object.h"

class Block : public Object
{
public:
	Block(Vector2D size);
	virtual ~Block();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

	virtual void OnCollisionEnterAbove() abstract;
	virtual void OnCollisionEnterLeft() abstract;
	virtual void OnCollisionEnterRight() abstract;
	virtual void OnCollisionEnterBelow() abstract;

private:
	Vector2D _size = {};
};

