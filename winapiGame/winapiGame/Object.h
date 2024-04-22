#pragma once
class Object
{
public:
	Object();
	virtual ~Object();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

protected:
	Vector2D _pos = {};
};

