#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> stk;
		for( int i=0; i<s.size(); ++i ){
				if( s[i] == '{' || s[i] == '[' || s[i] == '(' ){
						stk.push(s[i]);
				}
				else{
						if(stk.empty())
								return false;
						char c = stk.top();
						switch (c){
						case '{': if( s[i] != '}' ) return false; break;
						case '[': if( s[i] != ']' ) return false; break;
						case '(': if( s[i] != ')' ) return false; break;
						}
						stk.pop();
				}
		}
		if(stk.size() != 0)
				return false;
		return true;
	}
};
int main(){
	string s = "{[]}";
	cout << Solution().isValid(s) << endl;
}
