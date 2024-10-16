#include "Board.h"
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>
#include <EngineCore/Renderer.h>

Board* Board::mInstance = nullptr;

Board* Board::GetInstance()
{
	return mInstance;
}

void Board::BeginPlay()
{
	Super::BeginPlay();

	FIntPoint winSize = ConsoleEngine::GetEngine().GetWindow()->GetScreenSize();
	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create(winSize, '*');
	pRender = Render;

	mData.reserve(winSize.X * winSize.Y);
	mInstance = this;
}

void Board::Tick()
{
}

void Board::AddPoint(const FIntPoint& _point)
{
	pRender->RenderImage.SetPixel({ _point.X, _point.Y }, '@');
	mData.push_back(_point);
}

bool Board::canMove(const FIntPoint& _point)
{
	for (int i = 0; i < mData.size(); i++)
	{
		if (mData[i].X == _point.X && (mData[i].Y - 1) == _point.Y)
		{
			return false;
		}
	}
	return true;
}