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

	void WorkaroundStart(Node* node);		//����� � ������� � ������ �������
	void WorkaroundEnd(Node* node);			//����� � ������� � �������� �������
	void WorkaroundSimmetr(Node* node);		//������������ ����� � �������
	void WorkaroudStartStack(Node* node);	//����� � ������� � ������ �������
	void WorkaroundEndQueue(Node* node);	//����� � ������
	void WorkaroundSimmetr1(Node* node);	//������������ �����
};