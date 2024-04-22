#pragma once

class Object;

class Component
{
	void SetOwner(Object* owner) { _owner = owner; }
	Object* GetOwner() { return _owner; }
private:
	Object* _owner = nullptr;
};

