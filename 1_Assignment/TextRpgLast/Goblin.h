#pragma once
#include "Monster.h"

class AGoblin : public AMonster
{
public:
	AGoblin();
	~AGoblin();

	void BeginPlay() override;
};
