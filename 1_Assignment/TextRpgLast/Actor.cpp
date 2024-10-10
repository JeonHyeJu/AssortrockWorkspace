#include "Actor.h"
#include <iostream>

void AActor::StatusRender()
{
	TopLine();

	StatusTextRender();


	BotLine();
}


void AActor::StatusTextRender()
{
	printf_s("공격력 : %d ~ %d\n", MinAtt, MaxAtt);
	printf_s("체력 : %d\n", Hp);
	printf_s("골드 : %d\n", Gold);
}