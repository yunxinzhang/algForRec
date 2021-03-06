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
			if(s1[i] != s2[i])
				++cnt;
		if(cnt==1)
			return true;
		return false;		
	}
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
  	      	queue<pair<string, int>> remains;
		remains.push(make_pair(beginWord, 1));
		string word;
		int step ;
		vector<bool> visited(wordList.size(),false);
		while( !remains.empty() ) {
			word = remains.front().first;
			step = remains.front().second;
			remains.pop();
			for( int i=0; i<wordList.size(); ++i){
				if((!visited[i]) && diff(word, wordList[i]) ){
					if(endWord == wordList[i])
						return step; 
					visited[i] = true;
					remains.push(make_pair(wordList[i], step+1));
				}
			}						
		}			
		return false;
    }
};
int main(){
	vector<string> wl = { "dog", "hog", "hot", "hit" };
	string st = "dig", ed= "hit", t = "dog";
	cout << Solution().diff( st, t ) << endl;
	cout << Solution().ladderLength( st, ed, wl ) << endl;
}

