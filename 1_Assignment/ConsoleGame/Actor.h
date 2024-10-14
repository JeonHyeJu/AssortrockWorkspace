#pragma once
#include <BaseSystem/EngineMath.h>
#include "ConsoleImage.h"
#include "Enums.h"

class AActor
{
	

public:
	virtual void BeginPlay();
	virtual void Tick();

	void Render(ConsoleImage* _BackBuffer);

	FIntPoint GetActorLocation() const;
	void SetActorLocation(FIntPoint _Pos);
	void AddActorLocation(FIntPoint _Pos);

	void setActorType(const ActorType& _actorType);
	const ActorType& getActorType() const;

protected:
	ConsoleImage RenderImage;

private:
	FIntPoint Pos;
	ActorType mActorType;
	// 동적할당 할거냐 말거냐?
};

typedef AActor Super;