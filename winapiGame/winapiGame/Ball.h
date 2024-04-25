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
	void RecordPos();

	virtual void OnCollisionEnterAbove() override;
	virtual void OnCollisionEnterLeft() override;
	virtual void OnCollisionEnterRight() override;
	virtual void OnCollisionEnterBelow() override;

	Vector2D GetPos() { return _pos; }
private:

	Vector2D _velocity = {};
	int32 _radius = 5;
	int32 _moveSpeed = 120;
	int32 _jumpSpeed = 600;
	int32 _gravity = 2;

	list<Vector2D> _prevPoses;
	float _recordTimer = 0.f;
};

