#pragma once
#include "bin_Search_tree.h"

class BSBalanceTree: public BSearchTree
{
public:
	BSBalanceTree(): BSearchTree(){}
	BSBalanceTree(Node *root): BSearchTree(root){}
	//~BSBalanceTree();

	int Hight(Node* p);			 //����������� ������
	int BalVal(Node* p);		 //������ ��������� ����
	void FixHight(Node* p);		 //����������� ������ ��������� ����

	Node* TurnRight(Node* p);	 // ������ ������� ������ ���� p
	Node* TurnLeft(Node* y);	 // ����� ������� ������ ���� y
	Node* Balance(Node* p);		 // ������������ ���� p

	Node* Insert(Node *root, Edge r);	//������� �����
	Node* Insert2(Node *root, VT k);		//������� � �������� ������
	void Delete(Node* root, int key1);
};