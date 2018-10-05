#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		nth_element(nums.begin(), nums.begin() + k -1, nums.end(),greater<int>());
		return nums[k-1];
    }
};

int main(){
	int arr[9] = {3,2,3,1,2,4,5,5,6};
//	int arr[6] = {3,2,1,5,6,4};
	vector<int> v(arr, arr+9);
	int a = Solution().findKthLargest(v, 4);
	cout << a <<endl;
}

