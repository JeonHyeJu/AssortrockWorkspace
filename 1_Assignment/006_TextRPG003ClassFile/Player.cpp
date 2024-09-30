#include "Player.h"
#include <iostream>

// #CPP에서는 #include를 아무리 많이해도 순환참조는 걱정 안해도 된다.
// 그런데 문제가 있다. 빌드가 오래 걸린다.
// obj파일마다 #include가 


// 맴버함수 분할 구현
UPlayer::UPlayer()
{
	std::cout << "플레이어 생성자" << std::endl;
}

// 맴버함수를 구현할대는 이러면 그냥 전역함수다.
// 명확한 이름을 명시해줘야 한다.
// 어떤 클래스에 속한건지 명시해줘야 한다.
void UPlayer::Equip(class Item* Weapon)
{

}