#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		size_t sz = s.size(), len = 0, ans = 0;
		size_t left = 0;
		int cnt[256] = {0};
		for(size_t i=0; i<sz; ++i){
			++cnt[s[i]];
			if( cnt[s[i]] == 1 ){
				ans = max(ans, i-left +1);
			}
			while(cnt[s[i]] > 1){
				--cnt[s[left++]];
			}
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


