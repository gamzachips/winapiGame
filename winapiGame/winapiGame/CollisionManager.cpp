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
	for (list<BoxCollider*>::iterator it = _boxColliders.begin(); it != _boxColliders.end(); it++)
	{
		Block* block = static_cast<Block*>((*it)->GetOwner());

		if(!ball->IsColliding() && Collider::CheckCollisionSphereAboveBox(_ballCollider, *it))
		{
			_ballCollider->GetOwner()->OnCollisionEnterBelow(*it);
			block->OnCollisionEnterAbove(_ballCollider);
			isBallColliding = true;
		}
		if (!ball->IsColliding() && Collider::CheckCollisionSphereBelowBox(_ballCollider, *it))
		{
			_ballCollider->GetOwner()->OnCollisionEnterAbove(*it);
			block->OnCollisionEnterBelow(_ballCollider);
			isBallColliding = true;
		}
		if (!ball->IsColliding() && Collider::CheckCollisionSphereLeftBox(_ballCollider, *it))
		{
			_ballCollider->GetOwner()->OnCollisionEnterRight(*it);
			block->OnCollisionEnterLeft(_ballCollider);
			isBallColliding = true;
		}
		if (!ball->IsColliding() && Collider::CheckCollisionSphereRightBox(_ballCollider, *it))
		{
			_ballCollider->GetOwner()->OnCollisionEnterLeft(*it);
			block->OnCollisionEnterRight(_ballCollider);
			isBallColliding = true;
		}
	}
	if (isBallColliding == false)
		ball->SetColliding(false);
}

void CollisionManager::CreateBlockCollider(BoxCollider* collider)
{
	_boxColliders.push_back(collider);
}

void CollisionManager::RemoveBlockCollider(BoxCollider* collider)
{
	list<BoxCollider*>::iterator it = remove(_boxColliders.begin(), _boxColliders.end(), collider);
	_boxColliders.erase(it, _boxColliders.end());
}

void CollisionManager::ResetColliders()
{
	_ballCollider = nullptr;

	_boxColliders.clear();
}

