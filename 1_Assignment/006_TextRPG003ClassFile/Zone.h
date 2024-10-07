#pragma once
#include "StatusUnit.h"
#include "ContentsConst.h"

// 귀찮음이 있으면 큰일 납니다.
class UZone : public UObject
{
public:
	void InMsgPrint();
	void ZonePrint();
	// 지역과 지역을 연결한다.
	// bool 만약 이 지역과 연결될수 없다면

	bool InterConnecting(UZone* _LinkZone);

	bool Connecting(UZone* _LinkZone);

	// 이 지역과 연결되어 있다?
	bool IsConnecting(UZone* _LinkZone);

	void ConnectingPrint();

	UZone* ConnectingProgress();

	// 보통 이녀석 자체는 아무것도 하지 않습니다.
	// 부모는 인터페이스만 제공한다고 합니다.
	virtual UZone* InPlayer(class UPlayer& _Player) 
	{
		return nullptr;
	}

protected:


private:
	// 어떤 클래스 자신의 내부에 
	// 내부에는 사냥터 마을 앞으로 만들어들 모든 지역들이
	// 전부다 여기에 넣을수가 있다.
	UZone* LinkZone[LINKZONEMAX] = {nullptr,};
	//UTown* LinkZone[LINKZONEMAX] = { nullptr, };
	//UFightZone* LinkZone[LINKZONEMAX] = { nullptr, };

	//UZone* LinkZone;
	//__int64 LinkIndex;

	// __int64 LinkZone[LINKZONEMAX]
	int SelectMax = 0;
};