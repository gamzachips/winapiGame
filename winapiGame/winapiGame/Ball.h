#pragma once

//Player
class Ball
{
public:
	Ball();
	~Ball();

	void Init();
	void Update();
	void Render(HDC hdc);

	void Jump();
	void Move();
	void ApplyGravity();

	Vector2D GetPos() { return _pos; }

private:
	Vector2D _pos = {100, 100};
	Vector2D _velocity = {};
	int32 _radius = 5;
	int32 _moveSpeed = 80;
	int32 _jumpSpeed = 500;
	int32 _gravity = 10;
};

