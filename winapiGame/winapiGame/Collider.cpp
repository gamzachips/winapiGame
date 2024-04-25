#include "pch.h"
#include "Collider.h"
#include "Object.h"
#include "SphereCollider.h"
#include "BoxCollider.h"
#include "Ball.h"
#include "InputManager.h"

Collider::Collider(ColliderType type) : _type(type)
{

}

Collider::~Collider()
{
	if (_owner)
	{
		delete _owner;
		_owner = nullptr;
	}
}


bool Collider::CheckCollisionSphereAboveBox(SphereCollider* sphere, BoxCollider* box)
{
	Vector2D sPos = sphere->GetOwner()->GetPos();
	int32 sRadius = sphere->GetRadius();
	Vector2D bPos = box->GetOwner()->GetPos();
	Vector2D bSize = box->GetSize();

	//y���� üũ 
	if (sPos.y + sRadius > bPos.y - bSize.y / 2  && sPos.y < bPos.y - bSize.y / 2 )
	{
		// x���� üũ
		if (sPos.x  > bPos.x - bSize.x / 2 && sPos.x < bPos.x + bSize.x / 2) 
		{
			return true;
		}
	}
	return false;
}

bool Collider::CheckCollisionSphereLeftBox(SphereCollider* sphere, BoxCollider* box)
{
	Vector2D sPos = sphere->GetOwner()->GetPos();
	int32 sRadius = sphere->GetRadius();
	Vector2D bPos = box->GetOwner()->GetPos();
	Vector2D bSize = box->GetSize();

	if (sPos.y + sRadius > bPos.y - bSize.y / 2 && sPos.y - sRadius < bPos.y + bSize.y)
	{
		if (sPos.x - sRadius > bPos.x && sPos.x + sRadius > bPos.x - bSize.x)
			return true;
	}
	return false;
}

bool Collider::CheckCollisionSphereRightBox(SphereCollider* sphere, BoxCollider* box)
{
	Vector2D sPos = sphere->GetOwner()->GetPos();
	int32 sRadius = sphere->GetRadius();
	Vector2D bPos = box->GetOwner()->GetPos();
	Vector2D bSize = box->GetSize();

	if (sPos.y - sRadius > bPos.y - bSize.y / 2 && sPos.y + sRadius < bPos.y + bSize.y / 2)
	{
		if (sPos.x - sRadius < bPos.x + bSize.x / 2 && sPos.x > bPos.x + bSize.x / 2)
			return true;
	}
	return false;
}

bool Collider::CheckCollisionSphereBelowBox(SphereCollider* sphere, BoxCollider* box)
{
	Vector2D sPos = sphere->GetOwner()->GetPos();
	int32 sRadius = sphere->GetRadius();
	Vector2D bPos = box->GetOwner()->GetPos();
	Vector2D bSize = box->GetSize();
	
	//y���� üũ 
	if (sPos.y - sRadius > bPos.y && sPos.y - sRadius < bPos.y + bSize.y / 2)
	{
		// x���� üũ
		if (sPos.x + sRadius > bPos.x - bSize.x / 2 && sPos.x - sRadius < bPos.x + bSize.x / 2)
		{
			return true;
		}
	}
	return false;
}

bool Collider::CheckCollisionLayer(Collider* other)
{
	if (_bActive == false || other->IsActive() == false)
		return false;
	CollisionLayer otherLayer = other->GetCollisionLayer();
	if (_collisionFlag & (1 << (int)otherLayer))
		return true;
	return false;
}

void Collider::AddCollisionFlg(CollisionLayer layer)
{
	_collisionFlag |= (1 << (int)layer);
}

void Collider::RemoveCollisionFlag(CollisionLayer layer)
{
	_collisionFlag &= ~(1 << (int)layer);
}

