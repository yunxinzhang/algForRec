#include <iostream>
#include <vector>
using namespace std;
/*
 *     thing  value  weight
 *     0        6       1
 *     1        10      2
 *     2        12      3
 *
 *     capacity : 5
 */

class Bag{
public:
	int solve(vector<pair<int,int> >& things, int bag){
		vector<vector<int> > trans(things.size(), vector<int>(bag+1, 0));
		trans[0][0] = 0;
		for(int i=1; i<bag+1; ++i){
			trans[0][i] = things[0].first;	
		}
		for(int i=1; i<things.size(); ++i){
			trans[i][0] = 0;
			for(int j=1; j<bag+1; ++j){
				trans[i][j]=max(trans[i-1][j], j >= things[i].second ? things[i].first + trans[i-1][j-things[i].second] : 0);			
			}			
		}
		return trans[things.size()-1][bag];
	}				
};

int main(){
		vector<pair<int,int> > v;
		v.push_back(make_pair(6,1));
		v.push_back(make_pair(10,2));
		v.push_back(make_pair(12,3));
		v.push_back(make_pair(14,4));
		v.push_back(make_pair(19,5));
		cout << Bag().solve(v, 6) << endl;
}
