#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  		vector<int> v(m+n);
		size_t p1 =0,  p2 = 0;
		for(int i=0; i< m+n; ++i){
			if(p1 < m && p2 < n){
				if( nums1[p1] <= nums2[p2] )
					v[i] = nums1[p1++];
				else
					v[i] = nums2[p2++];
			}else if(p1 == m)
				 v[i] = nums2[p2++];
			else
				 v[i] = nums1[p1++];
		}      
		nums1 = v;
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
