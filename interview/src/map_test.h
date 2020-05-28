#pragma once 
#include "common.h"

struct st_t
{
        int status;
        char bitset;
        short pdata;
        char errstr;
};
class ReadBlackTree{
	private:
		map<string,int64_t> student_;
		set<int> identify_;
	public:
		ReadBlackTree(map<string,int64_t> stu,set<int> id);
		void Dis();
		void TestSet();
		void TestArray();
		void TestForward();
		void TestTuple();
	
};

void TestRBTree();






