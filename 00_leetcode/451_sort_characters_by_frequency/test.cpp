#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

			bool cmp(pair<char,int> a, pair<char, int> b){
					return a.second > b.second ? true : false;
			}
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
			vector<pair<char, int> > _v(ch2n.begin(), ch2n.end());
			cout <<  ch2n.size() <<endl;
			sort(_v.begin(), _v.end(), cmp);
			string ans = "";
			for(int i=0 ; i < _v.size(); ++i) {
					for(int j=0; j < _v[i].second; ++j)
						ans += _v[i].first;
			}
			return ans;
		}
};

int main(){
	string s= "tree";
	cout << Solution().frequencySort(s) << endl;
}
