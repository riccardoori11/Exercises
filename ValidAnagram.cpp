#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
		if (!s.empty() && t.empty() || !s.empty() && t.empty() || t.size() != s.size()){
		
		}
		sort(s.begin(),s.end()); 
		sort(t.begin(),t.end());
		return s ==t;
		
    }
};
