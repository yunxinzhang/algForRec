#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void helper( vector<int> nums, int st, int ed, vector<vector<int>> & ans){
	if( st == ed-1 ){
		ans.push_back(nums);
		return;
	}
	for(int i = st; i < ed; ++i){
		if( i != st && nums[i] == nums[st] )
			continue;
		swap( nums[i], nums[st] );
		helper( nums, st+1, ed, ans );
	}
    }
    vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
	helper( nums, 0, nums.size(), ans );
	return ans;     
    }
};

int main(){
	vector<int> nums = { 2,1,2,1};
	vector<vector<int>> ans = Solution().permute(nums);
	for(auto it : ans){
		for(auto it2 : it){
			cout << it2 << " ";
		}
		cout << endl;
	}
}
