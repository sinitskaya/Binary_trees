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

	Node* FindKey(Node* root, VT key1); //поиск с заданным ключом
	Node* FindMin(Node* root);			//поиск миним элем
	Node* FindMax(Node* root);			//поиск макс элем
	Node* FindNext(Node* node);			//поиск следущего за заданным
	Node* FindPred(Node* node);			//поиск предыдущего за заданным

	void Isert(Node* &root, Node* node);		//вставка
	void Delete(Node* root, int key1);			//удаление
	void Print(Node* root);						//печать
	VT GetNodeKey(Node* node);					//получить значение ключа
};