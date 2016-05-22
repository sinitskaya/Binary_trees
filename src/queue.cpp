#include "queue.h"

BSearchTree_Queue:: BSearchTree_Queue(int s, Node* node)
{
	if (s<=0) 
		throw exception ("Size<=0");
	if (node==0)
		throw exception ("node=0");
	qsize = s;
	search_tree = new BSearchTree (node);
}

BSearchTree_Queue:: ~BSearchTree_Queue(){
	delete search_tree;
}

void BSearchTree_Queue:: Insert(Node *node)      //вставка ребра
{
	if(node==0)
		throw exception ("node=0");
	search_tree->Insert(node);
	qsize++;
}

void BSearchTree_Queue:: Pop()			//изьятие из начала(с мин меткой)
{
	if (qsize==0)
		return;
	Node *p = search_tree->FindMin(search_tree->root);
	//cout << "delete key:"<<p->e.key << endl;
	search_tree->Delete(search_tree->root,p->e.key);
	qsize--;
}

int BSearchTree_Queue:: IsEmpty()
{
	if (qsize==0)   
		return 1;
	else
		return 0;
}

////////////////////////////////////////////////
void BSearchTree_Queue:: print1()		//вывод со списком ребер
{
	if(IsEmpty())
	{
		cout << "Пусто" << endl;
		return;
	}
	search_tree->Print1(search_tree->root);
}

void BSearchTree_Queue:: print2()
{
	if(IsEmpty()){	
		cout << "Пусто" << endl;
		return;
	}
	
	queue<Node*> q;
	q.push(search_tree->root);
	while(!q.empty())
	{
		Node* tmp = q.front();
		cout << "v1: " << tmp->e.v1 << "; ";
		cout << "v2: " << tmp->e.v2 << "; ";
		cout << "ves: " << tmp->e.key << endl;

		q.pop();
		//левое поддерево
		if (tmp->left!=0)
			q.push(tmp->left);
		//правое поддерево
		if (tmp->right!=0)
			q.push(tmp->right);
	}
}
////////////////////////////////////////////////
Edge BSearchTree_Queue:: Top()			//изьятие 
{
	Node *p = search_tree->FindMin(search_tree->root);
	Edge e; e.key = p->e.key;
	e.v1 = p->e.v1;
	e.v2 = p->e.v2;
	return 	e;
}
///////////////////////////////////////////////
int BSearchTree_Queue:: GetQsize(void){
	return qsize;
}

void BSearchTree_Queue:: SetQsize(int s)
{
	if(s<0)
		throw exception ("gsize<0");
	qsize = s;
}