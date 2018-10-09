#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> record;
		while( n != 1 ){
			n = calc_hn(n);
			if(record.find(n) != record.end())
					return false;
			record.insert(n);
		}
		return true;					    
	}
	int calc_hn(int n){
		int re = 0;
		while( n != 0 ){
			re += pow( n%10 ,2 );
			n /= 10;
		}
		return re;
	}
};

int main(){
	cout << Solution().isHappy(19) << endl;
}
