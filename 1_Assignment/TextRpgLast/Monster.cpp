#include "Monster.h"
#include <iostream>
#include <BaseSystem/EngineDebug.h>

void AMonster::BeginPlay()
{

}

void AMonster::SetRandomGold(int _Min, int _Max)
{
	if (_Min > _Max)
	{
		MSGASSERT("랜덤 골드의 Max가 Min보다 작습니다.");
	}

	// srand를 여기서 할거냐?
	int Gold = rand() % (_Max - _Min) + _Min;
	SetGold(Gold);
}