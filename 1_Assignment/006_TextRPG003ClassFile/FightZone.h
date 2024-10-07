#pragma once
#include "Zone.h"

// 컨텐츠 아키텍처
class UFightZone : public UZone
{
public:
	UZone* InPlayer(class UPlayer& _Player);

private:
	// 다형성의 핵심은 코드 관리이다.
	// 다형성은 상당히 느려집니다.
	// UMonster* Monsters[10];

	//UOrc Monster0;
	//UDragon Monster1;
	//UCobolt Monster2;
	//UCobolt Monster0;
};

