#pragma once
#include "Collider.h"

class SphereCollider : public Collider
{
public:
	SphereCollider(int radius);

	int32 GetRadius() { return _radius; }
private:
	int32 _radius;
};

