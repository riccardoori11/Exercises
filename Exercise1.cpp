#include <mutex>
#include <vector>
#include <iostream>
#include <syncstream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <semaphore>

std::mutex mtx;
std::counting_semaphore<3> semaphore(3);
int activeCounter{0};
int maxCounter{0};

void f(int iteration){
		
		semaphore.acquire();
		{
				std::lock_guard<std::mutex> lock(mtx);
				++activeCounter;					
				maxCounter = std::max(activeCounter,maxCounter);
				std::osyncstream(std::cout) << "Active counter: " << activeCounter << std::endl;

		}

		std::this_thread::sleep_for(std::chrono::milliseconds(500));	
			
		
		{

				std::lock_guard<std::mutex> lock(mtx);
				--activeCounter;					
				std::osyncstream(std::cout) << "Active counter: " << activeCounter << std::endl;

		}

		semaphore.release();
}


int main(){
		std::vector<std::thread> threads;
		for (int i{0};i<30;++i){
				std::thread ti(f,i);
				threads.push_back(std::move(ti));	
		}

		for (auto &x: threads){x.join();}

		std::cout << "Maximum observable active workers were: " << maxCounter <<  std::endl;

		return 0;
}
