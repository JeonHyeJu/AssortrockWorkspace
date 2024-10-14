#include "Actor.h"


void AActor::BeginPlay()
{

}
void AActor::Tick()
{

}
void AActor::Render(ConsoleImage* _BackBuffer)
{
	_BackBuffer->Copy(Pos, RenderImage);
}

FIntPoint AActor::GetActorLocation() const
{
	return Pos;
}

void AActor::SetActorLocation(FIntPoint _Pos)
{
	Pos = _Pos;
}

void AActor::AddActorLocation(FIntPoint _Dir)
{
	Pos += _Dir;
}

void AActor::setActorType(const ActorType& _actorType)
{
	mActorType = _actorType;
}

const ActorType& AActor::getActorType() const
{
	return mActorType;
}