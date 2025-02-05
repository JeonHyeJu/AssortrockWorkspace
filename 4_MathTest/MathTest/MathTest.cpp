// MathTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <EngineBase/EngineMath.h>

int main()
{
	FMatrix m1;
	m1 = m1 * 2;
	m1.Position(FVector { 2, 0, 0 });

	FMatrix m2;
	m2.Position(FVector{ 3, 0, 0 });

	FMatrix ret = m1* m2;
	int a = 0;

	return 0;
}
