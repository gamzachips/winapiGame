#pragma once

enum class ColliderType
{
	Box,
	Sphere
};

class Collider
{
public:
	Collider(ColliderType type);

	ColliderType GetColliderType() { return _type; }
private:
	ColliderType _type;
};

