
////////////////////////////////////////////////Delete
TEST(BSearchTree, can_delete_bin_search_tree)
{
	Node *t4 = new Node(10);
	Node *t1 = new Node(1);
	Node *t2 = new Node(14);
	Node *t3 = new Node(18);
	
	BSearchTree *tr = new BSearchTree(t4);
	tr->Insert(t1);
	tr->Insert(t2);
	tr->Insert(t3);
	ASSERT_NO_THROW(tr->Delete(t4, 14));
}

TEST(BSearchTree, can_delete_first_bin_search_tree)
{
	Node *t4 = new Node(10);
	Node *t1 = new Node(1);
	Node *t2 = new Node(14);
	Node *t3 = new Node(18);
	
	BSearchTree *tr = new BSearchTree(t4);
	tr->Insert(t1);
	tr->Insert(t2);
	tr->Insert(t3);
	ASSERT_NO_THROW(tr->Delete(t4, 10));
}

TEST(BSearchTree, cannt_delete_with_null_point_in_bin_search_tree)
{
	Node *t3 = 0;
	ASSERT_ANY_THROW(tr->Delete(t3, 10));
}
//////////////////////////////////////////////////////////GetNodeKey
TEST(BSearchTree, can_GetNodeKey_in_bin_search_tree)
{
	Node *t4 = new Node(10);
	Node *t1 = new Node(1);
	Node *t2 = new Node(14);
	Node *t3 = new Node(18);
	BSearchTree *tr = new BSearchTree(t4);

	ASSERT_NO_THROW(tr->GetNodeKey(t4));
}

TEST(BSearchTree, can_GetNodeKey_in_bin_search_tree_correct)
{
	Node *t4 = new Node(10);
	Node *t1 = new Node(1);
	Node *t2 = new Node(14);
	Node *t3 = new Node(18);
	BSearchTree *tr = new BSearchTree(t4);

	EXCEPT_EQ(10,t4->GetNodeKey);
}