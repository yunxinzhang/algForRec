#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end(), greater<int>());
		sort(s.begin(), s.end(), greater<int>());
		int gp = 0, sp = 0, gsz = g.size(), ssz = s.size(), ans = 0;
		while( gp < gsz && sp < ssz  ){
			if(g[gp] <= s[sp]){
				++ans;
				++gp;
				++sp;
			}else{
				++gp;	
			}
		}			
		return ans;
	}
};

int main(){
	vector<int> cookie= {1,2,3};	
	vector<int> children= {1,1};	
	cout << Solution().findContentChildren(cookie, children) << endl;
	vector<int> cookie1= {1,2};	
	vector<int> children1= {1,2,3};	
	cout << Solution().findContentChildren(cookie1, children1) << endl;
}
