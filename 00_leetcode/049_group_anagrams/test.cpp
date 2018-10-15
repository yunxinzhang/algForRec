#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
  		map< map<char,int>, vector<int> > str2i;
		for(int i=0; i<strs.size(); ++i){
			map<char, int> c2i;
			for(int j=0; j<strs[i].size(); ++j){
				++c2i[strs[i][j]];
			}	
			auto it = str2i.find(c2i);
			if(it == str2i.end())
				str2i[c2i] = vector<int>(1, i);
			else	
				it->second.push_back(i);
		}
		vector< vector<string> > ans;
		for(auto it = str2i.begin(); it != str2i.end(); ++it){
			vector<string> v;
			for(int j=0; j<it->second.size(); ++j)
				v.push_back(strs[it->second[j]]);
			ans.push_back(v);
		}
		return ans;
    }
};

int main(){
	vector<string> ss = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string> > ans = Solution().groupAnagrams(ss);
	for(int i = 0; i< ans.size(); ++i){
		for(int j=0; j<ans[i].size(); ++j){
			cout << ans[i][j] <<" ";
		}
		cout <<endl;
	}

}
