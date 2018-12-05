#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int> > dp(m+1, vector<int>(n+1, 0));										        
		for(int i=0; i<strs.size(); ++i){
			int nones = count(strs[i].begin(), strs[i].end(), '1');
			int nzeros = strs[i].size() - nones;
			for( int j=m; j >= nzeros; --j)
				for(int k=n; k >= nones; --k){
					dp[j][k] = max(dp[j][k], dp[j-nzeros][k-nones] +1);			
				}
		}					    
		return dp[m][n];
	}
};

int main(){
	vector<string> v = {"10", "0001", "111001", "1", "0"};
	cout << Solution().findMaxForm(v, 5, 3) << endl;
}
