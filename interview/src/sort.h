#pragma once
#include "common.h"
class  SortAlgo{
	public:
		vector<int> data_;
	public:
		SortAlgo(vector<int> d){
			data_=d;
		}
		virtual void Sort()=0;
		void DisData(){
			cout<<"\n";
			for(auto& i:data_){
				cout<<i<<" ";
			}
			cout<<"\n";
		}
};

class Bubbling:public SortAlgo{
	
	public:
		Bubbling(vector<int> d):SortAlgo(d){};
		void Sort();
		
};

class ChooseSort:public SortAlgo{
	public:
		ChooseSort(vector<int> d):SortAlgo(d){cout<<"ChooseSort"<<"\n";};
		void Sort();
};

class InsertSort:public SortAlgo{
	public :
		InsertSort(vector<int> d):SortAlgo(d){cout<<"insert sort\n";};
		void Sort();
};

class QuickSort:public SortAlgo{
	public:
		QuickSort(vector<int> d):SortAlgo(d){cout<<"quick sort\n";};
		void Sort(){
			int l=data_.size();
			Quic(data_,0,l-1);
		};
		void Quic(vector<int>& d,int s,int e);
				
};

class CombineSort:public SortAlgo{
	public:
		CombineSort(vector<int> d):SortAlgo(d){cout<<"CombineSort\n";}
		void ParseProblem(vector<int>& d,int s,int e);
		void SlutionProblem(vector<int>& d,int s,int e);
		void Sort(){
			int l=data_.size();
			ParseProblem(data_,0,l-1);
		}
	
};

void TTQuic(vector<int>& d,int s,int e);
void TestS();



