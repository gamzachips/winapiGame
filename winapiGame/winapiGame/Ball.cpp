#include "pch.h"
#include "Ball.h"
#include "InputManager.h"
#include "SphereCollider.h"
#include "CollisionManager.h"

Ball::Ball()
{
	_pos = { 100, 100 };
	SphereCollider* collider = new SphereCollider(_radius);
	collider->SetActive(true);
	collider->ResetCollisionFlag();
	collider->AddCollisionFlg(CollisionLayer::Block);
	CollisionManager::GetInstance()->SetBallCollider(collider);
	_collider = dynamic_cast<Collider*>(collider);
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

void Ball::OnCollisionEnterAboveBlock()
{
	Jump();
}

void Ball::OnCollisionEnterBesideBlock()
{
	//Æ¨±â±â
}


