#include "pch.h"
#include "Ball.h"
#include "InputManager.h"

Ball::Ball()
{

}

Ball::~Ball()
{
}

void Ball::Init()
{

}

void Ball::Update()
{
	Move();
	Jump();
	ApplyGravity();
}

void Ball::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 5);
}

void Ball::Jump()
{
	if(InputManager::GetInstance()->GetButtonDown(KeyType::Space))
		_velocity.y = -_jumpSpeed;
}

void Ball::Move()
{
	_pos += (_velocity * TimeManager::GetInstance()->GetDeltaTime());

	if (InputManager::GetInstance()->GetButtonPressed(KeyType::Left))
	{
		_pos.x -= _moveSpeed * TimeManager::GetInstance()->GetDeltaTime();
	}
	if (InputManager::GetInstance()->GetButtonPressed(KeyType::Right))
	{
		_pos.x += _moveSpeed * TimeManager::GetInstance()->GetDeltaTime();
	}
}

void Ball::ApplyGravity()
{
	_velocity.y += _gravity;
}



