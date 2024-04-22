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
	void SaveTilemap(const char* fileName);
	void LoadTilemap(const char* fileName);

private:
	Tile _tiles[TILEMAP_SIZEY][TILEMAP_SIZEX] = {};
};

