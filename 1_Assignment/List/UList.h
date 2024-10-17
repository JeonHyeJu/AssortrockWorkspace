#pragma once


typedef int DataType;

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
    public:
    private:
        UListNode* CurNode;
    };

public:
    UList()
    {
        // 더미노드라고 합니다.
        Start = new UListNode();
        End = new UListNode();
        Start->Data = -1;
        End->Data = -1;

        Start->Next = End;
        End->Prev = Start;
    }

    ~UList()
    {

    }

    // push_back의 역개념함수
    void push_front(const DataType& _Data)
    {
        UListNode* ListNode = new UListNode();
        ListNode->Data = _Data;

        ListNode->Prev = Start;
        ListNode->Next = Start->Next;

        Start->Next->Prev = ListNode;
        Start->Next = ListNode;
    }

    void push_back(const DataType& _Data)
    {
        UListNode* ListNode = new UListNode();
        ListNode->Data = _Data;

        ListNode->Next = End;
        ListNode->Prev = End->Prev;

        // 이녀석이 먼저 되면 
        End->Prev->Next = ListNode;
        End->Prev = ListNode;
    }


private:
    UListNode* Start = nullptr;
    UListNode* End = nullptr;

};

