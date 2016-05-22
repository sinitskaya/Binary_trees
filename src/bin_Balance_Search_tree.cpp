#include "bin_Balance_Search_tree.h"

int BSBalanceTree:: Hight(Node* p) //определение высоты
{
	if(p==0)
		return 0; //h=0
	return p->hight; //1,2, ..
}

int BSBalanceTree:: BalVal(Node* p) //баланс заданного узла
{
	int f = Hight(p->right)-Hight(p->left);
	return f;
}

void BSBalanceTree:: FixHight(Node* p) //пересчитать высоту заданного узла
{
	int hl = Hight(p->left);
	int hr = Hight(p->right);
	int max = hl;
	if (hr>max)
		max = hr;
	p->hight = max + 1;
}

Node* BSBalanceTree:: TurnRight(Node* p) // правый поворот вокруг узла p
{
	Node* q = p->left;
	p->left = q->right;
	q->right = p;
	FixHight(p);
	FixHight(q);
	return q;
}

Node* BSBalanceTree:: TurnLeft(Node* y) // левый поворот вокруг узла y
{
	Node* q = y->right;
	y->right = q->left;
	q->left = y;
	FixHight(y);
	FixHight(q);
	return q;
}

Node* BSBalanceTree:: Balance(Node* p) // балансировка узла p
{
	int bal = BalVal(p);
	FixHight(p);
	if(bal == 2) //высота правого поддерева > //hr>hl
	{
		if(BalVal(p->right) < 0)
			p->right = TurnRight(p->right);
		return TurnLeft(p);
	}
	if(bal == -2) //высота левого поддерева > //hl>hr
	{
		if(BalVal(p->left) > 0)
			p->left = TurnLeft(p->left);
		return TurnRight(p);
	}
	return p; // балансировка не нужна
}

Node* BSBalanceTree:: Insert(Node *root, Edge r) //вставка ребра
{// вставка ключа k в дерево с корнем root_
	if( !root ) 
		return new Node(r.key);
	if( r.key<root->e.key )
		root->left = Insert(root->left,r); //k
	else
		root->right = Insert(root->right,r);
	return Balance(root);
}

Node* BSBalanceTree:: Insert2(Node *root, VT k) //вставка ребра
{// вставка ключа k в дерево с корнем root_
	if(root == 0) 
		return new Node(k);
	if( k<root->e.key )
		root->left = Insert2(root->left,k); //k
	else
		root->right = Insert2(root->right,k);
	return Balance(root);
}

void BSBalanceTree:: Delete(Node* root, int key1)
{

}