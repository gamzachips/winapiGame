#pragma once
#include "Object.h"

class Block : public Object
{
public:
	Block(Vector2D size, TileType type);
	virtual ~Block();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

	virtual void OnCollisionEnterAbove(Collider* collider) abstract;
	virtual void OnCollisionEnterLeft(Collider* collider) abstract;
	virtual void OnCollisionEnterRight(Collider* collider) abstract;
	virtual void OnCollisionEnterBelow(Collider* collider) abstract;

	TileType GetTileType() { return _type; }

protected:
	Vector2D _size = {};
	TileType _type;
};

