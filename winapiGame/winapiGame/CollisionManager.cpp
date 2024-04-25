#include "pch.h"
#include "CollisionManager.h"
#include "BoxCollider.h"
#include "SphereCollider.h"
#include "Ball.h"

void CollisionManager::Init()
{
}

void CollisionManager::Update()
{
	if (_ballCollider == nullptr)
		return;
	for (list<BoxCollider*>::iterator it = _boxColliders.begin(); it != _boxColliders.end(); it++)
	{
		if(Collider::CheckCollisionSphereAboveBox(_ballCollider, *it))
		{
			_ballCollider->GetOwner()->OnCollisionEnterBelow();
			(*it)->GetOwner()->OnCollisionEnterAbove();
		}
		else if (Collider::CheckCollisionSphereBelowBox(_ballCollider, *it))
		{
			_ballCollider->GetOwner()->OnCollisionEnterAbove();
			(*it)->GetOwner()->OnCollisionEnterBelow();
		}
		else if (Collider::CheckCollisionSphereLeftBox(_ballCollider, *it))
		{
			_ballCollider->GetOwner()->OnCollisionEnterRight();
			(*it)->GetOwner()->OnCollisionEnterLeft();
		}
		else if (Collider::CheckCollisionSphereRightBox(_ballCollider, *it))
		{
			_ballCollider->GetOwner()->OnCollisionEnterLeft();
			(*it)->GetOwner()->OnCollisionEnterRight();
		}
	}
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

