#include "Goblin.h"

AGoblin::AGoblin()
{
}

AGoblin::~AGoblin()
{
	int a = 0;
}


void AGoblin::BeginPlay()
{
	AMonster::BeginPlay();
	SetName("Goblin");

	SetMinAtt(1);
	SetMaxAtt(5);
	SetHp(20);
	SetRandomGold(1, 20);
}