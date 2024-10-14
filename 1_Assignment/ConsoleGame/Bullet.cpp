#include "Bullet.h"
#include "ConsoleEngine.h"

void Bullet::BeginPlay()
{
	Super::BeginPlay();
	RenderImage.Create({ 1, 1 }, 'I');
}

void Bullet::Tick()
{
	Super::Tick();

	FIntPoint winSize = ConsoleEngine::GetWindowSize();
	FIntPoint pos = GetActorLocation();

	if ((pos.X >= 0 && pos.X < winSize.X) && (pos.Y >= 0 && pos.Y < winSize.Y))
	{
		SetActorLocation(pos + FIntPoint::UP);
	}
}
