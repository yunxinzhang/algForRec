#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int integerBreak(int n) {
		vector<int> ans(n+1, 0);
		ans[1] = 1;
		ans[2] = 1;
		ans[3] = 2;
		for( int i = 3; i < n+1; ++i ){
				for( int j = 2; j <= i / 2  + 1; ++j ){
					ans[i] = max(max(ans[i], (i-j)*j), j * ans[i-j]);
				}
		}
		return ans[n];
	}
};

int main(){
		cout << Solution().integerBreak(5) << endl;
		cout << Solution().integerBreak(6) << endl;
		cout << Solution().integerBreak(7) << endl;
		cout << Solution().integerBreak(8) << endl;
}
