#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		int left = 0; // [ left, i ]; sum
		int ans = INT_MAX;
		int sz = nums.size();
		int sum = 0;
		for(size_t i=0; i<sz; ++i){
			sum += nums[i];
			while(sum >= s){
				ans = ans < (i-left+1) ? ans : i-left+1;
				sum -= nums[left++];
			}
		}
		return ans == INT_MAX ? 0 : ans;
    }
};

int main(){
	//int _arr[6] = {2,3,1,2,4,3};
	  int _arr[5] = {1,2,3,4,5};
	vector<int> arr(_arr,_arr+5);
	int ans = Solution().minSubArrayLen(11, arr);
	cout << ans <<endl;

}
