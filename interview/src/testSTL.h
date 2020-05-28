#pragma once
#include "common.h"
class TestVector{
	private:
		vector<string> name;
		vector<int64_t> old;
	public:
		TestVector(vector<string> data);
		void Insert(vector<string> data1,int place);
		void Dis();
		void TestList();
		void TestDeque();
		void TestStack();
	
};
void TesSTL();





