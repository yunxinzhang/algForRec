#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		int bidx = 0;
		int pidx = 0;
		unordered_map<char, string> p2str;
		unordered_map<string, char> str2c;
		string word;
		for(size_t i=0; i<str.size(); ++i){
				if(str[i] = " "){
					word = str.substr(bidx, i-bidx);
					if(p2str.find(pattern[pidx]) == p2str.end() && str2p.find(word) == str2p.end()){
						p2str.insert(make_pair(pattern[pidx], word));
						str2p.insert(make_pair(word, pattern[pidx]));
						++pidx;
					}else if(p2str.find(pattern[pidx]) != p2str.end() && str2p.find(word) != str2p.end()){
						
					}

					p2str.insert(make_pair(pattern[pidx]))
				}
				bidx = i;

		}				        
							    
	}
};

int main(){


}
