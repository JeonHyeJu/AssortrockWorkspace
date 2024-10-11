#include "Player.h"
#include <conio.h>
#include "Enums.h"

void Player::BeginPlay()
{
	PlayerImage.Create({1, 1}, '@');
}

void Player::Tick()
{
	Move();
}

void Player::Render(ConsoleImage* _BackBuffer)
{
	// delete _BackBuffer;
	_BackBuffer->Copy(Pos, PlayerImage);
}

void Player::SetActorLocation(FIntPoint _Pos)
{
	Pos = _Pos;
}

void Player::SetBackScreenSize(const FSize& _size)
{
	mMaxBackScreenSize = _size;
}

bool Player::CanMove(const FIntPoint& _pos)
{
	if (0 > _pos.X || _pos.X >= mMaxBackScreenSize.w)
	{
		return false;
	}
	if (0 > _pos.Y || _pos.Y >= mMaxBackScreenSize.h)
	{
		return false;
	}

	return true;
}

void Player::Move()
{
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
		default:
			break;
		}

		FIntPoint futurePos = Pos;
		switch (Dir)
		{
		case Enums::GAMEDIR::LEFT:
			futurePos += FIntPoint::LEFT;
			break;
		case Enums::GAMEDIR::RIGHT:
			futurePos += FIntPoint::RIGHT;
			break;
		case Enums::GAMEDIR::UP:
			futurePos += FIntPoint::UP;
			break;
		case Enums::GAMEDIR::DOWN:
			futurePos += FIntPoint::DOWN;
			break;
		default:
			break;
		}

		int imgHalfW = PlayerImage.GetImageSizeX() / 2;
		int imgHalfH = PlayerImage.GetImageSizeY() / 2;
		futurePos -= FIntPoint{ imgHalfW , imgHalfH };

		bool canMove = CanMove(futurePos);
		if (canMove)
		{
			SetActorLocation(futurePos);
		}
	}
}