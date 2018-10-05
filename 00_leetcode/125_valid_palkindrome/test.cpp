#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
		if( s.size() == 0 ) return true;
		size_t l = 0, r = s.size() - 1;
		while( l < r ){
			if(!isalnum(s[l])){
				++l;
				continue;
			}
			if(!isalnum(s[r])){
				--r;
				continue;
			}	
			if( toupper(s[l++]) != toupper(s[r--]) )
				return false;
		}
		return true;
    }
};

int main(){
//	string s = "A man, a plan, a canal: Panama";
//	string s = "Sex at noon taxes.";
	string s = "0p";
	cout << Solution().isPalindrome(s) <<endl;

}

