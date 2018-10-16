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
	ListNode* partition(ListNode* head, int n) {
		ListNode lessNode = ListNode(0);
		ListNode greaterNode = ListNode(0);
		ListNode *l = &lessNode, *g = &greaterNode,  *cur = head, *next;	
		while( cur ){
			next = cur->next;
			cur->next = NULL;
			if( cur->val < n ){
				l->next = cur;
				l = l->next;
			} else {
				g->next = cur;
				g = g->next;
			}
			cur = next;
		}
		if( lessNode.next == NULL)
			return greaterNode.next;
		l->next = greaterNode.next;
		return lessNode.next;
    	}
};
int main(){
	int arr[5] = {1,5,3,2,5};
	ListNode * node = createList(arr, 5);
	printList(node);
	node = Solution().partition(node,4);
	printList(node);

}
