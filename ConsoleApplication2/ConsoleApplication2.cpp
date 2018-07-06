#include "stdafx.h"



#include <iostream>
#include "list.h"

void list_init(List* pList)
{// list_init 함수를 정의한다
	pList->m_pHead = NULL; // list의 맨앞을 비운다 
	pList->m_pTail = NULL; // list의 맨뒤를 비운다

}

Node* list_make_node(void)
{// list_make_node 함수를 정의한다 (새로운 노드 생성함수)
	Node* node = (Node*)malloc(sizeof(Node)); // Node의 사이즈 만큼의 heap의 공간을 빌려온다
	node->data = 0; // node의 data(int)에 0을 대입한다
	node->m_pNext = NULL; // 포인터 m_pNext 를 비운다
	node->m_pPrev = NULL; // 포인터 m_pPrev 를 비운다

	return node; // 그런 node를 return한다
}

void list_push_back(List* pList, int data)
{// list_push_back (list의 마지막에 node를 넣는 함수)
	Node* node = list_make_node(); //새로운 node를 만든다
	node->data = data; // node의 data에 data 값을 넣는다
	if(pList->m_pTail!=NULL)
	{// 만약 List의 맨뒤가 비어있지 않다면
		(pList->m_pTail)->m_pNext = node; //맨뒤의 다음에 그 새로운 노드를 넣는다
		node->m_pPrev = pList->m_pTail; //노드의 앞주소를 의미하는 m_pPrev에 list의 마지막 주소인 m_pTail를 넣는다
		pList->m_pTail = node; //그리고 다시 list의 마지막이 된 노드의 주소를 새로운 마지막 주소 m_pTail에 넣는다 
	}

	else
	{// List의 맨뒤가 비어있다면
		pList->m_pTail = node; // List의 맨뒤이자
		pList->m_pHead = node; // 맨앞이 노드임
	}
}

void list_push_front(List*pList, int data)
{// list_push_front(list의 맨 앞에 node를 넣는 함수)
	Node* node = list_make_node(); //새로운 node를 만든다
	node->data = data; // node의 data에 data 값을 넣는다
	if (pList->m_pHead != NULL)
	{// List의 맨앞이 비어있지 않다면
		(pList->m_pHead)->m_pPrev = node; // 맨앞의 앞에 새로운 노드를 넣는다
		node->m_pNext = pList->m_pHead; // 노드의뒷주소에 list의 첫 주소인 m_pHead를 넣는다
		pList->m_pHead = node; //list의 첫 주소를 노드로 교체한다

	}
	else
	{// List의 맨앞이 비어있다면
		pList->m_pTail = node;//List의 맨뒤이자
		pList->m_pHead = node;//List의 맨앞이 노드이다
	}
}
void list_insert(List* pList, Node* rhs, int data)
{// list에 node를 삽입한다.
	Node* lhs = rhs->m_pPrev; //rhs의 이전에 있는 것을 lhs라고 정의한다

	if (lhs==NULL)
	{//ppNode가 비어있다면
		list_push_front(pList, data); //data가 포함된 노드를 list의 맨앞에 넣는다
		return;
	}
	Node* node = list_make_node(); //새로운 node를 생성한다
	node->data = data; // node의 data에 data를 넣는다

	lhs->m_pNext = node; //lhs의 다음에 node를 넣는다 (주소를 넣는다)
	node->m_pPrev = lhs; //node의 이전 노드를 lhs로 한다 -> lhs를 node 왼쪽으로 둔다

	node->m_pNext = rhs; //node이후에 rhs를 넣는다 (주소를 넣는다)
	rhs->m_pPrev = node; //rhs의 이전이 node이다 
}

void list_erase(List* pList, Node *pNode)
{// node를 찾아서 지운다
	Node* pTarget = pList->m_pHead; // Target의 주소는 Head부터 출발한다
	while (pTarget != NULL)
	{// Target의 주소가 비어있지 않을 때 까지
		if (pTarget == pNode) // 만약 Target이 Node의 주소를 찾으면 빠져나온다
			break;
		pTarget = pTarget->m_pNext; // 찾을 때 까지 다음 주소로 넘어간다
	}
	if (pTarget == NULL) // 그 Node의 주소가 없다면 그대로 나온다
		return;


	if (pTarget == pList->m_pHead)
	{// 그 노드의 주소를 처음부터 찾았다면
		pList->m_pHead = pList->m_pHead->m_pNext; //Head의 주소를 그 다음부터 시작하도록 한다 (Head가 Node였으므로) 
		pTarget->m_pPrev = NULL; // 맨앞에 있는 주소를 비운다
		free(pNode);//Node주소를 삭제
		return;
	}
	if (pTarget->m_pNext == NULL)
	{// 그노드의 주소가 마지막 이었다면
		pList->m_pTail = pList->m_pTail->m_pPrev; // Tail의 주소를 그 이전에 끝내게 한다 (Tail이 Node였으므로)
		pTarget->m_pNext = NULL; // 맨뒤를 지운다
		free(pNode);//Node 주소를 삭제
		return;

	}
	pTarget->m_pPrev->m_pNext = pTarget->m_pNext; // 타겟 자기자신을 타겟 다음으로 미룬다
	pTarget->m_pNext->m_pPrev = pTarget->m_pPrev; // 다음으로 미룬 타겟 자신을 이전으로 미룬다
	free(pNode);

}


void print_list(List* pList, Node* cursor)
{ // 커서의 위치에 따라 list를 출력하는 함수
	Node* pNode = pList->m_pHead; // node의 주소는 list의 head부터 시작
		while (pNode != NULL)
		{ printf("%d", pNode->data);
		pNode = pNode->m_pNext; // 다음주소로 넘어간다
		}
	printf("\n");
}

int main(void)
{
	int m = 1;
	int n = 0;
	List list;
	list_init(&list);
	list_push_front(&list, 1);
	print_list(&list, NULL);
	Node* pNode = list.m_pHead;

	for (int i = 0; i < 20; i++)
	{
		//printf("%d st step\n", i);
		Node* pNode = list.m_pHead;
		//print_list(&list, NULL);
		while (pNode->m_pNext != NULL)
		{
			if (pNode->data == pNode->m_pNext->data)
			{
				m = m + 1;
				//print_list(&list, NULL);
				//printf("%d\n", m);
			}
			if (pNode->data != pNode->m_pNext->data)
			{
				list_insert(&list, pNode->m_pNext, m);

				if (m == 1) {
					//print_list(&list, NULL);
				}
				if (m != 1) {
					for (int n = 1; n < m; n++)
					{
						//print_list(&list, NULL);
						list_erase(&list, pNode->m_pPrev);
						//printf("%d\n", m);
					}

					m = 1;
				}
				pNode = pNode->m_pNext;
			}
			pNode = pNode->m_pNext;
		}

		if (pNode->m_pNext == NULL)
		{
			//printf("test\n");
			list_push_back(&list, m);

			if (m == 1) {
			}
			if (m != 1) {
				for (int n = 1; n < m; n++)
				{
					list_erase(&list, pNode->m_pPrev);
				}
				m = 1;
			}
		}
		print_list(&list, NULL);
	}


	system("PAUSE");

	return 0;
}