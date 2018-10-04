#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       for(size_t i=0; i<nums.size(); ++i){
			for(size_t j=i+1; j<nums.size(); ++j){
				if(nums[i]+nums[j] == target){
					vector<int> ans;
					ans.push_back(i);
					ans.push_back(j);
					return ans;
				}
			}
		}
			vector<int> v;
			return v;
    }
};

int main(){
	vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(6);
    v.push_back(14);
    v.push_back(33);
	Solution slv;
	vector<int> ans = slv.twoSum(v, 8);
	for(vector<int>::iterator it = ans.begin(); it != ans.end(); ++it)
		cout << *it << endl;
}
