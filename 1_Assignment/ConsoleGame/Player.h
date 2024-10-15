#pragma once
#include "ConsoleImage.h"
#include "Actor.h"
#include "ActorVector.h"

//class AActor
//{
//	FIntPoint Location;
//};
//
//class Monster
//{
//	
//};

// 화면어딘가에 이녀석이 랜더링
// 일반적인 게임엔진
class Player : public AActor
{
public:
	static Player* GetInstance();
	void BeginPlay() override;
	void Tick() override;

	ActorVector GetBulletVector() const;

private:
	static Player* mInstance;
	// 또다른 리스트를 가지게 한다.
	ActorVector BulletVector;
};

