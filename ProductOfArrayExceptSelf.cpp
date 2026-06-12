#include <vector>
#include <algorithm>
#include <unordered_map>


using namespace std;

class Solution {

public:
    vector<int> productExceptSelf(vector<int>& nums) {
				
			vector<int> results (nums.size(),1) ;


			int prefix = 1;

			for (int i{0}; i< nums.size(); ++i){
				results[i] = prefix;	
				prefix *= nums[i];
			}
			int suffix = 1;
			for (size_t i{nums.size()}; i --> 0 ;){
				results[i] *= suffix;	
				suffix *= nums[i];
			}
			return results;
    }
};
