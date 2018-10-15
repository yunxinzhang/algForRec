#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	unordered_map<int, int> s2i;
	int sum;
	for(int i=0; i<C.size(); ++i){
		for(int j=0; j<D.size(); ++j){
			sum = C[i] + D[j];
			if(s2i.find(sum) == s2i.end())
				s2i.insert(make_pair(sum, 1));
			else
				++s2i[sum];
		}
	}
	int re, ans = 0;
	for(int i = 0; i < A.size(); ++i ){
		for(int j=0; j<B.size(); ++j){
			re = -(A[i] + B[j]);		
			if(s2i.find(re) != s2i.end())
				ans += s2i[re];
		}
	}
	return ans;
    }
};


int main(){
	vector<int> v1 = { 1, 2 };
	vector<int> v2 = { -2, -1 };
	vector<int> v3 = { -1, 2 };
	vector<int> v4 = { 0, 2 };
	cout << Solution().fourSumCount(v1, v2, v3, v4) << endl;
}
