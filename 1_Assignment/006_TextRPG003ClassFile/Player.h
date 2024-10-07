#pragma once

// 구글 스탠다는 전방선언 하지 말자.
// 저는 그냥 적당적당히 알아서 잘할 겁니다.

// 파이트 유니트가 나오지 않을 것이다.
// #include <>
// " <= 이 파일의 경로와 같은 폴더내에 존재하는 파일들을 우선적으로 보여줍니다.

// < <= 내가 만들지 않은 외부파일 <= 디렉토리의 포함디렉토리에 존재하는
//      파일들을 우선적으로 검색해주는 용도로 사용합니다.

// C:AAAA\\bbbbb\\ccccc <= 어떤걸 사용하던 상관은 없습니다.

// 비주얼 스튜디오가 처리하는 방법

#include "FightUnit.h"

// 헤더안에는 최대한 헤더가 없을 수록 좋다.
// 순환 참조 때문에 그렇다.
// 상속관계 만큼은 #include를 피할수가 없다.

// #include 를 최소한 으로 하면 좋다고 했는데.
// 꼭 해야하는 상황을 제외하고는 안해도 상관이 없다.
// class Item; <= 이건 좋기는 좋은데.
class Item;

class UPlayer : public UFightUnit
{
	// 내부에서 다른 클래스를 값형으로 사용했을때 헤더를 넣지 않을수 없다.
	// Has a 인데 값형으로 Has a 했을때
	// UItem NewMonster;
	// 값형이면 무조건 #include 해줘야 한다.
	// 이유 => 이 클래스가 정확하게 빌드된다는것은 무슨 의미일까?
	// 이 클래스의 크기를 명확하게 정의 내려진다.
	// 이 클래스의 크기는 정확하게 얼마인지 

	// 포인터는 상관 없다.
	// 아래와 같은 경우에는 헤더가 없어도 상관이 없다.
	// Item이 뭔지를 알기는 알아야 하기 때문에.
	// extern int a; <= int a라는 변수가 있을것이다.
	// Item이라는 클래스가 있을 것이다 라는 뜻인
	// 전방선언을 해줘야 한다.
	// 전방선언의 위치는 상관이 없고
	// 심지어 선언과 동시에 상관 없다.
	// 한번 해주면 그다음부터는 할필요도 없는데.

public:
	UPlayer();

	void StatusRender() override;

	// 나쁜게 아닌데 절제 없이 하다보면 순환참조 및 문제가 생긴다.
	// 헤더에다가 구현하다보면 
	// 그 헤더가 include cpp를 컴파일데 시간 오래걸리게 된다.
	// 각 종 cpp에서 include를 하기 시작한다.
	void Equip(class Item* Weapon);
	// 헤더에서 함수를 구현하지 않습니다.
	// 함수의 구현을 보통 헤더하지 않습니다.
	//{
	//	// 그 클래스의 함수를 사용하면 헤더가 있어야 한다.
	//	// Weapon->Test();
	//}

	void SetCurZone(int _Index)
	{
		CurZoneIndex = _Index;
	}

	int GetCurZone()
	{
		return CurZoneIndex;
	}

protected:

private:
// #include "Item.h" <= 절대 좋은거 아니다.
	class Item* Weapon = nullptr;
	int CurZoneIndex = 0;
	int EquipAtt = 0;
};

