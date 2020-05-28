#include "cycle.h"

void CycleDelet(vector<int>data,int pos,int M,int& ret){
	if (M==pos){
		cout<<"Error\n";
		ret=-1;
		return;
	}
	int len_dat=data.size();
	if(1==len_dat){
		ret=data[0];
		return;
	}
	int tem=0;
	tem=(M + pos-1)%len_dat;
	data.erase(data.begin()+tem);
	CycleDelet(data,tem%len_dat,M,ret);
		
}

void ImplateCycle(){
	int n=3;
	int m=5;
	int ret=0;
	vector<int> data;
	for(int i=0;i<n;i++){
		data.emplace_back(i);
	}
	CycleDelet(data,0,m,ret);
	cout<<"ImplateCycle:"<<ret<<"\n";
	
	
}


