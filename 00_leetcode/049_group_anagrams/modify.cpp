#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
		vector<int> primes = {2,3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
		long key;
		vector< vector<string> > ans;
		map<long, int > str2i;
		for(int i=0; i<strs.size(); ++i){
			key = 1;
			for(int j=0; j<strs[i].size(); ++j){
				key *= primes[ strs[i][j] - 'a'];
			}	
			auto it = str2i.find(key);
			if(it == str2i.end()){
				str2i[key] = ans.size();
				ans.push_back(vector<string>(1, strs[i]));
			}
			else	
				ans[it->second].push_back(strs[i]);
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
