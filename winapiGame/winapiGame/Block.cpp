#include "pch.h"
#include "Block.h"
#include "BoxCollider.h"
#include "CollisionManager.h"

Block::Block(Vector2D size) : _size(size)
{
	BoxCollider* collider = new BoxCollider(_size);
	collider->SetActive(true);
	collider->ResetCollisionFlag();
	collider->SetOwner(this);
	collider->AddCollisionFlg(CollisionLayer::Ball);
	CollisionManager::GetInstance()->CreateBlockCollider(collider);
	_collider = dynamic_cast<Collider*>(collider);
}

Block::~Block()
{
}

void Block::Init()
{
}

void Block::Update()
{
}

void Block::Render(HDC hdc)
{
}

void Block::OnCollisionEnterAbove()
{
}

void Block::OnCollisionEnterLeft()
{
}

void Block::OnCollisionEnterRight()
{
}


void Block::OnCollisionEnterBelow()
{
}
