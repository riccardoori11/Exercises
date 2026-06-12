#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> map; 

		for (auto x: strs){
				string key = x;
				sort(key.begin(),key.end());
				
				map[key].push_back(x);

		}
		vector<vector<string>> results;
		for (auto seconds:map){
				results.push_back(seconds.second);
		}

		return results;
    }
};
