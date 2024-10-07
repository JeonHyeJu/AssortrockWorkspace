#pragma once
#include "Town.h"
#include "FightZone.h"

class UWorld
{
public:
	void InPlayer(class UPlayer& _Player);

private:
	void ZoneInit();
	void PlayerNameSelect(class UPlayer& _Player);
	void PlayerZonePlay(class UPlayer& _Player);

	UTown TownZone0;
	UTown TownZone1;
	UFightZone FightZone;
};

