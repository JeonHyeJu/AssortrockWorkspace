#pragma once

class UWorld
{
public:
	void InPlayer(class UPlayer& _Player);

private:
	void PlayerNameSelect(class UPlayer& _Player);
	void PlayerZonePlay(class UPlayer& _Player);
};

