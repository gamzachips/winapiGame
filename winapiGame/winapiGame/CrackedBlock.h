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

	virtual void OnCollisionEnterAbove() override;
	virtual void OnCollisionEnterLeft() override;
	virtual void OnCollisionEnterRight() override;
	virtual void OnCollisionEnterBelow() override;
};

