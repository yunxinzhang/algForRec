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
	ListNode* mergeTwoLists(ListNode* l1,  ListNode *l2) {
		ListNode dummy = ListNode(0);
		ListNode *dnode = &dummy;
		while( l1 && l2 ){
			if(l1->val > l2->val){
				dnode->next = l2;
				l2 = l2->next;
			}else{
				dnode->next = l1;
				l1 = l1->next;
			}
			dnode = dnode->next;
		}		
		while( l1 ){
			dnode->next = l1;
			l1 = l1->next;
			dnode = dnode->next;
		}
		while( l2 ){
			dnode->next = l2;
			l2 = l2->next;
			dnode = dnode->next;
		}
		return dummy.next;
    	}
};
int main(){
	int arr[5] = {1,2,3,4,5};
	ListNode * node = createList(arr, 5);
	int arr2[5] = {1,2,3,4,5};
	ListNode * node2 = createList(arr2, 5);
	printList(node);
	node = Solution().mergeTwoLists(node, node2);
	printList(node);

}
