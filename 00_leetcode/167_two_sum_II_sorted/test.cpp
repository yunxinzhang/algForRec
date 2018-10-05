#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    	   size_t l = 0, r = numbers.size()-1;
		   int sum;
			while( l != r ){
				sum = numbers[l] + numbers[r];
				if(sum == target){
					int ans[2] = { l+1 , r+1 };
					return vector<int>(ans, ans+2);
				}else if(sum < target){
					++l;
				}else{	
					--r;
				}
			} 
			throw("no answer");
    }
};


int main(){
	int arr[4] = {2, 7, 11, 15};
	vector<int> vec(arr, arr+4);
	vector<int> ans = Solution().twoSum( vec, 9 );
	cout << ans[0] <<" " <<ans[1]<<endl;
}
