#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int vx[4] = { 0, 0, 1, -1 };
    int vy[4] = {-1, 1, 0,  0 };
    vector<pair<int,int>> ans;
    vector<vector<int>>visited;
    bool isValid( int x, int y, int cmp){
	if(x<0 || y<0 || x>=visited.size() || y>=visited[0].size() || visited[x][y]>cmp)
	    return false;
	return true;
    }
    void dsf(int x, int y, vector<vector<int>> & b,int add, int cmp){
	visited[x][y] += add;
	for(int i = 0; i<4; ++i){
	    int x2 = x + vx[i];
	    int y2 = y + vy[i];
	    if( isValid(x2, y2, cmp) ){
		if( b[x2][y2] >= b[x][y] )
		    dsf(x2, y2, b, add, cmp);	
	    }
	}
    }
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
	ans.clear();
	if(matrix.size() == 0 || matrix[0].size() == 0)
	    return ans;
	visited = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(),0));
	for( int i=0; i<matrix.size(); ++i){
	    if(visited[i][0] == 0 )
	   	 dsf(i, 0, matrix, 1, 0 );
	}
	for( int i=1; i<matrix[0].size(); ++i ){
	    if(visited[0][i] == 0 )
	    	dsf(0, i, matrix, 1, 0 );
	}
	for( int i=0; i<matrix.size(); ++i){
	    if(visited[i][matrix[0].size()-1] < 2 )
	    dsf(i, matrix[0].size()-1, matrix, 3, 2 );
	}
	for( int i=0; i<matrix[0].size()-1; ++i ){
	    if(visited[matrix.size()-1][i] < 2 )
	    dsf(matrix.size()-1, i, matrix, 3, 2 );
	}
	for( int i=0; i<matrix.size(); ++i){
	    for(int j=0; j<matrix[0].size(); ++j){
		if(visited[i][j] == 4)
		    ans.push_back(make_pair(i,j));
	    }
	}	
	return ans;
    }
};


int main(){
	vector<vector<int>> b = {
	    {1,2,2,3,5},
	    {3,2,3,4,4},
	    {2,4,5,3,1},
	    {6,7,1,4,5},
	    {5,1,1,2,4}
	};
	vector<pair<int,int>> ans = Solution().pacificAtlantic(b);
	for(auto it : ans)
		cout << it.first <<" " <<it.second <<endl;
}
