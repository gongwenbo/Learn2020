#include "music.h"
void MusicGroup(vector<int>d,int index,int len,int& ret){
	if(0==len){
		ret++;
		return;
	}else if(len<0){
		return;
	}
	for(int i=index;i<(int)d.size();i++){
		MusicGroup(d,i+1,len-d[i],ret);		
	}
}

void TestMusicGroup(){
	vector<int> info={2,3,3,3};
	vector<int> d;
	int len=5;
	for(int i=0;i<info[1];i++){
		d.emplace_back(info[0]);
	}
	for(int i=0;i<info[3];i++){
		d.emplace_back(info[2]);
	}
	int ret=0;
	MusicGroup(d,0,5,ret);
	cout<<"TestMusicGroup:"<<ret<<"\n";
}