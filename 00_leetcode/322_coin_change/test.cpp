#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		sort(coins.begin(), coins.end());
		vector<int>  trans(amount+1, amount+1);						        
		trans[0] = 0;
		int n= coins.size();
		int num = coins[0], cnt = 0;
		while(num <= amount){
			trans[num] = min(++cnt, trans[num]);
			num += coins[0];
		}
		int res;
		for(int i=1; i<n; ++i){
			for(int j = coins[i]; j <= amount; ++j){
				trans[j] = min(1 + trans[j-coins[i]], trans[j]);
			}
		}
		for(auto it : trans)
				cout << it <<" ";
		cout << endl;
		return trans[amount] > amount ? -1 : trans[amount];
	}
};

int main(){
	vector<int> coins = {1,2,5};
	cout << Solution().coinChange(coins, 11) << endl;
	cout << Solution().coinChange(coins, 7) << endl;
}
