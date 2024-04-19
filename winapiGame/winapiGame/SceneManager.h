#pragma once

class Scene;

class SceneManager
{
private:
	SceneManager() = default;

public:
	static SceneManager* GetInstance()
	{
		static SceneManager _instance;
		return &_instance;
	}
public:
	void Init();
	void Update();
	void Render(HDC hdc);

public:
	void ChangeScene(SceneType sceneType);
private:
	Scene* _scene = nullptr;
	SceneType _sceneType = SceneType::None;
};

