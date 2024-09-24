#include <iostream>

// with division
// 0: X, -: X
int NumberCount(int _Value)
{
    const int BASE = 10;
    int Result = 0;

    while (_Value)
    {
        _Value /= BASE;
        Result += 1;
    }
    return Result;
}

void NumberToString(char* Buffer, int BufferSize, int _Value)
{
    if (!Buffer) return;
    if (BufferSize == 0) return;

    const int BASE = 10;
    int cnt = NumberCount(_Value) - 1;
    int idx = 0;

    while (cnt >= 0) {
        int denorm = static_cast<int>(pow(BASE, cnt));
        int norm = _Value / denorm;
        _Value = _Value % denorm;

        Buffer[idx++] = norm + '0';

        if (idx >= (BufferSize - 1)) {
            break;
        }

        cnt = NumberCount(_Value) - 1;
    }

    Buffer[idx] = 0;
}

int main()
{
    int Result0 = NumberCount(12358);
    int Result1 = NumberCount(5258);
    int Result2 = NumberCount(525);
    int Result3 = NumberCount(52);
    int Result4 = NumberCount(5);
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