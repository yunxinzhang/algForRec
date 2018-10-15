#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


class Solution {
public:
    int dist(pair<int, int> a ,pair<int,int> b){
	return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
    }
	bool intersect( pair<int ,int> a ,pair<int, int> b ){
		return a.first == b.first || a.first == b.second || a.second == b.second || a.second == b.first ;
	}
    int numberOfBoomerangs(vector<pair<int, int> >& points) {
	map< int , vector< pair<int, int> > > d2ps;
	int d;
	for(int i=0; i<points.size(); ++i){
		for(int j=i+1; j<points.size(); ++j){
			d = dist( points[i], points[j] );
			auto it = d2ps.find(d);
			if(it == d2ps.end())
				d2ps[d] = vector< pair<int, int> >(1, make_pair(i, j));
			else
				it->second.push_back( make_pair(i, j));			
		}	
	}
	int ans =  0;
	for( auto it = d2ps.begin(); it != d2ps.end(); ++it){
		for( int i = 0; i < it->second.size() ; ++i){
			for(int j=i+1; j < it->second.size(); ++j)
				if(intersect( it->second[i] ,it->second[j]))
					ans += 2;;
		}		
	}
	return ans;
    }
};
int main(){
	vector< pair < int, int> > v = { { 0, 0 }, { 1, 0 } , { 2, 0 } };
	cout << Solution().numberOfBoomerangs( v ) << endl;
}
