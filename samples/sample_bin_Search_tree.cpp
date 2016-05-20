#include "bin_Search_tree.h"

int main()
{
	try{
	setlocale (0,"");
	Node *root = new Node();
	root->key = 6;
	root->left = new Node();
	root->left->key = 2;
	root->right = new Node;
	root->right->key = 8;

	Node *t1 = new Node;
	t1 = root->right;
	t1->left = new Node;
	t1->left->key = 7;
	t1->left->left = NULL;
	t1->left->right = NULL;
	t1->right = new Node;
	t1->right->key = 9;
	t1->right->left = NULL;
	t1->right->right = NULL;

	Node *t2 = new Node;
	t2 = root->left;
	t2->left = new Node;
	t2->left->key = 0;
	t2->right = new Node;
	t2->right->key = 4;

	Node *t3 = new Node;
	t3 = t2->left;
	t3->left = NULL;
	t3->right = new Node;
	t3->right->key = 1;
	t3->right->right = NULL;
	t3->right->left = NULL;

	Node *t4 = new Node;
	t4 = t2->right;
	t4->left = NULL;
	t4->right = new Node;
	t4->right->key = 5;
	t4->right->right = NULL;
	t4->right->left = NULL;

	BSearchTree *T = new BSearchTree(root);
	cout << "Обход в прямом порядке:" << endl;//+
	T->Print(root); cout << endl << endl;
	
	Node* t = T->FindKey(root,6);
	VT k = T->GetNodeKey(t);
	cout << "Найденный ключ: " << k << endl;

	t = T->FindMax(root);
	k = T->GetNodeKey(t);
	cout << "FindMAX: " << k << endl;

	t = T->FindMin(root);
	k = T->GetNodeKey(t);
	cout << "FindMIN: " << k << endl;
	
	t = T->FindNext(root);
	k = T->GetNodeKey(t);
	cout << "FindNEXT: " << k << endl;
	
	t = T->FindPred(root);
	k = T->GetNodeKey(t);
	cout << "FindPRED: " << k << endl;//не бпд
	
	}
	catch(exception &e)
	{
		cout << e.what() << endl;
		return 0;
	}
	return 0;
}