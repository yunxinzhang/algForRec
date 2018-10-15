#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
	map< pair<int, int>, int >  idx2val;
	int getVal(int i, int j){
		auto it = idx2val.find( make_pair(i,j));
		if(it != idx2val.end())
			return it->second;
		if(j == 0 || j == i){
			idx2val[make_pair(i,j)] = 1;
			return 1;
		}
		int add1 = getVal(  i-1, j-1 );
		int add2 = getVal(  i-1, j );

		idx2val[make_pair(i, j)] = add1 + add2;		
		return add1 + add2;
	}
    vector<int> getRow(int rowIndex) {
	vector<int> v(rowIndex+1, 0);
	for(int i=0; i<rowIndex+1; ++i)
		v[i] = getVal(rowIndex, i);
	return v;
    }
};
int main(){
	vector<int> ans = Solution().getRow(3);
	for(int i= 0; i<ans.size(); ++i)
		cout << ans[i] << " " ;
	cout <<endl;

}
