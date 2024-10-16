#pragma once
#include <vector>
#include <EngineCore/Actor.h>

class Board : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;

	static Board* GetInstance();
	void AddPoint(const FIntPoint& point);
	bool canMove(const FIntPoint& _point);

private:
	static Board* mInstance;
	Renderer* pRender = nullptr;
	std::vector<FIntPoint> mData;
};
