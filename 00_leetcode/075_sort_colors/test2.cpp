#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
		size_t sz = nums.size();
		int p0 = 0, p1 = 0, p2 = sz-1;
		for(int i=0; i <= p2; ){ // size_t  && -- ==> danger
			if(nums[i] == 0){
				if(i != p0);
					swap(nums[i] , nums[p0]);
				++i;
				++p0;
			}else if(nums[i] == 2){
				swap(nums[i] , nums[p2--]);
			}else{
				++i;
			}
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
