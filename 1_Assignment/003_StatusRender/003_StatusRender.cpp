#include <iostream>

const int LINECOUNT = 50;
void StatusRender(const char* _Name, int _Att, int _HP)
{
    printf_s("%s ", _Name);

    int size = LINECOUNT - static_cast<int>(strlen(_Name)) - 1;
    for (int i = 0; i < size; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");

    printf_s("공격력 : %d\n", _Att);
    printf_s("체력 : %d\n", _HP);
}

int main()
{
    char buffer[100] = "Test";
    StatusRender(buffer, 100, 100);

    char buffer2[100] = "TesterABCDEFGHIJK";
    StatusRender(buffer2, 100, 100);
}