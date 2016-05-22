#include "bin_tree.h"

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

	Tree *T = new Tree(root);

	cout << "Обход в прямом порядке:" << endl;//+ 620 145 879
	T->WorkaroundStart(root); cout << endl << endl;

	cout << "Обход в обратном порядке:" << endl;//+ 105 427 986
	T->WorkaroundEnd(root); cout << endl << endl;

	cout << "Cимметричный обход:" << endl;//+ 012 456 789
	T->WorkaroundSimmetr(root); cout << endl << endl;

	cout << "Обход в прямом порядке с помощью СТЕКА:" << endl;//+ 620 145 879
	T->WorkaroudStartStack(root); cout << endl << endl;

	cout << "Обход в ширину с помощью ОЧЕРЕДИ:" << endl;//+ 628 047 915
	T->WorkaroundEndQueue(root); cout << endl << endl;

	cout << "Симметричный обход2:" << endl;
	T->WorkaroundSimmetr1(root); cout << endl << endl;
	
	
	}
	catch(exception &e)
	{
		cout << e.what() << endl;
		return 0;
	}
	return 0;
}