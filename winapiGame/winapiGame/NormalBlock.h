#pragma once
#include "Block.h"
class NormalBlock : public Block
{
public:
	NormalBlock(Vector2D size);
	virtual ~NormalBlock();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	virtual void OnCollisionEnterAbove(Collider* collider) override {};
	virtual void OnCollisionEnterLeft(Collider* collider) override {};
	virtual void OnCollisionEnterRight(Collider* collider) override {};
	virtual void OnCollisionEnterBelow(Collider* collider) override {};
};

