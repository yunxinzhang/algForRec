#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
  	      	queue<pair<string, int>> remains;
		remains.push(make_pair(beginWord, 1));
		string word;
		int step ;
		unordered_set<string> visited(wordList.begin(), wordList.end());
		char ch;
		while( !remains.empty() ) {
			tie(word,step) = remains.front();
			remains.pop();
			for( int i=0; i<word.size(); ++i){
				for(char c = 'a'; c <= 'z' ; ++c){
					if( c != word[i] ){
						ch = word[i];
						word[i] = c;
						if(visited.find(word) != visited.end()){
							if(word == endWord)
								return step+1;
							visited.erase(word);
							remains.push(make_pair( word, step+1));
						}
						word[i] = ch;
					}
				}
			}						
		}			
		return false;
    }
};
int main(){
	vector<string> wl = { "dog", "hog", "hot", "hit" };
	string st = "dig", ed= "hit", t = "dog";
	cout << Solution().ladderLength( st, ed, wl ) << endl;
}

