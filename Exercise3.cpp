#include <thread>
#include <syncstream>
#include <iostream>
#include <semaphore>

std::binary_semaphore foo_semaphore{1};
std::binary_semaphore bar_semaphore{0};

auto ping(int n){
		
		while (n-->0){
				foo_semaphore.acquire();
				std::osyncstream(std::cout) << "ping";
				bar_semaphore.release();
		}
}
auto pong(int n){
		while (n-->0){
				bar_semaphore.acquire();
				std::osyncstream(std::cout) << "pong" << "\n";
				foo_semaphore.release();
		}
}

int main(){
		int n{1000};
		
		
		std::thread t1(ping,n);
		std::thread t2(pong,n);

		t1.join();
		t2.join();

		return 0;
}
