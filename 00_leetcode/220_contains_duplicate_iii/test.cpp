#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//  200+ ms

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if(nums.size() < 2 || k <= 0)
			return false;
		int l = 0, r = 1; // [ l, r ];
		while( r < nums.size() ){
			for(int i=l; i<r; ++i)
				if((long)abs(nums[r]- (long) nums[i]) <=t)
					return true;
			if( r - l < k ){
				++r;
			}else if( r - l == k ){
				++r; 
				++l;
			}
		}        	
		return false;
    	}        
};
int main(){
	vector<int> v = { 1,2,3,1};
	int k = 3, t = 0;
	cout << Solution().containsNearbyAlmostDuplicate( v, k, t) << endl;
	vector<int> v1 = { 1,0,1,1};
	k = 3, t = 0;
	cout << Solution().containsNearbyAlmostDuplicate( v1, k, t) << endl;
	vector<int> v2 = { 1,5,9,1,5,9};
	k = 2, t = 3;
	cout << Solution().containsNearbyAlmostDuplicate( v2, k, t) << endl;

}
