#pragma once
#include "Actor.h"

// UObject 이름
// UStatusUnit를 통해서 능력치
// UFightUnit를 통해서 전투
class APlayer : public AActor
{
	// 일부러 생성

public:
	APlayer();

	inline int GetEquipAtt() const
	{
		return EquipAtt;
	}

	inline void SetEquipAtt(int _Value)
	{
		EquipAtt = _Value;
	}

	void StatusTextRender() override;

private:
	int EquipAtt = 0;
};

