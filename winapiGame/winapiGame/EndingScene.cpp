#include "pch.h"
#include "EndingScene.h"
#include "SceneManager.h"

EndingScene::EndingScene()
{
}

EndingScene::~EndingScene()
{
}

void EndingScene::Init(HWND hwnd)
{
}

void EndingScene::Update()
{
	Scene::Update();
}

void EndingScene::Render(HDC hdc)
{
	WCHAR buffer[30];
	swprintf_s(buffer, 30, L"CLEAR");
	Utils::DrawTextWithFontSize(hdc, { 700, 400 }, buffer, 100);

	swprintf_s(buffer, 30, L"½ÃµµÈ½¼ö: %dÈ¸", SceneManager::GetInstance()->GetTrialNum());
	Utils::DrawTextWithFontSize(hdc, { 800, 600}, buffer, 30);

}
