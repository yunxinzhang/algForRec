#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
int minimumTotal(vector<vector<int> >& triangle){
	vector<vector<int>  > ans(triangle.size());
	ans[triangle.size()-1] = triangle[triangle.size()-1];
	for(int i = triangle.size()-2; i >= 0; --i){
		for(int j = 0, n = triangle[i].size(); j < n; ++j){
			ans[i].push_back( (ans[i+1][j] < ans[i+1][j+1] ? ans[i+1][j] : ans[i+1][j+1]) + triangle[i][j] ); 
		}
	}					    
	/*
	for(int i=0; i<ans.size(); ++i){
		for(int j=0; j<ans[i].size(); ++j){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	*/
	return ans[0][0];
}
};

int main(){
	vector< vector<int> > v;
	vector<int> r;
	r.push_back(2);
	v.push_back(r);
	r.clear();
	r.push_back(3); 
	r.push_back(4); 
	v.push_back(r);
	r.clear();
	r.push_back(6); 
	r.push_back(5); 
	r.push_back(7); 
	v.push_back(r);
	r.clear();
	r.push_back(4); 
	r.push_back(1); 
	r.push_back(8); 
	r.push_back(3); 
	v.push_back(r);
	cout << Solution().minimumTotal( v ) << endl;	
}
