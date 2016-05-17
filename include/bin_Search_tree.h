#include "node.h"
#include <iostream>
using namespace std;
typedef float VT;

struct Node
{
	VT key;
	Node* right;
	Node* left;
	Node* parent;
	//Node();
	//~Node();
};
class BSearchTree
{
private:
		Node *root;
public:
	//Node *root;
	BSearchTree();
	BSearchTree(Node* root);
	~BSearchTree();

	Node* FindKey(Node* root, VT key1); //����� � �������� ������
	Node* FindMin(Node* root);			//����� ����� ����
	Node* FindMax(Node* root);			//����� ���� ����
	Node* FindNext(Node* node);			//����� ��������� �� ��������
	Node* FindPred(Node* node);			//����� ����������� �� ��������

	void Isert(Node* &root, Node* node);		//�������
	void Delete(Node* root, int key1);			//��������
	void Print(Node* root);						//������
	VT GetNodeKey(Node* node);					//�������� �������� �����
};