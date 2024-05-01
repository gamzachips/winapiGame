#pragma once

class Texture
{
public:
	Texture();
	~Texture();

	Texture* LoadBmp(HWND hwnd, const WCHAR* path);
	HDC GetDC();
	void SetSize(Vector2DInt size) { _size = size; }
	Vector2DInt GetSize() { return _size; }

private:
	HDC _hdc = {};
	HBITMAP _bitmap = {};
	Vector2DInt _size = {};
};

