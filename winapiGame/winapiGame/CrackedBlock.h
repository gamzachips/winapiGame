#pragma once
#include "Block.h"

class CrackedBlock : public Block
{
public:
	CrackedBlock(Vector2D size);
	virtual ~CrackedBlock();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	virtual void OnCollisionEnterAbove(Collider* collider) override;
	virtual void OnCollisionEnterLeft(Collider* collider) override;
	virtual void OnCollisionEnterRight(Collider* collider) override;
	virtual void OnCollisionEnterBelow(Collider* collider) override;
};

