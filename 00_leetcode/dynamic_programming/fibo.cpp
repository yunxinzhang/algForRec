#include <iostream>
#include <vector>
using namespace std;


int fibo(int n){
	if(n == 0)
			return 0;
	if(n == 1)
			return 1;
    vector<int> ans(n+1, -1);
	ans[0] = 0;
	ans[1] = 1;
	for(int i=2; i<=n; ++i){
		ans[i] = ans[i-1] + ans[i-2];
	}
	return ans[n];
}
int main(){
		for(int i=1; i<10; ++i){
				cout << fibo(i) << endl;
		}

}
