#include <iostream>

double Power(unsigned int _base, unsigned int _exp)
{
    if (_base == 0) return 0;
    if (_base == 1) return 1;
    if (_exp == 0) return 1;

    double result = static_cast<double>(_base);
    for (unsigned int i = 0; i < _exp - 1; i++) {
        result = static_cast<double>(result * _base);
    }

    return result;
}

// with division
// 0: X, -: X
int StringCount(int _Value)
{
    const int BASE = 10;
    int exp = 0;
    double comparator = 1;

    while (_Value >= comparator)
    {
        exp = exp + 1;
        comparator = Power(BASE, exp);
    }

    return exp;
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