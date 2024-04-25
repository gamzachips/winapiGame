#include "pch.h"
#include "Utils.h"

void Utils::DrawText(HDC hdc, Vector2D pos, const wstring& str)
{
	::TextOut(hdc, static_cast<int32>(pos.x), static_cast<int32>(pos.y), str.c_str(), static_cast<int32>(str.size()));
}

void Utils::DrawRect(HDC hdc, Vector2D pos, int width, int height)
{
    ::Rectangle(hdc, pos.x - width / 2, pos.y - width / 2, pos.x + width / 2, pos.y + height / 2);
}

void Utils::DrawCircle(HDC hdc, Vector2D pos, int radius)
{
    ::Ellipse(hdc, pos.x - radius, pos.y - radius, pos.x + radius, pos.y + radius);
}

void Utils::DrawRectWithColor(HDC hdc, Vector2D pos, int width, int height, COLORREF color)
{
    HPEN hPen = ::CreatePen(PS_SOLID, 1, color);
    HPEN hOldPen = (HPEN)::SelectObject(hdc, hPen);
    HBRUSH hBrush = ::CreateSolidBrush(color);
    HBRUSH hOldBrush = (HBRUSH)::SelectObject(hdc, hBrush);

   ::Rectangle(hdc, pos.x - width / 2, pos.y - width / 2, pos.x + width / 2, pos.y + height / 2);

    ::SelectObject(hdc, hOldPen);
    ::SelectObject(hdc, hOldBrush);

    ::DeleteObject(hPen);
    ::DeleteObject(hBrush);
}

void Utils::DrawCircleWithColor(HDC hdc, Vector2D pos, int radius, COLORREF color)
{
    HPEN hPen = ::CreatePen(PS_SOLID, 1, color);
    HPEN hOldPen = (HPEN)::SelectObject(hdc, hPen);
    HBRUSH hBrush = ::CreateSolidBrush(color);
    HBRUSH hOldBrush = (HBRUSH)::SelectObject(hdc, hBrush);

    ::Ellipse(hdc, pos.x - radius, pos.y - radius, pos.x + radius, pos.y + radius);

    ::SelectObject(hdc, hOldPen);
    ::SelectObject(hdc, hOldBrush);

    ::DeleteObject(hPen);
    ::DeleteObject(hBrush);

}

void Utils::DrawLine(HDC hdc, Vector2D from, Vector2D to)
{
	::MoveToEx(hdc, static_cast<int32>(from.x), static_cast<int32>(from.y), nullptr);
	::LineTo(hdc, static_cast<int32>(to.x), static_cast<int32>(to.y));
}
