#include <thread>
#include <syncstream>
#include <iostream>
#include <semaphore>

std::binary_semaphore foo_semaphore{1};
std::binary_semaphore bar_semaphore{0};

auto foo(int n){
		
		while (n-->0){
				foo_semaphore.acquire();
				std::osyncstream(std::cout) << "foo";
				bar_semaphore.release();
		}
}
auto bar(int n){
		while (n-->0){
				bar_semaphore.acquire();
				std::osyncstream(std::cout) << "bar" << "\n";
				foo_semaphore.release();
		}
}

int main(){
		int n{1000};
		
		
		std::thread t1(foo,n);
		std::thread t2(bar,n);

		t1.join();
		t2.join();

		return 0;
}
