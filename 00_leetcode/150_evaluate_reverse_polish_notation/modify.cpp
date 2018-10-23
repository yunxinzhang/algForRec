#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> stk;
		int first, second;
		for(int i=0; i<tokens.size(); ++i){
			if(tokens[i] == "+"){
				second = stk.top();
				stk.pop();
				first = stk.top();
				stk.pop();
				stk.push(first + second);
			}else if(tokens[i] == "-"){
				second = stk.top();
				stk.pop();
				first = stk.top();
				stk.pop();
				stk.push(first - second);
			}else if(tokens[i] == "*"){
				second = stk.top();
				stk.pop();
				first = stk.top();
				stk.pop();
				stk.push(first * second);
			}else if(tokens[i] == "/"){
				second = stk.top();
				stk.pop();
				first = stk.top();
				stk.pop();
				stk.push(first / second);
			}
			else{
					stk.push(atoi(tokens[i].c_str()));
			}
		}
		return stk.top();	    
	}
};

int main(){
	//vector<string> v = { "2", "1", "+", "3" , "*" };
	vector<string> v = { "4", "13", "5", "/" , "+" };
	cout << Solution().evalRPN( v ) << endl;
}
