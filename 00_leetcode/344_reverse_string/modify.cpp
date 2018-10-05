#include <iostream>
#include <string>
#include <cstdio>
using namespace std;


class Solution {
public:
    string reverseString(string s) {
		printf("%p\n", s);
		int l = 0, r = s.size()-1;
		while( l < r ){
			swap(s[l++], s[r--]);
		}
		printf("%p\n", s);
		return s;
    }
};

int main(){
	string s = "hello world";
	string ans = Solution().reverseString(s);
	cout << ans <<endl;
	cout << s <<endl;
}
