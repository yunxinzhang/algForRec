#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:   
    pair<int,int> dir[4] = { {1,0},{-1,0},{0,1},{0,-1}};
    bool valid( int x, int y, vector<vector<bool>> & v ){
	if( x < 0 || y < 0 || x >= v.size() || y >= v[0].size()|| v[x][y] )
		return false;
	return true;
    }
    void bsf( int x, int y, vector<vector<char>> & b, vector<vector<bool>> &v ){
	if ( b[x][y] == '0' )
		return;
	v[x][y] = true;
	for( int i=0; i<4; ++i){
	    int nx = x+dir[i].first;
	    int ny = y+dir[i].second;
	    if( valid( nx, ny, v )){
		bsf(nx, ny, b, v);
	    }
	}
    }
    int numIslands(vector<vector<char>>& board) {
	if(board.size() == 0 || board[0].size() == 0)
		return 0;
	int cnt = 0;
	vector<vector<bool>> v(board.size(), vector<bool>(board[0].size(), false));
	for(int i=0; i< board.size(); ++i){
	    for(int j=0; j<board[0].size(); ++j){
		if( board[i][j] == '1' && !v[i][j]){
			bsf(i,j,board,v);
			++cnt;	
		}
	    }
	}        
	return cnt;
    }
};

int main(){
	vector<vector<char>> b = {
	{'1','1','1','1','0'},
	{'1','1','0','1','0'},
	{'1','1','0','0','0'},
	{'0','0','1','0','0'}
	};
	cout << Solution().numIslands( b ) <<endl; 

}
