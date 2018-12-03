#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
		int r = obstacleGrid.size();
		int c = obstacleGrid[0].size();
		if(obstacleGrid[0][0] == 1 || obstacleGrid[r-1][c-1] == 1)
			return 0;
		vector< vector<int> > ans(r, vector<int>(c, 0));
		ans[0][0] = 1;
		for( int i = 1; i < r; ++i ){
				if (obstacleGrid[i][0] != 1){
						ans[i][0] = 1;
				}else
						break;
		}				    
		for( int i = 1; i < c; ++i ){
				if (obstacleGrid[0][i] != 1){
						ans[0][i] = 1;
				}else
						break;
		}				    
		for( int i = 1; i < r; ++i )
				for(int j = 1; j < c; ++j)
						if(obstacleGrid[i][j] != 1)
								ans[i][j] = ans[i-1][j] + ans[i][j-1];
		return ans[r-1][c-1];
	}
};

int main(){

}
