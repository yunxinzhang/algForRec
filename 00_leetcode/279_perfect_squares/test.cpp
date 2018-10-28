#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    
    int numSquares(int n) {
	queue<int> remains;
	vector<int> visited(n+1,-1);  // 不需要用 map来进行查找，可以大幅度提升性能
	remains.push(n);
	visited[n] = 0;
	int num, remain, temp, cnt =0;        
	unordered_map<int,int>::iterator it;
  	while( !remains.empty()){
		num = remains.front();
		remains.front();
		remains.pop();
		for( int i=1; ; ++i){
			temp = i*i;
			if( temp > num )
				break;	
			remain = num - temp;
			if( remain == 0){
				return visited[num] + 1;
			}
			else if( visited[remain] == -1 ){
				visited[remain] = visited[num] + 1;
				remains.push(remain);
			} 
		}	
	}	
    }
};

int main(){
	int n = 15;
	cout << Solution().numSquares( n ) << endl;
}
