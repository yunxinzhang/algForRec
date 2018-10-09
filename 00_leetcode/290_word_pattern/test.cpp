#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		int bidx = 0;
		int pidx = 0;
		unordered_map<string, char> str2p;
		unordered_map<char, string> p2str;
		string word;
		int nword = 0;
		for(size_t i=0; i<str.size(); ++i){
				if(str[i] == ' ' || i==str.size()-1){
					if(++nword > pattern.size())
							return false;
					word = i==str.size()-1 ? str.substr(bidx, i-bidx+1):str.substr(bidx, i-bidx);
					if( str2p.find(word) == str2p.end() ){
						str2p.insert(make_pair(word, pattern[pidx]));
						if( p2str.find(pattern[pidx]) != p2str.end() ){
								return false;
						}
						p2str.insert(make_pair(pattern[pidx++],word));
					} else {
						if( str2p[word] != pattern[ pidx++ ] )
								return false;
					}
					bidx = i + 1;
				}
		}				    
		return nword==pattern.size();
	}
};

int main(){
	string pattern = "abab";
	string str = "cat dog cat fish";
	cout << Solution().wordPattern(pattern, str) <<endl;
}
