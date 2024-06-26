#pragma once

class Collider;
class Texture;

class Object
{
public:
	Object();
	virtual ~Object();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

	Vector2D GetPos() { return _pos; }
	void SetPos(Vector2D pos) { _pos = pos; }
	void SetTexture(Texture* texture) { _texture = texture; }
	Texture* GetTexture() { return _texture; }

	virtual void OnCollisionEnterAbove(Collider* collider) {};
	virtual void OnCollisionEnterLeft(Collider* collider) {};
	virtual void OnCollisionEnterRight(Collider* collider) {};
	virtual void OnCollisionEnterBelow(Collider* collider) {};

protected:
	Vector2D _pos = {};
	Collider* _collider = nullptr;
	Texture* _texture = nullptr;
};

