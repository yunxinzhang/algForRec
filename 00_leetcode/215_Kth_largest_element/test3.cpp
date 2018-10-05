#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int partition(vector<int> & nums, int l, int r){// [ l, r ] 
		size_t sz = r - l + 1;
		int rnd = rand() % sz;
		swap(nums[l], nums[l + rnd]);
		size_t p = l + 1;
		for(size_t i= p; i<l+sz; ++i){
			if(nums[i] > nums[l])
				swap(nums[p++], nums[i]);
		}
		swap(nums[l], nums[p-1]);
		return p-1;
	}	
    int findKthLargest(vector<int>& nums, int k) {
		int pos = -1;
		int l = 0, r = nums.size()-1;
		while(true){
			pos = partition(nums, l, r);
			if(pos == k-1)
				return nums[pos];
			else if(pos < k-1){
				l = pos + 1;
			}else{
				r = pos - 1;
			}
		}
    }
};

int main(){
	int arr[9] = {3,2,3,1,2,4,5,5,6};
//	int arr[6] = {3,2,1,5,6,4};
	vector<int> v(arr, arr+9);
	int a = Solution().findKthLargest(v, 4);
	cout << a <<endl;
}

