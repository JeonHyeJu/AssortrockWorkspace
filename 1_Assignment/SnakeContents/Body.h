#pragma once
#include "ListNode.h"

class Body : public ListNode
{
public:
	static Body* CurEatBody;

	void BeginPlay() override;
	void Tick() override;
protected:

};

