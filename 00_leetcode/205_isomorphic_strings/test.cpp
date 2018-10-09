#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
	public:
		bool isIsomorphic(string s, string t) {
			assert(s.size() == t.size());
			unordered_map<char,char> a2b;
			unordered_set<char> uset;
			for(size_t i=0; i<s.size(); ++i){
					if(a2b.count(s[i])){
							if(a2b[s[i]] != t[i])
									return false;
					}else{
							if(uset.find(t[i]) != uset.end())
									return false;
							uset.insert(t[i]);
							a2b[s[i]] = t[i];
					}
			}
			return true;
		}
};

int main(){
	string s = "foo", t = "baa";
	cout << Solution().isIsomorphic(s,t) << endl;
}
