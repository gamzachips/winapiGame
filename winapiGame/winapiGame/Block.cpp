#include "pch.h"
#include "Block.h"
#include "BoxCollider.h"

Block::Block(Vector2D size) : _size(size)
{
	_collider = new BoxCollider(_size);
	_collider->SetActive(true);
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
