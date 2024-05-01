#include "pch.h"
#include "Ball.h"
#include "InputManager.h"
#include "SphereCollider.h"
#include "CollisionManager.h"
#include "Collider.h"
#include "BoxCollider.h"
#include "SceneManager.h"
#include "Scene.h"
#include "StageScene.h"

Ball::Ball()
{
	_pos = { 100, 100 };

	//Create Collider
	SphereCollider* collider = new SphereCollider(_radius);
	collider->SetActive(true);
	collider->ResetCollisionFlag();
	collider->SetOwner(this);
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
	_deltaTime = TimeManager::GetInstance()->GetDeltaTime();
	_recordTimer += _deltaTime;
	_inputTimer += _deltaTime;
	Move();
	ApplyGravity();
	RecordPos();
	CheckFall();
	CheckGoal();
}

void Ball::Render(HDC hdc)
{
	for (list<Vector2D>::iterator it = _prevPoses.begin(); it != _prevPoses.end(); ++it)
	{
		Utils::DrawCircle(hdc, *it, 5);
	}

	Utils::DrawCircle(hdc, _pos, 5);
}

void Ball::Jump()
{
	_velocity.y = -_jumpSpeed;
}

void Ball::Move()
{
	_pos += (_velocity);

	if (_inputTimer > 0.08f)
	{
		_inputTimer -= 0.08f;
		if (InputManager::GetInstance()->GetButtonPressed(KeyType::Left))
		{
			_velocity.x -= _accelSpeed;
		}
		if (InputManager::GetInstance()->GetButtonPressed(KeyType::Right))
		{
			_velocity.x += _accelSpeed;
		}
	}

	if (_velocity.x > _moveMaxSpeed)
		_velocity.x = _moveMaxSpeed;
	else if (_velocity.x < -_moveMaxSpeed)
		_velocity.x = -_moveMaxSpeed;
}

void Ball::ApplyGravity()
{
	_velocity.y += _gravity;
}

void Ball::RecordPos()
{
	if (_recordTimer > 0.01f)
	{
		_recordTimer -= 0.01f;

		_prevPoses.push_back(_pos);

		if (_prevPoses.size() > 15)
			_prevPoses.pop_front();
	}
}

void Ball::CheckFall()
{
	if (_pos.y > GWinSizeY)
	{
		SceneManager::GetInstance()->EndScene();
	}
}

void Ball::CheckGoal()
{
	if (_pos.x > GWinSizeX)
	{
		SceneManager::GetInstance()->GoToNextStage();
		SceneManager::GetInstance()->EndScene();
	}
}

void Ball::OnCollisionEnterAbove(Collider* collider)
{
	_bIsColliding = true;

	BoxCollider* box = static_cast<BoxCollider*>(collider);
	if (box == nullptr) return;

	Vector2D bSize = box->GetSize();
	Vector2D bPos = box->GetOwner()->GetPos();

	_pos.y = bPos.y + bSize.y / 2 + _radius;
	_velocity.y = 0.f;

}

void Ball::OnCollisionEnterLeft(Collider* collider)
{
	_bIsColliding = true;

	_velocity.x = _moveMaxSpeed;
	_velocity.y = _gravity;

	if (InputManager::GetInstance()->GetButtonPressed(KeyType::Right))
		Jump();
}

void Ball::OnCollisionEnterRight(Collider* collider)
{
	_bIsColliding = true;

	_velocity.x = -_moveMaxSpeed;
	_velocity.y = _gravity;

	if (InputManager::GetInstance()->GetButtonPressed(KeyType::Left))
		Jump();
}

void Ball::OnCollisionEnterBelow(Collider* collider)
{
	Jump();
}




