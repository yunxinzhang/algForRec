#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void helper( int n, int idx, int re, vector<int>&path, vector<vector<int>>&ans ){
	if( re == 0 ){
	    ans.push_back(path);
	    return;
     	}
	for( int i = idx; i<=n-re+1; ++i){
	    path.push_back( i );
	    helper( n, i+1, re-1, path, ans );
	    path.pop_back( );
	}
    }
    vector<vector<int>> combine(int n, int k) {
	vector<int> path;
	vector<vector<int>> ans;
	helper( n, 1, k, path, ans );	        
	return ans;
    }
};

int main(){
    vector<vector<int>> ans = Solution().combine( 4, 2 );
    for(auto it : ans ){
	for(auto it2 : it)
	    cout << it2 <<" ";
	cout <<endl;
    }
}
