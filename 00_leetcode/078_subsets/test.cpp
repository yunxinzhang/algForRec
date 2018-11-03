#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void helper( vector<int>&nums, int idx, vector<int>&path, vector<vector<int>>& ans){
	if( idx == nums.size()){
	    ans.push_back(path);
	    return;
 	}
	path.push_back( nums[idx] );
	helper(nums, idx+1, path, ans);
	path.pop_back();
	helper(nums, idx+1, path, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
	vector<int> path;
	vector<vector<int>> ans;
	helper( nums, 0, path, ans);
	return ans;	        
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
