#include "StatusUnit.h"
#include "EngineDebug.h"
#include <iostream>

void UStatusUnit::StatusRender()
{
    // 디버깅상 받는게 유리해서.
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
    printf_s("공격력 : %d ~ %d\n", MinAtt, MaxAtt);
    printf_s("체력 : %d\n", Hp);

    for (int i = 0; i < LINECOUNT; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");
}

