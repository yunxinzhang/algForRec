#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    void helper( vector<int>&nums,int idx, vector<int>&path, set<vector<int>>& ans){
	if( idx == nums.size()){
	    ans.insert(path);
	    return;
 	}
	path.push_back( nums[idx] );
	helper(nums, idx+1, path, ans);
	path.pop_back();
	helper(nums, idx+1, path, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<int> path;
	set<vector<int>> ans;
	helper( nums, 0, path, ans);
	return vector<vector<int>>(ans.begin(), ans.end());	        
    }
};

int main(){
	vector<int> a = {1,2,3};
	vector<vector<int>> ans = Solution().subsets( a);
	for(auto it : ans ){
		for(auto it2 :it){
			cout << it2 <<" ";
		}
		cout << endl;
	}
}
