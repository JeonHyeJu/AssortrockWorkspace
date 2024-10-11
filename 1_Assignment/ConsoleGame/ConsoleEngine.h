#pragma once
#include "ConsoleWindow.h"
#include "Player.h"

class ConsoleEngine
{
	// void Update(); // 움직인다.
	// void Move(); // 움직인다.
public:
	static void Start();

private:
	ConsoleEngine();

	UConsoleWindow Window;
	Player NewPlayer;

	// 2번 실행되지 않습니다.
	void BeginPlay(); // 움직인다.

	void Tick(); // 움직인다.
	void Render(); // 그린다.
};

