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
		vector<bool>  trans(sum+1, 0);
		trans[0] = true;
		trans[nums[0]] = true;
		for(int i=1; i<n; ++i){
			for(int j=sum; j>=nums[i]; --j){
				trans[j] = trans[j] || trans[j-nums[i]];
			}	
			for(auto it : trans)
					cout << it << " ";
			cout << endl;
		}
		return trans[sum];
	}
};

int main(){
	vector<int> v = {1, 5, 11, 5};
//	cout << Solution().canPartition(v) << endl;
	vector<int> v2 = {1, 2, 3, 5};
//	cout << Solution().canPartition(v2) << endl;
	vector<int> v3 = {1, 2, 5};
	cout << Solution().canPartition(v3) << endl;
}
