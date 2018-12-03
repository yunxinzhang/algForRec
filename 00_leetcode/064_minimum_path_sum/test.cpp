#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int> >& grid) {
		int r = grid.size(), c = grid[0].size();	
		vector< vector<int> >  ans(r, vector<int>(c, 0));						        
		ans[0][0] = grid[0][0];
		for(int i=1; i<r; ++i)
				ans[i][0] = grid[i][0] + ans[i-1][0];
		for(int j=1; j < c; ++j){
				ans[0][j] = grid[0][j] + ans[0][j-1];
		}
		for(int i=1; i < r; ++i){
				for(int j=1; j < c; ++j){
					ans[i][j] = grid[i][j] + min(ans[i-1][j], ans[i][j-1]);
				}
		}
	    return ans[r-1][c-1];
	}
};
int main(){
	vector< vector<int> > v;
	vector<int> v1 = {1,3,1};
	v.push_back( v1 );
	vector<int> v2 = {1,5,1};
	v.push_back( v2 );
	vector<int> v3 = {4,2,1};
	v.push_back( v3 );
	cout << Solution().minPathSum(v) << endl;
}
