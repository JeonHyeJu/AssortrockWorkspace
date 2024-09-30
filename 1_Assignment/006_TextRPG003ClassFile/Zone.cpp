#include "Zone.h"
#include <conio.h>


void UZone::InMsgPrint()
{
	system("cls");
	std::cout << GetName() << "에 입장했습니다.\n";
}