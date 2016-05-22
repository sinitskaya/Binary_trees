#pragma once
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
typedef int VT;

struct Node
{
	VT key;
	Node* right;
	Node* left;
	Node* parent;
};

class Tree
{
private:
	Node *first;
public:
	Tree (Node *First);
	~Tree();

	void WorkaroundStart(Node* node);		//обход в глубину в прямом порядке
	void WorkaroundEnd(Node* node);			//обход в глубину в обратном порядке
	void WorkaroundSimmetr(Node* node);		//симметричный обход в глубину
	void WorkaroudStartStack(Node* node);	//обход в глубину в прямом порядке
	void WorkaroundEndQueue(Node* node);	//обход в ширину
	void WorkaroundSimmetr1(Node* node);	//симметричный обход
};