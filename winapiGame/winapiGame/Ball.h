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
	void CheckFall();
	void CheckGoal();

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
	float _moveMaxSpeed = 0.7;
	float _accelSpeed = 0.23;
	float _jumpSpeed = 2;
	float _gravity = 0.02;

	bool _bIsColliding = false;

	list<Vector2D> _prevPoses;
	float _recordTimer = 0.f;
	float _inputTimer = 0.f;
	float _deltaTime = 0.f;
};

