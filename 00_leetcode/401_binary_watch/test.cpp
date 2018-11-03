#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> h = {1,2,4,8};
    vector<int> m = {1,2,4,8,16,32};
    void getSum( vector<int> &arr, int idx, int th, int &sum, set<int> &s){
	if( th==0 ){
	    s.insert(sum);
	    return;
	}
	if( arr.size() - idx < th )
		return;
	sum += arr[idx];
	getSum( arr, idx+1, th-1,sum, s );
	sum -= arr[idx];
	getSum( arr, idx+1, th,sum, s );
    } 
    vector<string> readBinaryWatch(int num) {
        set<int> hour;
	int sumh, summ;
    	set<int> minute;
	vector<string> ans;
	for( int i=0; i<= num; ++i){
	    sumh = 0;
	    summ = 0;
	    minute.clear();
	    hour.clear();
	    getSum( h , 0, i, sumh, hour );
	    vector<int> _hour(hour.begin(), hour.end());
	    getSum( m , 0, num-i, summ, minute );
	    vector<int> _min(minute.begin(), minute.end());
	    for( int ih = 0; ih < _hour.size(); ++ih ){
		for( int im = 0; im < _min.size(); ++im){
		    if( _hour[ih] <=11 && _min[im] <=59 ){
			if( _min[im] >= 10 )
				ans.push_back( to_string(_hour[ih]) +":"+ to_string(_min[im]));
			else
				ans.push_back( to_string(_hour[ih]) +":0"+ to_string(_min[im]));
		    }
		}
	    }
	} 
	return ans;
    }
};

int main(){
	Solution sol;
	int sumh = 0;
	set<int> s;	
	sol.getSum( sol.m, 0, 0,sumh, s);
	vector<string> ans= Solution().readBinaryWatch(1); 
	for(auto it : ans)
		cout << it << endl; 
}
