#include "pch.h"
#include "NormalBlock.h"

NormalBlock::NormalBlock(Vector2D size) : Block(size)
{
}

NormalBlock::~NormalBlock()
{
}

void NormalBlock::Init()
{
}

void NormalBlock::Update()
{
}

void NormalBlock::Render(HDC hdc)
{
	Utils::DrawRect(hdc, { (float)_pos.x , (float)_pos.y }, TILE_SIZE, TILE_SIZE);
	Utils::DrawRect(hdc, { (float)_pos.x+ 1, (float)_pos.y + 1 }, TILE_SIZE - 25, TILE_SIZE - 25);
}

