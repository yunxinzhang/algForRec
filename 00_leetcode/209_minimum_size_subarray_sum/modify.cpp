#include <iostream>
#include <vector>
using namespace std;

//#define min(a,b) ((a)<(b)?(a):(b))
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		int p = 0, mv=-1; // start	
		int sz = nums.size();
		int minsz = sz + 1;
		int sum = 0;
		while(mv<sz && p<sz){
			if(sum < s && mv+1 < sz)
				sum += nums[++mv];
			else if(sum >= s){
				minsz = minsz < (mv-p+1)? minsz: mv-p+1;
				sum -= nums[p++];
			}else
				break;
		}
		return minsz > sz ? 0 : minsz;
    }
};

int main(){
	//int _arr[6] = {2,3,1,2,4,3};
	  int _arr[5] = {1,2,3,4,5};
	vector<int> arr(_arr,_arr+5);
	int ans = Solution().minSubArrayLen(11, arr);
	cout << ans <<endl;

}
