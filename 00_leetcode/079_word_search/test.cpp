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
    bool bsf( int x, int y, vector<vector<char>> & b, vector<vector<bool>> &v, string word, int idx ){
	if( b[x][y] != word[idx] )
	    return false;
 	v[x][y] = true;
	if( idx == word.size()-1 )
	    return true;
	for( int i=0; i<4; ++i){
	    int nx = x+dir[i].first;
	    int ny = y+dir[i].second;
	    if( valid( nx, ny, v )){
		if(bsf(nx, ny, b, v, word, idx+1))
		    return true;
	    }
	}
	v[x][y] = false;
	return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
	if(board.size() == 0 || board[0].size() == 0)
		return false;
	if(word.size()==0)
		return true;
	vector<vector<bool>> v(board.size(), vector<bool>(board[0].size(), false));
	for(int i=0; i< board.size(); ++i){
	    for(int j=0; j<board[0].size(); ++j){
		if(bsf(i,j,board,v,word, 0))
		    return true;
	    }
	}        
	return false;
    }
};

int main(){
	vector<vector<char>> b = {{'a','b','c','d'},{'s','f','c','s'},{'a','d','e','e'}};
	string s = "add";
	cout << Solution().exist( b, s ) <<endl; 

}
