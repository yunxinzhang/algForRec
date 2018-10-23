#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		size_t st, ed;
		string str;
		stack<string> stk;
		st = path.find("/");
		while(st < path.size() ){
			ed = path.find("/", st+1);
			str = path.substr(st+1, ed - st -1);
			if(str.size() > 0)
					if(str == "."){

					}else if( str == ".." ){
						if(stk.size() > 0)
								stk.pop();
					}else
						stk.push(str);
			if( ed == string::npos ){
				break;
			}else{
				st = ed;
			}
		}
		string newpath = "", sls = "/";
		if(stk.size() == 0)
				return "/";
		while( !stk.empty() ){
			newpath = sls + stk.top() + newpath;
			stk.pop();
		}
		return newpath;
	}
};
int main(){
//	string path = "/../";
//	string path = "/a/./b/../../c/";
	string path = "/a//b///c/d//././/..";
	cout << Solution().simplifyPath(path) << endl;
}
