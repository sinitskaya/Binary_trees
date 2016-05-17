#include "bin_Search_tree.h"
BSearchTree:: BSearchTree()
{
	root = new Node;
}

BSearchTree:: BSearchTree(Node* root)
{
	this->root = root;	
}

BSearchTree:: ~BSearchTree()
{
	delete root;
}

Node* BSearchTree:: FindKey(Node* root, VT key1) //����� � �������� ������
{
	while ((root) && (root->key != key1))
		if (key1 < root->key)
			root = root->left;
		else
			root = root->right;
	return root;
}

Node* BSearchTree:: FindMin(Node* root)	//����� ��� ����
{
	if (root == 0)
		return NULL;
	while(root->left)
		root = root->left;
	return root;
}

Node* BSearchTree:: FindMax(Node* root)	//����� ���� ����
{
	if (root == 0)
		return NULL;
	while(root->right)
		root = root->right;
	return root;
}

Node* BSearchTree:: FindNext(Node* node) //����� ��������� �� ��������
{
	if (node == 0)
		return NULL;
	if (node->right!=0)
		return FindMin(node->right);

	while((node->parent) && (node->parent->right == node))
		node = node->parent;
	return node ->parent;
}

Node* BSearchTree:: FindPred(Node* node)//left / max //����� ����������� �� ��������
{
	if (node == 0)
	{
		cout << "NULL";
		return NULL;
	}
	if (node->left!=0)
		return FindMax(node->left);

	while((node->parent) && (node->parent->left == node))
		node = node->parent;
	return node ->parent;
}

void BSearchTree:: Isert(Node* &root, Node* node)  /////�������
{
	if (root == 0)
	{
		root = node;
		return;
	}
	Node* x = root;
	Node* y;
	while(x!=0)
	{
		y = x;
		if (x->key<= node->key)
			x = x->right;
		else
			x = x->left;
		if (y->key<=node->key)
			y->right = node;
		else
			y->left = node;
		node->parent = y;
	}
}

void BSearchTree:: Delete(Node* root, int key1) //��������
{
	Node* x = FindKey(root, key1);
	
	//list
	if(x == 0)
		return;
	if((x->left == 0) && (x->right == 0))
	{
		if(x->parent->right == x)
			x->parent->right = 0;
		else
			x->parent->left = 0;
		delete x;
		return;
	}//

	//1 �������
	if((x->left==0) && (x->right!=0))
	{
		Node* y = x->right;
		y->parent = x->parent;
		if(x->parent->right==x)//���� ��� ������ ��������
			x->parent->right = y;
		else
			x->parent->left = y;
		delete x;
		return;
	}
	if((x->left!=0) && (x->right==0))
	{
		Node* y = x->left;
		y->parent = x->parent;
		if(x->parent->left==x)//���� ��� ������ ��������
			x->parent->left = y;
		else
			x->parent->right = y;
		delete x;
		return;
	}//1 �������

	//2 �������
	Node* y = FindMin(x->right);
	x->key = y->key;
	y->parent->left = y->right;
	// � � ��� ������� �������
	if(y->right!=0)
		y->right->parent = y->parent;
	delete y;
	//2 �������
}

void BSearchTree:: Print(Node* root) //������
{
	if (root == 0)	return;
	cout << root->key << " ";
	Print(root->left);
	Print(root->right);
}

VT BSearchTree:: GetNodeKey(Node* node) //�������� �������� �����
{
	return node->key; 
}