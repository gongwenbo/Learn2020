#include "coin2.h"
void Choice(int n,int layer,int& ret){
	if(n==0){
		ret++;
		return;
	}else if(n<0){
		return;
	}
	for(int i=layer;;i++){
		int money=pow(2,i);
		if(money>n)
			break;		
		Choice(n-money,i+1,ret);
		Choice(n-2*money,i+1,ret);
	}
			
}

void CanPair(int a,int b,int A,int B,int&ret){
	while(a<A){
		a*=2;
		b*=2;
		ret++;
	}
	if(a==A && b==B){
			return ;
	}else{
		a/=2;
		b/=2;
		ret--;
	}

	while(a<A){
		a+=1;
		b+=1;
		ret++;
	}		
	if(a==A && b==B){
			return ;
	}else{
		ret=-1;
	}
}
void Transcoder(vector<int> data,int& ret){
	std::sort(data.begin(),data.end());
	if(data.size()!=4)
		return ;
	int a=data[0];
	int b=data[1];
	int A=data[2];
	int B=data[3];
	CanPair(a,b,A,B,ret);
	if(ret<0){
		ret=0;
		CanPair(a,A,b,B,ret);
	}	
}

void TestCoin2(){
	int ret=0;
	Choice(6,0,ret);
	cout<<"TestCoin2:"<<ret<<"\n";
	vector<int> d={100,1000,202,2002};
	ret=0;
	Transcoder(d,ret);
	cout<<"Transcoder:"<<ret<<"\n";
}