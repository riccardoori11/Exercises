#include <chrono>
#include <algorithm>
#include <thread>
#include <iostream>
#include <vector>
#include <semaphore>
#include <mutex>

std::mutex mtx;
int counter{0};
int Maxcounter{0};
std::counting_semaphore<3> semaphore(3);

void f(int id){
		semaphore.acquire();	
		
		{
				std::lock_guard<std::mutex> lock(mtx);
				++counter;
				Maxcounter = std::max(Maxcounter,counter);
				std::cout << "Active counters: " << counter << std::endl;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		
		{
				std::lock_guard<std::mutex> lock(mtx);
				--counter;
				
				std::cout << "Active counters: " << counter << std::endl;
		}

		semaphore.release();

}


int main(){
		
		std::vector<std::thread> threads;
		for(int i{0};i< 30;++i){
				std::thread ti(f,i);	
				threads.push_back(std::move(ti));
		}

		for (auto &x:threads){x.join();}
		
		std::cout << "Maximum thread at a given time was: " << Maxcounter << std::endl;
		return 0;
}
