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
    vector<string> letterCombinations(string digits) {
	vector<string> ans;
	if(digits.size() == 0)
		return ans;
	ans.push_back("");
	for( size_t i = 0; i < digits.size(); ++i ){
		vector<string> temp;
		size_t idx = digits[i] - '0';
		for( size_t j = 0; j < ans.size(); ++j ){
			for( size_t k = 0; k < dict[idx].size(); ++k ){
				temp.push_back( ans[j] + dict[idx][k] );
			}
		}
		ans = temp;
	}
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
