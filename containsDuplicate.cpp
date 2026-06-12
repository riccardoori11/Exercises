#include <vector>
#include <algorithm>
#include <unordered_map>




using namespace std;




class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> map;

		for (auto &x: nums){
				++map[x];
		}

		return any_of(map.begin(),map.end(),[](auto &map){
						return map.second > 1;
						});
    }
};
