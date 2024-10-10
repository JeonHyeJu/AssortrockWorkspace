#pragma once
#include "Zone.h"

class BlackSmith : public UZone
{
public:
	void TryUpgrade();

	UZone* InPlayer() override;

	inline void SetParent(class UZone* _ParentZone)
	{
		Connecting(_ParentZone);
	}

private:
};

