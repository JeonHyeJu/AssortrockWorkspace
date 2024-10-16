#include "Block.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>
#include <conio.h>

#include "Board.h"

void Block::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, '@');
	SetActorLocation({ 1, 0 });
}

void Block::Tick()
{
	Super::Tick();

	FIntPoint blockLoc = GetActorLocation();
	FIntPoint winSize = ConsoleEngine::GetEngine().GetWindow()->GetScreenSize();

	Board* pBoard = Board::GetInstance();
	if (!pBoard) return;

	bool isFilled = pBoard->IsFilledLocation(blockLoc);
	if (blockLoc.Y >= (winSize.Y - 1) || isFilled)
	{
		AddBlockAndResetLoc(blockLoc);
		return;
	}

	int Value = _kbhit();
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			if (blockLoc.X > 0)
			{
				AddActorLocation(FIntPoint::LEFT);
			}
			break;
		case 'D':
		case 'd':
			if (blockLoc.X < (winSize.X - 1))
			{
				AddActorLocation(FIntPoint::RIGHT);
			}
			break;
		case 'W':
		case 'w':
			if (blockLoc.Y > 0)
			{
				AddActorLocation(FIntPoint::UP);
			}
			break;
		case 'S':
		case 's':
			{
				if (blockLoc.Y < (winSize.Y - 1))
				{
					AddActorLocation(FIntPoint::DOWN);
				}
				else
				{
					AddBlockAndResetLoc(blockLoc);
				}
				break;
			}
		default:
			break;
		}
	}
	
	//AddActorLocation(FIntPoint::DOWN);
}

void Block::AddBlockAndResetLoc(const FIntPoint& _point)
{
	Board::GetInstance()->AddPoint(_point);
	SetActorLocation({ 1, 0 });
}