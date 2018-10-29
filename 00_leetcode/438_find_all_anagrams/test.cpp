#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int cnts[128] = {0}, szp = p.size(), szs = s.size();
		for(size_t i=0; i<szp; ++i){
			++cnts[p[i]];
		}   
		vector<int> ans;
		int cntp[128] = {0}, point = 0;
		for(size_t i=0; i<szp; ++i){
			if(cnts[s[i]] > 0){
				++cntp[s[i]];
				if(cntp[s[i]] <= cnts[s[i]])
					++point;
			}
		} 
		if(point == szp) ans.push_back(0);
		for(size_t i = szp ; i < szs; ++i){
			if(cnts[s[i-szp]] > 0) {
				if(cntp[s[i-szp]] <= cnts[s[i-szp]])
					--point;
				--cntp[s[i-szp]];
			}
			if(cnts[s[i]] > 0){
				++cntp[s[i]];
				if(cntp[s[i]] <= cnts[s[i]])
					++point;
			}
			if(point == szp) ans.push_back(i-szp+1);
		}
		return ans;
	}
};

int main(){
		string s = "abab";
		string p = "ab";
		vector<int> ans = Solution().findAnagrams(s, p);
		for(int i=0 ;i <ans.size(); ++i){
				cout << ans[i] <<" ";
		}
		cout <<endl;
}
