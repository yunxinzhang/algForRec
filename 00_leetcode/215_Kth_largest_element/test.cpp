#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		size_t sz = nums.size();
  		int rnd = rand() % sz;
		swap(nums[0], nums[rnd]);
		size_t p = 1;
		for(int i=1; i<sz; ++i){
			if(nums[i] < nums[0]){
				swap(nums[p++], nums[i]);
			}
		}    
		if(k == sz - p + 1){
			return nums[0];
		} else if(k > sz - p + 1){
			vector<int> v(nums.begin()+1,nums.begin()+p);
			return findKthLargest(v, k- (sz-p+1));
		} else{
			vector<int> v(nums.begin() + p,nums.end());
			return findKthLargest(v, k);
		}
    }
};

int main(){
//	int arr[9] = {3,2,3,1,2,4,5,5,6};
	int arr[6] = {3,2,1,5,6,4};
	vector<int> v(arr, arr+6);
	int a = Solution().findKthLargest(v, 2);
	cout << a <<endl;
}

