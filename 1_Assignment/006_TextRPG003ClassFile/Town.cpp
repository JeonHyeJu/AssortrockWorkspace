#include "Town.h"
#include <conio.h>
#include "Player.h"

// 포인터나 레퍼런스는 무조건 8바이트 이기 때문에
int UTown::InPlayer(class UPlayer& _Player)
{
	InMsgPrint();

	while (true)
	{
		// 미리 헤더를 #include 최대한 미루는게 좋다.
		_Player.StatusRender();

		std::cout << "0. 체력회복\n";
		std::cout << "1. 강화\n";
		std::cout << "2. 사냥터이동\n";
		std::cout << "3. 중급마을로 이동\n";
		int Select = _getch();

		switch (Select)
		{
		case '0':
			printf_s("0눌렀습니다.");
			_getch();
			continue;
		case '1':
			printf_s("1눌렀습니다.");
			_getch();
			continue;
		case '2':
		{
			printf_s("2눌렀습니다.");
			_getch();
			break;
		}
		case '3':
			printf_s("3눌렀습니다.");
			_getch();
			break;
		default:
			continue;
		}
		
		return Select;
	}
}
