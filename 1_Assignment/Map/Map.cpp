// Map.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include "UMap.h"

// 기초에 집중
// 가상함수테이블 설명

// map에 사용된 알고리즘은 
// 레드블랙 바이너리서치 트리

// 트리

// map 메모리구조 노드 구조
// map 메모리구조 시퀀스 연관
class MapNode
{
public:
    MapNode* Parent;
    MapNode* LeftChild;
    MapNode* RightChild;
};

class OctMapNode
{
public:
    MapNode* Parent;
    MapNode* Childs[8];
};

class QuadMapNode
{
public:
    MapNode* Parent;
    MapNode* Childs[4];
};


class BiMapNode
{
public:
    MapNode* Parent;
    // MapNode* Childs[2];
    MapNode* LeftChild;
    MapNode* RightChild;
};


class greater
{
    // 연산자를 겹지정한 클래스를()
    // 함수 객체라고 한다.
public:
    bool operator()(int _left, int _Right)
    {
        return _left < _Right;
    }
};

//class MapData
//{
//public:
//    int first = 10;
//    int second = 10;
//};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // 상속 받았어?
    // 컴파일 타임 어써션과 템플릿 컴파일을 이용한 컴파일시 결정되는 
    // 다이나믹 캐스트를 사용하지 않고 더 빠른 상속 판단 클래스
    // 템플릿 썼죠? => std 아래 stl
    // std::is_base_of<APlayer, AActor>::value

    // std => 스탠다드 라이브리
    // stl => 스탠다드 템플릿 라이브러리

    {
        // stl의 한 클래스이다.
        // 자료구조 stl들은 
        std::vector<int> Test;
        // int* index
        std::vector<int>::iterator StartIter = Test.begin();
        std::vector<int>::iterator EndIter = Test.end();

        for (; StartIter != EndIter; ++StartIter)
        {
            int Value = *StartIter;
        }
    }

    {
        // 가속성 과 사용성을 고려했다고 한다.
        // stl의 한 클래스이다.
        // 자료구조 stl들은 
        std::list<int> Test;
        // int* index
        std::list<int>::iterator StartIter = Test.begin();
        std::list<int>::iterator EndIter = Test.end();

        for (; StartIter != EndIter; ++StartIter)
        {
            int Value = *StartIter;
        }
    }

    {
        // Set은 value가 없는 map입니다.
        std::set<int> TestSet;

        // Map은 Value가 추가된 set입니다.
        // Map 메모리 형태 => 노드형
        // Map은 어떤 컨테이너 인가요? 연관 컨테이너
        // 맵에는 세번째 템플릿 인자가 있다.
        // 보통 맵을 특정 데이터들을 빠르게(코드 치는걸 빠르게) 하고 싶을때
        // 용도로 사용할때 사용합니다.
        std::map<int, int, std::greater<int>> TestMap;


        // 클래스
        // Key라고 정의내리고 
        // Key 서치 2진트리 규칙은
        // Key를 기반으로 처리한다.
        // std::pair<Key, Value>
        // Key만으로 이루어진 자료구조가 
        std::pair<int, int> PairValue;
        PairValue.first = 10;
        PairValue.second = 10;
        // std::make_pair(10, 20) return std::pair<int, int>
        // 결론적으로는 pair를 만들어서 넣어줘야 한다.
        TestMap.insert(PairValue);
        TestMap.insert({10, 20});
        TestMap.insert(std::make_pair(10, 0));
        TestMap.insert(std::map<int, int>::value_type(2, 0));
        TestMap.insert(std::make_pair(5, 0));
        TestMap.insert(std::make_pair(7, 0));
        TestMap.insert(std::make_pair(15, 0));

        // 맵을 사용하는 이유
        std::map<int, int>::iterator FindIter = TestMap.find(7);
        FindIter->first;
        FindIter->second;

        // 같은 키 넣으면 map은 무시한다.
        // TestMap.insert(std::make_pair(10, 0));


        std::map<int, int>::iterator StartIter = TestMap.begin();
        std::map<int, int>::iterator EndIter = TestMap.end();

        for (; StartIter != EndIter; ++StartIter)
        {
            std::cout << StartIter->first << std::endl;
        }

    }

    {
        //const char* Ptr = "Orc";
        //const char* Ptr0 = "Dragon";

        //__int64 Value = reinterpret_cast<__int64>(Ptr);
        //__int64 Value0 = reinterpret_cast<__int64>(Ptr0);

        //bool Check = Value > Value0;

        // // std::pair<__int64, AActor> PairValue;

        // TestMap.insert({ "Orc", AActor()});
        // TestMap.insert({ "Orc", AActor() });

        UMap TestMap;

        // pair가 뭔지 
        UPair PairValue = {10, 2};
        PairValue.first = 10;
        PairValue.second = 2;

        TestMap.insert({10, 0}); // <= root
        TestMap.insert({ 2, 0 });
        TestMap.insert(Umake_pair(6, 0));
        TestMap.insert(Umake_pair(5, 0));
        TestMap.insert(Umake_pair(4, 0));
        TestMap.insert(Umake_pair(7, 9999));
        TestMap.insert(Umake_pair(15, 0));

        //UMap::iterator FindIter = TestMap.Find(10);

        //FindIter = TestMap.erase(FindIter);

        //FindIter->first;
        //FindIter->second;

        //FindIter.operator->()->first;
        //FindIter.operator->()->second;

        //UPair Pair;
        //UPair* PairPtr = &Pair;
        //Pair.first;
        //Pair.second;
        //PairPtr->first;
        //PairPtr->second;
        // TestMap.Root;

        //UMap::iterator StartIter = TestMap.begin();
        //UMap::iterator EndIter = TestMap.end();
        //for (; StartIter != EndIter; ++StartIter)
        //{
        //    KeyType Value = StartIter->first;
        //    std::cout << StartIter->first << std::endl;
        //}

        // TestMap.FirstOrder();
        // TestMap.MidOrder();
        // TestMap.LastOrder();
    }
}

