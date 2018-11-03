#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void helper( vector<int> & can,int st, int target, vector<int>&path, vector<vector<int>>&ans){
	if( target == 0 ){
	    ans.push_back(path);
	    return;
	}
	for( auto i=st; i<can.size(); ++i ){
	    if( can[i] <= target ){
		path.push_back(can[i]);
		helper( can,i, target-can[i], path, ans );
		path.pop_back();
	    }
	    else
	    	break;
	}	
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<int> path;
	vector<vector<int>> ans;
	helper( candidates, 0, target, path, ans );
	return ans;
    }
};

int main(){
    vector<int> c = { 1,2,3 };
    vector<vector<int>> ans = Solution().combinationSum( c, 3 );
    for(auto it : ans){
	for(auto it2 : it )
	    cout << it2 <<" ";
	cout << endl;
    }
}
