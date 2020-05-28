#pragma once
#include "common.h"

typedef struct Node{
	int data=-1;
	struct Node* next=nullptr;
} *NODE;

NODE ListRevert(NODE node);
void DisList(NODE p);
void TestListRevert();








