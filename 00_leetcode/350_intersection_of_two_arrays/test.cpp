#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
	public:
		vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
			set<int> s1(nums1.begin(), nums1.end()), ans;
			for(size_t i=0; i<nums2.size(); ++i){
				if(s1.find(nums2[i]) != s1.end())
						ans.insert(nums2[i]);
			}
			return vector<int>(ans.begin(), ans.end());
		}

};


int main(){
	int _a1[4] = { 1,2,2,1 };
	int _a2[2] = { 2,2 };
	vector<int> a1(_a1, _a1+4);
	vector<int> a2(_a2, _a2+2);
	vector<int> ans = Solution().intersection(a1,a2);
	for(int i=0; i<ans.size(); ++i){
			cout << ans[i] <<endl;
	}
}
