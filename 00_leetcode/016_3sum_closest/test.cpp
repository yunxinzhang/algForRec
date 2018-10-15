#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
	assert(nums.size() >= 3);
	sort(nums.begin(), nums.end());
	int re, l, r, rm;
	int closest = INT_MAX;
	int ans;
	for(int i=0; i< nums.size()-2; ++i){
		l = i+1; 
		r = nums.size() -1;
		re = target - nums[i];
		while( l < r ){
			rm = re - ( nums[l] + nums[r] ); 
			if( abs(rm) < closest ){ 
				closest = abs(rm);
				ans = target - rm;
			}
			if( rm > 0){
				++l;
				while(l<r && nums[l] == nums[l-1])++l;  
			}else if( rm < 0 ){
				--r;
				while(r>l && nums[r] == nums[r+1])--r;  
			}else{
				return target - rm;
			}
		}
	}	
	return ans;
    }
};

int main(){
	int _arr[4] = { -1, 2, 1, -4 };
	vector<int> arr(_arr, _arr+4);
	cout << Solution().threeSumClosest( arr, 1 ) << endl;

}
