#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int> & nums, int k) {
     	 int l = 0, r = 0;  	// [ l, r )
	unordered_set<int> uset;
	while(r < nums.size() ){
		if(uset.find(nums[r]) == uset.end()){
			uset.insert(nums[r]);
			++r;
		}else{
			return true;
		}
		if( r - l > k ){
			uset.erase(nums[r-k-1]);
			++l;
		}
	}
	return false;
    }
};
int main(){
	vector<int > v = { 1, 2, 3, 1};
	cout << Solution().containsNearbyDuplicate( v, 3 ) <<endl;
	cout << Solution().containsNearbyDuplicate( v, 2 ) <<endl;

}
