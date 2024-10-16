#include "Body.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/ConsoleEngine.h>

Body* Body::CurEatBody = nullptr;

void Body::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, 'B');

	// 무조건 사용하라는게 아니다.
	CurEatBody = this;
}

void Body::Tick()
{

}