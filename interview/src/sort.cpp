#include "sort.h"
void Bubbling::Sort(){
	int l=data_.size();
	int buf;
	for(int i=l-1;i>0;i--){
		for(int j=1;j<=i;j++){
			if(data_[j-1]>data_[j]){
				buf=data_[j-1];
				data_[j-1]=data_[j];
				data_[j]=buf;
			}
		}
	}
}

void ChooseSort::Sort(){
	int l=data_.size();
	int index=0,buff;
	for(int i=l-1;i>0;i--){
		for(int j=1;j<=i;j++){
			if(data_[index]<data_[j]){
				index=j;
			}
		}
		buff=data_[index];
		data_[index]=data_[i];
		data_[i]=buff;
		index=0;				
	}
}

void InsertSort::Sort(){
	int l=data_.size();
	int index,buf;
	for(int i=1;i<l;i++){
		index=i-1;
		buf=data_[i];
		while(buf<data_[index] && index>=0){
			data_[index+1]=data_[index];
			index--;
		}
		data_[index+1]=buf;
	}
				
}

void QuickSort::Quic(vector<int>& d,int s,int e){
	if(s>e)
		return;
	int i=s,j=e;
	int buf=d[i];
	while(i<j){
		while(i<j){
			if(d[j]>buf){
				j--;
			}else{
				d[i]=d[j];
				break;
			}
		}
		while(i<j){
			if(d[i]<buf){
				i++;
			}else{
				d[j]=d[i];
				break;
			}
		}
	}
	d[i]=buf;
	Quic(d,s,i-1);
	Quic(d,i+1,e);
};
void CombineSort::ParseProblem(vector<int>& d,int s,int e){
	
	if(s>=e)
		return ;
	int m=(s+e)/2;
	ParseProblem(d,s,m);
	ParseProblem(d,m+1,e);
	SlutionProblem(d,s,e);
}

void CombineSort::SlutionProblem(vector<int>& d,int s,int e){

	int mid=(s+e)/2;
	int m=s,n;
	n=mid+1;
	vector<int> buf;
	while(m<=mid && n<=e){
		if(d[m]<d[n]){
			buf.emplace_back(d[m]);
			m++;
		}else{
			buf.emplace_back(d[n]);
			n++;
		}
		
	}
	while(m<=mid){
		buf.emplace_back(d[m]);
		m++;
	}
	
	while(n<=e){
		buf.emplace_back(d[n]);
		n++;
	}
	for(auto& iter:buf){
		d[s]=iter;
		s++;
		//cout<<iter<<" ";
	}
	
}


void TestS(){
	vector<int> d={55,100,12 ,223,1000000 ,10,1};
	//SortAlgo* opera=new Bubbling(d);
	//SortAlgo* opera=new ChooseSort(d);
	//SortAlgo* opera=new InsertSort(d);
	//SortAlgo* opera=new QuickSort(d);
	SortAlgo* opera=new CombineSort(d);
	
	opera->Sort();
	opera->DisData();
		
}
