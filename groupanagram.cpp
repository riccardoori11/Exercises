#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>


// strs = ["eat","tea","tan","ate","nat","bat"]
// [["bat"],["nat","tan"],["ate","eat","tea"]]

class Solution{

		public:

				std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs){
						std::unordered_map<std::string, std::vector<std::string>> map;	
						for (auto x:strs){
								std::string key = x;
								std::sort(x.begin(),x.end());
								
								map[x].push_back(key);
						}
						std::vector<std::vector<std::string>> result;
						for (auto s:map){
								result.push_back(s.second);
						}
						return result;
				}


};
