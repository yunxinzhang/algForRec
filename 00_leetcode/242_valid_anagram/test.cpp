#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> c2i;
		for(size_t i=0; i<s.size(); ++i){
				if(c2i.find(s[i]) == c2i.end()){
						c2i.insert(make_pair(s[i], 1));
				}else{
						++c2i.find(s[i])->second;
				}
		}
		//find
		for(size_t i=0; i<t.size(); ++i){
				if(c2i.find(t[i]) == c2i.end())return false;
				--c2i[t[i]];
				if(c2i[t[i]]==0)
						c2i.erase(t[i]);
		}
		if(c2i.size() > 0) return false;
		return true;
	}
};

int main(){
		string s = "anagram";
		string t = "nagaram";
		cout << Solution().isAnagram( s, t ) << endl;
		string s2 = "rat";
		string t2 = "car";
		cout << Solution().isAnagram( s2, t2 ) << endl;
}
