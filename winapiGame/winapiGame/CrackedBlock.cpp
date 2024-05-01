#include "pch.h"
#include "CrackedBlock.h"
#include "Collider.h"
#include "SceneManager.h"
#include "Scene.h"
#include "CollisionManager.h"
#include "BoxCollider.h"
#include "Texture.h"

CrackedBlock::CrackedBlock(Vector2D size) : Block(size)
{
}

CrackedBlock::~CrackedBlock()
{
}

void CrackedBlock::Init()
{
}

void CrackedBlock::Update()
{
}

void CrackedBlock::Render(HDC hdc)
{
	//Utils::DrawRect(hdc, { (float)_pos.x , (float)_pos.y }, TILE_SIZE, TILE_SIZE);
	::StretchBlt(hdc, _pos.x - TILE_SIZE / 2, _pos.y - TILE_SIZE / 2, TILE_SIZE + 14, TILE_SIZE + 14, _texture->GetDC(),
		0, 0, 42, 42, SRCCOPY);
}

void CrackedBlock::OnCollisionEnterAbove(Collider* collider)
{
	Scene* scene = SceneManager::GetInstance()->GetScene();
	CollisionManager::GetInstance()->RemoveBlockCollider(static_cast<BoxCollider*>(_collider));
	scene->DestroyObject(this);
}

void CrackedBlock::OnCollisionEnterLeft(Collider* collider)
{
}

void CrackedBlock::OnCollisionEnterRight(Collider* collider)
{
}

void CrackedBlock::OnCollisionEnterBelow(Collider* collider)
{
}
