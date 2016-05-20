#pragma once
#include "bin_Search_tree.h"

class BSBalanceTree: public BSearchTree
{
public:
	BSBalanceTree(): BSearchTree(){}
	BSBalanceTree(Node *root): BSearchTree(root){}
	//~BSBalanceTree();

	int Hight(Node* p);			 //определение высоты
	int BalVal(Node* p);		 //баланс заданного узла
	void FixHight(Node* p);		 //пересчитать высоту заданного узла

	Node* TurnRight(Node* p);	 // правый поворот вокруг узла p
	Node* TurnLeft(Node* y);	 // левый поворот вокруг узла y
	Node* Balance(Node* p);		 // балансировка узла p

	Node* Insert(Node *root, Edge r);	//вставка ребра
	Node* Insert2(Node *root, VT k);		//вставка с задданым ключом
	void Delete(Node* root, int key1);
};