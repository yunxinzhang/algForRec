#include <iostream>
#include <vector>
using namespace std;
#define min(a,b) ((a)>(b)?(b):(a))
class Solution {
public:
    int maxArea(vector<int>& height) {
		int area = 0, maxA = 0;
		int l = 0, r = height.size() - 1;
		while(l < r){
			area = min(height[l], height[r]) * (r-l);
			if( area > maxA ){
				maxA = area;
			}
			if( height[l] > height[r] ){
				--r;
			}else{
				++l;
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
