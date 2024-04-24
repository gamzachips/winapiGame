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
	for (list<BoxCollider*>::iterator it = _boxColliders.begin(); it != _boxColliders.end(); it++)
	{
		if(Collider::CheckCollisionSphereAboveBox(_ballCollider, *it))
		{
			dynamic_cast<Ball*>(_ballCollider->GetOwner())->OnCollisionEnterAboveBlock();
		}
		else if (Collider::CheckCollisionSphereBelowBox(_ballCollider, *it))
		{

		}
		else if (Collider::CheckCollisionSphereBesideBox(_ballCollider, *it))
		{

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

