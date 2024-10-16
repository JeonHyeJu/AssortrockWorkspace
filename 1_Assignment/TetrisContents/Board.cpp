#include "Board.h"
#include <EngineCore/Renderer.h>

Board* Board::mInstance = nullptr;

void Board::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 3, 5 }, '*');

	mData.reserve(3 * 5);	// TODO

	pRender = Render;

	Board::mInstance = this;
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