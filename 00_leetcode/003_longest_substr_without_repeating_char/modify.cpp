#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int sz = s.size(), ans = 0, left = -1;
		vector<int> dict(256,-1);
		for(size_t i=0; i<sz; ++i){
			if( dict[s[i]] > left )
				left = dict[s[i]];
			dict[s[i]] = i;		
			ans = max(ans, i - left);
		}        
		return ans;
    }
};

int main(){
	//string s = "bbb";
	string s = "pwwkew";
	int ans = Solution().lengthOfLongestSubstring(s);
	cout << ans <<endl;
}


