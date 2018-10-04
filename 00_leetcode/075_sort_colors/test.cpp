#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
    	size_t cnt[3] = {0};
		size_t sz = nums.size();
		for(size_t i=0; i<sz; ++i){
			++cnt[nums[i]];
		}
		size_t idx = 0;
		for(size_t i=0; i < cnt[0]; ++i){
			nums[idx++] = 0;
		}
		for(size_t i=0; i < cnt[1]; ++i ){
			nums[idx++] = 1;
		}
		for(size_t i=0; i < cnt[2]; ++i ){
			nums[idx++] = 2;
		}
    }
};

int main(){
	int arr[8] = {0,1,2,2,1,0,2,1};
	vector<int> v(arr,arr+8);
	Solution slv;
	slv.sortColors(v);
	for(int i=0; i<v.size(); ++i){
		cout << v[i] <<" ";
	}
	cout <<endl;
}
