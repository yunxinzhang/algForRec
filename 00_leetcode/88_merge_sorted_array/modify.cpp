#include <iostream>
#include <vector>
using namespace std;

// time complexity : O(n)
// space complexity: O(1)   better
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int p1 = m-1,  p2 = n-1, p = m+n-1;
		while( p1 >= 0 && p2 >= 0){
			if(nums1[p1] >= nums2[p2]){
				nums1[p--] = nums1[p1--];
			}else{
				nums1[p--] = nums2[p2--];
			}
		}
		while(p2 >= 0)
			nums1[p--] = nums2[p2--];
    }
};

int main(){
	int nums[6] = {1,2,3,0,0,0};
	int nums2[3] = {2,5,6};
	vector<int> v1(nums, nums+6);
	vector<int> v2(nums2, nums2+3);
	Solution().merge(v1,3, v2,3);
	for(int i=0; i< v1.size(); ++i){
		cout << v1[i] << " ";
	}
	cout << endl;

}
