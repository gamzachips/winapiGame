#pragma once
#include "Collider.h"

class BoxCollider : public Collider
{
public:
	BoxCollider(Vector2D size);

	Vector2D GetSize() { return _size; }
private:
	Vector2D _size;
};

