#include "Zone.h"
#include <iostream>
#include <BaseSystem/EngineDebug.h>
#include <conio.h>


void UZone::InMsgPrint()
{
	system("cls");
	std::cout << GetName() << "에 입장했습니다.\n";
}

void UZone::ZonePrint()
{
	std::cout << GetName() << "에 체류중.\n";
}

bool UZone::IsConnecting(UZone* _ConnectingZone)
{
	for (size_t i = 0; i < static_cast<int>(Enums::MAXS::ZONELINKMAX); i++)
	{
		if (_ConnectingZone == ConnectingZones[i])
		{
			return true;
		}
	}

	return false;
}

// 100분 25분때 안됐어 무조건 질문.
// 50분때 또 안됐어 또 질문
// 아예 핀트가 나감. => 정답 제발 평생해도 

bool UZone::InterConnecting(UZone* _LinkZone)
{
	// 2줄이면 됩니다.
	// 만들어주세요.
	// 기본이 저한테 기본입니다.
	// 무식하게 짜세요.
	// 디버깅
	_LinkZone->Connecting(this);
	this->Connecting(_LinkZone);

	return true;
}

bool UZone::Connecting(UZone* _LinkZone)
{
	if (this == _LinkZone)
	{
		MSGASSERT("자기자신을 자신에게 연결하려고 했습니다.");
		return false;
	}


	if (true == IsConnecting(_LinkZone))
	{
		MSGASSERT("이미 연결된 지역을 같은 지역에 또 연결하려고 했습니다.");
		return false;
	}

	for (size_t i = 0; i < static_cast<int>(Enums::MAXS::ZONELINKMAX); i++)
	{
		if (nullptr == ConnectingZones[i])
		{
			ConnectingZones[i] = _LinkZone;
			SelectMax += 1;
			// 무한 루프
			// _LinkZone->Link(this);
			return true;
		}
	}

	MSGASSERT("이미 모든 연결이 완결된 지역이라 연결에 실패했습니다.");
	return false;
}

UZone* UZone::ConnectingProgress()
{

	while (true)
	{
		ConnectingPrint();

		// 2곳 연결이 되어있다라고 생각해보자.
		int Select = _getch();
		Select -= '0';

		// 2곳이랑 연결되어 있을때 
		// 1~2사이일때
		if (Select >= 1 && Select <= SelectMax)
		{
			return ConnectingZones[Select - 1];
		}
		else if(Select <= (SelectMax + 1))
		{
			return this;
		}
	}

	return nullptr;
}

void UZone::ConnectingPrint()
{
	system("cls");

	int StartIndex = 1;

	// 1. 초보마을
	// 2. 사냥터
	// 3. 
	for (size_t i = 0; i < static_cast<int>(Enums::MAXS::ZONELINKMAX); i++)
	{
		if (nullptr != ConnectingZones[i])
		{
			const char* NamePtr = ConnectingZones[i]->GetName();
			// char Number[100];
			// itoa(StartIndex, Number, )
			//%s char* 넣어주면 붙여서 출력을 해준다.
			printf_s("%d. %s로 이동.\n", StartIndex, NamePtr);
			StartIndex += 1;
		}
	}

	printf_s("%d. %s로 돌아간다.\n", StartIndex, GetName());
}