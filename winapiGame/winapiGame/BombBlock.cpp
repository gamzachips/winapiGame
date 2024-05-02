#include "pch.h"
#include "BombBlock.h"
#include "Texture.h"
#include "SceneManager.h"
#include "Collider.h"

BombBlock::BombBlock(Vector2D size) : Block(size, TileType::Bomb)
{
}

BombBlock::~BombBlock()
{
}

void BombBlock::Init()
{
}

void BombBlock::Update()
{
}

void BombBlock::Render(HDC hdc)
{
	::StretchBlt(hdc, _pos.x - TILE_SIZE / 2, _pos.y - TILE_SIZE / 2, TILE_SIZE + 14, TILE_SIZE + 14, _texture->GetDC(),
		0, 0, 42, 42, SRCCOPY);
}

void BombBlock::OnCollisionEnterAbove(Collider* collider)
{
	SceneManager::GetInstance()->EndScene();
	SceneManager::GetInstance()->IncreaseTrialNum();
}

void BombBlock::OnCollisionEnterLeft(Collider* collider)
{
}

void BombBlock::OnCollisionEnterRight(Collider* collider)
{
}

void BombBlock::OnCollisionEnterBelow(Collider* collider)
{
}
