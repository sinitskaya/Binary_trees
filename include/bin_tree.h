#include "node.h"
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
	//Node();
	//~Node();
};

class Tree
{
private:
public:
	Node *first;
	Tree (Node *First);
	~Tree();
	void WorkaroundStart(Node* node);//����� � ������ �������
	void WorkaroundEnd(Node* node);//����� � �������� �������
	void WorkaroundSimmetr(Node* node);//������������ �����
	void WorkaroudStartStack(Node* node);//
	void WorkaroundEndQueue(Node* node);//
	void WorkaroundSimmetr1(Node* node);//
};