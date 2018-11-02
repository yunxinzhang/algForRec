#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void helper( string & str, int idx, int addth, const string path, vector<string>&ans){
	if( idx > str.size() )
	    return;
	if( str.size() - idx > (4-addth)*3 || str.size() -idx < 4 - addth )
	    return;
	for(size_t i=1; i<=3; ++i){
	    if( addth < 2 ){
		string word= str.substr(idx, i);
		if( word.size() > 1 && word[0] == '0' )
		    continue;
		if( atoi( word.c_str()) > 255 )
		    continue;
		helper( str, idx + i, addth + 1, path+"."+word, ans);
	    }else{
		string word1 = str.substr( idx , i);
		if( word1.size() > 1 && word1[0] == '0' )
		    continue;
		if( str.size() <= idx + i)
		    continue;
		string word2 = str.substr( idx + i);
		if( word2.size() > 1 && word2[0] == '0' )
		    continue;
		if( atoi( word1.c_str()) <= 255 && atoi(word2.c_str()) <= 255 ){
		    ans.push_back( (path + "." + word1 + "." + word2).substr(1 ));
		}
	    }
	}
    }
    vector<string> restoreIpAddresses(string s) {
	vector<string> ans;
	helper(s, 0, 0, "", ans);
	return ans; 
    }
};

int main(){
	string s = "255255255255";
	vector<string> ans = Solution().restoreIpAddresses(s);
	for(auto it : ans)
		cout << it << endl;
}
