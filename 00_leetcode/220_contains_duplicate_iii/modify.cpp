#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
using namespace std;


class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if(nums.size() < 2 || k <= 0)
			return false;
		deque<int> que;
		multiset<int> mset;
		for( int i=0; i<nums.size(); ++i){
			if(que.size() > k){
				mset.erase(mset.find(que[0]));
				que.pop_front();
			}
			que.push_back(nums[i]);
			auto it = lower_bound(mset.begin(), mset.end(), (long)nums[i] - (long)t);
			if(it == mset.end() || *it >(long) nums[i] + (long) t )
				mset.insert(nums[i]);
			else	
				return true;
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
