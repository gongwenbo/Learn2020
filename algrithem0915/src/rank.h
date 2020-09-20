#pragma once
#include "common.h"
void Test();
class Sort{
	public:
		vector<int> data_;
	public:
		Sort(vector<int> d);
		void BubbindRank();
		void DirecInsert();
		void SelectSort();		
		void QuickSort(vector<int>& data,int left,int right);
		void TestQuick();
		void BackSortCombine(vector<int>& data,int L1,int R1,int L2,int R2);
		void Segment(vector<int>& d,int l,int r);
		void TestCombineSort();
		void Swap(int& a,int& b);
		void HeadAdaper(vector<int>& data,int len,int index);		
		void HeapSort();
		void BaseSolution(int exp);
		void BaseSort();
		
		
						
		void Dis();	
};

void TestRank();

