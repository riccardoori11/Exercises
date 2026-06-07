#include <chrono>
#include <thread>
#include <vector>
#include <mutex>
#include <semaphore>
#include <iostream>


std::counting_semaphore<3> semaphore(3);
std::mutex mutex;
int Counter{0};
int maxCounter{0};


void worker(int id){
		semaphore.acquire();

	
		{
				std::lock_guard<std::mutex> lock(mutex);
				++Counter;
				maxCounter = std::max(Counter,maxCounter);

				std::cout << "Active workers : "<< Counter << std::endl;
		}	
		// simulate some work
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
				

		
		{
				std::lock_guard<std::mutex> lock(mutex);
				--Counter;
				
				std::cout << "Active workers : "<< Counter << std::endl;
		}

		
		semaphore.release();
		

}

int main(){
		std::vector<std::thread> threads;
		for (int i{0}; i < 30; ++i){
				std::thread ti(worker,i);	
				threads.push_back(std::move(ti));
		}	

		for (auto &x:threads){x.join();}
		
		std::cout << "Maximum observed counter was: " << maxCounter << std::endl;

		return 0;
}
