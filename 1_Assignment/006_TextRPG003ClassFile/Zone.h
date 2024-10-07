#pragma once
#include "StatusUnit.h"
#include "ContentsConst.h"

// 귀찮음이 있으면 큰일 납니다.
class UZone : public UObject
{
public:
	void InMsgPrint();

	// 지역과 지역을 연결한다.
	// bool 만약 이 지역과 연결될수 없다면

	bool InterConnecting(UZone* _LinkZone);

	bool Connecting(UZone* _LinkZone);

	// 이 지역과 연결되어 있다?
	bool IsConnecting(UZone* _LinkZone);

	// void LinkPrint();

protected:


private:
	// 어떤 클래스 자신의 내부에 
	// dhkswjs 
	UZone* LinkZone[LINKZONEMAX] = {nullptr,};
};