#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    
    int numSquares(int n) {
		vector<int> ans(n+1, n);
		for(int i = 1; i < n; ++i){
				if( i*i > n )
						break;
				ans[i*i] = 1;
		}
		for( int i = 2; i < n+1; ++i ){
				if( ans[i] == 1 )
						continue;
				for(int j = 1; j <= i/2; ++j){
						ans[i] = min(ans[i], ans[j]+ans[i-j]); 
				}
		}
//		for(int i=0; i<n; ++i)
//				cout << ans[i] << " ";
//		cout <<endl;
		return ans[n];
    }
};

int main(){
	cout << Solution().numSquares( 13 ) << endl;
	cout << Solution().numSquares( 15 ) << endl;
}
