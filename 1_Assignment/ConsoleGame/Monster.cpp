#include "Monster.h"
#include "Renderer.h"
#include "Player.h"

void Monster::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, 'M');
}

void Monster::Tick()
{
	// 무한 재귀
	// Monster::Tick();

	// 1. 모든 총알을 가져온다.
	// 2. 모든 총알 과 자신의 위치를 비교해야 한다.
	//    엔진이 기능을 제공 안해주면 손가락을 빨고 있어야하느냐?

	// 1-1. 컨텐츠에서 직접 짠다. 
	//      유저가 직접 관리하는 방식을 만든다. 스킬매니저 등등을 만들어서
	//      클라이언트 프로그래머가 이방법을 선호합니다.
	//      엔진이 제공하는 기능을 알아내는게 더 느려.
	//      엔진의 기능은 보통 다형성 기반으로 했을때 사용하지 않는게 좋다.
	//      
	// 1-2. 엔진의 기능을 이용한다. 엔진의 기능은 대부분 느려요.
	//      직관적이고 무식하게 짜여져 있기 때문에 
	//      엔진의 입장에서 Player Monster Bullet고 다 => AActor일 뿐이다.
	//      자료구조 하나에서 관리하고 100
	//      엔진에서 제공하는 FindObject나 Find 같은 기능들은 대부분 극혐하는 기능들.
	//      Find(const char*) <= 심지어 문자열 비교라서 2배로 느리다.

	bool isCrahsed = IsCrahsed();
	if (isCrahsed)
	{
		FIntPoint monsterPos = GetActorLocation();
		SetActorLocation(monsterPos + FIntPoint::UP);
	}
}

bool Monster::IsCrahsed()
{
	FIntPoint monsterPos = GetActorLocation();
	Player* player = Player::GetInstance();
	ActorVector bullets = player->GetBulletVector();

	for (int i = 0; i < bullets.size(); i++)
	{
		FIntPoint pos = bullets[i]->GetActorLocation();
		if (monsterPos.X == pos.X && monsterPos.Y == pos.Y)
		{
			return true;
		}
	}

	return false;
}
