#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		map<int,int>n2i;
		for(int i=0; i<nums1.size(); ++i){
				if(n2i.find(nums1[i]) == n2i.end()){
						n2i.insert(make_pair(nums1[i], 1));
				}else{
						++n2i[nums1[i]];
				}
		}
		vector<int> ans;
		for(int i=0; i<nums2.size(); ++i){
				if(n2i.find(nums2[i]) != n2i.end()){
						ans.push_back(nums2[i]);
						--n2i[nums2[i]];
						if(n2i[nums2[i]] == 0)
								n2i.erase(nums2[i]);
				}
		}
		return ans;
	}
};

int main(){
	int _a1[4] = { 1,2,2,1 };
	int _a2[2] = { 2,2 };
	vector<int> a1(_a1, _a1+4);
	vector<int> a2(_a2, _a2+2);
	vector<int> ans = Solution().intersect(a1,a2);
	for(int i=0; i<ans.size(); ++i){
			cout << ans[i] <<endl;
	}
}
