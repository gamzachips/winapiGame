#include "pch.h"
#include "StraightBlock.h"
#include "Ball.h"
#include "Collider.h"
#include "Texture.h"

StraightBlock::StraightBlock(Vector2D size, bool left) : Block(size, TileType::StraightLeft)
{
	_left = left;
}

StraightBlock::~StraightBlock()
{
}

void StraightBlock::Init()
{
}

void StraightBlock::Update()
{
}

void StraightBlock::Render(HDC hdc)
{
	if (_left == false)
	{
		::StretchBlt(hdc, _pos.x - TILE_SIZE / 2, _pos.y - TILE_SIZE / 2, TILE_SIZE + 14, TILE_SIZE + 14, _texture->GetDC(),
			0, 0, 42, 42, SRCCOPY);
	}
	else
	{
		::StretchBlt(hdc, _pos.x + TILE_SIZE / 2 + 14, _pos.y + TILE_SIZE / 2 + 14, -(TILE_SIZE + 14), -(TILE_SIZE + 14), _texture->GetDC(),
			0, 0, 42, 42, SRCINVERT);
	}

}

void StraightBlock::OnCollisionEnterAbove(Collider* collider)
{
	Ball* ball = static_cast<Ball*>(collider->GetOwner());
	if(_left)	
		ball->SetPos({ _pos.x - TILE_SIZE, _pos.y });
	else
		ball->SetPos({ _pos.x + TILE_SIZE, _pos.y });

	ball->GoStraight(_left);
}

void StraightBlock::OnCollisionEnterLeft(Collider* collider)
{
	Ball* ball = static_cast<Ball*>(collider->GetOwner());
	if (_left)
		ball->SetPos({ _pos.x - TILE_SIZE, _pos.y });
	else
		ball->SetPos({ _pos.x + TILE_SIZE, _pos.y });

	ball->GoStraight(_left);
}

void StraightBlock::OnCollisionEnterRight(Collider* collider)
{
	Ball* ball = static_cast<Ball*>(collider->GetOwner());
	if (_left)
		ball->SetPos({ _pos.x - TILE_SIZE, _pos.y });
	else
		ball->SetPos({ _pos.x + TILE_SIZE, _pos.y });

	ball->GoStraight(_left);
}

void StraightBlock::OnCollisionEnterBelow(Collider* collider)
{
}
