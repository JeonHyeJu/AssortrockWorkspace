#pragma once
#include "Zone.h"
#include "BlackSmith.h"

class UTown : public UZone
{
	// 인터페이스 통일화.
public:
	UTown();

	// 다음지역을 리턴해줄 겁니다.
	// 정말 많이 사용되는 방법
	UZone* InPlayer();

	BlackSmith BS;
};

