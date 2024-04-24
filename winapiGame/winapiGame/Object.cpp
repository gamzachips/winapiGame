#include "pch.h"
#include "Object.h"

Object::Object()
{
}

Object::~Object()
{
	if (_collider)
	{
		delete _collider;
		_collider = nullptr;
	}
}
