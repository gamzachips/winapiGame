#pragma once


struct Tile
{
	TileType type = TileType::None;
};

class Tilemap
{
public:
	Tilemap();
	~Tilemap();

	Tile* GetTileAt(Vector2DInt pos);
	Tile(*GetTiles())[TILEMAP_SIZEX] {	return _tiles;	}
	void SaveTilemap(const char* fileName, int stage);
	void LoadTilemap(const char* fileName, int stage);

private:
	Tile _tiles[TILEMAP_SIZEY][TILEMAP_SIZEX] = {};
};

