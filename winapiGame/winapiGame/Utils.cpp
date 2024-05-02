#include "pch.h"
#include "Utils.h"

void Utils::DrawTextWithFontSize(HDC hdc, POINT pos, const WCHAR* str, int fontSize) {
    HFONT hFont = ::CreateFont(
        -fontSize,                      // Height of font
        0,                              // Width of font
        0,                              // Angle of escapement
        0,                              // Orientation angle
        FW_NORMAL,                      // Font weight
        FALSE,                          // Italic
        FALSE,                          // Underline
        FALSE,                          // Strikeout
        DEFAULT_CHARSET,                // Character set identifier
        OUT_DEFAULT_PRECIS,             // Output precision
        CLIP_DEFAULT_PRECIS,            // Clipping precision
        DEFAULT_QUALITY,                // Output quality
        DEFAULT_PITCH | FF_DONTCARE,    // Pitch and family
        L"Arial"                        // Font face name
    );

    if (hFont) {
        HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);
        RECT rc = { pos.x, pos.y, 0, 0 };
        SetTextColor(hdc, WHITE);
        SetBkMode(hdc, TRANSPARENT);//배경색 투영하기.
        ::DrawText(hdc, str, -1, &rc, DT_NOCLIP);
        SelectObject(hdc, hOldFont);
        DeleteObject(hFont);
    }
 
};

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
