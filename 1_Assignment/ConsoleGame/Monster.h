#pragma once
#include "Actor.h"

class Monster : public AActor
{
public:
	Monster();
	void BeginPlay() override;
	void Tick() override;
};

