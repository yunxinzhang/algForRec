#include <iostream>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
	public:
		bool isIsomorphic(string s, string t) {
			assert(s.size() == t.size());
			vector<int> s2t(256,-1);
			vector<int> t2s(256,-1);
			for(size_t i=0; i<s.size(); ++i){
					if(s2t[s[i]] != t2s[t[i]]) 
							return false;
					s2t[s[i]] = i;
					t2s[t[i]] = i;
			}
			return true;
		}
};

int main(){
	string s = "foo", t = "baa";
	cout << Solution().isIsomorphic(s,t) << endl;
}
