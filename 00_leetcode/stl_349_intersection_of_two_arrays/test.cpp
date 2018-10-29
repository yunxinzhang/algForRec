#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> s1(nums1.begin(),nums1.end());
		set<int> _ans;
		for( vector<int>::iterator it= nums2.begin(); it != nums2.end(); ++it){
			if(s1.find(*it) != s1.end()){
				_ans.insert(*it);
			}
		}
		return vector<int>(_ans.begin(), _ans.end());
    }
};

int main(){
	int _n1[3] = {4,9,5};
	int _n2[5] = {9,4,9,8,4};
	vector<int> nums1(_n1, _n1+3);
	vector<int> nums2(_n2, _n2+5);
	vector<int> ans = Solution().intersection(nums1, nums2);
	for(int i=0; i<ans.size(); ++i){
		cout << ans[i]<<endl;
	}
}
