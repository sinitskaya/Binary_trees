#include "bin_Search_tree.h"
//#include "bin_Balance_Search_tree.h"

int main()
{
	try{
	setlocale (0,"");
	Node *root = new Node;
	root->e.key = 10;
	root->left = NULL;
	root->right = NULL;
	root->parent = 0;
	BSearchTree *T = new BSearchTree (root);
	
	Node *t01 = new Node(5);
	Node *t02 = new Node(1);
	Node *t03 = new Node(3);
	Node *t04 = new Node(15);
	Node *t05 = new Node(20);
	Node *t06 = new Node(7);
	Node *t07 = new Node(8);
	Node *t08 = new Node(9);
	Node *t09 = new Node(25);
	Node *t10 = new Node(12);
	Node *t11 = new Node(13);
	Node *t12 = new Node(17);
	Node *t13 = new Node(18);
	Node *t14 = new Node(23);
	Node *t15 = new Node(24);
	Node *t16 = new Node(25);
	Node *t17 = new Node(30);
	
	Node *t18 = new Node(13);
	Node *t19 = new Node(13);
	Node *t20 = new Node(13);
	T->Insert(t01);
	T->Insert(t02);
	T->Insert(t03);
	T->Insert(t04);
	T->Insert(t06);
	T->Insert(t07);
	T->Insert(t08);
	T->Insert(t09);
	T->Insert(t10);
	T->Insert(t11);
	T->Insert(t12);
	T->Insert(t13);
	T->Insert(t14);
	T->Insert(t15);
	T->Insert(t16);
	T->Insert(t17);
	T->Print(root);

	Node *t1 = new Node(10);
	//node *t2 = new node(12);
	//node *t3 = new node(1);
	//insert(t1,10);
	//Node* rtt = new Node(10);
	cout << endl << "BSBalanceTree " << endl;
/*	BSBalanceTree *TT = new BSBalanceTree(t1);
	TT->Insert2(t1,5);
	TT->Insert2(t1,15);
	TT->Insert2(t1,1);
	TT->Insert2(t1,7);
	TT->Insert2(t1,12);
	TT->Insert2(t1,17);
	TT->Insert2(t1,30);
	TT->Insert2(t1,18);
	TT->Insert2(t1,3);
	TT->Insert2(t1,8);
	TT->Insert2(t1,9);
	TT->Insert2(t1,13);
	TT->Insert2(t1,25);
	TT->Insert2(t1,24);
	TT->Insert2(t1,23);
	TT->Print(t1);*/
	cout << endl << "BSBalanceTree " << endl;
	/*root->left->e.key = 2;
	root->right = new Node;
	root->right->e.key = 8;
	
	//Node *(*rooT) = *root;
	Node **rooT = new Node*[1];
	*rooT = root;

	Node *t1 = new Node;
	t1 = root->right;
	t1->left = new Node;
	t1->left->e.key = 7;
	t1->left->left = NULL;
	t1->left->right = NULL;
	t1->right = new Node;
	t1->right->e.key = 9;
	t1->right->left = NULL;
	t1->right->right = NULL;

	Node *t2 = new Node;
	t2 = root->left;
	t2->left = new Node;
	t2->left->e.key = 0;
	t2->right = new Node;
	t2->right->e.key = 4;

	Node *t3 = new Node;
	t3 = t2->left;
	t3->left = NULL;
	t3->right = new Node;
	t3->right->e.key = 1;
	t3->right->right = NULL;
	t3->right->left = NULL;

	Node *t4 = new Node;
	t4 = t2->right;
	t4->left = NULL;
	t4->right = new Node;
	t4->right->e.key = 5;
	t4->right->right = NULL;
	t4->right->left = NULL;

	BSearchTree *T = new BSearchTree(root);
	cout << "Обход в прямом порядке:" << endl;//+
	T->Print(root); cout << endl << endl;
	
	cout << "Обход в ширину:" << endl;//+
	T->Print1(root); cout << endl << endl;

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
	
	Node *w1 = new Node;
	w1->e.key = 12;
	w1->right = NULL;
	w1->left = NULL;

	cout << "T:" << endl;
	T->Print1((root));
	T->Isert(root,w1);
	cout << "T:" << endl;
	T->Print1(root);


	Node * root1 = new Node;
	Node *w2 = new Node;
	w2->e.key = 12;
	w2->right = NULL;
	w2->left = NULL;
	*/
	//T->Copy(w2,root1);
	//T->Copy(root, root1);
	cout << "T: " << endl;
	T->Print1(root);
	//int * p1 = new int;
	//int ** p2 = new int*[1];
	//*p2 = p1;
	//int kj=0;
	}
	catch(exception &e)
	{
		cout << e.what() << endl;
		return 0;
	}
	return 0;
}