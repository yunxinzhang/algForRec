#include <iostream>
#include <vector>
#include <unordered_set> 
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
	return nums.size() < unordered_set<int>(nums.begin(), nums.end());
    }
};
int main(){
	vector<int> v = { 1,2,3,4};
	vector<int> v1 = { 1,2,3,1};
	cout << Solution().containsDuplicate( v ) <<endl;
	cout << Solution().containsDuplicate( v1 ) <<endl;

}
