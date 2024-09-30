#pragma once
#include "StatusUnit.h"
// #include "Player.h"

// A 클래스를 빌드하려면 B 클래스가 필요하고.
// B를 만들려면 A를 빌드해야하는 상황이 오면
// 이를 순환 참조라고 한다.
// 서클형이 가장 위험하고 찾기 힘들다.
// A => B.h => C.h => D.h => E.h => A =>

// 언리얼 대비
class UFightUnit : public UStatusUnit
{
	// 부모는 절대로 자식을 알면 안된다.
	// UPlayer Test;
};

