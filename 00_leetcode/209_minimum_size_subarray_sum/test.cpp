#include <iostream>
#include <vector>
using namespace std;
//#define min(a,b) ((a)<(b)?(a):(b))
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		size_t p = 0, mv; // start	
		size_t sz = nums.size();
		size_t minsz = sz + 1;
		int sum = 0;
		while(p < sz){
			mv = p;
			sum = nums[mv];
			while( sum < s && (mv+1) < sz ){
				sum += nums[++mv]; 
			}
			if( sum >= s ){
				minsz = min(minsz, (mv-p+1));
				++p;
			}else{
				break;
			}
		}
		return minsz;
    }
};

int main(){
	//int _arr[6] = {2,3,1,2,4,3};
	int _arr[5] = {1,2,3,4,5};
	vector<int> arr(_arr,_arr+5);
	int ans = Solution().minSubArrayLen(11, arr);
	cout << ans <<endl;

}
