#include "pch.h"
#include "StageScene.h"
#include "Ball.h"
#include "TilemapObject.h"
#include "ResourceManager.h"
#include "Tilemap.h"
#include "Block.h"
#include "NormalBlock.h"
#include "CrackedBlock.h"
#include "SceneManager.h"
#include "Texture.h"

StageScene::StageScene()
{
}

StageScene::~StageScene()
{
	for (list<Object*>::iterator it = _objects.begin(); it != _objects.end(); it++)
	{
		delete* it;
		*it = nullptr;
	}
	_objects.clear();
}

void StageScene::Init(HWND hwnd)
{
	
	{
		Ball* ball = new Ball;
		_objects.push_back(ball);
	}

	{
		//Craete Tilemap
		TilemapObject* tilemapObject = new TilemapObject();
		Tilemap* tilemap = new Tilemap();
		tilemap->LoadTilemap("Tilemap", SceneManager::GetInstance()->GetStageNum());
		tilemapObject->SetTilemap(tilemap);

		Texture* normalBlockT = new Texture;
		normalBlockT->LoadBmp(hwnd, L"NormalBlock.bmp");
		Texture* crackedBlockT = new Texture;
		crackedBlockT->LoadBmp(hwnd, L"CrackedBlock.bmp");

		//Create Blocks
		Tile (*tiles)[TILEMAP_SIZEX] = tilemapObject->GetTilemap()->GetTiles();
		for (int y = 0; y < TILEMAP_SIZEY; y++)
		{
			for (int x = 0; x < TILEMAP_SIZEX; x++)
			{
				switch (tiles[y][x].type)
				{
					case TileType::Normal:
					{
						NormalBlock* block = new NormalBlock({ TILE_SIZE,TILE_SIZE });
						Vector2D pos = {x * TILE_SIZE + TILE_SIZE/2, y * TILE_SIZE + TILE_SIZE / 2 };
						block->SetPos(pos);
						block->SetTexture(normalBlockT); 
						_objects.push_back(block);
						break;
					}
					case TileType::Cracked:
					{
						CrackedBlock* block = new CrackedBlock({ TILE_SIZE,TILE_SIZE });
						Vector2D pos = { x * TILE_SIZE + TILE_SIZE / 2, y * TILE_SIZE + TILE_SIZE / 2 };
						block->SetPos(pos);
						block->SetTexture(crackedBlockT);
						_objects.push_back(block);
						break;
					}
				}
			}
		}
	}
}

void StageScene::Update()
{
	for (list<Object*>::iterator it = _objects.begin(); it != _objects.end(); it++)
	{
		(*it)->Update();
	}

}

void StageScene::Render(HDC hdc)
{
	for (list<Object*>::iterator it = _objects.begin(); it != _objects.end(); it++)
	{
		(*it)->Render(hdc);
	}
}
