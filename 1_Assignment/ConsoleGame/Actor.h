#pragma once
#include <BaseSystem/EngineMath.h>
#include "ConsoleImage.h"


class AActor
{
	

public:
	virtual void BeginPlay();
	virtual void Tick();

	void Render(ConsoleImage* _BackBuffer);

	void SetActorLocation(FIntPoint _Pos);

	void AddActorLocation(FIntPoint _Pos);


protected:
	ConsoleImage RenderImage;

private:
	FIntPoint Pos;
	// 동적할당 할거냐 말거냐?
};

typedef AActor Super;