#include "bin_tree.h"
#include <gtest.h>


TEST(Tree, can_create_bin_tree)
{
	Node *t4 = new Node;
	t4->left = NULL;
	t4->right = NULL;
	ASSERT_NO_THROW(Tree *t = new Tree (t4));
}
//////////////////////////////////
/*TEST(Disjoint_set, cant_create_disjoint_set_with_negative_size)
{
	ASSERT_ANY_THROW(Disjoint_set set(-2));
}
///////////////////////////////////
TEST(Disjoint_set, can_create_Singleton)
{
	Disjoint_set set(5);
	ASSERT_NO_THROW(set.CreateSingleton(1));
}

TEST(Disjoint_set, cant_create_Singleton_with_x_less_then_0)
{
	Disjoint_set set;
	ASSERT_ANY_THROW(set.CreateSingleton(-1));
}*/