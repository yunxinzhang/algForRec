#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void helper( int st, int target, int step,vector<int>&path, vector<vector<int>>&ans){
	if( step == 0){
	    if(target == 0)
	    	ans.push_back(path);
	    return;
	}
	for( auto i=st; i<= 10-step; ++i ){
	    if( i <= target ){
		path.push_back(i);
		helper( i+1, target-i,step-1, path, ans );
		path.pop_back();
	    }
	    else
	    	break;
	}	
    }
    vector<vector<int>> combinationSum(int k, int n) {
	vector<int> path;
	vector<vector<int>> ans;
	helper( 1,n ,k, path, ans );
	return ans;
    }
};

int main(){
    vector<vector<int>> ans = Solution().combinationSum( 3, 9 );
    for(auto it : ans){
	for(auto it2 : it )
	    cout << it2 <<" ";
	cout << endl;
    }
}
