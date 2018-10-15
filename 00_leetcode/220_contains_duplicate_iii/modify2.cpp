#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
// ~12ms

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		int sz = nums.size();
		if(sz < 2 || k <= 0)
			return false;
		vector< pair<long, int> > numsWithPos(sz, make_pair(0,0));
		for(int i=0; i<sz; ++i){
			numsWithPos[i].first = nums[i];
			numsWithPos[i].second = i;
		}
		sort( numsWithPos.begin(), numsWithPos.end() );
		set<int> pos;
		set<int>::iterator it;
		int r = 1; // pos :   [ l+1 , r )
		for( int l = 0; l < sz; ++l){
			pos.erase( numsWithPos[l].second );
			r = max(l+1, r);
			while( r < sz && numsWithPos[r].first - numsWithPos[l].first <= t ){
				pos.insert( numsWithPos[r].second );
				++r;
			}
			it = pos.lower_bound( numsWithPos[l].second - k );
			if( it != pos.end() && *it <= numsWithPos[l].second + k ){
				return true;
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
