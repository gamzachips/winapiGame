#include "pch.h"
#include "CrackedBlock.h"
#include "Collider.h"
#include "SceneManager.h"
#include "Scene.h"

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

void CrackedBlock::OnCollisionEnterAbove()
{
	Scene* scene = SceneManager::GetInstance()->GetScene();
	scene->DestroyObject(this);
}

void CrackedBlock::OnCollisionEnterLeft()
{
}

void CrackedBlock::OnCollisionEnterRight()
{
}

void CrackedBlock::OnCollisionEnterBelow()
{
}
