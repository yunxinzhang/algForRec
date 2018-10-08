#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
	public:
		int reverse(int x) {
			int ne = x < 0 ? -1 : 1;				        
			int absx = ne * x;
			long re = 0;
			while(absx > 0){
				re = re * 10 + absx % 10;
				absx /= 10;
			}
			if( ne > 0 && re > 2147483647L){
					return 0;
			}else if(ne < 0 && re > 2147483648L){
					return 0;
			}else 
					return ne * re;
		}
};

int main(){
	int a = 123456;
	cout << Solution().reverse(a)<<endl;
	int b = -2147483648;
	cout << Solution().reverse(b)<<endl;
	int c = -1234563456;
	cout << Solution().reverse(c)<<endl;

}
