#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		vector<vector<int> > fourSum(vector<int>& nums, int target) {
			if(nums.size() < 4) return vector< vector<int> >();
			sort(nums.begin(), nums.end());				    
			int re, l, r, sum;
			vector< vector<int> > ans; 
			for(size_t i=0; i < nums.size() - 3; ++i) {
					for( size_t j = i+1; j < nums.size() - 2; ++j ){
						re = (target - nums[i] - nums[j]);
						l = j+1;
						r = nums.size() -1;
						while(l < r){
							sum = nums[l] + nums[r];
							if(sum < re)
									++l;
							else if(sum > re)
									--r;
							else{
									int _a[4] = {nums[i], nums[j], nums[l], nums[r]};
									ans.push_back( vector<int>(_a, _a + 4) );
									while(nums[++l] == _a[2]);
									while(nums[--r] == _a[3]);
							}
						}
						while(nums[j+1] == nums[j] ) ++j;
					}
					while(nums[i+1] == nums[i]) ++i;
			}	    
			return ans;
		}
};

int main(){
	int _arr[6] = { 1, 0, -1, 0, -2, 2 };
	vector<int> arr(_arr, _arr+6);
	vector< vector<int> > ans = Solution().fourSum(arr, 0);
	for(int i=0; i< ans.size(); ++i) {
			for(int j=0; j<ans[i].size(); ++j)
					cout << ans[i][j] << " ";
			cout << "\n";
	}
}
