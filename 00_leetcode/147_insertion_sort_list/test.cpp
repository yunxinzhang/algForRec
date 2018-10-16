#include <iostream>
#include <vector>
#include <string>
#include <climits>
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
	ListNode* insertionSortList(ListNode* head) {
		ListNode dummy =  ListNode(INT_MIN);
		ListNode * dnode = &dummy, *cur = head, *next;
		while(cur){
			dnode = &dummy;
			while( dnode->next != NULL && cur->val > dnode->next->val ){
				dnode = dnode->next;
			}
			next = dnode->next;
			dnode->next = cur;
			cur = cur->next;
			dnode->next->next = next;
		}
		return dummy.next;
		
    	}
};
int main(){
	int arr[5] = {1,6,2,4,5};
	ListNode * node = createList(arr, 5);
	printList(node);
	node = Solution().insertionSortList(node);
	printList(node);

}
