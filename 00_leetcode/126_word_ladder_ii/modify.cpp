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
   void helper(unordered_map<string,vector<string>> & paths, 
		string &st, 
		string &ed, 
		vector<string> &path,
		vector<vector<string>> &ans)
	{
		if(st == ed){
			ans.push_back(path);
			return;
		}
		for(auto it : paths[st]){
			path.push_back(it);
			helper(paths, it, ed, path, ans);
			path.pop_back();		
		}
	}


    vector<vector<string>> ladderLength(string beginWord, string endWord, vector<string>& wordList) {
  	queue<string> remains;
	unordered_map<string,vector<string>> paths;
	vector<vector<string>> ans;
	unordered_set<string> wset(wordList.begin(), wordList.end());
	wset.erase(beginWord);
	unordered_set<string> nlevel;
	remains.push(beginWord);
	string word, rword;
	char ch;
	bool conn = false;
	int sz =1, cnt = 0;
	while( !remains.empty() ) {
	    if(conn && cnt==sz){
		break;
	    }
	    word = remains.front();
	    remains.pop();
	    ++cnt;
	    for( int i=0; i<word.size(); ++i ){
		ch = word[i];
		for(char c = 'a'; c <= 'z' ; ++c){
		    if( c != ch ){
			word[i] = c;
			if(wset.find(word) != wset.end()){
			    if(word == endWord){
				conn = true;
				rword = word;
				rword[i] = ch;
				paths[rword].push_back(endWord);
			    }else if(!conn){
				if(nlevel.find(word) == nlevel.end()){
				    remains.push(word);
				    nlevel.insert(word);
				}
				rword = word;
				rword[i] = ch;
				paths[rword].push_back(word);
			    }
			}
		    }
		}
		word[i] = ch;
	    }
	    if( sz == cnt && !conn){
		sz = nlevel.size();
		for(auto it : nlevel)
		    wset.erase(it);
		nlevel.clear();
		cnt = 0;
	    }
	}
	for(auto it : paths){
		cout << it.first << ":"<<endl;
		for(auto it2 : it.second)
			cout << it2 <<" ";
		cout << endl;
	}
	vector<string> v(1, beginWord);
	helper( paths, beginWord, endWord, v, ans);
	return ans;
    }
};
int main(){
	//vector<string> wl = { "hot", "him", "hom", "kom" };
	vector<string> wl = { "hot",  "dog", "dot" };
	string st = "hot", ed= "dog";
	vector<vector<string>> v =  Solution().ladderLength( st, ed, wl );
	for( auto i =0; i<v.size(); ++i){
		for(auto j=0; j <v[i].size(); ++j){
			cout << v[i][j] <<" ";
		}
		cout <<endl;
	}
}

