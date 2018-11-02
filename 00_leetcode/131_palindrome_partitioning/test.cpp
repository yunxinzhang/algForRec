#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMirror(string s){
 	for(int i=0; i<s.size()/2; ++i){
 	    if( s[i] != s[s.size()-1-i] )
		return false;
	}		
	return true;
    }
    void helper(string &s, int idx, vector<string> & v, bool left,vector<vector<string>> &ans){
	if( idx == s.size() )
		return;
	if( idx == s.size()-1 ){
		if(left){
			if(v.size()>0 && !isMirror(v[v.size()-1]))
				return;
			v.push_back(s.substr(idx,1));
			ans.push_back(v);
			v.pop_back();
		}else{
			if( isMirror(v[v.size()-1]+s[idx]) ){
				v[v.size()-1] += s[idx];
				ans.push_back(v);
				v[v.size()-1] = v[v.size()-1].substr(0,v[v.size()-1].size()-1);
			} 
		}
		return;
	}
  	if(left){
		if( v.size() > 0 && !isMirror(v[v.size()-1]))
			return;
		v.push_back( s.substr(idx,1) );
		helper(s, idx+1, v, true, ans);
		helper(s, idx+1, v, false, ans);
		v.pop_back();
	}else{
		v[v.size()-1] += s[idx];
		helper(s, idx+1, v, true,ans);
		helper(s, idx+1, v, false,ans);
		v[v.size()-1] = v[v.size()-1].substr(0,v[v.size()-1].size()-1);
	}		
    }
    vector<vector<string>> partition(string s) {
       	vector<vector<string>> ans; vector<string> v;
	helper( s, 0,  v, true, ans);
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
