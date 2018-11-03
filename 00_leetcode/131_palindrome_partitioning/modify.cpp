#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMirror(string &s, int st, int ed){
 	for(; st < ed ; ++st, --ed){
 	    if( s[st] != s[ed] )
		return false;
	}		
	return true;
    }
    void helper(string &s, int idx, vector<string> & v,vector<vector<string>> &ans){
	if( idx == s.size() )
		ans.push_back(v);
	for( int j = idx; j < s.size(); ++j){// [i,j]
	    if( !isMirror( s, idx, j )) 
		continue;
	    v.push_back( s.substr(idx, j-idx+1) );
 	    helper( s, j+1, v, ans );
	    v.pop_back();
	}	
    }
    vector<vector<string>> partition(string s) {
       	vector<vector<string>> ans; vector<string> v;
	helper( s, 0,  v, ans);
	return ans;
    }
};
int main(){
	string s = "cdd";
	vector<vector<string>> ans = Solution().partition(s);
	for(auto it : ans){
		for(auto it2: it)
			cout << it2 <<" ";
		cout << endl;
	}
}
