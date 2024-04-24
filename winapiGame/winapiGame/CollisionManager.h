#pragma once

class SphereCollider;
class BoxCollider;

class CollisionManager
{
private:
	CollisionManager() = default;

public:
	static CollisionManager* GetInstance()
	{
		static CollisionManager _instance;
		return &_instance;
	}

	void Init();
	void Update();

	void SetBallCollider(SphereCollider* collider) { _ballCollider = collider; }
	void CreateBlockCollider(BoxCollider* collider);
	void RemoveBlockCollider(BoxCollider* collider);

private:
	SphereCollider* _ballCollider;
	list<BoxCollider*> _boxColliders;
};
