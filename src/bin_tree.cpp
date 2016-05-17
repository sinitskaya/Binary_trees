#include "bin_tree.h"
void Tree:: WorkaroundStart(Node *node)
{
	if (node == 0)	return;
	cout << node->key << " ";
	WorkaroundStart(node->left);
	WorkaroundStart(node->right);
}
void Tree:: WorkaroundEnd(Node *node)
{
	if (node == 0)	return;
	WorkaroundEnd(node->left);
	WorkaroundEnd(node->right);
	cout << node->key << " ";
}
void Tree:: WorkaroundSimmetr(Node *node)
{
	if (node == 0)	return;
	WorkaroundSimmetr(node->left);
	cout << node->key << " ";
	WorkaroundSimmetr(node->right);
}
void Tree:: WorkaroudStartStack(Node* node)
{
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
void Tree:: WorkaroundEndQueue(Node* node)
{
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
void Tree:: WorkaroundSimmetr1(Node* node)
{

}
Tree:: Tree(Node * First)
{
	first = First;
	//first->left = NULL;
	//first->right = NULL;
}
Tree:: ~Tree()
{
	delete first;
}