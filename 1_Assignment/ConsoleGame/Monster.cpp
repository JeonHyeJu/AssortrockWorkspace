#include "Monster.h"

Monster::Monster()
{
	setActorType(ActorType::Monster);
}

void Monster::BeginPlay()
{
	Super::BeginPlay();
	RenderImage.Create({ 1, 1 }, 'M');
}

void Monster::Tick()
{
	Super::Tick();
}
