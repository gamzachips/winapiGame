#include "Game.h"
#include "pch.h"
#include "Game.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CollisionManager.h"

Game::Game()
{
}

Game::~Game()
{

	//::_CrtDumpMemoryLeaks();
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
	SceneManager::GetInstance()->Init(hwnd);
	CollisionManager::GetInstance()->Init();

	SceneManager::GetInstance()->ChangeScene(SceneType::StageScene);
}

void Game::FixedUpdate()
{
	while(_fixedTimer >= 0.0035f)
	{
		InputManager::GetInstance()->Update();
		SceneManager::GetInstance()->Update();
		CollisionManager::GetInstance()->Update();
		_fixedTimer -= 0.0035f;
	}
}

void Game::Update()
{
	_fixedTimer += TimeManager::GetInstance()->GetDeltaTime();
	TimeManager::GetInstance()->Update();

}

void Game::Render()
{

	SceneManager::GetInstance()->Render(_hdcBack);

	WCHAR buffer[30];
	swprintf_s(buffer, 30, L"Stage %d", SceneManager::GetInstance()->GetStageNum());
	Utils::DrawTextWithFontSize(_hdcBack, { 1500, 30 }, buffer, 50);

	//Double Buffering
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY); //_hdcBack을 _hdc에 복사
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, BLACKNESS);
}
