#pragma once
#include "Object.h"

//Player
class Ball : public Object
{
public:
	Ball();
	virtual ~Ball();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void Jump();
	void Move();
	void ApplyGravity();

	Vector2D GetPos() { return _pos; }

private:

	Vector2D _velocity = {};
	int32 _radius = 5;
	int32 _moveSpeed = 80;
	int32 _jumpSpeed = 500;
	int32 _gravity = 10;
};

