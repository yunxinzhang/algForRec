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
    ListNode* mergeTwo(ListNode*a, ListNode *b){
  	ListNode dummy(0),*cur = &dummy;
	while( a != nullptr && b!=nullptr){
	    if(a->val > b->val){
		cur->next = b;
		b = b->next;
	    }else{
		cur->next = a;
		a = a->next;
	    }
	    cur = cur->next;
	}
	if( a != nullptr){
	    cur->next = a;
	}
	if( b != nullptr){
	    cur->next = b;
	}
	return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
	int sz = lists.size();
	if(sz == 0)
		return nullptr;
	if(sz == 1)
		return lists[0];
	if(sz == 2)
		return mergeTwo(lists[0], lists[1]);
	int mid = sz/2;
	vector<ListNode*> l1(lists.begin(), lists.begin()+mid);
	vector<ListNode*> l2(lists.begin()+mid, lists.begin()+sz);
	return mergeTwo( mergeKLists(l1), mergeKLists(l2) );
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
