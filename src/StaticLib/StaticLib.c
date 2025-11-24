#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


// ノードを初期化
void initialize_node(node* p, int val)
{
	p->pNext = NULL;
	p->pPrev = NULL;
	p->data = val;
}

// リストを初期化
void initialize_list(list* l)
{
	l->header = NULL;
	l->footer = NULL;
}


// 先頭にデータを追加
void push_front(list* l, node* p)
{
	if (p == NULL) return;
	p->pNext = l->header;
	p->pPrev = NULL;
	if (p->pNext != NULL) 
	{
		p->pNext->pPrev = p;
	}
	else {
		l->footer = p;
	}
	l->header = p;
}


// 末尾にデータを追加
void push_back(list* l, node* p)
{
	if (p == NULL) return;
	p->pPrev = l->footer;
	p->pNext = NULL;
	if (p->pPrev != NULL)
	{
		p->pPrev->pNext = p;
	}
	else {
		l->header = p;
	}
	l->footer = p;
}

// pのノードを削除
void remove_node(list* l, node* p)
{
	if (p == NULL) return;
	if (p->pPrev != NULL) 
	{
		p->pPrev->pNext = p->pNext;
	}
	else {
		l->header = p->pNext;
	}
	if (p->pNext != NULL) 
	{
		p->pNext->pPrev = p->pPrev;
	}
	else {
		l->footer = p->pPrev;
	}
	p->pNext = NULL;
	p->pPrev = NULL;
}

// pの次のノードを削除
void remove_next(list* l, node* p)
{
	if (p == NULL)
	{
		return;
	}
	node* x = p->pNext;
	if (x == NULL) return;
	p->pNext = x->pNext;
	if (x->pNext != NULL) 
	{
		x->pNext->pPrev = p;
	}
	else {
		l->footer = p;
	}
	x->pNext = NULL;
	x->pPrev = NULL;
}

// pの前のノードを削除
void remove_prev(list* l, node* p)
{
	if (p == NULL) return;
	node* x = p->pPrev;
	if (x == NULL) return;
	p->pPrev = x->pPrev;
	if (x->pPrev != NULL) 
	{
		x->pPrev->pNext = p;
	}
	else {
		l->header = p;
	}
	x->pNext = NULL;
	x->pPrev = NULL;

}


// pの次のノードを取得
node* get_next(list* l, node* p)
{
	if (!p) return NULL;
	return p->pNext;

	return NULL;
}

// pの前のノードを取得
node* get_prev(list* l, node* p)
{
	if (!p) return NULL;
	return p->pPrev;

	return NULL;
}
