#include "pch.h"
#include "InputManager.h"

void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;
}

void InputManager::Update()
{
	BYTE asciiKeys[KEY_TYPE_COUNT] = {};
	if (::GetKeyboardState(asciiKeys) == false)
		return;

	for (uint32 key = 0; key < KEY_TYPE_COUNT; key++)
	{
		if (asciiKeys[key] & 0x80)
		{
			KeyState& state = _states[key];

			if (state == KeyState::Pressed || state == KeyState::Down)
				state = KeyState::Pressed;
			else
				state = KeyState::Down;
		}
		else
		{
			KeyState& state = _states[key];
			if (state == KeyState::Pressed || state == KeyState::Down)
				state = KeyState::Up;
			else
				state = KeyState::None;
		}
	}
	::GetCursorPos(&_mousePos);
	::ScreenToClient(_hwnd, &_mousePos);
}