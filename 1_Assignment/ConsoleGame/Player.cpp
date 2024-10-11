#include "Player.h"
#include <conio.h>
#include "Enums.h"

void Player::BeginPlay()
{
	PlayerImage.Create({2, 2}, '@');
}

bool Player::Tick()
{
	return Move();
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
	int imgHalfW = PlayerImage.GetImageSizeX() / 2;
	int imgHalfH = PlayerImage.GetImageSizeY() / 2;
	int realLimitW = mMaxBackScreenSize.w - imgHalfW;
	int realLimitH = mMaxBackScreenSize.h - imgHalfH;

	if (0 > _pos.X || _pos.X >= realLimitW)
	{
		return false;
	}
	if (0 > _pos.Y || _pos.Y >= realLimitH)
	{
		return false;
	}

	return true;
}

bool Player::Move()
{
	int Value = _kbhit();
	if (Value != 0)
	{
		Enums::GAMEDIR Dir = Enums::GAMEDIR::NONE;
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
		case 'Q':
		case 'q':
			return true;
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

		bool canMove = CanMove(futurePos);
		if (canMove)
		{
			SetActorLocation(futurePos);
		}
	}

	return false;
}