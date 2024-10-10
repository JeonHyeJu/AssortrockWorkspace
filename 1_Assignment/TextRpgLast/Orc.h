#pragma once
#include "Monster.h"

// 그냥 그 회사만의 스탠다드.

// 
class AOrc : public AMonster
{
public:
	// 무조건 구현해야 한다.
	void BeginPlay() override;
};

