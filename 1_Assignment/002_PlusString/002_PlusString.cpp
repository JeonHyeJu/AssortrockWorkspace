#include <iostream>

void PlusString(char* _Buffer, int _BufferSize, const char* const _Value0, const char* const _Value1)
{
    if (!_Buffer || !_Value0 || !_Value1) return;
    if (_BufferSize == 0) return;

    int bufferIdx = 0;
    int idx = 0;

    while (_Value0[idx]) {
        _Buffer[bufferIdx++] = _Value0[idx];
        idx++;
    }

    idx = 0;
    while (_Value1[idx]) {
        _Buffer[bufferIdx++] = _Value1[idx];
        idx++;
    }

    _Buffer[bufferIdx] = 0;
}

int main()
{
    char Arr[100] = {};
    PlusString(Arr, 100, "AAAA", "BBBB");
    std::cout << "PlusString: " << Arr << std::endl;
}