#pragma once

class Collider;

class Object
{
public:
	Object();
	virtual ~Object();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

	Vector2D GetPos() { return _pos; }

protected:
	Vector2D _pos = {};
	Collider* _collider = nullptr;
};

