#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    int dist(pair<int, int> a ,pair<int,int> b){
	return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
    }
    int numberOfBoomerangs(vector<pair<int, int> >& points) {
	int *ds = new int[points.size()], nsame = 0, ans = 0;
	for(int i=0; i < points.size(); ++i){
		for(int j=0; j < points.size(); ++j){
			ds[j] = dist( points[i], points[j] );	
		}	
		sort( ds, ds + points.size() );
		for(int j=0; j < points.size()-1; ++j){
			while( ds[j] == ds[j+1] ){
				++j;
				++nsame; 
			}
			ans += nsame * (nsame + 1);
			nsame = 0;
		}		
	}
	delete ds;
	return ans;
    }
};
int main(){
	vector< pair < int, int> > v = { { 0, 0 }, { 1, 0 } , { 2, 0 } };
	cout << Solution().numberOfBoomerangs( v ) << endl;
}
