#pragma once
#include <EngineCore/Actor.h>

// 어떠한 클래스가 자신의 내부에
// 자신과 완전히 동일한 클래스의 참조 형을 가지는 방식을
// Node형 메모리 형태라고 부릅니다.

class ListNode : public AActor
{
public:
	FIntPoint PrevPos;
	// 양방향 연결 리스트 방식으로
	ListNode* Prev = nullptr;
	ListNode* Next = nullptr;


	void push_back(ListNode* _Node);

	void NodeMode();

	ListNode* GetLastNode();

	FIntPoint GetPrevPos()
	{
		return PrevPos;
	}

	void TraceMove();

protected:
	
};

