// 상속헤더
#include "ConsoleEngine.h"

// Platform
#include <Windows.h>

// User
#include "ConsoleWindow.h"
#include "Actor.h"

ConsoleEngine* ConsoleEngine::MainEngine = nullptr;

ConsoleEngine::ConsoleEngine()
{

}


// void ConsoleEngine::Start(void(*Ptr)(ConsoleEngine*))
void ConsoleEngine::Start(class UserInit* _Init)
{
	ConsoleEngine Engine;

	MainEngine = &Engine;

	Engine.BeginPlay();

	_Init->UserBeginPlay(&Engine);

	// 콜백
	// Ptr(&Engine);

	while (true == Engine.EngineActive)
	{
		Engine.Tick();
		Engine.Render();
		Sleep(250);
	}

	Engine.End();
}

void ConsoleEngine::End()
{
	if (nullptr != Window)
	{
		delete Window;
		Window = nullptr;
	}
}

void ConsoleEngine::BeginPlay()
{
	Window = new UConsoleWindow();
	Window->BeginPlay();

	// 대리객체 방법이 있습니다.

	// 나중에 배우겠습니다.
	// 함수포인터로 하는법
	Window->SetScreenSize({10, 10});
}

void ConsoleEngine::Tick()
{
	for (size_t i = 0; i < AllActorVector.size(); i++)
	{
		AllActorVector[i]->Tick();
	}
}

void ConsoleEngine::Render()
{
	Window->Clear();

	ConsoleImage* BackBufferPtr = Window->GetBackBufferPtr();
	for (size_t i = 0; i < AllActorVector.size(); i++)
	{
		AllActorVector[i]->Render(BackBufferPtr);
	}

	Window->ScreenRender();
}