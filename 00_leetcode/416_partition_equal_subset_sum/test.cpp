#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if(sum % 2 == 1)
				return false;
		sum /= 2;
		int n= nums.size();
		vector< vector<int> > trans(n, vector<int>(sum+1, 0));
		trans[0][0] = 1;
		trans[0][nums[0]] = 1;
		for(int i=1; i<n; ++i){
			for(int j=0; j<=sum; ++j){
				if(trans[i-1][j]){
					trans[i][j] = 1;
					if( j + nums[i] <= sum )
						trans[i][j+nums[i]] = 1;
				}
			}	
		}
		return trans[n-1][sum];
	}
};

int main(){
	vector<int> v = {1, 5, 11, 5};
	cout << Solution().canPartition(v) << endl;
	vector<int> v2 = {1, 2, 3, 5};
	cout << Solution().canPartition(v2) << endl;
	vector<int> v3 = {1, 2, 5};
	cout << Solution().canPartition(v3) << endl;
}
