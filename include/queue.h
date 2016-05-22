#pragma once
#include "bin_Search_tree.h"

class Queue 
{
public:
	
	virtual void SetQsize(int s) = 0;
	virtual int GetQsize(void) = 0;
	
	virtual void Pop() = 0;						//������� �� ������(� ��� ������)
	virtual Edge Top() = 0;						//������� ����� ��� ��������
	
	virtual void Insert(Edge n, int i) = 0;		//������� �����
	virtual int IsEmpty() = 0;
	////void Print();					//����� �������
	
	//Queue& operator =(const Queue& q);
	//int operator ==(const Queue &q)const;
	//int operator !=(const Queue &q)const;
	
	virtual void print1() = 0;		//����� �� ������� �����
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

	virtual void Pop();						//������� �� ������(� ��� ������)
	Edge Top();						//�������  ��� ��������

	virtual void Insert(Node * node);			//������� node
	int IsEmpty();
	//void Print();					//����� �������

	void print1();		//����� �� ������� �����
	void print2();		// � ������
};
