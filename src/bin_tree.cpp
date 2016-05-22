#include "bin_tree.h"

Tree:: Tree(Node * First)
{
	if(!First)
		throw exception ("first=0");
	first = First;
	//first->left = NULL;
	//first->right = NULL;
}

void Tree:: WorkaroundStart(Node *node) //обход в прямом порядке
{
	if (node == 0)	return;
	cout << node->key << " ";
	WorkaroundStart(node->left);
	WorkaroundStart(node->right);
}

void Tree:: WorkaroundEnd(Node *node) //обход в обратном порядке
{
	if (node == 0)	return;
	WorkaroundEnd(node->left);
	WorkaroundEnd(node->right);
	cout << node->key << " ";
}

void Tree:: WorkaroundSimmetr(Node *node) //симметричный обход
{
	if (node == 0)	return;
	WorkaroundSimmetr(node->left);
	cout << node->key << " ";
	WorkaroundSimmetr(node->right);
}

void Tree:: WorkaroudStartStack(Node* node)  //обход в прямом порядке
{
	if(!node)
		throw exception ("node=0");
	stack<Node*> s;
	s.push(node);
	while(!s.empty())
	{
		Node* tmp = s.top();
		cout << tmp->key << " ";
		s.pop();
		if (tmp->right!=0)
			s.push(tmp->right);
		if (tmp->left!=0)
			s.push(tmp->left);
	}
}

void Tree:: WorkaroundEndQueue(Node* node) //обход в ширину
{
	if(!node)
		throw exception ("node=0");
	queue<Node*> q;
	q.push(node);
	while(!q.empty())
	{
		Node* tmp = q.front();
		cout << tmp->key << " ";
		q.pop();
		if (tmp->left!=0)
			q.push(tmp->left);
		if (tmp->right!=0)
			q.push(tmp->right);
	}
}

void Tree:: WorkaroundSimmetr1(Node* node) //симметричный обход
{

}

Tree:: ~Tree()
{
	delete first;
}