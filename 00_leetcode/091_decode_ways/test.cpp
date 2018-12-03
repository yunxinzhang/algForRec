#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		int n = s.size() +1;
		vector<int> ans(n, 0);
		if( s[0] == '0' )
				return 0;
		ans[1] = 1;
		ans[0] = 1;
		for( int i=2; i< n; ++i){
			if(s[i-1] == '0'){
				if(s[i-2] != '1' && s[i-2] != '2')
						return 0;
				ans[i] = ans[i-2];
				continue;
			}
			if(s[i-2]  == '2' ){
					if(s[i-1] - '0' >= 0 && s[i-1] - '0' <= 6){
							ans[i] = ans[i-1] + ans[i-2];
							continue;
					}
			}else if(s[i-2] == '1'){
					ans[i] = ans[i-1] + ans[i-2];
					continue;
			}
			ans[i] = ans[i-1];
		}
		return ans[n-1];
	}
};

int main(){
	cout << Solution().numDecodings("226") << endl;
	cout << Solution().numDecodings("17") << endl;
	cout << Solution().numDecodings("12") << endl;
}
