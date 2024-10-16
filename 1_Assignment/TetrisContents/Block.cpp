#include "Block.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>
#include <conio.h>

#include "Board.h"

// Debug
#include <iostream>
#include <string>

void Block::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, '@');
}

void Block::Tick()
{
	Super::Tick();

	FIntPoint blockLoc = GetActorLocation();
	FIntPoint winSize = ConsoleEngine::GetEngine().GetWindow()->GetScreenSize();

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
			if (blockLoc.Y < (winSize.Y - 1))
			{
				AddActorLocation(FIntPoint::DOWN);
			}
			else
			{
				FIntPoint loc = GetActorLocation();
				Board::GetInstance()->AddPoint(loc);

				SetActorLocation({0, 0});
			}
			break;
		default:
			break;
		}
	}
	
	//AddActorLocation(FIntPoint::DOWN);
}

