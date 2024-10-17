// List.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <list>
#include "UList.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // 메모리 : 노드형
    // 종류 : 시퀀스 자료구조

    {
        // Node 메모리 구조이기 때문에
        // [9] [0] [1] [2] [3] 
        std::list<int> Newint;
        Newint.push_back(0);
        Newint.push_back(1);
        Newint.push_back(2);
        Newint.push_back(3);
        Newint.push_front(9);

        std::list<int>::iterator StartIter = Newint.begin();
        std::list<int>::iterator EndIter = Newint.end();
        for (; StartIter != EndIter; ++StartIter)
        {
            int& Value = *StartIter;
            std::cout << Value << std::endl;

        }
    }

    {
        // Node 메모리 구조이기 때문에
        // [9] [0] [1] [2] [3] 

        // 1. 릭 없애기 
        // 2. push_front 만들기

        UList Newint;
        Newint.push_back(0);
        Newint.push_back(1);
        Newint.push_back(2);
        Newint.push_back(3);
        Newint.push_front(9);

        int a = 0;

        //UList::iterator StartIter = Newint.begin();
        //UList::iterator EndIter = Newint.end();
        //for (; StartIter != EndIter; ++StartIter)
        //{
        //    int& Value = *StartIter;
        //    std::cout << Value << std::endl;

        //}
    }
}
