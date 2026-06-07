#include <mutex>
#include <syncstream>
#include <thread>
#include <iostream>

int i{0};
const int maxIteration{1000000};
std::mutex mtx;

void foo(int iteration){
		
		std::lock_guard<std::mutex> lock(mtx);
		while(iteration --> 0)
				++i;
		std::osyncstream(std::cout) << "Thread: " << std::this_thread::get_id() << " counter: " << i << std::endl;
}

void bar(int iteration){
		
		while(iteration --> 0)
				++i;
		std::osyncstream(std::cout) << "Thread: " << std::this_thread::get_id() << " counter: " << i << std::endl;
}

int main(){
			
		std::thread t1(foo,maxIteration);	
		std::thread t2(foo,maxIteration);
		
		t1.join();
		t2.join();
		
		std::thread t3(bar,maxIteration);	
		std::thread t4(bar,maxIteration);

		t3.join();
		t4.join();

		return 0;
}
