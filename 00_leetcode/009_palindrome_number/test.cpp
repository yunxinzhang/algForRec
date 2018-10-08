#include <iostream>
using namespace std;

class Solution {
	public:
		bool isPalindrome(int x) {
			if(x < 0 )return false;				        
			int y = 0, temp = x;
			while(x){
				y = y*10+ x%10;
				x /= 10;
			}
			if(temp == y)return true;
			return false;
		}
};

int main(){
	int a = 121;
	cout << Solution().isPalindrome(a) <<endl;

}
