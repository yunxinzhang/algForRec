#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int climbStairs(int n) {
		if(n == 0 || n==1)
			return 1;
		vector<int> ans(n+1, -1);
		ans[0] = 1;
		ans[1] = 1;
		for(int i=2; i<=n; ++i){
			ans[i] = ans[i-1] + ans[i-2];
		}				    
		return ans[n];
	}
};

int main(){
	cout << Solution().climbStairs(3) << endl;
	cout << Solution().climbStairs(5) << endl;
}
