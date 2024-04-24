#include "pch.h"
#include "BoxCollider.h"

BoxCollider::BoxCollider(Vector2D size) : Collider(ColliderType::Box), _size(size)
{

}
