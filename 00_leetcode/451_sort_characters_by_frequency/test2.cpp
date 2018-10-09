#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution {
	public:
		string frequencySort(string s) {
			map<char, int> ch2n;
			for(size_t i=0; i<s.size(); ++i){
					if(ch2n.find(s[i]) == ch2n.end())
							ch2n.insert(make_pair(s[i], 1));
					else
							++ch2n.find(s[i])->second;
		 	}
			vector<pair<int, char> > _v;
			for(auto it : ch2n)
					_v.push_back(make_pair(it.second, it.first));
			cout <<  ch2n.size() <<endl;
			sort(_v.begin(), _v.end());
			string ans = "";
			for(int i=_v.size()-1 ; i >= 0; --i) {
					for(int j=0; j < _v[i].first; ++j)
						ans += _v[i].second;
			}
			return ans;
		}
};

int main(){
	string s= "tree";
	cout << Solution().frequencySort(s) << endl;
}
