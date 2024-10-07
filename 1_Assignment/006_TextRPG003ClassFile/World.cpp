#include "World.h"
#include "FightZone.h"
#include "Town.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <BaseSystem/EngineFile.h>

// #include "EngineFile.h"

// #include "..\BaseSystem\EngineFile.h"
// 정석적인 방법은 아닙니다.

// #include < <= 시작하는 외부경로는 크게 2가지 기능의 영향을 받는다.


#include <conio.h>



void UWorld::PlayerNameSelect(class UPlayer& _Player)
{
	// C:\\

	char InputName[100] = { 0, };

	bool IsNameInput = true;

	while (true)
	{
		if (true == IsNameInput)
		{
			system("cls");
			std::cout << "이름을 적어주세요" << std::endl;
			std::cin >> InputName;
		}

		system("cls");
		printf_s("당신의 이름은 %s입니다. 결정하시겠습니까?\n", InputName);
		printf_s("a. 결정\n");
		printf_s("b. 재입력\n");
		int Select = _getch();

		bool IsEnd = true;
		switch (Select)
		{
		case 'a':
		case 'A':
			IsEnd = true;
			break;
		case 'b':
		case 'B':
			IsEnd = false;
			IsNameInput = true;
			break;
		default:
			IsEnd = false;
			IsNameInput = false;
			printf_s("잘못된 선택입니다. 다시 선택해주세요\n");
			_getch();
			break;
		}

		if (true == IsEnd)
		{
			break;
		}
	}

	// 파일 저장

	_Player.SetName(InputName);
}

void UWorld::ZoneInit()
{
	// 지역들을 준비시키것.
	// 이니셜라이즈 단계
	// 객체들을 만들고 처음으로 준비시키는 단계
	// 대부분 딱 1번한다.
	TownZone0.SetName("초보마을");
	TownZone1.SetName("중급마을");
	FightZone.SetName("초보사냥터");

	TownZone0.Connecting(&FightZone);
	TownZone0.InterConnecting(&FightZone);

	// TownZone0.Connecting(&FightZone);
	// FightZone.Connecting(&TownZone0);

	// 업캐스팅
	// 같은곳을 2번 
	// 무조건 디버깅이 최우선
	// 테스트 코드를 짜야 합니다.
	// 2번 연결 예외처리 테스트
	// 귀찮아 
	//TownZone0.Link(&FightZone);
	//TownZone0.Link(&FightZone);

	// 테스팅2
	//UTown Arr[100];
	//for (size_t i = 0; i < 100; i++)
	//{
	//	TownZone0.Link(&Arr[i]);
	//}
}


void UWorld::PlayerZonePlay(class UPlayer& _Player)
{
	ZoneInit();
	_Player.SetCurZone(0);
	_Player.SetGold(10000000);

	while (true)
	{
		int SelectZone = _Player.GetCurZone();

		switch (SelectZone)
		{
		case 0:
			TownZone0.InPlayer(_Player);
			break;
		case 1:
			TownZone1.InPlayer(_Player);
			break;
		case 2:
			FightZone.InPlayer(_Player);
			break;
		default:
			break;
		}
	}

}

void UWorld::InPlayer(class UPlayer& _Player)
{
	// 외부기로 헤더만 있고 CPP는 없다. 
	UEngineFile File;
	File.SetPath("SaveFile.Dat");

	// 파일이 없을때
	if (false == File.IsExits())
	{
		File.FileOpen("wb");

		// 이름 정하고 나왔다.
		PlayerNameSelect(_Player);
		const char* Name = _Player.GetName();

		// 문자열을 저장할때는 문제가 있다.
		// 초반에는 안좋을수 있다.
		// 저장할때 가장 쉬운 방법은 크기가 고정되어 있는 것이다.
		File.Write(Name, NAMELEN);
	}
	else 
	{
		File.FileOpen("rb");

		char Arr[100] = {};
		File.Read(Arr, NAMELEN);
		_Player.SetName(Arr);
	}

	PlayerZonePlay(_Player);
}