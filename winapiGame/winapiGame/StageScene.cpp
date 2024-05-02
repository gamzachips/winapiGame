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
#include "BombBlock.h"
#include "StraightBlock.h"

StageScene::StageScene()
{
}

StageScene::~StageScene()
{
	for (List<Object*>::Iterator it = _objects.Begin(); it != _objects.End(); ++it)
	{
		delete* it;
		*it = nullptr;
	}
	_objects.Clear();
}

void StageScene::Init(HWND hwnd)
{
	
	{
		Ball* ball = new Ball;
		_objects.PushBack(ball);
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
		Texture* bombBlockT = new Texture;
		bombBlockT->LoadBmp(hwnd, L"BombBlock.bmp");
		Texture* straightBlockT = new Texture;
		straightBlockT->LoadBmp(hwnd, L"StraightBlock.bmp");

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
						_objects.PushBack(block);
						break;
					}
					case TileType::Cracked:
					{
						CrackedBlock* block = new CrackedBlock({ TILE_SIZE,TILE_SIZE });
						Vector2D pos = { x * TILE_SIZE + TILE_SIZE / 2, y * TILE_SIZE + TILE_SIZE / 2 };
						block->SetPos(pos);
						block->SetTexture(crackedBlockT);
						_objects.PushBack(block);
						break;
					}
					case TileType::Bomb:
					{
						BombBlock* block = new BombBlock({ TILE_SIZE,TILE_SIZE });
						Vector2D pos = { x * TILE_SIZE + TILE_SIZE / 2, y * TILE_SIZE + TILE_SIZE / 2 };
						block->SetPos(pos);
						block->SetTexture(bombBlockT);
						_objects.PushBack(block);
						break;
					}
					case TileType::StraightLeft:
					case TileType::StraightRight:
					{
						StraightBlock* block;
						if(tiles[y][x].type == TileType::StraightLeft)
							block = new StraightBlock({ TILE_SIZE,TILE_SIZE }, true);
						else
							block = new StraightBlock({ TILE_SIZE,TILE_SIZE }, false);
						Vector2D pos = { x * TILE_SIZE + TILE_SIZE / 2, y * TILE_SIZE + TILE_SIZE / 2 };
						block->SetPos(pos);
						block->SetTexture(straightBlockT);
						_objects.PushBack(block);
						break;
					}
				}
			}
		}
	}
}

void StageScene::Update()
{
	for (List<Object*>::Iterator it = _objects.Begin(); it != _objects.End(); ++it)
	{
		(*it)->Update();
	}

}

void StageScene::Render(HDC hdc)
{
	for (List<Object*>::Iterator it = _objects.Begin(); it != _objects.End(); ++it)
	{
		(*it)->Render(hdc);
	}
}
