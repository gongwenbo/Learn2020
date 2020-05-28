#include "map_test.h"



ReadBlackTree::ReadBlackTree(map<string,int64_t> stu,set<int> id){
	student_=stu;
	identify_=id;
}

void ReadBlackTree::Dis(){
	cout<<"ReadBlackTree student_\n";
	for(auto& i:student_){
		cout<<i.first<<":"<<i.second<<"\n";
	}
	cout<<"identify_\n";
	for(auto& i:identify_){
		cout<<i<<"\n";
	}
}
void ReadBlackTree::TestSet(){
	auto place=identify_.find(3);
	if(place!=identify_.end()){
		cout<<"TestSet"<<*place<<"\n";
	}
	multiset<int> stu2{99,1,2,33,4,4,1,10};
	stu2.insert(10);
	stu2.erase(10);
	for(auto& iter:stu2){
		cout<<iter<<"\n";
	}
	cout<<stu2.count(4)<<"\n";
	TestArray();
		
}

void ReadBlackTree::TestArray(){
	array<int,10> father={1,2,3};
	for(auto& i:father){
		cout<<i<<"\n";
	}
	TestForward();
	TestTuple();
}

void ReadBlackTree::TestTuple(){
	auto mather=make_tuple(1,2,"one");
	cout<<get<0>(mather)<<"*"<<get<1>(mather)<<"*"<<
		get<2>(mather)<<"\n";	
}


void ReadBlackTree::TestForward(){
	forward_list<pair<int,string>> stu{{1,"asdf"}};	
	stu.emplace_after(stu.begin(),2,"s");
	for(auto& i:stu){
		cout<<i.first<<"*"<<i.second<<"\n";
	}
	forward_list<int> stu1{5,4,3,2,1,4};
	stu1.sort();
	stu1.unique();
	for(auto& i:stu1){
		cout<<i<<"\n";
	}
	
	
	
}
void TestStruct(){
	
	st_t st[16];
	char *p = (char *)(&(st[2].bitset));
	cout<<p-(char*)st<<"\n";
	cout<<sizeof(struct st_t)<<"\n";
}

void TestRBTree(){
	
	map<string,int64_t> stu;
	stu.emplace(make_pair("gong",0));
	stu.emplace(make_pair("wen",1));
	
	set<int> id={1,2,3,4,4,5,6};
	id.emplace(9);
	id.emplace(99);		
	auto run=make_shared<ReadBlackTree>(stu,id);
	run->Dis();
	run->TestSet();
	TestStruct();
	
}