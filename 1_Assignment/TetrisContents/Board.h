#pragma once
#include <vector>
#include <EngineCore/Actor.h>

class Board : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;

	void AddPoint(const FIntPoint& point);

	static Board* GetInstance()
	{
		return mInstance;
	}

private:
	static Board* mInstance;
	Renderer* pRender = nullptr;
};
