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

	virtual void OnCollisionEnterAbove(Collider* collider) override;
	virtual void OnCollisionEnterLeft(Collider* collider) override;
	virtual void OnCollisionEnterRight(Collider* collider) override;
	virtual void OnCollisionEnterBelow(Collider* collider) override;

	Vector2D GetPos() { return _pos; }

	bool IsColliding() { return _bIsColliding; }
	void SetColliding(bool IsColliding) { _bIsColliding = IsColliding; }

private:

	Vector2D _velocity = {};
	int32 _radius = 5;
	int32 _moveSpeed = 200;
	int32 _jumpSpeed = 600;
	int32 _gravity = 2;

	bool _bIsColliding = false;

	list<Vector2D> _prevPoses;
	float _recordTimer = 0.f;
};

