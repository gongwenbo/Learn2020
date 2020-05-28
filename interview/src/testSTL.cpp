#include "testSTL.h"
TestVector::TestVector(vector<string> data){
	name.assign(data.begin(),data.end());
}
void TestVector::Insert(vector<string> data1,int place){
	name.insert(name.begin()+place,data1.begin(),data1.end());
}
void TestVector::Dis(){
	cout<<"TestVector\n";
	for(auto &i:name){
		cout<<i<<" ";
	}
	cout<<"\n";
	cout<<name.capacity()<<"\n";
	reverse(name.begin(),name.end());
	for(auto &i:name){
		cout<<i<<" ";
	}
	cout<<"\n";
	TestList();
	TestDeque();
	TestStack();
	
}
void TestVector::TestList(){
	list<int64_t> num;
	int count=10;
	while(count--){
		num.emplace_back(count);
	}
	cout<<num.front()<<"\n";
	num.pop_back();
	num.pop_back();
	num.resize(50);
	cout<<num.size()<<"\n";
	
	num.sort(std::greater<int64_t>());
	num.unique();
	auto pose=++num.begin();
	num.insert(pose,100);
	
	for(auto &i:num){
		cout<<i<<"\n";
	}
	cout<<"\n";
	
	list<int> e1={1,2,4};
	list<int> e2={6,7,8};
	e1.swap(e2);
	cout<<e2.front()<<"\n";
	
}

void TestVector::TestDeque(){
	deque<int> stu1={1,2,3};
	stu1.emplace_back(100);
	cout<<stu1.back()<<"\n";
	stu1.emplace_front(120);
	cout<<stu1.front()<<"\n";	
}
void TestVector::TestStack(){
	stack<int> father;
	father.push(12);
	cout<<father.top()<<"\n";
	father.pop();
	
	queue<int> mather;
	mather.push(89);
	mather.push(189);
	cout<<mather.front()<<"\n";
	mather.pop();
	cout<<mather.back()<<"\n";
	
}
void main_test()
 {
   int i = 0, sum = 0;
   do{
      if(i!=(i/9)*10){
		 sum += i; 
	  }else{
		  cout<<i<<" ";
	  }
        
     }while(++i<100);
     printf("%d\n",sum);
}

void TesSTL(){
	vector<string> n={"one","two","three"};
	vector<string> m={"zero","five"};
	auto test_vec=std::make_shared<TestVector>(n);
	test_vec->Insert(m,0);
	test_vec->Dis();
	main_test();
	char *name="asdf";
	char stu1[]="asdf";
	cout<<"TesSTL&&&&&&&&&&&\n";
	cout<<sizeof(name)<<"*"<<sizeof(stu1)<<"\n";
	
	
	
}