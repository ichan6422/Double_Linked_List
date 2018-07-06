#pragma once
#define LinkedList_list_h
#include "stdafx.h"

typedef struct _Node {
	//Node 함수를 선언한다
	int data; 	//data 값을 넣는다
	struct _Node* m_pNext;	//Node에서 뒤에 나오는 노드의 주소를 가리키는 포인터 m_pNext 를 선언한다
	struct _Node* m_pPrev;	//Node에서 앞에 나오는 노드의 주소를 가리키는 포인터 m_pNext 를 선언한다
} Node; //Node라고 별명짓는다

typedef struct _List {
	Node* m_pHead;   //List에서 맨앞의 주소를 가리키는 포인터 m_pHead 를 선언한다
	Node* m_pTail;   //List에서 맨뒤의 주소를 가리키는 포인터 m_pTail 를 선언한다
} List;


void list_init(List* pList);
void list_push_back(List* pList, int data);
void list_push_front(List* pList, int data);
void list_insert(List* pList, Node* rhs, int data);
Node* list_find(List* pList, int data);
void list_erase(List* pList, Node* pNode);
//각 함수를 선언한다 

Node *list_make_node(void);

