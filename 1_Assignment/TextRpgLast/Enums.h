#pragma once

// 모든 enum은 여기에 모아 놓는다.

class Enums
{
	// 접근제한 지정자는 중요하다.
	// MAXS을 사용할수 없게 된다.
public:
	enum class MAXS
	{
		NAMEMAX = 256,
		ACTORNAMEMAX = 10,
		ZONELINKMAX = 5,
		LINECOUNT = 50
	};

	enum class MONSTERTYPE
	{
		// 실수여지를 확인하기 위해서
		NONE = 0,
		GOBLIN,
		ORC
	};

};
