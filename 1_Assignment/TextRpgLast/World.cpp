#include "World.h"

void UWorld::ZoneInit()
{
	Town0.SetName("초보마을");
	Town1.SetName("중급마을");

	FZone0.SetName("초보사냥터");
	FZone0.SetMonsterType(Enums::MONSTERTYPE::GOBLIN);

	Town0.InterConnecting(FZone0);
}

void UWorld::PlayerZonePlay()
{
	UZone* CurZone = &Town0;

	while (true)
	{
		// 포인터는 실체가 아니고
		// 그냥 주소값일 뿐이다. 언제든지 변경될수 있다.
		// UZone이지만 자식의 함수들이 실행됩니다.

		CurZone = CurZone->InPlayer();
	}
}
