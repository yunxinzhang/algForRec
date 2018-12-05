#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if(sum < S || -sum > S || (sum+S)%2 == 1)
				return 0;
		vector<int> dp1(sum*2+1, 0);
		vector<int> dp2(sum*2+1, 0);
		sort(nums.begin(), nums.end());
		dp1[sum+nums[0]] += 1;
		dp1[sum-nums[0]] += 1;
		for( int i = 1; i < nums.size(); ++i ){
			for( int j = sum; j >= -sum; --j ){
				if( i % 2 == 1 ){
					if( sum +j >= nums[i] )
						dp2[sum+j] = dp1[sum+j - nums[i]];
					if( sum +j + nums[i] <= 2*sum  )
						dp2[sum+j] += dp1[sum+j + nums[i]];
				}else{
					if( sum +j >= nums[i] )
						dp1[sum+j] = dp2[sum+j - nums[i]];
					if( sum +j + nums[i] <= 2*sum  )
						dp1[sum+j] += dp2[sum+j + nums[i]];
				}
			}
		}
		return  nums.size() % 2 != 1 ? dp2[sum + S] : dp1[sum + S];					    
	}
};

int main(){
	vector<int> v = { 1,1,1,1,1 };
	cout << Solution().findTargetSumWays(v, 3) << endl;
}
