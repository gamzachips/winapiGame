#pragma once

class TimeManager
{
private:
	TimeManager() = default;

public:
	static TimeManager* GetInstance()
	{
		static TimeManager _instance;
		return &_instance;
	}

public:
	void Init();
	void Update();

	uint32 GetFps() { return _fps; }
	float GetDeltaTime() { return _deltaTime; }

private:
	uint64 _frequency = 0;
	uint64 _prevCount = 0;
	float _deltaTime = 0.f;

	uint32 _frameCount = 0;
	float _frameTime = 0.f;
	uint32 _fps = 0;
};

