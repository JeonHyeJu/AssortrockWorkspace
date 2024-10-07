#pragma once
#include "Town.h"
#include "FightZone.h"

// 게임의 시작을 알리고
// 겡임의 종료를 책임진다.
// world 게임 세계 그자체라고 생각하고 만들어서 world이다.
class UWorld
{
public:
	void InPlayer(class UPlayer& _Player);

private:

	void ZoneInit();
	void PlayerNameSelect(class UPlayer& _Player);
	void PlayerZonePlay(class UPlayer& _Player);
	void PlayerInit(class UPlayer& _Player);

	UTown TownZone0;
	UTown TownZone1;
	UFightZone FightZone;
};

