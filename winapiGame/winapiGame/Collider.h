#pragma once


class Object;
class SphereCollider;
class BoxCollider;

class Collider
{
public:
	Collider(ColliderType type);
	~Collider();

	ColliderType GetColliderType() { return _type; }
	Object* GetOwner() { return _owner; }
	void SetOwner(Object* owner) { _owner = owner; }
	void SetActive(bool bActive) { _bActive = bActive; }
	bool IsActive() { return _bActive; }

	//CollisionTest
	static bool CheckCollisionSphereAboveBox(SphereCollider* sphere, BoxCollider* box);
	static bool CheckCollisionSphereLeftBox(SphereCollider* sphere, BoxCollider* box);
	static bool CheckCollisionSphereRightBox(SphereCollider* sphere, BoxCollider* box);
	static bool CheckCollisionSphereBelowBox(SphereCollider* sphere, BoxCollider* box);

	//CollisionFlag
	void ResetCollisionFlag() { _collisionFlag = 0; }
	void AllCollisionFlag() { _collisionFlag = 0xFFFFFFFF; }
	void AddCollisionFlg(CollisionLayer layer);
	void RemoveCollisionFlag(CollisionLayer layer);

	//CollisionLayer
	CollisionLayer GetCollisionLayer() { return _layer; }
	bool CheckCollisionLayer(Collider* other);

	bool IsCollidingWith(Collider* collider);
	void AddCollidingOne(Collider* collider);
	void EraseCollidingOne(Collider* collider);

protected:
	ColliderType _type;
	CollisionLayer _layer = CollisionLayer::Block;
	uint32 _collisionFlag = 0xFFFFFFFF; //충돌처리할 상대들
	bool _bActive = true;

	Object* _owner = nullptr;
	list<Collider*> _onColliders; //현재 충돌중인 것들
};

