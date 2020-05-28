#include "chocolate.h"
void Alloc(int N,int m,int M,int& ret){
	int s=m;
	for(int i=1;i<N;i++){
		if(0!=(m%2)){
			m=m/2+1;
		}else{
			m=m/2;
		}
		s+=m;
		if(s>M){
			ret=-1;
			return;
		}
	}
	ret=0;
}


void CacuMax(int N,int M,int& max){
	int ret=0;
	for(int i=1;i<=M;i++){
		Alloc(N,i,M,ret);
		if(0==ret){
			max=i;
		}else{
			break;
		}
	}
}

void TestChocolate(){
	int max=0;
	CacuMax(10,100,max);
	cout<<"TestChocolate: "<<max<<"\n";
	
}