#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int n= nums.size();
		if(n == 0)
				return 0;
		vector<int> ans(n, 0);
		ans[0] = nums[0];
		for(int i = 1; i < n; ++i){
			ans[i] = max( nums[i] + (i>=2 ? ans[i-2]:0 ), ans[i-1] );
		}				    
		for(int i=0; i<n;++i)
				cout << ans[i] <<" ";
		cout << endl;
		return ans[n-1];
	}
};

int main(){
	vector<int> v{1,2,3,1};
	vector<int> v2{2,7,9,3,1};
	cout << Solution().rob(v) << endl;
	cout << Solution().rob(v2) << endl;
}
