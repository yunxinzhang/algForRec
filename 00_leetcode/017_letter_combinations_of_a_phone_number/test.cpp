#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string dict[10] = {
	" ",
	" ",
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqrs",
	"tuv",
	"wxyz"	
    };
    void help( string &str, int idx, const string & word, vector<string> & ans){
	if( idx == str.size()-1 ){
	    for(auto i = 0; i < dict[str[idx]-'0'].size(); ++ i)
		ans.push_back( word + dict[str[idx]-'0'][i] );
	    return ;
	}		
  	for(auto i = 0; i < dict[str[idx] - '0'].size(); ++i){
	    help( str, idx+1, word+dict[str[idx]-'0'][i], ans );
	}	
    }
    vector<string> letterCombinations(string digits) {
	vector<string> ans;
	if(digits.size() == 0)
		return ans;
	help(digits, 0, "", ans);
	return ans;
    }	
};

int main(){
	vector<string> ans;
	string str = "23";
	ans = Solution().letterCombinations( str );
	cout << ans.size() << endl;	
	for(auto it : ans)
		cout << it << endl;
}
