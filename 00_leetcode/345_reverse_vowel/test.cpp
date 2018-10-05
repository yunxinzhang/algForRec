#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isVowels(char c){
		if(c=='e'|| c=='a' || c== 'i' || c=='o' || c=='u' || c=='A' ||c=='E' || c=='I' ||c=='O' || c=='U')
		return true;
		return false;
	}
    string reverseVowels(string s) {
		int l = 0 , r = s.size() -1;
		while( l < r ){
			while( !isVowels(s[l]) && l < r ) ++l;	
			while( !isVowels(s[r]) && l < r ) --r;
			swap(s[l++], s[r--]);	
		}		        
		return s;
    }
};

int main(){
	string s = "hello world";
	string ans = Solution().reverseVowels(s);
	cout << ans <<endl;

}
