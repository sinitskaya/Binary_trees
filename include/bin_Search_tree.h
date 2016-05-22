#pragma once
#include <iostream>
#include <queue>
using namespace std;
typedef float VT;

struct Edge
{
	VT key; // ves = key
	int v1; //вершина 1
	int v2; //вершина 2
};

class Node
{
public:
	int hight;
	Edge e;
	Node* right;
	Node* left;
	Node* parent;
	Node(VT key1)
	{
		e.key = key1;
		hight = 1;
		left = 0;
		right = 0;
		parent = 0;
	}
	Node(){}
	~Node(){}
};

class BSearchTree
{
private:
	Node *root;
public:
	BSearchTree();
	BSearchTree(VT startkey);
	BSearchTree(Node* root_);
	~BSearchTree();

	Node* FindKey(Node *root_, VT key1); //поиск с заданным ключом
	Node* FindMin(Node * node);			//поиск миним элем
	Node* FindMax(Node * node);			//поиск макс элем
	Node* FindNext(Node* node);			//поиск следущего за заданным
	Node* FindPred(Node* node);			//поиск предыдущего за заданным

	VT GetNodeKey(Node* node);					//получить значение ключа
	void Insert(Node* node);						//вставка
	void Delete(Node *root_ ,VT key1);			//удаление
	void DeleteRoot();		//удаление корня

	//void Copy(Node const *root_, Node* tmp);

	void Print(Node *root_);			//печать //обход в глубину в прямом порядке
	void Print1(Node *root_);			//печать //обход в ширину
	friend class BSearchTree_Queue;

	//BSearchTree(int s, Node* node);
	//BSearchTree(const Node* & node);
};