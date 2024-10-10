#pragma once
#include "Object.h"
#include "StatusUnit.h"
#include "FightUnit.h"

class AActor : public UObject, public UStatusUnit, public UFightUnit
{
public:
	void StatusRender();

	virtual void StatusTextRender();
};

