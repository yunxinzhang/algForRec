#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int findKth(vector<int> & nums, int l, int r, int k){
		size_t sz = r - l + 1;
		int rnd = rand() % sz;
		swap(nums[l], nums[l + rnd]);
		size_t p = l + 1;
		for(size_t i= p; i<l+sz; ++i){
			if(nums[i] < nums[l])
				swap(nums[p++], nums[i]);
		}
		if(k == sz - p + 1 + l){
			return nums[l];
		} else if(k > sz - p + 1 + l){
			return findKth(nums, l+1, p-1,  k- (sz-p+1+l));
		} else{
			return findKth(nums, p, r, k);
		}
	}	
    int findKthLargest(vector<int>& nums, int k) {
		return findKth(nums, 0, nums.size()-1, k);
    }
};

int main(){
	int arr[9] = {3,2,3,1,2,4,5,5,6};
//	int arr[6] = {3,2,1,5,6,4};
	vector<int> v(arr, arr+9);
	int a = Solution().findKthLargest(v, 4);
	cout << a <<endl;
}

