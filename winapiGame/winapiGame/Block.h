#pragma once
#include "Object.h"

class Block : public Object
{
public:
	Block(Vector2D size);
	virtual ~Block();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;


private:
	Vector2D _size = {};
};

