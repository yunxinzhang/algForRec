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
	ListNode* swapPairs(ListNode* head) {
		if(head == NULL || head->next == NULL)
			return head;
		ListNode dummy = ListNode(0);
		ListNode *l1 = head, *l2 = head->next, *dnode = &dummy;
		while( l1 && l2 ){
			dnode->next = l2;
			l1->next = l2->next;
			l2->next = l1;
			dnode = l1;
			l1 = l1->next;
			if( l1 != NULL)
				l2 = l1->next;
		}
		return dummy.next;
    	}
};
int main(){
	int arr[5] = {1,2,3,4,5};
	ListNode * node = createList(arr, 5);
	printList(node);
	node = Solution().swapPairs(node);
	printList(node);

}
