#include "kmp.h"
void CreateLPS(string str,vector<int>& ret){
	int i=0,j=1;
	int len=str.size();
	while(j<len && i<=j){
		if(str[j]==str[i]){
			ret[j]=i+1;
			i++;
		}else{
			i=0;
		}
		j++;
	}
}
int MatchStr(const vector<int> lps,string txt,string str){
	int len_txt=txt.size();
	int len_str=str.size();
	int l=0;
	for(int i=0;i<len_txt;i++){
		if(l>=len_str){
			return (i-1);
		}
		cout<<"l:"<<l<<"\n";
		if(str[l]==txt[i]){
			l++;
		}else{
			while(0==lps[l-1] && 0<l){
				l--;
			}
			if(0!=l)
				l=lps[l-1];
			if(str[l]==txt[i])
				l++;
			
		}
	}
	return -1;
}

void TestKMP(){
	string txt="aabbcaabbccaabbs";
	string str="aabbccaabb";
	vector<int> value(10,0);
	CreateLPS(str,value);
	for(auto& i:value){
		cout<<i<<",";
	}
	
	int ret=MatchStr(value,txt,str);
	if(-1==ret){
		cout<<"no find\n";
	}else{
		cout<<ret-str.size()+1<<"-"<<ret<<"\n";		
	}
	
	
}
