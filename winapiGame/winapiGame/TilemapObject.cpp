#include "pch.h"
#include "TilemapObject.h"
#include "Tilemap.h"
#include "InputManager.h"
#include "SceneManager.h"


TilemapObject::TilemapObject()
{
}

TilemapObject::~TilemapObject()
{
	if (_tilemap)
	{
		delete _tilemap;
		_tilemap = nullptr;
	}
		
}

void TilemapObject::Init()
{
}

void TilemapObject::Update()
{
	if(SceneManager::GetInstance()->GetSceneType() == SceneType::EditScene)
		TickPicking();
}

void TilemapObject::Render(HDC hdc)
{
	if (_tilemap == nullptr)
		return;

	Tile(*tiles)[TILEMAP_SIZEX] = _tilemap->GetTiles();
	
	for (int y = 0; y < GWinSizeY / TILE_SIZE; y++)
	{
		for (int x = 0; x < GWinSizeX / TILE_SIZE; x++)
		{
			if (y < 0 || y >= TILEMAP_SIZEY)
				continue;
			if (x < 0 || x >= TILEMAP_SIZEX)
				continue;

			switch (tiles[y][x].type)
			{
			case TileType::None:
				break;
			case TileType::Wall:
				Utils::DrawRect(hdc, { (float)x * TILE_SIZE, (float)y * TILE_SIZE }, TILE_SIZE, TILE_SIZE);
				Utils::DrawRect(hdc, { (float)x * TILE_SIZE + 1, (float)y * TILE_SIZE + 1 }, TILE_SIZE -25, TILE_SIZE - 25);
				break;
			case TileType::Cracked:
				Utils::DrawRect(hdc, { (float)x * TILE_SIZE, (float)y * TILE_SIZE }, TILE_SIZE, TILE_SIZE);
			default:
				break;
			}
		}
	}
}


void TilemapObject::TickPicking()
{
	if (InputManager::GetInstance()->GetButtonDown(KeyType::LeftMouse))
	{
		POINT mousePos = InputManager::GetInstance()->GetMousePos();
		int32 mouseX = (mousePos.x + TILE_SIZE / 2) / TILE_SIZE;
		int32 mouseY = (mousePos.y + TILE_SIZE / 2) / TILE_SIZE;

		Tile* tile = _tilemap->GetTileAt({ mouseX, mouseY });
		if (tile)
		{
			tile->type = (TileType)(((int)(tile->type) + 1) % (int)(TileType::Count));
		}
	}
}
