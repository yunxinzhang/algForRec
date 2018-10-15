#include <iostream>
#include <vector>
#include <unordered_set> 
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
	unordered_set<int> uset;
	for(size_t i=0; i<nums.size(); ++i){
		if(uset.find(nums[i]) == uset.end()){
			uset.insert(nums[i]);
		}else{
			return true;
		}
	}
	return false;
    }
};
int main(){
	vector<int> v = { 1,2,3,4};
	vector<int> v1 = { 1,2,3,1};
	cout << Solution().containsDuplicate( v ) <<endl;
	cout << Solution().containsDuplicate( v1 ) <<endl;

}
