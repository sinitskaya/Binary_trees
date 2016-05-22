#include "queue.h"
#include <gtest.h>

TEST(Queue, can_create_queue)
{
	Node *t1 = new Node(10);
	ASSERT_NO_THROW(BSearchTree_Queue *que = new BSearchTree_Queue(10,t1));
}

TEST(Queue, cant_create_queue_wiht_null_size)
{
	Node *t1 = new Node(10);
	ASSERT_ANY_THROW(BSearchTree_Queue *que = new BSearchTree_Queue(0,t1));
}

TEST(Queue, cant_create_queue_with_negative_size)
{
	Node *t1 = new Node(10);
	ASSERT_ANY_THROW(BSearchTree_Queue *que = new BSearchTree_Queue (-7,t1));
}

TEST(Queue, cant_create_queue_with_null_pointer)
{
	ASSERT_ANY_THROW(BSearchTree_Queue *que = new BSearchTree_Queue(7,0));
}
////////////////////////////////////////////////Insert
TEST(Queue, can_insert_elem)
{
	Node * t1 = new Node(10);
	Node *t2 = new Node(1);
	BSearchTree_Queue *que = new BSearchTree_Queue(1,t1);
	ASSERT_NO_THROW(que->Insert(t2));
}

TEST(Queue, size_more_in_insert_elem)
{
	Node * t1 = new Node(10);
	Node *t2 = new Node(1);
	BSearchTree_Queue *que = new BSearchTree_Queue(1,t1);
	que->Insert(t2);
	EXPECT_EQ(2,que->GetQsize());
}
///////////////////////////////////////////Pop
TEST(Queue, can_Pop_elem)
{
	Node * t1 = new Node(10);
	Node *t2 = new Node(1);
	BSearchTree_Queue *que = new BSearchTree_Queue(1,t1);
	que->Insert(t2);
	ASSERT_NO_THROW(que->Pop());
}

TEST(Queue, size_less_in_Pop)
{
	Node * t1 = new Node(10);
	Node *t2 = new Node(1);
	BSearchTree_Queue *que = new BSearchTree_Queue(1,t1);
	que->Insert(t2);
	que->Pop();
	EXPECT_EQ(1,que->GetQsize());
}
/////////////////////////////////Top
TEST(Queue, can_Top_elem)
{
	Node * t1 = new Node(10);
	Node *t2 = new Node(1);
	BSearchTree_Queue *que = new BSearchTree_Queue(1,t1);
	que->Insert(t2);
	ASSERT_NO_THROW(que->Top());
}

TEST(Queue, size_not_change_in_Top)
{
	Node * t1 = new Node(10);
	Node *t2 = new Node(1);
	BSearchTree_Queue *que = new BSearchTree_Queue(1,t1);
	que->Insert(t2);
	que->Top();
	EXPECT_EQ(2,que->GetQsize());
}
////////////////////////////////IsEmpty
TEST(Queue, can_IsEmpty)
{
	Node * t1 = new Node(10);
	Node *t2 = new Node(1);
	BSearchTree_Queue *que = new BSearchTree_Queue(1,t1);
	que->Insert(t2);
	ASSERT_NO_THROW(que->IsEmpty());
}

TEST(Queue, return_1_when_IsEmpty)
{
	Node * t1 = new Node(10);
	Node *t2 = new Node(1);
	BSearchTree_Queue *que = new BSearchTree_Queue(1,t1);
	que->Insert(t2);
	que->Pop();
	que->Pop();
	EXPECT_EQ(1,que->IsEmpty());
}

TEST(Queue, return_0_when_not_IsEmpty)
{
	Node * t1 = new Node(10);
	Node *t2 = new Node(1);
	BSearchTree_Queue *que = new BSearchTree_Queue(1,t1);
	que->Insert(t2);
	que->Pop();
	EXPECT_EQ(0,que->IsEmpty());
}
////////////////////////////////////////print1
TEST(Queue, can_print1)
{
	Node * t1 = new Node(10);
	Node *t2 = new Node(1);
	BSearchTree_Queue *que = new BSearchTree_Queue(1,t1);
	que->Insert(t2);
	que->Pop();
	ASSERT_NO_THROW(que->print1());
}

TEST(Queue, can_print1_null_que)
{
	Node * t1 = new Node(10);
	BSearchTree_Queue *que = new BSearchTree_Queue(1,t1);
	que->Pop();
	ASSERT_NO_THROW(que->print1());
}
////////////////////////////////////////print2
TEST(Queue, can_print2)
{
	Node * t1 = new Node(10);
	Node *t2 = new Node(1);
	BSearchTree_Queue *que = new BSearchTree_Queue(1,t1);
	que->Insert(t2);
	que->Pop();
	ASSERT_NO_THROW(que->print2());
}

TEST(Queue, can_print2_null_que)
{
	Node * t1 = new Node(10);
	BSearchTree_Queue *que = new BSearchTree_Queue(1,t1);
	que->Pop();
	ASSERT_NO_THROW(que->print2());
}
/////////////////////////////////////////GetQsize
TEST(Queue, can_GetQsize)
{
	Node * t1 = new Node(10);
	Node *t2 = new Node(1);
	BSearchTree_Queue *que = new BSearchTree_Queue(1,t1);
	que->Insert(t2);
	que->Pop();
	ASSERT_NO_THROW(que->GetQsize());
}

TEST(Queue, can_GetQsize_correct)
{
	Node * t1 = new Node(10);
	BSearchTree_Queue *que = new BSearchTree_Queue(1,t1);
	que->Pop();
	EXPECT_EQ(0,que->GetQsize());
}
//////////////////////////////////////SetSize
TEST(Queue, can_SetQsize)
{
	Node * t1 = new Node(10);
	Node *t2 = new Node(1);
	BSearchTree_Queue *que = new BSearchTree_Queue(1,t1);
	que->Insert(t2);
	ASSERT_NO_THROW(que->SetQsize(2));
}

TEST(Queue, cant_Set_negative_size)
{
	Node * t1 = new Node(10);
	Node *t2 = new Node(1);
	BSearchTree_Queue *que = new BSearchTree_Queue(1,t1);
	que->Insert(t2);
	ASSERT_ANY_THROW(que->SetQsize(-2));
}

TEST(Queue, can_SetQsize_correct)
{
	Node * t1 = new Node(10);
	Node *t2 = new Node(1);
	BSearchTree_Queue *que = new BSearchTree_Queue(1,t1);
	que->Insert(t2);
	que->SetQsize(2);
	EXPECT_EQ(2,que->GetQsize());
}