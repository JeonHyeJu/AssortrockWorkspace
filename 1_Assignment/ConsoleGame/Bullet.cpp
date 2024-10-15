#include "Bullet.h"
#include "Renderer.h"


void Bullet::BeginPlay()
{
	Super::BeginPlay();

	// 언리얼은 컴포넌트구조가 아니다.
	// 한번 액터에 랜더러(컴포넌트)가 만들어지고 나면 
	// 한번만들어진 랜더러(컴포넌트)는 지울수 없습니다.
	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, 'I');
}

void Bullet::Tick()
{
	Super::Tick();
	AddActorLocation(FIntPoint::UP);
}
