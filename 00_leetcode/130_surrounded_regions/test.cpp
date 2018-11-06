#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:   
    pair<int,int> dir[4] = { {1,0},{-1,0},{0,1},{0,-1}};
    bool valid( int x, int y, vector<vector<bool>> & v ){ // 0 1 -1
	if( x < 0 || y < 0 || x >= v.size() || y >= v[0].size() || v[x][y] )
		return false;
	return true;
    }
    void bsf( int x, int y, vector<vector<char>> & b, vector<vector<bool>> &v ){
	if ( b[x][y] == 'X' )
		return;	//  near borad
	else{
	  	v[x][y] = true;
	}
	for( int i=0; i<4; ++i){
	    int nx = x+dir[i].first;
	    int ny = y+dir[i].second;
	    if( valid(nx,ny,v)){
		bsf(nx, ny, b, v);
	    }
	}
    }
    void solve(vector<vector<char>>& board) {
	if(board.size() == 0 || board[0].size() == 0)
		return;
	vector<vector<bool>> v(board.size(), vector<bool>(board[0].size(), false));
	vector<pair<int,int>> os;
	for(int i=0, r=board.size(); i< r; ++i){
	    for(int j=0, c=board[0].size(); j<c; ++j){
		if((i==0) || (i==(r-1)) || j==0 || j==(c-1)){
			bsf(i,j,board,v);
		}
		if( board[i][j] == 'O' )
			os.push_back(make_pair(i,j));
	    }
	}        
	for( auto it : os ){
		if( !v[it.first][it.second] ){
			board[it.first][it.second] = 'X';
		}
	}
    }
};

int main(){
	vector<vector<char>> b = {
	{'X','X','X','X'},
	{'X','O','O','X'},
	{'X','X','O','X'},
	{'X','O','X','X'}
	};
	Solution().solve( b ); 
	for(auto it : b){
		for(auto it2 : it){
			cout << it2 << " ";
		}
		cout << endl;
	}

}
