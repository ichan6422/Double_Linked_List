#pragma once
#define LinkedList_list_h
#include "stdafx.h"

typedef struct _Node {
	//Node �Լ��� �����Ѵ�
	int data; 	//data ���� �ִ´�
	struct _Node* m_pNext;	//Node���� �ڿ� ������ ����� �ּҸ� ����Ű�� ������ m_pNext �� �����Ѵ�
	struct _Node* m_pPrev;	//Node���� �տ� ������ ����� �ּҸ� ����Ű�� ������ m_pNext �� �����Ѵ�
} Node; //Node��� �������´�

typedef struct _List {
	Node* m_pHead;   //List���� �Ǿ��� �ּҸ� ����Ű�� ������ m_pHead �� �����Ѵ�
	Node* m_pTail;   //List���� �ǵ��� �ּҸ� ����Ű�� ������ m_pTail �� �����Ѵ�
} List;


void list_init(List* pList);
void list_push_back(List* pList, int data);
void list_push_front(List* pList, int data);
void list_insert(List* pList, Node* rhs, int data);
Node* list_find(List* pList, int data);
void list_erase(List* pList, Node* pNode);
//�� �Լ��� �����Ѵ� 

Node *list_make_node(void);

