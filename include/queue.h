#pragma once
#include "bin_Search_tree.h"

class Queue 
{
public:
	
	virtual void SetQsize(int s) = 0;
	virtual int GetQsize(void) = 0;
	
	virtual void Pop() = 0;						//изьятие из начала(с мин меткой)
	virtual Edge Top() = 0;						//изьятие ребра без удаления
	
	virtual void Insert(Edge n, int i) = 0;		//вставка ребра
	virtual int IsEmpty() = 0;
	////void Print();					//вывод массива
	
	//Queue& operator =(const Queue& q);
	//int operator ==(const Queue &q)const;
	//int operator !=(const Queue &q)const;
	
	virtual void print1() = 0;		//вывод со списком ребер
};

class BSearchTree_Queue : public BSearchTree
{
private:

	int qsize;
	BSearchTree  *search_tree;
public:

	BSearchTree_Queue(int s, Node* node);

	~BSearchTree_Queue();

	virtual void SetQsize(int s);
	virtual int GetQsize(void);

	virtual void Pop();						//изьятие из начала(с мин меткой)
	Edge Top();						//изьятие  без удаления

	virtual void Insert(Node * node);			//вставка node
	int IsEmpty();
	//void Print();					//вывод массива

	void print1();		//вывод со списком ребер
	void print2();		// в ширину
};
