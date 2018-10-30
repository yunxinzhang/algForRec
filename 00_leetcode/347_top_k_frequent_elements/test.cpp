#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> n2i;
  	for(int i=0, n = nums.size(); i<n; ++i){
	    ++n2i[nums[i]];
	}
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	for(auto it = n2i.begin(); it != n2i.end(); ++it){
	    if( pq.size() == k ){
		if( it->second > pq.top().first ){
		    pq.pop();
		    pq.push( make_pair( it->second, it->first ));
		}
	    }else{
		pq.push( make_pair( it->second, it->first ));
	    }
	} 	
	vector<int> ans;
	while( !pq.empty() ){
	    ans.push_back(pq.top().second);
	    pq.pop();
	}
	return ans;
    }
};

int main(){
	vector<int> nums = { 1,1,1,2,2,3 };
	vector<int> ans = Solution().topKFrequent( nums, 2 );
	for(auto it : ans )
		cout << it << endl;
}
