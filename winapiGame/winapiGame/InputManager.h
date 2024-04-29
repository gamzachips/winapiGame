#pragma once

enum class KeyType
{
	Up = VK_UP,
	Down = VK_DOWN,
	Left = VK_LEFT,
	Right = VK_RIGHT,
	Space = VK_SPACE,
	LeftMouse = VK_LBUTTON,
	T = 'T',
	N = 'N'
};

enum class KeyState
{
	None,
	Pressed,
	Down,
	Up,
	End
};

const int KEY_TYPE_COUNT = static_cast<int32>(UINT8_MAX) + 1;
const int KEY_STATE_COUNT = static_cast<int32>(KeyState::End);

class InputManager
{
private:
	InputManager() = default;

public:
	static InputManager* GetInstance()
	{
		static InputManager _instance;
		return &_instance;
	}
public:
	void Init(HWND hwnd);
	void Update();

	bool GetButtonPressed(KeyType type) { return GetState(type) == KeyState::Pressed; }
	bool GetButtonDown(KeyType type) { return GetState(type) == KeyState::Down; }
	bool GetButtonUp(KeyType type) { return GetState(type) == KeyState::Up; }
	POINT GetMousePos() { return _mousePos; }

private:
	KeyState GetState(KeyType key) { return _states[static_cast<uint8>(key)]; }
private:
	HWND _hwnd = 0;
	KeyState _states[KEY_TYPE_COUNT];
	POINT _mousePos{};
};

