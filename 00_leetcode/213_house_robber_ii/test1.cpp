#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int _rob(vector<int>& nums, int st, int ed) {
		int n= nums.size();
		if(n == 0)
				return 0;
		vector<int> ans(n, 0);
		ans[0] = nums[0];
		for(int i = 1; i < n; ++i){
			ans[i] = max( nums[i] + (i>=2 ? ans[i-2]:0 ), ans[i-1] );
		}				    
		return ans[n-1];
	}
	int rob(vector<int> & nums){
		if(nums.size() == 0)
				return 0;
		if(nums.size() == 1)
				return nums[0];
		vector<int> v1(nums.begin()+1, nums.end());
		vector<int> v2(nums.begin(), nums.end()-1);
		return max(_rob(v1), _rob(v2));
	}
};

int main(){
	vector<int> v{1,2,3,1};
	vector<int> v2{2,7,9,3,1};
	vector<int> v3{2,3,2};
	vector<int> v4{1,2,3,1};
	vector<int> v5{1,7,3};
	vector<int> v6{1,1,1,2};
	vector<int> v7{2,2,4,3,2,5};
	cout << Solution().rob(v) << endl;
	cout << Solution().rob(v2) << endl;
	cout << Solution().rob(v3) << endl;
	cout << Solution().rob(v4) << endl;
	cout << Solution().rob(v5) << endl;
	cout << Solution().rob(v6) << endl;
	cout << Solution().rob(v7) << endl;
}
