#include "Actor.h"
#include "Renderer.h"


void AActor::BeginPlay()
{
}

void AActor::Tick()
{

}

Renderer* AActor::CreateDefaultSubObject()
{
	ImageRenderer = new Renderer();
	return ImageRenderer;
}

void AActor::Render(ConsoleImage* _BackBuffer)
{
	if (nullptr == ImageRenderer)
	{
		return;
	}

	if (false == ImageRenderer->Active)
	{
		return;
	}

	_BackBuffer->Copy(Pos, ImageRenderer->RenderImage);
}

void AActor::SetActorLocation(FIntPoint _Pos)
{
	Pos = _Pos;
}

void AActor::AddActorLocation(FIntPoint _Dir)
{
	Pos += _Dir;
}