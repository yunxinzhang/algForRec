#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int target;
		vector<vector<int> > ans;
		int start, end, _sum;
		for(int i=0; i<nums.size()-2; ++i){
			target = -nums[i];
			start = i+1; 
			end = nums.size() - 1;
			while(start < end) {
				_sum = nums[start] + nums[end];
				if(_sum < target) {
					++start;	
				}else if(_sum > target){
					--end;
				}else{
					int _a[3] = {nums[i], nums[start], nums[end]};
					ans.push_back(vector<int>(_a,_a+3));
					++start;
					while(start < nums.size() && nums[start] == nums[start-1])
							++start;
				}
			}
			while(i + 1 < nums.size() && nums[i+1] == nums[i])
					++i;

		}							    
		return ans;
	}
};

int main(){
	int _a[6] = { -1, 0, 1, 2, -1, -4 };
	vector<int> a(_a,_a+6);
	vector<vector<int> > ans = Solution().threeSum(a);
	cout << ans.size() <<endl;
	for(int i=0; i<ans.size(); ++i){
			for(int j=0; j < ans[i].size(); ++j){
					cout << ans[i][j] << " ";
			}
			cout << endl;
	}
}
