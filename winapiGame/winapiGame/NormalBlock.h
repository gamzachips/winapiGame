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

	virtual void OnCollisionEnterAbove() override;
	virtual void OnCollisionEnterLeft() override;
	virtual void OnCollisionEnterRight() override;
	virtual void OnCollisionEnterBelow() override;
};

