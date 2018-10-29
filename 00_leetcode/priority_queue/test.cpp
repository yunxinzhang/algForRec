#include <iostream>
#include <queue>
using namespace std;

void test_top(){
	priority_queue<int> pq;
	pq.push(5);
	pq.push(4);
	pq.push(7);
	pq.push(2);
	while(!pq.empty()){
		cout << pq.top() << endl;
		pq.pop();
	}
}
void test_greater(){
	priority_queue<int, vector<int>, greater<int> > pq;
	pq.push(5);
	pq.push(4);
	pq.push(7);
	pq.push(2);
	while(!pq.empty()){
		cout << pq.top() << endl;
		pq.pop();
	}
}
struct cmp{
	bool operator()( const int a, const int b){
		return a%10 > b%10;
	}
};
int main(){
	priority_queue<int, vector<int>, cmp > pq;
	pq.push(15);
	pq.push(44);
	pq.push(27);
	pq.push(32);
	while(!pq.empty()){
		cout << pq.top() << endl;
		pq.pop();
	}
}
