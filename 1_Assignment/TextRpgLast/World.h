#pragma once
#include "Town.h"
#include "FightZone.h"

// 모든 맵을 관리하는 관리자 개념
// 지도역할
// UZone을 관리하는 역할지 
class UWorld
{
public:
	void ZoneInit();

	void PlayerZonePlay();

	UTown Town0;
	UTown Town1;
	UFightZone FZone0;
};

