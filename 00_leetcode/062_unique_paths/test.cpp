#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector< vector<int> > ans(m, vector<int>(n, 0));
		for( int i = 0; i < m; ++i )
				ans[i][0] = 1;
		for( int i = 0; i < n; ++i )
				ans[0][i] = 1;
		for( int r = 1; r < m; ++r )
				for(int c = 1; c < n; ++c)
						ans[r][c] = ans[r-1][c] + ans[r][c-1];
		return ans[m-1][n-1];
	}
};

int main(){
	cout << Solution().uniquePaths(3,2) << endl;
	cout << Solution().uniquePaths(7,3) << endl;
}
