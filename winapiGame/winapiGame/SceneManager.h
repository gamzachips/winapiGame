#pragma once

class Scene;

class SceneManager
{
private:
	SceneManager() = default;
	~SceneManager();
public:
	static SceneManager* GetInstance()
	{
		static SceneManager _instance;
		return &_instance;
	}

public:
	void Init(HWND hwnd);
	void Update();
	void Render(HDC hdc);
	void ChangeSceneByInput();
	void EndScene();
	SceneType GetSceneType() { return _sceneType; }
	Scene* GetScene() { return _scene; }

public:
	void ChangeScene(SceneType sceneType);
	int GetStageNum() { return _stageNum; }
	void GoToNextStage() { _stageNum++; }
	void IncreaseTrialNum() { _trialNum++; }
	int32 GetTrialNum() { return _trialNum; }
	void RestartGame();

private:
	HWND _hwnd = {};
	Scene* _scene = nullptr;
	SceneType _sceneType = SceneType::None;
	bool _endFlag = false;

	int32 _finalStageNum = 2;
	int32 _stageNum = 0;
	int32 _trialNum = 1;
};

