#include <iostream>
#include <queue>

using namespace std;

int main(){
		priority_queue<pair<int, char> > qp;
		qp.push(make_pair(4, 'a'));
		qp.push(make_pair(3, 'b'));
		qp.push(make_pair(6, 'd'));
		qp.push(make_pair(5, 'c'));
		while(!qp.empty()){
				cout << qp.top().second << endl;
				qp.pop();
		}
}
