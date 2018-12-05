#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp(nums.size(), 1);
		for( int i=1; i < nums.size(); ++i ){
			for( int j=0; j<i; ++j ){
				if( nums[j] < nums[i] )
					dp[i] = max(dp[i], 1+dp[j]);			
			}
		}
		int maxlen = dp[0];
		for(int i = 1; i<dp.size(); ++i)
			maxlen = max(maxlen, dp[i]); 
		return maxlen;
	}
};

int main(){
	vector<int> v = { 10, 9 , 2, 5, 3, 7, 101, 18 };
	cout << Solution().lengthOfLIS(v) << endl;
}
