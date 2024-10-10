#pragma once
#include "Actor.h"

// 사실 추상적인 개념이죠?
// 포유류 같은 추상적인 개념으로 실체화 할수 없다.
class AMonster : public AActor
{
public:
	// 시작함수
	virtual void BeginPlay() = 0;

	void SetRandomGold(int _Min, int _Max);

};

