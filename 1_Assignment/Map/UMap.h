#pragma once
#include <iostream>


typedef int KeyType;
typedef int ValueType;

class UPair
{
public:
	KeyType first;
	ValueType second;
};

UPair Umake_pair(const KeyType& _Key, const ValueType& _Value);

class less
{
	// 연산자를 겹지정한 클래스를()
	// 함수 객체라고 한다.
public:
	bool operator()(int _left, int _Right)
	{
		return _left > _Right;
	}
};


// template<typename KeyType, typename ValueType>
class UMap
{
private:
	class UMapNode
	{
	public:
		UMapNode* Parent = nullptr;
		UMapNode* LeftChild = nullptr;
		UMapNode* RightChild = nullptr;
		UPair Pair;

		//            전위순회
		void FirstOrder()
		{
			// 무언가 할일이 있다면 그걸 처음에 하느냐
			std::cout << Pair.first << std::endl;
			// delete this;
			if (nullptr != this->LeftChild)
			{
				LeftChild->FirstOrder();
			}
			if (nullptr != this->RightChild)
			{
				RightChild->FirstOrder();
			}
		}
		//            중위순회
		void MidOrder()
		{
			if (nullptr != LeftChild)
			{
				LeftChild->MidOrder();
			}
			// 무언가 할일이 있다면 그걸 가운데 
			std::cout << Pair.first << std::endl;
			if (nullptr != RightChild)
			{
				RightChild->MidOrder();
			}
		}
		//            후위순회
		void LastOrder()
		{
			if (nullptr != LeftChild)
			{
				LeftChild->LastOrder();
			}
			if (nullptr != RightChild)
			{
				RightChild->LastOrder();
			}
			// 무언가 할일이 있다면 그걸 가운데 
			std::cout << Pair.first << std::endl;
		}

		void ChildRelease(UMapNode* _Node)
		{
			// _Node->Parent = nullptr;

			if (LeftChild == _Node)
			{
				LeftChild = nullptr;
				return;
			}

			if (RightChild == _Node)
			{
				RightChild = nullptr;
				return;
			}
		}

		UMapNode* OverParent(const KeyType& _Key)
		{
			if (nullptr != Parent)
			{
				if (Parent->Pair.first > _Key)
				{
					return Parent;
				}

				return Parent->OverParent(_Key);
			}

			return nullptr;
		}

		UMapNode* NextNode()
		{
			if (nullptr == RightChild)
			{
				// 부모중에
				return OverParent(Pair.first);
			}

			return RightChild->MinNode();
		}

		UMapNode* MinNode()
		{
			if (nullptr == LeftChild)
			{
				return this;
			}

			// 꼬리재귀
			return LeftChild->MinNode();
		}

		UMapNode* MaxNode()
		{
			if (nullptr == RightChild)
			{
				return this;
			}

			// 꼬리재귀
			return RightChild->MaxNode();
		}

		UMapNode* FindNode(const KeyType& _Key)
		{
			if (this->Pair.first == _Key)
			{
				return this;
			}

			if (Pair.first > _Key)
			{
				return LeftChild->FindNode(_Key);
			}
			else 
			{
				return RightChild->FindNode(_Key);
			}

			// 의미는 
			return nullptr;
		}

		void insertNode(const UPair& _Pair)
		{
			if (Pair.first == _Pair.first)
			{
				return;
			}

			//  10            2
			// 이 > 하나 때문이다. 

			less NewLess;

			if (NewLess(Pair.first, _Pair.first))
			{
				if (nullptr == LeftChild)
				{
					LeftChild = new UMapNode();
					LeftChild->Parent = this;
					LeftChild->Pair = _Pair;
					return; // <= 여기서 완벽하게 종료해야한다면 return 꼭 해주세요
				}

				// Left차일드가 있다는 이야기
				LeftChild->insertNode(_Pair);
			}
			else 
			{
				if (nullptr == RightChild)
				{
					RightChild = new UMapNode();
					RightChild->Parent = this;
					RightChild->Pair = _Pair;
					return; // <= 여기서 완벽하게 종료해야한다면 return 꼭 해주세요
				}

				// Left차일드가 있다는 이야기
				RightChild->insertNode(_Pair);

			}
		}
	};

public:
	class iterator
	{
		friend UMap;
	public:
		iterator& operator++()
		{
			CurNode = CurNode->NextNode();
			return *this;
		}


		bool operator!=(const iterator& _Other)
		{
			return CurNode != _Other.CurNode;
		}

		UPair* operator->()
		{
			return &CurNode->Pair;
		}

		iterator(UMapNode* _Node)
			: CurNode(_Node)
		{

		}

	private:
		UMapNode* CurNode = nullptr;
	};



public:
	iterator begin()
	{
		if (nullptr == Root)
		{
			return iterator(nullptr);
		}

		return iterator(Root->MinNode());
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	iterator Find(const KeyType& _Key)
	{
		if (nullptr == Root)
		{
			return nullptr;
		}

		UMapNode* Node = Root->FindNode(_Key);
		return iterator(Node);
	}

	iterator erase(iterator& _iter)
	{
		// 절대 안바뀔 코드는 먼저 치는게 좋다.
		iterator Return = _iter.CurNode->NextNode();
		UMapNode* CurNode = _iter.CurNode;
		UMapNode* Parent = _iter.CurNode->Parent;

		// 자식이 없을때
		if (nullptr == CurNode->LeftChild && 
			nullptr == CurNode->RightChild)
		{
			// 루트노드라는 뜻
			// 루트노드가 삭제되었다는 뜻이
			if (nullptr == Parent)
			{
				Root = nullptr;
			}

			Parent->ChildRelease(CurNode);

			delete CurNode;
			CurNode = nullptr;
			return Return;
		}

		if (nullptr != CurNode->LeftChild ||
			nullptr != CurNode->RightChild)
		{
			UMapNode* ChangeNode = nullptr;
			// 나를 대체할 노드

			if (nullptr != CurNode->LeftChild)
			{
				ChangeNode = CurNode->LeftChild->MaxNode();
			}
			else 
			{
				ChangeNode = CurNode->RightChild->MinNode();
			}

			if (nullptr != ChangeNode->Parent)
			{
				ChangeNode->Parent->ChildRelease(ChangeNode);
			}

			UMapNode* CurLeftChild = CurNode->LeftChild;
			UMapNode* CurRightChild = CurNode->RightChild;

			// 삭제될 노드의 자식들의 부모를 미리 끊어 놓는다.
			if (nullptr != CurLeftChild)
			{
				CurLeftChild->Parent = nullptr;
			}

			if (nullptr != CurRightChild)
			{
				CurRightChild->Parent = nullptr;
			}


			if (nullptr != CurLeftChild)
			{
				if (CurLeftChild != ChangeNode)
				{
					CurLeftChild->Parent = ChangeNode;
					ChangeNode->LeftChild = CurLeftChild;
				}
			}

			if (nullptr != CurRightChild)
			{
				if (CurRightChild != ChangeNode)
				{
					CurRightChild->Parent = ChangeNode;
					ChangeNode->RightChild = CurRightChild;
				}
			}

			ChangeNode->Parent = CurNode->Parent;

			UMapNode* ParentNode = CurNode->Parent;

			if (nullptr != ParentNode)
			{
				if (ParentNode->RightChild == CurNode)
				{
					ParentNode->RightChild = ChangeNode;
				}
				else
				{
					ParentNode->LeftChild == ChangeNode;
				}
			}

			if (Root == CurNode)
			{
				Root = ChangeNode;
			}

			delete CurNode;
			CurNode = nullptr;
			return Return;
		}

		return nullptr;
	}

	// 2진트리에는 전위순회
	void FirstOrder()
	{
		std::cout << "전위 순회" << std::endl;
		Root->FirstOrder();
		std::cout << std::endl;
	}
	//            중위순회
	void MidOrder()
	{
		std::cout << "중위 순회" << std::endl;
		Root->MidOrder();
		std::cout << std::endl;
	}
	//            후위순회
	void LastOrder()
	{
		std::cout << "후위 순회" << std::endl;
		Root->LastOrder();
		std::cout << std::endl;
	}

	void insert(const UPair& _Pair)
	{
		if (nullptr == Root)
		{
			Root = new UMapNode();
			Root->Pair = _Pair;
			return;
		}

		if (true == isRotate())
		{
			// 편향트리다
			Rotate();
		}

		Root->insertNode(_Pair);
	}

	void clear()
	{
		if (!Root)
		{
			return;
		}

		UMapNode* node = Root;
		while (node)
		{
			if (node->LeftChild)
			{
				node = node->LeftChild;
				continue;
			}

			if (node->RightChild)
			{
				node = node->RightChild;
				continue;
			}

			UMapNode* deleteNode = node;
			UMapNode* parentNode = node->Parent;
			if (parentNode)
			{
				if (parentNode->LeftChild == deleteNode)
				{
					parentNode->LeftChild = nullptr;
				}
				else
				{
					parentNode->RightChild = nullptr;
				}
			}

			node = parentNode;
			delete deleteNode;
			deleteNode = nullptr;
		}
	}

public:
	~UMap()
	{
		clear();
	}

	UMapNode* Root = nullptr;

	bool isRotate()
	{
		return false;
	}

	void Rotate()
	{
		if (true)
		{
			LeftRotate();
		}

		if (true)
		{
			RightRotate();
		}

		return;
	}

	void LeftRotate()	{	}

	void RightRotate()	{	}
};

