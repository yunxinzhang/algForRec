#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next; 
    ListNode(int x) : val(x), next(NULL) {}
};
void printList( ListNode *node){
	ListNode * mv = node;
	while(node!=NULL){
		cout << node->val << " -->";
		node = node->next;
	}
	cout << endl;
}
ListNode* createList( int arr[], int n ){
	if(n==0) 
		return NULL;
	ListNode * head = new ListNode(arr[0]);
	ListNode * mv = head;
	for(int i=1; i<n; ++i){
		ListNode *node = new ListNode(arr[i]);
		mv->next = node;
		mv = node;
	}
	return head;
}

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode dummy = ListNode(0);
		ListNode *dnode = &dummy, *cur = head, *pre, *next, *nextd, *nexts;
		int cnt = 0;
		dnode->next = head;
		while(cur){
			++cnt;
			if( cnt % k == 0 ){
				pre = nexts = cur->next;
				cur = nextd = dnode->next;
				while( cur != nexts ){
					next = cur->next;
					cur->next = pre;
					pre = cur;
					cur = next;
				}
				dnode->next = pre;
				dnode = nextd;
				continue;
			}
			cur = cur->next;
		}
		return dummy.next;
    	}
};
int main(){
	int arr[5] = {1,2,3,4,5};
	ListNode * node = createList(arr, 5);
	printList(node);
	node = Solution().reverseKGroup(node, 3);
	printList(node);

}
