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

	Vector2DInt GetMapSize() { return _mapSize; }
	int32 GetTileSize() { return _tileSize; }
	Tile* GetTileAt(Vector2DInt pos);
	vector<vector<Tile>>& GetTiles() { return _tiles; }

	void SetMapSize(Vector2DInt size);

private:
	Vector2DInt _mapSize = {};
	int32 _tileSize = 48;
	vector<vector<Tile>> _tiles;
};

