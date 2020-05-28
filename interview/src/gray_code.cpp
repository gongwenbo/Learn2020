#include "gray_code.h"
void CreateGray(int nbit,deque<deque<int>>& ret){
	deque<deque<int>> buf;

	if(1>=nbit)
		return;
	for(auto& i:ret){
		i.push_front(0);
		buf.emplace_back(i);
		i.pop_front();
	}
	std::reverse(ret.begin(),ret.end());
	for(auto& i:ret){
		i.push_front(1);
		buf.emplace_back(i);
		i.pop_front();
	}
	ret.clear();
	ret=buf;
	CreateGray(nbit-1,ret);	
}

void TestGray(){
	deque<int> b1={0};
	deque<int> b2={1};
	deque<deque<int>> ret={b1,b2};
	int nbit=5;
	CreateGray(nbit,ret);
	for(auto& i:ret){
		cout<<"\n";
		for(auto& i2:i){
			cout<<i2<<" ";
		}
	}
	cout<<"\n";
	
}







