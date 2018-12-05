#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> dp(target+1, 0);
		sort(nums.begin(), nums.end());
		dp[0] = 1;
		for(int i  = 1; i <= target; ++i){
			for(auto it : nums){
				if(it > i)
					break;
				dp[i] += dp[i - it];
			}	
		}
		for(auto it : dp)
				cout << it << " ";
		cout << endl;
		return dp.back();
	}
};


int main(){
	vector<int> v = { 1,2,3 };
	cout << Solution().combinationSum4(v, 4) << endl;
}
