#include <iostream>

int StringCount(const char* const _Str)
{
    if (!_Str) return 0;

    int Count = 0;
    while (_Str[Count])
    {
        if (_Str[Count] == '\0') {
            break;
        }

        Count++;
    }

    return Count;
}

int main()
{
    // [B][B][B][B][0]

    const char* temp = "BBBB";
    int Count = strlen(temp);

    std::cout << "original: " << Count << std::endl;

    Count = StringCount(temp);
    std::cout << "new: " << Count << std::endl;
}
