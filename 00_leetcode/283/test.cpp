#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		size_t sz = nums.size();
		size_t p = 0; // to write
  		for(size_t i=0; i < sz; ++i){
			if(nums[i] != 0){
				nums[p++] = nums[i];
			}
		}      
		for(size_t i=p-1; i < sz;){
			nums[++i] = 0;
		}
    }
};
// [4,2,4,0,0,3,0,5,1,0]
int main(){
	vector<int> v;
	v.push_back(4);
	v.push_back(2);
	v.push_back(4);
	v.push_back(0);
	v.push_back(0);
	v.push_back(3);
	v.push_back(0);
	v.push_back(5);
	v.push_back(1);
	v.push_back(0);
	Solution slv;
	for(int i=0; i<v.size(); ++i){
		cout << v[i] << " ";
	}
	cout << "\n";
	slv.moveZeroes(v);
	for(int i=0; i<v.size(); ++i){
		cout << v[i] << " ";
	}
	cout << "\n";

}
