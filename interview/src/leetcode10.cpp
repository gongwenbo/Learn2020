#include "leetcode10.h"
void MatchStr(string txt,string patt,int& ret,int ts,int ps){
	if(ts>txt.size() || ps>patt.size()){
		return;
	}
	if(ts==txt.size() && ps==patt.size()){
		ret=1 ;
		return ;
	}	
	if(patt[ps]==txt[ts] || '.'==patt[ps]){
		ts++;
		ps++;
		MatchStr(txt,patt,ret,ts,ps);
	}else if('*'==patt[ps] && (ps-1)>-1){
		if(patt[ps-1]==txt[ts]){
			ts++;
			MatchStr(txt,patt,ret,ts,ps);
			MatchStr(txt,patt,ret,ts,ps+1);
			
		}else{
			ps++;
		}
		
		
	}
}

void TestMatch(){
	string txt="ASDSSSS";
	string str="A.DS*G";
	int ret=0;
	MatchStr(txt,str,ret,0,0);
	cout<<"TestMatch: "<<ret<<"\n";
}





