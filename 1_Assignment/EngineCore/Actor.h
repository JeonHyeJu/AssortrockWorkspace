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

	FIntPoint GetActorLocation()
	{
		return Pos;
	}

	class Renderer* CreateDefaultSubObject();

	class Renderer* GetImageRenderer()
	{
		return ImageRenderer;
	}

protected:
	// ConsoleImage RenderImage;
	// 값형으로 만들수 없다.
	// 그려져야 하면 랜더러를 만들고
	// 안그려져야하면 안만들면 된다.

private:
	class Renderer* ImageRenderer;
	FIntPoint Pos;
	// 동적할당 할거냐 말거냐?
};

typedef AActor Super;