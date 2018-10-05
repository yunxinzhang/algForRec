#include <iostream>
#include <vector>
using namespace std;
//#define min(a,b) ((a)>(b)?(b):(a))
class Solution {
public:
    int maxArea(vector<int>& height) {
		int area = 0, maxA = 0;
		for(size_t i=0; i<height.size(); ++i){
			for(size_t j=i+1; j<height.size(); ++j){
				area =  min(height[i], height[j]) * (j-i);
				if(area > maxA){
					maxA = area;
				}
			}
		}        
		return maxA;
    }
};

int main(){
	int a[9] = {1,8,6,2,5,4,8,3,7};
	vector<int> arr(a,a+9);
	int ans = Solution().maxArea(arr);
	cout << ans <<endl;
}
