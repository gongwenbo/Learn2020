#include "thread_pool.h"
ThreadPool::ThreadPool(int num){
	for(int i=0;i<num;i++){
		threads_.emplace_back([=](){
			for(;;){						
				unique_lock<mutex> loc1(mux_);
				con_.wait(loc1,[]{return true;});
				if(task_.empty()){
					loc1.unlock();
					continue;
				}
					
				auto run=task_.front();
				task_.pop();
				loc1.unlock();
				
				
				std::thread::id thread_id = std::this_thread::get_id();
				cout<<thread_id<<"\n";						
				run();
				
			}

		});
		
	}
}



ThreadPool::~ThreadPool(){
	for(auto& i:threads_){
		i.join();
	}
}

int Add(int a,int b){
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	return (a+b);
}

void TestThreadPool(){
	auto run_task=make_shared<ThreadPool>(3);
	vector<future<int>> ret;
	for(int i=0;i<10;i++){
		ret.emplace_back(run_task->AddTask(Add,0,i));
	}
	for(auto& i:ret){
		cout<<i.get()<<"\n";
	}
}


