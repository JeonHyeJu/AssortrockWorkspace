﻿// TextRpg000.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int LINECOUNT = 50;

const int NAMELEN = 10;

// 절차지향 
// 어떠한 현실적인 개념을 컴퓨터 세계로 끌고 들어온다.
// 상태와 
int PlayerAtt = 0;
int PlayerHp = 0;
char PlayerName[NAMELEN] = "NONE";

int MonsterAtt = 10;
int MonsterHp = 100;
char MonsterName[NAMELEN] = "NONE";

// 아주 중요한
void StrCopy(char* _Arr, int _BufferSize, const char* const _Name)
{
	for (int i = 0; i < _BufferSize; i += 1)
	{
		_Arr[i] = 0;
	}

	// C스타일 글자 개수 세어주는 함수
	int Size = strlen(_Name);
	_Arr[0] = _Name[0];
	// strcpy_s()
	for (int i = 0; i < Size; i++)
	{
		_Arr[i] = _Name[i];
	}
}

// 함수는 그냥 자기가 만들고 싶으면 만드는 것이다.
// 전 많이 만들수록 좋아합니다.

// 행동
void CreatePlayer(const char* const _Ptr, int _Att, int _Hp)
{
	// char[100] = 300번지
	StrCopy(PlayerName, NAMELEN, _Ptr);
	PlayerAtt = _Att;
	PlayerHp = _Hp;
}

// 모든 문법은 코드를 덜치기 위해서 발전해왔습니다.
void CreateMonster(const char* const _Ptr, int _Att, int _Hp)
{
	StrCopy(MonsterName, NAMELEN, _Ptr);
	MonsterAtt = _Att;
	MonsterHp = _Hp;
}

void StatusRender(const char* _Name, int _Att, int _HP)
{
	printf_s("%s Status", _Name);
	int nameLineCount = LINECOUNT - strlen(_Name) - strlen(" Status");
	for (int i = 0; i < nameLineCount; i += 1)
	{
		printf_s("-");
	}
	printf_s("\n");
	printf_s("공격력 : %d\n", _Att);
	printf_s("체력 : %d\n", _HP);

	for (int i = 0; i < LINECOUNT; i += 1)
	{
		printf_s("-");
	}
	printf_s("\n");

	// printf_s("---------------------------------------------------\n");
}

void PlayerStatusRender()
{
	StatusRender(PlayerName, PlayerAtt, PlayerHp);
}

// 편의를 위해서 랩핑했다고 한다.
void MonsterStatusRender()
{
	StatusRender(MonsterName, MonsterAtt, MonsterHp);
}

// 클래스의 필요성
// 함수는 다양한 상황에서 쓸수있게 만들수록 좋다.
// 함수는 작은 기능을 많이 만들고 
// 함수는 한번에 1가지 일을 할수록 좋다.

// 랜더링
void showDamage(const char* const _AttName, const char* const _DefName, int _Att)
{
	printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, _DefName, _Att);
}

// 게임 로직
void Damage(const char* const _AttName, const char* const _DefName, int& _DefHp, int _Att)
{
	_DefHp -= _Att;
}

int getOrder(int speed)
{
	return rand() % speed + 1;
}

class ClassTest
{
	char v0;
	int v1;
	bool v2;
	short v3;
};

int main()
{
	ClassTest test = ClassTest();
	std::cout << sizeof(test) << std::endl;
	return 0;

	srand(time(NULL));

	CreatePlayer("1", 10, 100);
	CreateMonster("Orc", 10, 50);

	const int PLAYER_MAX_ORDER = 19;
	const int MONSTER_MAX_ORDER = 9;

	while (true)
	{
		char Input = ' ';

		int playerOrder = getOrder(PLAYER_MAX_ORDER);
		int monsterOrder = getOrder(MONSTER_MAX_ORDER);

		system("cls");
		if (playerOrder > monsterOrder) {
			Damage(PlayerName, MonsterName, MonsterHp, PlayerAtt);
			PlayerStatusRender();
			MonsterStatusRender();
			printf_s("%s 선공 (%d:%d)\n", PlayerName, playerOrder, monsterOrder);
			showDamage(PlayerName, MonsterName, PlayerAtt);
			Input = _getch();
			if (Input == 'q') return 0;

			system("cls");
			Damage(MonsterName, PlayerName, PlayerHp, MonsterAtt);
			PlayerStatusRender();
			MonsterStatusRender();
			printf_s("%s 선공 (%d:%d)\n", PlayerName, playerOrder, monsterOrder);
			showDamage(PlayerName, MonsterName, PlayerAtt);
			showDamage(MonsterName, PlayerName, MonsterAtt);
		} else if (playerOrder < monsterOrder) {
			Damage(MonsterName, PlayerName, PlayerHp, MonsterAtt);
			PlayerStatusRender();
			MonsterStatusRender();
			printf_s("%s 선공 (%d:%d)\n", MonsterName, playerOrder, monsterOrder);
			showDamage(MonsterName, PlayerName, MonsterAtt);
			Input = _getch();
			if (Input == 'q') return 0;

			system("cls");
			Damage(PlayerName, MonsterName, MonsterHp, PlayerAtt);
			PlayerStatusRender();
			MonsterStatusRender();
			printf_s("%s 선공 (%d:%d)\n", MonsterName, playerOrder, monsterOrder);
			showDamage(MonsterName, PlayerName, MonsterAtt);
			showDamage(PlayerName, MonsterName, PlayerAtt);
		} else {    // same
			printf_s("동일 숫자. 재실행");
			continue;
		}

		Input = _getch();
		if (Input == 'q') return 0;
	}
}
