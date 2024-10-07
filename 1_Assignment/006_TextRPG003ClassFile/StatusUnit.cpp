#include "StatusUnit.h"
#include <BaseSystem/EngineDebug.h>
#include <iostream>


void UStatusUnit::TopLine()
{
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
    for (int i = 0; i < LINECOUNT; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");
}

void UStatusUnit::StatusRender()
{
    TopLine();
    printf_s("공격력 : %d ~ %d\n", MinAtt, MaxAtt);
    printf_s("체력 : %d\n", Hp);
    BotLine();
}
