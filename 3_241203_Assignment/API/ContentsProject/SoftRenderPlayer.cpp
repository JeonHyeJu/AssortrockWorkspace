#include "PreCompile.h"
#include "SoftRenderPlayer.h"
#include <EngineCore/SoftRenderer.h>

SoftRenderPlayer::SoftRenderPlayer()
{
	// 0~180�� �ۿ� �ȳ��ɴϴ�.
	// �̰� 0~360 => ����
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
