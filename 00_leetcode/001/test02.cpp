#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		map<int,size_t> num2idx;
		int toFind;
		size_t sz = nums.size();
        for(size_t i=0; i<sz; ++i){
				toFind = target - nums[i];
				if(num2idx.find(toFind) != num2idx.end()){
					vector<int> v;
					v.push_back(num2idx.find(toFind)->second);
					v.push_back(i);
					return v;
				}
			//	num2idx.insert(pair<int,int>(nums[i], i));
				num2idx[nums[i]] = i;  // neat code            
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
