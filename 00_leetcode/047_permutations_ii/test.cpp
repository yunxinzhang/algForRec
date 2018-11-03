#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void helper( vector<int> & nums, vector<bool> &dict, vector<int>&path, set<vector<int>> & ans){
	if( path.size() == nums.size()){
		ans.insert(path);
		return;
	}
	for(int i=0; i<dict.size(); ++i){
	    if(dict[i])
		continue;
	    dict[i] = true;
	    path.push_back( nums[i] );
	    helper(nums, dict, path, ans);
	    dict[i] = false;
	    path.pop_back();
	}
    }
    vector<vector<int>> permute(vector<int>& nums) {
	set<vector<int>> ans;
	vector<int> path;
	vector<bool> dict(nums.size(), false);
	helper( nums, dict, path, ans );
	vector<vector<int>> ans2(ans.begin(), ans.end());
	return ans2;     
    }
};

int main(){
	vector<int> nums = { 1,2,1};
	vector<vector<int>> ans = Solution().permute(nums);
	for(auto it : ans){
		for(auto it2 : it){
			cout << it2 << " ";
		}
		cout << endl;
	}
}
