#pragma once
#include "Zone.h"

class UPlayer;

class BlackSmith
{
public:
	// 안넣어주면 생성이 안되.
	//BlackSmith(UZone& _ParentZone)
	//	: ParentZone(_ParentZone)
	//{

	//}

	void InPlayer(UPlayer& _Player/*, int& Result*/);

	inline void SetParent(class UZone* _ParentZone)
	{
		ParentZone = _ParentZone;
	}

private:
	// class UZone& ParentZone;

	void Enhance(UPlayer& _Player);

	class UZone* ParentZone = nullptr;
};