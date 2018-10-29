#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
		int cntt[128] = {0}, cnts[128] = {0};
		int szs = s.size(), szt = t.size();
		for(size_t i=0; i<szt; ++i){
			++cntt[t[i]];
		}
		int point = 0, start=0, minlen=INT_MAX, idx=-1;    
		for(int i=0; i<szs; ++i){
			if(cntt[s[i]] > 0){
				++cnts[s[i]];
				if( cnts[s[i]] <= cntt[s[i]] )
					++point;
			}
			while(point == szt){
				if(cntt[s[start]] > 0){
					if(cnts[s[start]] <= cntt[s[start]]){
						--point;
						if(minlen > i-start+1){
							minlen =  (i-start+1);
							idx = start;
						}
					}
					--cnts[s[start]];
				}
				++start;
			}
		}
		if(idx == -1)
			return "";
		return s.substr(idx, minlen);
    }
};

int main(){
	string s = "ADOBECODEBANC", t = "ABC";
	string ans = Solution().minWindow(s, t);
	cout << ans <<endl;

}
