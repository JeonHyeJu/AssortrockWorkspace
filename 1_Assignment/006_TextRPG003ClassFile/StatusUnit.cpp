#include "StatusUnit.h"
#include <BaseSystem/EngineDebug.h>
#include <iostream>

void UStatusUnit::StatusRender()
{
    // 상속관계에서 자식이 존재하는데.
    // 같은 함수를 사용함에도 자식들마다 다른 동작을 해야할때 사용하는 것이
    // virtual 
    
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

