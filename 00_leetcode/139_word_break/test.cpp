#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> dict(wordDict.begin(), wordDict.end());					        
		int maxlen = 0;
		for(auto it : wordDict){
			if(it.size() > maxlen)
				maxlen = it.size();
		}
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for(int i=1; i<dp.size(); ++i){
			int len = 1, st = i-len;
			while(st >= 0 && len <= maxlen){
				string word = s.substr(st, len);
				if(dict.find(word) != dict.end() && dp[st]){
					dp[i] = true;
					break;
				}
				--st;
				++len;
			}
		}
		return dp[s.size()];
	}
};

int main(){
	string s = "leetcode";
	vector<string> v = {"leet", "code"};
	cout << Solution().wordBreak(s, v) << endl;
	string s1 = "applepenapple";
	vector<string> v1 = {"apple", "pen"};
	cout << Solution().wordBreak(s1, v1) << endl;
	string s2 = "catsandog";
	vector<string> v2 = {"cats", "dog", "sand", "and", "cat"};
	cout << Solution().wordBreak(s2, v2) << endl;
}
