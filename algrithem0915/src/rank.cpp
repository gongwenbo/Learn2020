#include "rank.h"
void Test(){
	cout<<"Hello Word!\n";
}


Sort::Sort(vector<int> d){
	data_=d;
}
void Sort::BubbindRank(){
	int sum=data_.size()-1;
	int buf=0;
	for(int i=sum;i>=0;i--){
		for(int j=1;j<=i;j++){
			if(data_[j]<data_[j-1]){
				buf=data_[j];
				data_[j]=data_[j-1];
				data_[j-1]=buf;
			}
		}
	}
}

void Sort::Dis(){
	for(auto& iter:data_){
		cout<<iter<<"\n";
	}
}

void Sort::DirecInsert(){
	int sum=data_.size()-1;
	for(int i=1;i<=sum;i++){
		int j=i-1;
		int buf=data_[i];
		while(j>=0){
			if(data_[j]>buf){
				data_[j+1]=data_[j];
			}else{
				break;
			}
			j--;
		}
		data_[j+1]=buf;
		

	}
}

void Sort::SelectSort(){
	int sum=data_.size()-1;
	int index=0,buf=0;
	for(int i=sum;i>=0;i--){
		for(int j=0;j<=i;j++){
			if(data_[index]<data_[j]){
				index=j;
			}
		}
		buf=data_[i];
		data_[i]=data_[index];
		data_[index]=buf;
		index=0;
	}
}


void Sort::QuickSort(vector<int>& data,int left,int right){
	if(left>=right)
		return;

	int l=left,r=right;
	int buf=data[left];

	while(left<right){
		while(left<right){
			if(buf<data[right]){
				right--;
			}else{
				data[left]=data[right];
				left++;
				break;
			}
		}
		
		while(left<right){
			if(buf>data[left]){
				left++;
			}else{
				data[right]=data[left];
				right--;
				break;
			}
		}				
		
	}
	data[left]=buf;
	
	QuickSort(data,l,left-1);
	QuickSort(data,left+1,r);
	

}

void Sort::TestQuick(){
	QuickSort(data_,0,data_.size()-1);
}


void Sort::BackSortCombine(vector<int>& data,int L1,int R1,int L2,int R2){
	vector<int> buf;
	int pose=L1;
	
	while(L1<=R1 && L2<=R2){
		if(data[L1]<data[L2]){
			buf.emplace_back(data[L1]);
			L1++;
		}else{
			buf.emplace_back(data[L2]);
			L2++;
		}
	}
	while(L1<=R1){
		buf.emplace_back(data[L1]);
		L1++;				
	}
	while(L2<=R2){
		buf.emplace_back(data[L2]);
		L2++;					
	}
	for(auto& inter:buf){
		data[pose]=inter;
		pose++;
	}
	
}
void Sort::Segment(vector<int>& d,int l,int r){
	if(l>=r)
		return;
	int m=(l+r)/2;
	Segment(d,l,m);
	Segment(d,m+1,r);
	BackSortCombine(d,l,m,m+1,r);			
}
void Sort::TestCombineSort(){
	Segment(data_,0,data_.size()-1);
}



void Sort::Swap(int& a,int& b){
	int buf=a;
	a=b;
	b=buf;
}
void Sort::HeadAdaper(vector<int>& data,int len,int index){
	int left=2*index+1,right=2*index+2;
	int max=index;
	if(len>left && data[max]<data[left])
		max=left;
	if(len>right && data[max]<data[right])
		max=right;
	if(max!=index){
		Swap(data[max],data[index]);
		HeadAdaper(data,len,max);				
	}
	
}

void Sort::HeapSort(){
	int sum=data_.size();
	for(int i=sum/2-1;i>=0;i--){
		HeadAdaper(data_,sum,i);
	}
	
	for(int j=sum-1;j>=0;j--){
		Swap(data_[0],data_[j]);
		HeadAdaper(data_,j,0);
	}
	
}
			



void Sort::BaseSolution(int exp){
	int sum=data_.size();
	vector<int> pose(10,0);
	vector<int> buf(100,0);
	for(int i=0;i<sum;i++){
		pose[(data_[i]/exp)%10]++;
	}
	for(int j=1;j<10;j++){
		pose[j]+=pose[j-1];
	}
	
	for(int k=0;k<sum;k++){
		buf[pose[(data_[k]/exp)%10]-1]=data_[k];
		pose[(data_[k]/exp)%10]--;				
	}
	
	for(int m=0;m<sum;m++){
		data_[m]=buf[m];	
	}
	
}

void Sort::BaseSort(){
	int max=0,sum=data_.size();
	
	for(int i=0;i<data_.size();i++){
		if(max<data_[i]){
			max=data_[i];
		}
			
	}
	for(int j=1;j<=max;j=10*j){
		BaseSolution(j);
	}
				
}


void TestRank(){
	vector<int> d={4,1,800,10002,9,100};
	vector<int> d1={4,1};
	auto star=make_shared<Sort>(d);
	//star->BubbindRank();
	//star->DirecInsert();
	//star->SelectSort();
	//star->TestQuick();
	//star->TestCombineSort();
	//star->HeapSort();
	star->BaseSort();
	
	star->Dis();
}


