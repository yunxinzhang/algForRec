#include <iostream>
#include <vector>
using namespace std;

class Solution {
		public:
				int removeElement(vector<int>& nums, int val) {
						size_t p = 0; //  index to write
						size_t sz = nums.size();
						for(size_t i=0; i<sz; ++i){
								if(nums[i] != val){
										if(i != p){
												swap(nums[i],nums[p++]);
										}else{
												++p;
										}
								}
						}    
						return p;
				}
};


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
		int n = slv.removeElement(v, 0);
		cout << n << endl;
		for(int i=0; i<v.size(); ++i){
				cout << v[i] << " ";
		}
		cout << "\n";

}
