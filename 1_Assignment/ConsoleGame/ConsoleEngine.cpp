#include "ConsoleEngine.h"
#include <Windows.h>

ConsoleEngine::ConsoleEngine()
{

}

void ConsoleEngine::Start()
{
	ConsoleEngine Engine;

	Engine.BeginPlay();

	while (true)
	{
		bool isClose = Engine.Tick();
		Engine.Render();
		// 프로그램 250
		// 1000이 1초입니다.

		if (isClose)
		{
			break;
		}

		Sleep(250);
	}
	
}

void ConsoleEngine::BeginPlay()
{
	Window.BeginPlay();
	Window.SetScreenSize({20, 10});

	NewPlayer.BeginPlay();
	NewPlayer.SetBackScreenSize(Window.GetScreenSize());
}

bool ConsoleEngine::Tick()
{
	return NewPlayer.Tick();
}

void ConsoleEngine::Render()
{
	Window.Clear();

	ConsoleImage* BackBufferPtr = Window.GetBackBufferPtr();
	NewPlayer.Render(BackBufferPtr);

	Window.ScreenRender();
}