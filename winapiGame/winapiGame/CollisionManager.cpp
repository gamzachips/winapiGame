#include "pch.h"
#include "CollisionManager.h"
#include "BoxCollider.h"
#include "SphereCollider.h"
#include "Ball.h"
#include "Block.h"

void CollisionManager::Init()
{
}

void CollisionManager::Update()
{
	if (_ballCollider == nullptr)
		return;

	Ball* ball = static_cast<Ball*>(_ballCollider->GetOwner());
	bool isBallColliding = false;
	for (List<BoxCollider*>::Iterator it = _boxColliders.Begin(); it != _boxColliders.End(); ++it)
	{
		Block* block = static_cast<Block*>((*it)->GetOwner());

		if (!ball->IsColliding() && Collider::CheckCollisionSphereLeftBox(_ballCollider, *it))
		{
			ball->OnCollisionEnterRight(*it);
			block->OnCollisionEnterLeft(_ballCollider);
			isBallColliding = true;
		}
		if (!ball->IsColliding() && Collider::CheckCollisionSphereRightBox(_ballCollider, *it))
		{
			ball->OnCollisionEnterLeft(*it);
			block->OnCollisionEnterRight(_ballCollider);
			isBallColliding = true;
		}
		if(!ball->IsColliding() && Collider::CheckCollisionSphereAboveBox(_ballCollider, *it))
		{
			ball->OnCollisionEnterBelow(*it);
			block->OnCollisionEnterAbove(_ballCollider);
			isBallColliding = true;
		}
		 if (!ball->IsColliding() && Collider::CheckCollisionSphereBelowBox(_ballCollider, *it))
		{
			ball->OnCollisionEnterAbove(*it);
			block->OnCollisionEnterBelow(_ballCollider);
			isBallColliding = true;
		}
		
	}
	if (isBallColliding == false)
	{
		ball->SetColliding(false);
	}
		
}

void CollisionManager::CreateBlockCollider(BoxCollider* collider)
{
	_boxColliders.PushBack(collider);
}

void CollisionManager::RemoveBlockCollider(BoxCollider* collider)
{
	for (List<BoxCollider*>::Iterator it = _boxColliders.Begin(); it != _boxColliders.End(); ++it)
	{
		if (*it == collider)
		{
			_boxColliders.Erase(it);
			break;
		}
	}
}

void CollisionManager::ResetColliders()
{
	_ballCollider = nullptr;

	_boxColliders.Clear();
}

