#pragma once
#include "ConsoleImage.h"

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
class Player
{
public:
	void BeginPlay();
	bool Tick();
	void Render(ConsoleImage* _BackBuffer);
	void SetActorLocation(FIntPoint _Pos);

	bool Move();
	bool CanMove(const FIntPoint& _pos);
	void SetBackScreenSize(const FSize& _size);

private:
	FIntPoint Pos;
	FSize mMaxBackScreenSize;
	ConsoleImage PlayerImage;
};

