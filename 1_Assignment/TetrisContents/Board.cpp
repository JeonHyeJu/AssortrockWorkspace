#include "Board.h"
#include <EngineCore/Renderer.h>

Board* Board::mInstance = nullptr;

void Board::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, '@');
	pRender = Render;

	Board::mInstance = this;
}

void Board::Tick()
{
}

void Board::AddPoint(const FIntPoint& point)
{
	//pRender->RenderImage.Clear('*');
	pRender->RenderImage.SetPixel({ point.X, point.Y }, '@');
	//pRender->RenderImage.Create({ point.X, point.Y }, '@');
}