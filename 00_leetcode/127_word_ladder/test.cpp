#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    	bool diff(string &s1, string &s2){
		int cnt = 0;
		for(int i=0; i<s1.size(); ++i)
			if(s1[i] == s2[i])
				++cnt;
		if(cnt==1)
			return true;
		return false;		
	}
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		wordList.push_back(beginWord);
  	      	queue<string> remains;
		remains.push(beginWord);
		string word;
		vector<bool> visited(false, wordList.size());
		while( !remains.empty() ) {
			word = remains.front();
			word.pop();
								
		}			
    }
};


