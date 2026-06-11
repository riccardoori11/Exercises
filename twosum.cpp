#include <vector>
#include <unordered_map>

class Solution {
public:
		std::vector<int> twoSum(std::vector<int>& nums, int target) {
				std::unordered_map<int,int> hash;

				for (int i{0};i<nums.size();++i){
						
						int diff = target - nums[i];

						auto iterator = hash.find(diff);

						if (iterator != hash.end()){
								return {iterator ->second,i};
						}
						hash[nums[i]] = i;
				}
				return {};
}
};

