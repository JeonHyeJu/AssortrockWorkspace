#pragma once
#include <EngineCore/Actor.h>

class Block : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;

private:
	void AddBlockAndResetLoc(const FIntPoint& _point);
};
