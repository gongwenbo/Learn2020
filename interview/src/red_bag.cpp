#include "red_bag.h"
void MaxRedBag(vector<int> money,int &ret){
	map<int,int> money_info;
	int len=money.size()/2;
	for(auto& i:money){
		auto place=money_info.find(i);
		if(place!=money_info.end()){
			place->second=place->second+1;
			if(place->second>len){
				ret=place->first;
				break;
			}
		}else{
			money_info.emplace(i,1);
		}
	}
	for(auto& i:money_info){
		cout<<i.first<<"*"<<i.second<<"\n";
	}
}
void TestRedBag(){
	vector<int> money={1,2,3,2,2,7,7,7,7,7,7,7,7};
	int ret=0;
	MaxRedBag(money,ret);
	cout<<"TestRedBag: "<<ret<<"\n";
}