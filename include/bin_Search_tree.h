#pragma once
#include <iostream>
#include <queue>
using namespace std;
typedef int VT;

struct Edge
{
	VT key;
	int v1; //������� 1
	int v2; //������� 2
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
public:
	Node *root;

	BSearchTree();
	BSearchTree(Node* node);
	BSearchTree(const Node* & node);
	~BSearchTree();

	Node* FindKey(Node *root_, VT key1); //����� � �������� ������
	Node* FindMin(Node * node);			//����� ����� ����
	Node* FindMax(Node * node);			//����� ���� ����
	Node* FindNext(Node* node);			//����� ��������� �� ��������
	Node* FindPred(Node* node);			//����� ����������� �� ��������

	VT GetNodeKey(Node* node);					//�������� �������� �����
	void Insert(Node* node);						//�������
	void Delete(Node *root_ ,VT key1);			//��������
	
	void Copy(Node const *root_, Node* tmp);

	void Print(Node *root_);			//������ //����� � ������� � ������ �������
	void Print1(Node *root_);		//������ //����� � ������
};