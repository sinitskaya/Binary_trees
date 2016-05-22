#include "bin_Search_tree.h"

BSearchTree:: BSearchTree()
{
	root = new Node(100);
}

BSearchTree:: BSearchTree(VT startkey)
{
	root = new Node(startkey);
}

BSearchTree:: BSearchTree(Node* root_)
{
	if(root_==0)
		throw exception ("root_=0");
	root = root_;
}

BSearchTree:: ~BSearchTree()
{
	delete root;
}
/*
BSearchTree:: BSearchTree(const Node* & node)
{
	Copy(node,root);
}*/

Node* BSearchTree:: FindKey(Node *root_, VT key1) //поиск с заданным ключом
{
	if(root_==0)
		//return NULL;
		throw exception ("root=0");

	while ((root_) && (root_->e.key != key1))
		if (key1 < root_->e.key)
			root_ = root_->left;
		else
			root_ = root_->right;
	return root_;
}

Node* BSearchTree:: FindMin(Node * root_)	//поиск мин элем
{
	if (root_ == 0)
		return NULL;
	while(root_->left)
		root_ = root_->left;
	return root_;
}

Node* BSearchTree:: FindMax(Node *root_)	//поиск макс элем
{
	if (root_ == 0)
		return NULL;
	while(root_->right)
		root_ = root_->right;
	return root_;
}

Node* BSearchTree:: FindNext(Node* node) //поиск следущего за заданным
{
	if (node == 0)
		return NULL;
	if (node->right!=0)
		return FindMin(node->right);

	while((node->parent) && (node->parent->right == node))
		node = node->parent;
	return node->parent;
}

Node* BSearchTree:: FindPred(Node* node)//left / max //поиск предыдущего за заданным
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

void BSearchTree:: Insert(Node* node)  /////вставка
{
	if(node == 0)
		throw exception ("node = 0");
	if (root == 0){			//есди дерево пустое
		root = node;
		return;
	}

	Node* x = root;
	Node* y = x;
	while(x!=0)
	{
		y = x;
		if (x->e.key <= node->e.key) //пойти в правое
			x = x->right;
		else
			x = x->left;			//пойти в левое
	}
	if (y->e.key <= node->e.key)
		y->right = node;
	else
		 y->left = node;
	node->parent = y;
}

/*
void BSearchTree :: Copy(Node const *root_, Node* tmp)
{
	if (root_ == 0)
		return;
	if(tmp == 0) { cout << "tmp = 0" << endl; return; }
	tmp->e.key = root_->e.key;
	tmp->e.v1 = root_->e.v1;
	tmp->e.v2 = root_->e.v2;

	if(root_->left !=0)
		tmp->left = new Node;
	else 
		tmp->left = 0;//////////
	if(root_->right != 0)
		tmp->right = new Node;
	else
		tmp->right = 0;//////////
	if(root_->parent != 0)
		tmp->parent = new Node;
	else 
		tmp->parent = 0;//////////
	Copy(root_->left, tmp->left);
	Copy(root_->right, tmp->right);
	Copy(root->parent, tmp->parent);
}*/

void BSearchTree:: DeleteRoot() //удаление корня
{
	if(root==0) throw exception ("root=0");
	Node * t = FindNext(root);
	if(t!=0)
	{
		Node *t1 = new Node(t->e.key);
		t1->e.v1 = t->e.v1;
		t1->e.v2 = t->e.v2;

		Delete(t, t->e.key);

		if(root->right!=0) 
			root->right->parent = t1;
		if(root->left!=0)
			root->left->parent = t1;//

		t1->left = root->left;
		t1->right = root->right;
		root = t1;
	}
	else
	{
		Node * t3 = FindPred(root);
		if(t3==0)
			delete root;
		else
		{
			cout << "Pred" << endl;
			Node *t1 = new Node(t3->e.key);
			t1->e.v1 = t3->e.v1;
			t1->e.v2 = t3->e.v2;

			Delete(t3, t3->e.key);

			if(root->right!=0)
				root->right->parent = t1;
			if(root->left!=0)
				root->left->parent = t1;//

			t1->left = root->left;
			t1->right = root->right;
			root = t1;
		}
	}
}
void BSearchTree:: Delete(Node* root_, VT key1) //удаление
{
	if(root_==0) throw exception ("delete root_=0");
	Node* x = FindKey(root_, key1);
	
	//list
	if(x == 0)
		return;
	if((x->left == 0) && (x->right == 0))
	{
		if(x->parent!=0)///
		{
			if(x->parent->right == x)
				x->parent->right = 0;
			else
				x->parent->left = 0;
			delete x;
			return;
		}///не корень
		else
		{
			DeleteRoot();
			return;
		}
	}//

	//1 потомок
	if((x->left==0) && (x->right!=0))
	{
		if(x->parent!=0) //new
		{
			Node* y = x->right;
			y->parent = x->parent;

			if(x->parent->right==x)//прав кот своего родителя
				x->parent->right = y;
			else
				x->parent->left = y;
			delete x;
			return;
		}
		//////////////////////new
		else
		{
			DeleteRoot();
			return;
		}
		///////////////////////////new
	}
	if((x->left!=0) && (x->right==0))
	{
		if(x->parent!=0) //new
		{
			Node* y = x->left;
			y->parent = x->parent;
			if(x->parent->left==x)//прав кот своего родителя
				x->parent->left = y;
			else
				x->parent->right = y;
			delete x;
			return;
		}
		else
		{
			DeleteRoot();
			return;
		}
	}//1 потомок

	//2 потомка
	Node* y = FindMin(x->right);
	x->e.key = y->e.key;
	y->parent->left = y->right;
	// у у нет правого потомка
	if(y->right!=0)
		y->right->parent = y->parent;
	delete y;
	//2 потомка
}

void BSearchTree:: Print(Node *root_) //печать //обход в прямом порядке
{
	if (root_ == 0)	return;
	cout << root_->e.key << " ";
	Print(root_->left);
	Print(root_->right);
}

void BSearchTree:: Print1(Node* root_) //печать //обход в ширину
{
	if(root_==0){	
		cout << "Дерево пусто" << endl;
		return; }
	
	queue<Node*> q;
	q.push(root_);
	while(!q.empty())
	{
		Node* tmp = q.front();
		//cout << "v1: " << tmp->e.v1 << "; ";
		//cout << "v2: " << tmp->e.v2 << "; ";
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

VT BSearchTree:: GetNodeKey(Node* node) //получить значение ключа
{
	return node->e.key; 
}