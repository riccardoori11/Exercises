#include <vector>
#include <algorithm>
#include <unordered_map>


using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> map;

		for (auto &x: nums){
				++map[x];	
		}
		vector<int> results;
		vector<pair<int,int>> sorted;		
		for (auto pair: map){
				sorted.push_back(pair);
		}
		sort(sorted.begin(),sorted.end(),[](pair<int,int>a,pair<int,int>b){
				return a.second > b.second;	
						});	
		for (int i{};i < k ; ++i){
				results.push_back(sorted[i].first);	
		}
		return results;
    }
};
