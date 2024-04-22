#include "pch.h"
#include "Tilemap.h"
#include <fstream>
#include <iostream>

Tilemap::Tilemap()
{

}

Tilemap::~Tilemap()
{
	SaveTilemap("Tilemap0");
}

Tile* Tilemap::GetTileAt(Vector2DInt pos)
{
	if (pos.x < 0 || pos.y < 0 || pos.x >= TILEMAP_SIZEX || pos.y >= TILEMAP_SIZEY)
		return nullptr;

	return &_tiles[pos.y][pos.x];
}

void Tilemap::SaveTilemap(const char* fileName)
{
	ofstream ofs;
	char fileFullName[20];
	sprintf_s(fileFullName, 20, "%s.text", fileName);
	ofs.open(fileFullName);

	if (!ofs.is_open())
	{
		MessageBox(NULL, L"Unable to open file for writing", L"Error", MB_OK | MB_ICONERROR);
		return;
	}

	for (int y = 0; y < TILEMAP_SIZEY; y++)
	{
		for (int x = 0; x < TILEMAP_SIZEX; x++)
		{
			int typeNum = static_cast<int>(_tiles[y][x].type);
			ofs << typeNum << " ";
		}
	}

	ofs.close();
}

void Tilemap::LoadTilemap(const char* fileName)
{
	ifstream ifs;
	char fileFullName[20];
	sprintf_s(fileFullName, 20, "%s.text", fileName);
	ifs.open(fileFullName);

	if (!ifs.is_open())
	{
		MessageBox(NULL, L"Unable to open file for Reading", L"Error", MB_OK | MB_ICONERROR);
		return;
	}

	for (int y = 0; y < TILEMAP_SIZEY; y++)
	{
		for (int x = 0; x < TILEMAP_SIZEX; x++)
		{
			int typeNum;
			ifs >> typeNum;
			_tiles[y][x].type = static_cast<TileType>(typeNum);
		}
	}

	ifs.close();
}
