#include "StatusUnit.h"
#include <BaseSystem/EngineDebug.h>
#include <iostream>

void UStatusUnit::TopLine()
{
    // TopLine
    const char* Name = GetName();
    //printf_s("%s Status", GetName());
    //int NameLan = static_cast<int>(strlen(GetName()));
    printf_s("%s Status", Name);
    int NameLan = static_cast<int>(strlen(Name));
    int StatusRand = static_cast<int>(strlen(" Status"));
    int nameLineCount = LINECOUNT - NameLan - StatusRand;
    for (int i = 0; i < nameLineCount; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");
}

void UStatusUnit::BotLine()
{
    // BotLine
    for (int i = 0; i < LINECOUNT; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");

}

void UStatusUnit::StatusRender()
{
    // 상속관계에서 자식이 존재하는데.
    // 같은 함수를 사용함에도 자식들마다 다른 동작을 해야할때 사용하는 것이
    // virtual 
    
    // 디버깅상 받는게 유리해서.
    TopLine();

    // UStatusUnit* const this;
    // 부모쪽에서 virtual을 호출해도 자식쪽 virtual이 호출됩니다.
    this->StatusTextPrint();

    // 가상함수나 이런애들이 더 느립니다.
    BotLine();
}


