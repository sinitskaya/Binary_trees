#pragma once
#include <iostream>
#include <queue>
using namespace std;
typedef float VT;

struct Edge
{
	VT key; // ves = key
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
private:
	Node *root;
public:
	BSearchTree();
	BSearchTree(VT startkey);
	BSearchTree(Node* root_);
	~BSearchTree();

	Node* FindKey(Node *root_, VT key1); //����� � �������� ������
	Node* FindMin(Node * node);			//����� ����� ����
	Node* FindMax(Node * node);			//����� ���� ����
	Node* FindNext(Node* node);			//����� ��������� �� ��������
	Node* FindPred(Node* node);			//����� ����������� �� ��������

	VT GetNodeKey(Node* node);					//�������� �������� �����
	void Insert(Node* node);						//�������
	void Delete(Node *root_ ,VT key1);			//��������
	void DeleteRoot();		//�������� �����

	//void Copy(Node const *root_, Node* tmp);

	void Print(Node *root_);			//������ //����� � ������� � ������ �������
	void Print1(Node *root_);			//������ //����� � ������
	friend class BSearchTree_Queue;

	//BSearchTree(int s, Node* node);
	//BSearchTree(const Node* & node);
};