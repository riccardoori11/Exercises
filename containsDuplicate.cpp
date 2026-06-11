#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution{
		public:
bool contains_duplicate(std::vector<int> nums){
		
		std::unordered_map<int, int> map;	

		for(auto x: nums){
				++map[x];
		}

		return std::any_of(map.begin(),map.end(),[](auto &map){
								return map.second > 1;
						});	

}
};


int main(){
		
		std::vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
		Solution solution;
		std::cout << solution.contains_duplicate(nums) << std::endl;

}
