#include "PreCompile.h"
#include "SoftRenderPlayer.h"
#include <EngineCore/SoftRenderer.h>

SoftRenderPlayer::SoftRenderPlayer()
{
	// 0~180도 밖에 안나옵니다.
	// 이걸 0~360 => 외적
	// float Angle = FVector::GetVectorAngleDeg({0, 1}, {1, 0});

	USoftRenderer* Renderer = CreateDefaultSubObject<USoftRenderer>();
}

SoftRenderPlayer::~SoftRenderPlayer()
{
}

void SoftRenderPlayer::BeginPlay()
{
	Super::BeginPlay();
}
void SoftRenderPlayer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
