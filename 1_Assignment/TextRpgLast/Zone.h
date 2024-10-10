#pragma once
#include "Object.h"
#include "Enums.h"

class UZone : public UObject
{
public:
	void InMsgPrint();
	void ZonePrint();

	bool InterConnecting(UZone& _LinkZone)
	{
		return InterConnecting(&_LinkZone);
	}
	bool InterConnecting(UZone* _LinkZone);
	bool Connecting(UZone* _LinkZone);
	bool IsConnecting(UZone* _LinkZone);
	void ConnectingPrint();

	UZone* ConnectingProgress();

	// 이게 요즘 스타일
	bool IsConnectEmpty()
	{
		return SelectMax == 0;
	}

	int GetSelectMax()
	{
		return SelectMax;
	}


	virtual UZone* InPlayer()
	{
		return nullptr;
	}

protected:
	inline UZone* GetZone(int _Index)
	{
		return ConnectingZones[_Index];
	}

private:
	UZone* ConnectingZones[static_cast<int>(Enums::MAXS::ZONELINKMAX)] = { nullptr, };
	int SelectMax = 0;

	// 대부분의 로직 최적화는 공간적 최적화와 연산적 최적화가 있다.
	// 
	// 대부분의 문제의 해결책은 
	// 내가 뭔가를 생각했다면 
	// 무조건 왠만하면 일단 변수가 필요하다.
	// ConnectingZones 몇개나 
};