#include <iostream>
#include <vector>
#include <queue>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
using namespace std;
class Solution {
public:
    struct cmp{
	bool operator()(pair<ListNode*,int> a, pair<ListNode*,int> b){
		return a.first->val > b.first->val;
	}
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
  	priority_queue<pair<ListNode*,int>, vector<pair<ListNode*,int>>, cmp>pq;
	for(int i=0, n=lists.size(); i<n; ++i){
	    if(lists[i] != nullptr){
		pq.push( make_pair(lists[i],i) );
		lists[i] = lists[i]->next;
	    }
	}
	ListNode ln(0), *cur = &ln; 
	pair<ListNode*,int> pr;
	while( !pq.empty()){
	    pr = pq.top();
	    pq.pop();
	    if(lists[pr.second] != nullptr){
		pq.push( make_pair(lists[pr.second], pr.second));
		lists[pr.second] = lists[pr.second]->next;
	    }
	    cur->next = pr.first;
	    cur = cur->next;
	}
	return ln.next;
    }
};
int main(){
	ListNode* a =new ListNode(1);
	a->next = new ListNode(2);
	ListNode* b = new ListNode(3);
	b->next = new ListNode(4);
	vector<ListNode*> v = {a,b};
	ListNode *c = Solution().mergeKLists(v);
	ListNode *cur =c;
	while(cur){
	    cout << cur->val <<endl;
	    cur = cur->next;
	}	
}
