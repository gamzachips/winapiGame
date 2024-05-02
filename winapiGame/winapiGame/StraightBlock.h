#pragma once
#include "Block.h"

class StraightBlock :public Block
{
public:
	StraightBlock(Vector2D size, bool left);
	virtual ~StraightBlock();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	virtual void OnCollisionEnterAbove(Collider* collider) override;
	virtual void OnCollisionEnterLeft(Collider* collider) override;
	virtual void OnCollisionEnterRight(Collider* collider) override;
	virtual void OnCollisionEnterBelow(Collider* collider) override;

	bool GetIsLeft() { return _left; }
	void SetIsLeft(bool left) { _left = left; }

private:
	bool _left = false;
};

