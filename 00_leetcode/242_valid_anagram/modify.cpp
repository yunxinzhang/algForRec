#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		int ch[26] = {0};
		for(int i=0; i<s.size(); ++i)
				++ch[s[i] - 'a'];
		for(int i=0; i<t.size(); ++i)
				--ch[t[i] - 'a'];
		for(int i=0; i<26; ++i)
				if(ch[i] != 0) return false;
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
