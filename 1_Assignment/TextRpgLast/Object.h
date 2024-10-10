#pragma once
#include "Enums.h"

class UObject
{
public:
	UObject()
	{

	}

	virtual ~UObject()
	{

	}

	void SetName(const char* const _Name);
	inline const char* GetName()
	{
		return Name;
	}

	void TopLine();
	void BotLine();

private:
	char Name[static_cast<int>(Enums::MAXS::NAMEMAX)] = {0,};
};


