#include <iostream>
#include <vector>
// error
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int n= nums.size();
		if(n == 0)
				return 0;
		vector<int> ans(n, 0);
		vector<bool> c0(n, false);
		ans[0] = nums[0];
		c0[0] = true;
		int pre, cur;
		for(int i = 1; i < n; ++i){
			if( i < n-1 )
				cur = nums[i] + (i>=2 ? ans[i-2]:0);	
			else{
				if(i>=2)
						if(c0[i-2])
							cur = nums[0] > nums[n-1] ? ans[i-2] : ans[i-2] - nums[0] + nums[n-1];
						else
							cur = nums[n-1] + ans[i-2];
				else
						cur = nums[n-1];
			}

			if(cur >= ans[i-1]){
					if(i-2>=0)
							c0[i] = c0[i-2];
					ans[i] = cur;
			}else{
					ans[i] = ans[i-1];
					c0[i] = c0[i-1];
			}
		}				    

		for(int i=0; i<n;++i)
				cout << ans[i] <<" ";
		cout << endl;
		for(int i=0; i<n;++i)
				cout << c0[i] <<" ";
		cout << endl;
		return ans[n-1];
	}
};

int main(){
	vector<int> v{1,2,3,1};
	vector<int> v2{2,7,9,3,1};
	vector<int> v3{2,3,2};
	vector<int> v4{1,2,3,1};
	vector<int> v5{1,7,3};
	vector<int> v6{1,1,1,2};
	vector<int> v7{2,2,4,3,2,5};
	cout << Solution().rob(v) << endl;
	cout << Solution().rob(v2) << endl;
	cout << Solution().rob(v3) << endl;
	cout << Solution().rob(v4) << endl;
	cout << Solution().rob(v5) << endl;
	cout << Solution().rob(v6) << endl;
	cout << Solution().rob(v7) << endl;
}
