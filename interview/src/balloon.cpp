#include "balloon.h"
void Dis(vector<int>d){
	for(auto& i:d){
		cout<<i<<" ";
	}
	cout<<"\n";
}
void Section(vector<int> action,vector<int> data,
int& len,int index){
	int right=0;
	vector<int> data_buf=data;
	int offset=action.size()-data.size();
	if(index>offset)
		return ;
	for(int i=index;i<action.size();i++){
		
		auto find_=std::find(data_buf.begin(),data_buf.end(),action[i]);
		if(find_!=data_buf.end()){
			data_buf.erase(find_);
		}
		if(data_buf.empty()){
			right=i;
			break;
		}
		
	}
	if(len>(right-index) && right!=0){		
		len=right-index+1;
	}
	Section(action,data,len,index+1);
	
}

void TestBalloon(){
	vector<int> action={1,1,2,3,0,4,5,6,2,3};
	vector<int> data={1,2,3,4,5,6};
	int len=action.size();
	Section(action,data,len,0);
	cout<<"Section:"<<len<<"\n";
}