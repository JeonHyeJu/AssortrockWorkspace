#include "Player.h"
#include <conio.h>
#include "Enums.h"
#include "GlobalValue.h"
#include "ConsoleEngine.h"


Player::Player()
{
	setActorType(ActorType::Player);
}

void Player::BeginPlay()
{
	Super::BeginPlay();

	RenderImage.Create({1, 1}, '@');
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
	FIntPoint winSize = ConsoleEngine::GetWindowSize();

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
			FIntPoint playerPos = GetActorLocation();
			if (playerPos.Y < (winSize.Y - 1))
			{
				NewBullet->SetActorLocation(playerPos);
			}
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

