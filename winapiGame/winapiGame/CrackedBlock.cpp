#include "pch.h"
#include "CrackedBlock.h"
#include "Collider.h"
#include "SceneManager.h"
#include "Scene.h"
#include "CollisionManager.h"
#include "BoxCollider.h"

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
	Utils::DrawRect(hdc, { (float)_pos.x , (float)_pos.y }, TILE_SIZE, TILE_SIZE);
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
