#include <iostream>

// with division
// 0: X, -: X
int StringCount(int _Value)
{
    const int BASE = 10;
    int Result = 1;

    while (_Value >= BASE)
    {
        _Value /= BASE;
        Result += 1;
    }
    return Result;
}

void NumberToString(char* Buffer, int BufferSize, int _Value)
{
    if (StringCount(_Value) + 1 > BufferSize) {
        return;
    }
    sprintf_s(Buffer, BufferSize, "%d", _Value);
}

int main()
{
    int Result0 = StringCount(12358);
    int Result1 = StringCount(5258);
    int Result2 = StringCount(525);
    int Result3 = StringCount(52);
    int Result4 = StringCount(5);
    std::cout << "Result0: " << Result0 << std::endl;
    std::cout << "Result1: " << Result1 << std::endl;
    std::cout << "Result2: " << Result2 << std::endl;
    std::cout << "Result3: " << Result3 << std::endl;
    std::cout << "Result4: " << Result4 << std::endl;

    const int BUFFER_SIZE = 16;
    char buffer[BUFFER_SIZE] = { 0, };
    NumberToString(buffer, BUFFER_SIZE, 12358);
    std::cout << "buffer: " << buffer << std::endl;
}