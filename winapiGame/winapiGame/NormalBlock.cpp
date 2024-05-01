#include "pch.h"
#include "NormalBlock.h"
#include "Texture.h"


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
	//Utils::DrawRect(hdc, { (float)_pos.x , (float)_pos.y }, TILE_SIZE, TILE_SIZE);
	//Utils::DrawRect(hdc, { (float)_pos.x+ 1, (float)_pos.y + 1 }, TILE_SIZE - 25, TILE_SIZE - 25);

	::StretchBlt(hdc, _pos.x - TILE_SIZE/2, _pos.y - TILE_SIZE / 2, TILE_SIZE+14, TILE_SIZE+14, _texture->GetDC(),
		0, 0, 42, 42, SRCCOPY);
}

