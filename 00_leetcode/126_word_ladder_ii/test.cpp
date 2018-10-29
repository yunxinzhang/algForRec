#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    struct node{
  	int step;
	int idx;
	node * pa;
	node(int v, int x):step(v), idx(x),pa(NULL){};
    };    
    vector<vector<string>> ladderLength(string beginWord, string endWord, vector<string>& wordList) {
  	      	queue<pair<string, node*>> remains;
		node root(1, -1);
		remains.push(make_pair(beginWord, &root));
		vector<vector<string>> ans;
		string word;
		node* step, *cur ;
		unordered_map<string,int> visited;
		for(auto i= 0; i<wordList.size(); ++i)
			visited.insert(make_pair( wordList[i], i));
		char ch;
		int mins = INT_MAX;
		unordered_map<string, int>::iterator itv;
		while( !remains.empty() ) {
			tie(word,step) = remains.front();
			if(mins< step->step)
				return ans;
			remains.pop();
			unordered_set<string> eset;
			for( int i=0; i<word.size(); ++i){
				for(char c = 'a'; c <= 'z' ; ++c){
					if( c != word[i] ){
						ch = word[i];
						word[i] = c;
						itv = visited.find(word);
						if(itv != visited.end()){
							if(word == endWord){
								if(mins>step->step)
									mins = step->step;
								vector<string> v;
								v.push_back( endWord );
								cur = step;
								while(cur->pa){
									v.push_back( wordList[cur->idx] );
									cur = cur->pa; 
								}	
								v.push_back( beginWord);
								reverse(v.begin(), v.end());
								ans.push_back(v);
							}else{
							  node * nxt= new node(step->step +1, itv->second);
							  nxt->pa = step;
							  remains.push(make_pair( word, nxt));
							}
						}
						word[i] = ch;
					}
				}
			}						
			for(auto it : eset)
				visited.erase(it);
			eset.clear();
		}			
		return ans;
    }
};
int main(){
	vector<string> wl = { "dog", "hog", "hot", "hit" };
	string st = "dig", ed= "hit", t = "dog";
	vector<vector<string>> v =  Solution().ladderLength( st, ed, wl );
	for( auto i =0; i<v.size(); ++i){
		for(auto j=0; j <v[i].size(); ++j){
			cout << v[i][j] <<" ";
		}
		cout <<endl;
	}
}

