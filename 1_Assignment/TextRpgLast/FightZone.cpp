#include "FightZone.h"
#include "Monster.h"
#include "Player.h"
#include <conio.h>
#include "Orc.h"
#include "Goblin.h"
#include <BaseSystem/EngineDebug.h>
#include "TextRpgCore.h"
#include "Orc.h"
#include "Goblin.h"

void UFightZone::CreateMonster()
{
	// FightZone에서는 오로지 1종류의 몬스터 
	// 다 메모리 낭비입니다.

	// 동적 바인딩
	// 필요한 순간 필요한 만큼의 메모리를 할당한다.
	// new 연산자 입니다.
	switch (MonsterType)
	{
	case Enums::MONSTERTYPE::GOBLIN:
	{
		// class AMonster* CurMonster;
		AGoblin* Ptr = new AGoblin();
		CurMonster = Ptr;
		break;
	}
	case Enums::MONSTERTYPE::ORC:
		CurMonster = new AOrc();
		break;
	default:
		break;
	}

	// FightZone을 만드는 사람과 
	
	// 고블린인지 오크인지가 정해졌다.
	// 모두다 만들었으면 준비시켜야 한다.
	CurMonster->BeginPlay();
}


UZone* UFightZone::InPlayer()
{
	if (Enums::MONSTERTYPE::NONE == MonsterType)
	{
		MSGASSERT("몬스터 타입이 정해지지 않은 사냥터입니다.");
		return nullptr;
	}

	InMsgPrint();
	_getch();

	// 개념적으로 사냥터라는 개념은 따 똑같다고 생각한다.
	// 변수 주도형. <= 이방법을 가장 권장합니다.
	// 변수 <= 클래스
	// <= 이미지만 
	
	// 사냥터에서 무한히 싸울수는 없다.
	// 사냥터 난이도에 따라서 N마리의 몬스터가 등장할수 있다.

	// 왜 말이 안될까요?
	// 함수 내부에서건
	// 맴버변수에서건 2종류의 몬스터가 동시에 객체화 되는 일이 없어야 한다.
	// 객체화 되는 
	
	CreateMonster();
	APlayer& Player = TextRpgCore::GetPlayer();
	AMonster& Monster = *CurMonster;

	// 여기서 싸우겠죠?
	while (true)
	{
		Player.StatusRender();
		Monster.StatusRender();
		_getch();

		break;
	}

	// 사용을 다 했으면
	// 갈끔하게 지워주면 됩니다.
	if (nullptr != CurMonster)
	{
		delete CurMonster;
		CurMonster = nullptr;
	}

	// 이 내부에서 어떤 메모리들이 할당되었고
	// 기존의 코드를 그냥 사용해도 될겁니다.
	// 4시 15분까지 마을로 돌아가는 코드 아래쪽에 넣어주세요.
	
	return GetZone(0);
}