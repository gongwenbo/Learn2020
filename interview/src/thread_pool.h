#pragma once
#include "common.h"
class ThreadPool{
	public:
		ThreadPool(int num);
		template<typename F,typename... Args>
		auto AddTask(F&& f,Args&&... args)->future<typename result_of<F(Args...)>::type>{
			using type_ret=decltype(f(args...));
			auto task=std::make_shared<packaged_task<type_ret()>>(std::bind(forward<F>(f),forward<Args>(args)...));			
			future<type_ret> ret=(*task).get_future();			
			unique_lock<mutex> loc(mux_);
			task_.emplace([=](){
				(*task)();
			});
		loc.unlock();
		con_.notify_one();
		return ret;
}
		~ThreadPool();
	public:
		
	private:
		queue<function<void()>> task_;
		vector<thread> threads_;
		mutex mux_;
		condition_variable con_;
};

int Add(int a,int b);
void TestThreadPool();


