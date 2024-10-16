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

	bool canMove(const FIntPoint& _point);

private:
	static Board* mInstance;
	Renderer* pRender = nullptr;
	std::vector<FIntPoint> mData;
};
