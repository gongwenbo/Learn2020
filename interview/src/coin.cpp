#include "coin.h"
void Coin(){
	cout<<"test coin\n";
}
void FindCombin(vector<int> data,int coin_num,int& ret){
	if(coin_num<=0)
		return;
	int coin_tem=coin_num/data[0];
	int num=0;
	int reminder_tem=coin_num%data[0];
	int reminder=0;
	
	for(auto& inter:data){
		num=coin_num/inter;
		reminder_tem=coin_num%inter;
		if(coin_tem > num && coin_num>=inter){
			coin_tem=num;
			reminder=reminder_tem;
			
		}else if(coin_tem == num && coin_num>=inter){
			if(reminder_tem<reminder){
				reminder=reminder_tem;
			}
		}
	}
	cout<<coin_tem<<":"<<reminder_tem<<"\n";
	ret+=coin_tem;
	FindCombin(data,reminder,ret);
}

void TestCoin(){
	vector<int> data={1,2,6,4};
	int coin=100;
	int ret=0;
	FindCombin(data,coin,ret);
	cout<<"TestCoin: "<<ret<<"\n";
}





