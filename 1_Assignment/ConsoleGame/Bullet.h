#pragma once
#include "Actor.h"

class Bullet : public AActor
{
public:
	Bullet();
	void BeginPlay() override;
	void Tick() override;
};

