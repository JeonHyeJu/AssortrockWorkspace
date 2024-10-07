#include "FightZone.h"
#include "Monster.h"
#include "Player.h"
#include <conio.h>


int UFightZone::InPlayer(class UPlayer& _Player)
{
	InMsgPrint();
	_getch();

	UMonster NewMonster;

	while (true)
	{
		system("cls");
		_Player.StatusRender();
		NewMonster.StatusRender();
		_getch();
	}
}