#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
using namespace std;

class Solution {
public:
		void split(string str, vector<string> & res){
				istringstream iss(str);
				string word;
				while( iss >> word ){
						res.push_back(word);
				}
		}
	bool wordPattern(string pattern, string str) {
		vector<string> words;
		split(str, words);
		unordered_map<char, string> p2w;
		unordered_set<string> ws;
		if(words.size() != pattern.size()) return false;
		for(size_t i=0; i<pattern.size(); ++i){
					if( p2w.count(pattern[i] ) ){
							if( p2w[pattern[i]] != words[i] )
								return false;
					} else {
							if( ws.find(words[i]) != ws.end() ) 
								return false;
							ws.insert(words[i]);
							p2w[pattern[i]] = words[i];
					}
		}				    
		return true;
	}
};

int main(){
	string pattern = "abab";
	string str = "cat dog cat fish";
	cout << Solution().wordPattern(pattern, str) <<endl;
}
