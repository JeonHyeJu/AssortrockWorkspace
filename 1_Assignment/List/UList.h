#pragma once
#include <assert.h>
#include <map>

typedef int DataType;

std::map<int, int> temp;

// 중단점이나 디버깅할때 그냥 자료형이 
// 정해져 있는것이 보기가 더 편해서 이방법을 많이 사용했다.
// template<typename DataType>
class UList
{
public:
    class UListNode
    {
        // friend UList;
        // friend iterator;

    public:
        UListNode* Prev = nullptr;
        UListNode* Next = nullptr;
        DataType Data;
    };

public:
    // 순회자라는 클래스를 통해서 
    class iterator
    {
        friend UList;

    public:
        iterator()
        {

        }

        bool operator!=(const iterator& _Other)
        {
            return CurNode != _Other.CurNode;
        }

        // * 진짜 곱하기로도 사용할수 있다.
        DataType& operator*()
        {
            return CurNode->Data;
        }

        iterator& operator++()
        {
            CurNode = CurNode->Next;
            return *this;
        }

        DataType& GetValue()
        {
            return CurNode->Data;
        }

    private:
        // 노드가 존재한다는것은 외부에 알리고 싶지 않다.
        iterator(UListNode* _Node)
            : CurNode(_Node)
        {

        }

        // 
        // 3000번지
        UListNode* CurNode = nullptr;
    };

public:
    UList()
    {
        // 더미노드라고 합니다.
        StartNode = new UListNode();
        EndNode = new UListNode();
        StartNode->Data = -1;
        EndNode->Data = -1;

        StartNode->Next = EndNode;
        EndNode->Prev = StartNode;
    }

    ~UList()
    {
        UListNode* node = StartNode;
        while (node)
        {
            if (node->Prev)
            {
                delete node->Prev;
                node->Prev = nullptr;
            }

            if (node->Next)
            {
                node = node->Next;
            }
            else
            {
                delete node;
                node = nullptr;
            }
        }
    }

    // 자료구조 3대장
    // => List Vector Map
    // 
    // push_back의 역개념함수
    void push_front(const DataType& _Data)
    {
        // 정확하게 다시 무슨일이 벌어지는지
        // 그려가면서 확인해보세요.
        UListNode* ListNode = new UListNode();
        ListNode->Data = _Data;

        // 개념들을 다 역개념으로
        ListNode->Prev = StartNode;
        ListNode->Next = StartNode->Next;

        // 이녀석이 먼저 되면 
        StartNode->Next->Prev = ListNode;
        StartNode->Next = ListNode;
    }

    void push_back(const DataType& _Data)
    {
        UListNode* ListNode = new UListNode();
        ListNode->Data = _Data;

        ListNode->Next = EndNode;
        ListNode->Prev = EndNode->Prev;

        // 이녀석이 먼저 되면 
        EndNode->Prev->Next = ListNode;
        EndNode->Prev = ListNode;
    }

    iterator erase(iterator& _Data)
    {
        UListNode* CurNode = _Data.CurNode;
        if (CurNode == nullptr)
        {
            assert(false);
            return iterator();
        }

        if (CurNode == StartNode)
        {
            assert(false);
            return iterator();
        }

        // C++
        if (CurNode == EndNode)
        {
            assert(false);
            return iterator();
        }

        UListNode* ReturnNode = CurNode->Next;

        CurNode->Prev->Next = CurNode->Next;
        CurNode->Next->Prev = CurNode->Prev;

        delete CurNode;
        CurNode = nullptr;

        return iterator(ReturnNode);
    }

    iterator begin() 
    {
        return iterator(StartNode->Next);
    }

    iterator end()
    {
        return iterator(EndNode);
    }


private:
    UListNode* StartNode = nullptr;
    UListNode* EndNode = nullptr;

};

