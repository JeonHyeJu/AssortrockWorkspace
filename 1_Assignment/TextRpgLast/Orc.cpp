#include "Orc.h"
#include <iostream>

void AOrc::BeginPlay() 
{
	// 부모 클래스의 함수를 호출하는 법
	// 오버라이드 했다면 무조건 해주는게 좋다.
	// 부모가 아무것도 안하는데요? => 진짜 다 살펴볼 자신 있나요?
	// 그냥 실행해주는게 좋습니다.
	// 구현할때도 자식이 실행한다고해서 문제가 생길만한 내용은 넣지 않는게 좋습니다.
	// 이때 순서는 언제나 무조건 가장 먼저 해야한다.
	// 보통 부모클래스의 함수에 준비하는 내용들을 넣어 놓습니다.
	AMonster::BeginPlay(); // class ImageRenderer를 만든다.
	// 부모쪽의 준비 함수가 뭔가를 해주니까.

	SetName("Orc");

	SetMinAtt(5);
	SetMaxAtt(10);
	SetHp(100);
	SetRandomGold(50, 100);


}
