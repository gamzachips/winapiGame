#include "Game.h"
#include "pch.h"
#include "Game.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"

Game::Game()
{
}

Game::~Game()
{

	::_CrtDumpMemoryLeaks();
}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_hdc = ::GetDC(hwnd);
	::GetClientRect(hwnd, &_rect);

	//Double Buffering
	_hdcBack = ::CreateCompatibleDC(_hdc); //_hdc와 호환되는 DC를 생성
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom); //_hdc와 호환되는 비트맵 생성
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack); //DC와 BMP를 연결
	::DeleteObject(prev); //이전 BMP 제거 

	//Managers Init
	TimeManager::GetInstance()->Init();
	InputManager::GetInstance()->Init(hwnd);
	SceneManager::GetInstance()->Init();

	SceneManager::GetInstance()->ChangeScene(SceneType::StageScene);
}

void Game::Update()
{
	TimeManager::GetInstance()->Update();
	InputManager::GetInstance()->Update();
	SceneManager::GetInstance()->Update();
}

void Game::Render()
{
	uint32 fps = TimeManager::GetInstance()->GetFps();
	float deltaTime = TimeManager::GetInstance()->GetDeltaTime();
	WCHAR buffer[100];
	int bIdx = 0;
	bIdx = swprintf(buffer, 100, L"fps: %d   ", fps);
	bIdx += swprintf(buffer + bIdx, 100, L"DT: %d", static_cast<int>(deltaTime * 1000));
	::TextOut(_hdcBack, 1300, 10, buffer, bIdx);

	SceneManager::GetInstance()->Render(_hdcBack);

	//Double Buffering
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY); //_hdcBack을 _hdc에 복사
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
}
