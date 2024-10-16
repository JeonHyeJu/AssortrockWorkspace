#include "ListNode.h"


// 재귀함수
void ListNode::push_back(ListNode* _Node)
{
	// this => Head
	// _Node => Body

	ListNode* LastNode = this;

	while (nullptr != LastNode->Next)
	{
		LastNode = LastNode->Next;
	}

	if (nullptr == LastNode->Next)
	{
		LastNode->Next = _Node;
		_Node->Prev = LastNode;
		return;
	}

	int a = 0;
}

void ListNode::NodeMode()
{
	if (nullptr != Next)
	{
		Next->SetActorLocation(PrevPos);
	}
	
}

// 특정 함수 안에서
// 자신을 다시한번 호출하는 함수를 재귀함수라고 한다고 했습니다.
ListNode* ListNode::GetLastNode()
{
	// this => Head
	if (nullptr == Next)
	{
		return this;
	}

	// 내가 LastNode가 아니다.
	return Next->GetLastNode();
}

void ListNode::TraceMove()
{
	if (nullptr == Next)
	{
		return;
	}

	// 무언가 이제 이동을 하려면 언제나 내 위치를 기억해 놔야한다.
	Next->PrevPos = Next->GetActorLocation();
	Next->SetActorLocation(PrevPos);
	return Next->TraceMove();
}