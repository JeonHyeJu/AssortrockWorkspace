#include "Player.h"
#include <conio.h>
#include "Enums.h"
#include "GlobalValue.h"
#include "ConsoleEngine.h"
#include "Renderer.h"

Player* Player::mInstance = nullptr;

Player* const Player::GetInstance()
{
	if (!mInstance)
	{
		mInstance = new Player();
	}

	return mInstance;
}

void Player::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, '@');

	// 1. 적당히 아래 위치에 놓아달라.
	SetActorLocation({ 1, 3 });
	//SetActorLocation({ 10, 8 });
}

void Player::Tick()
{
	Super::Tick();
	// ConsoleEngine::MainPlayer

	// 타고가서 쓰게 할려는 방법.
	// ConsoleEngine::GetEngine().GetPlayer()

	// ConsoleImage& BackBuffer = *_BackBuffer;

	// static은 전역이니까 객체가 필요없다.
	ConsoleEngine::GetWindow();
	ConsoleEngine::GetWindowSize();

	// 남에 코드 안건드리고 
	GlobalValue::WindowPtr;
	GlobalValue::WindowSize;

	

	int Value = _kbhit();
	Enums::GAMEDIR Dir = Enums::GAMEDIR::NONE;
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			Dir = Enums::GAMEDIR::LEFT;
			break;
		case 'D':
		case 'd':
			Dir = Enums::GAMEDIR::RIGHT;
			break;
		case 'W':
		case 'w':
			Dir = Enums::GAMEDIR::UP;
			break;
		case 'S':
		case 's':
			Dir = Enums::GAMEDIR::DOWN;
			break;
		case 'Z':
		case 'z':
		{
			Bullet* NewBullet = ConsoleEngine::GetEngine().SpawnActor<Bullet>();

			// 1. 총알이 플레이어 위치에 나오게 만드세요
			// 2. 총알이 위쪽으로 올라가게 만드세요.
			NewBullet->SetActorLocation(this->GetActorLocation());

			// 관리하는자가 누구냐?
			// 지금 엔진의 AllActorVector 에서 가지고 있다.
			// 플레이어를 만든 컨텐츠 프로그래머가 BulletVector를 만들고 여기에도 넣어놨다.
			// 
			// 플레이어가 총알을 매니지먼트 
			BulletVector.push_back(NewBullet);
			// delete NewBullet;

			break;
		}
		default:
			break;
		}

	}

	switch (Dir)
	{
	case Enums::GAMEDIR::LEFT:
		AddActorLocation(FIntPoint::LEFT);
		break;
	case Enums::GAMEDIR::RIGHT:
		AddActorLocation(FIntPoint::RIGHT);
		break;
	case Enums::GAMEDIR::UP:
		AddActorLocation(FIntPoint::UP);
		break;
	case Enums::GAMEDIR::DOWN:
		AddActorLocation(FIntPoint::DOWN);
		break;
	default:
		break;
	}

	// Pos += FIntPoint::RIGHT;
}

ActorVector Player::GetBulletVector() const
{
	return BulletVector;
}