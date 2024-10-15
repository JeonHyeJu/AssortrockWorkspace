#pragma once
#include "ConsoleImage.h"
#include "Actor.h"
#include "ActorVector.h"

class Player : public AActor
{
public:
	static Player* const GetInstance();
	void BeginPlay() override;
	void Tick() override;

	ActorVector GetBulletVector() const;

private:
	Player() = default;

	static Player* mInstance;
	// 또다른 리스트를 가지게 한다.
	ActorVector BulletVector;
};

