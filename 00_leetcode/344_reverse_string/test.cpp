#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string reverseString(string s) {
        string ans = "";
        for(int i = s.size() -1; i>-1; --i){
            ans += s[i];
        }
        return ans;
    }
};

int main(){
	string s = "hello world";
	string ans = Solution().reverseString(s);
	cout << ans <<endl;
}
