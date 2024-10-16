#pragma once
#include "ListNode.h"

// Body로 만들었다고 칩시다.
// Body 아직 내가 먹지 않은 상태로 허공중에 떠있다.
// 1. 먹는다 => 내뒤에 단다.

// Food로 마들었다고 칩시다.
// 1. Food를 먹는 순간 Food는 지워야 합니다.
// 2. Body를 만든다. 그리고 달아준다.



class Head : public ListNode
{
public:
	void BeginPlay() override;
	void Tick() override;

	void Move();
	void EatCheck();


	FIntPoint GetEmptyPoint();
};

