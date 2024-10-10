#pragma once
#include "Zone.h"
#include "Enums.h"


// 컨텐츠 아키텍처
class UFightZone : public UZone
{
public:
	void SetMonsterType(Enums::MONSTERTYPE _MonsterType)
	{
		MonsterType = _MonsterType;
	}

	UZone* InPlayer() override;

private:
	// 다형성의 핵심은 코드 관리이다.
	// 다형성은 상당히 느려집니다.
	// UMonster* Monsters[10];

	//UOrc Monster0;
	//UDragon Monster1;
	//UCobolt Monster2;
	//UCobolt Monster0;

	int MinMonsterCount = 1;
	int MaxMonsterCount = 1;

	// 맴버변수로 값형으로 몬스터를 가질수가 없다.
	//class AOrc Monster;
	//class AGoblin Monster;

	// 부모족에서는 이걸로 들고 있는다.
	//AOrc Orc;
	//AGoblin Goblin;

	class AMonster* CurMonster;
	// 이 FightZone에 만들어져야 하는 몬스터의 
	// type으로 정해져 있다.
	Enums::MONSTERTYPE MonsterType = Enums::MONSTERTYPE::NONE;

	void CreateMonster();
};


