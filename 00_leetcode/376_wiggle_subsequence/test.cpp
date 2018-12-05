#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp1(nums.size(), 1);
		vector<int> dp2(nums.size(), 1);
		for( int i=1; i < nums.size(); ++i ){
			for( int j=0; j<i; ++j ){
				if( nums[j] < nums[i] )
					dp1[i] = max(dp1[i], 1+dp2[j]);			
				if( nums[j] > nums[i] )
					dp2[i] = max(dp2[i], 1+dp1[j]);			
			}
		}
		int maxlen = dp1[0];
		for(int i = 1; i<dp1.size(); ++i)
			maxlen = max(max(maxlen, dp1[i]), dp2[i]);
		return maxlen;
	}
};

int main(){
	vector<int> v = { 10, 9 , 2, 5, 3, 7, 101, 18 };
	cout << Solution().lengthOfLIS(v) << endl;
}
