#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
				unordered_map<int, int> map; 
				

				for (int x{}; x < nums.size(); ++x){
						int diff = target- nums[x];

						auto iterator = map.find(diff);

						if (iterator != map.end()){
								return {iterator -> second,x};						
						}
						map[nums[x]] = x;
				}
				return {};
    }
};
