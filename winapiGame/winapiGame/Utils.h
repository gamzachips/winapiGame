#pragma once
#include <windows.h>
#include <string>
using namespace std;

class Utils
{
public:

	static void DrawTextWithFontSize(HDC hdc, POINT pos, const WCHAR* str, int fontSize);
	static void DrawRect(HDC hdc, Vector2D pos, int width, int height);
	static void DrawCircle(HDC hdc, Vector2D pos, int radius);

	static void DrawRectWithColor(HDC hdc, Vector2D pos, int width, int height, COLORREF color);
	static void DrawCircleWithColor(HDC hdc, Vector2D pos, int radius, COLORREF color);
	static void DrawLine(HDC hdc, Vector2D from, Vector2D to);
};

