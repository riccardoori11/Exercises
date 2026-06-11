#include <algorithm>
#include <unordered_map>
#include <string>


class Solution{

		public:
		

				bool isAnagram(std::string s,std::string t){
						std::unordered_map<char, int> m1; std::unordered_map<char, int> m2;
						for (auto x: s){
								++m1[x];	
						}

						for (auto x: t){
								++m2[x];	
						}

						return m1 == m2;	
						

				}

};



