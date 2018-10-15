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
	ListNode* reverseList(ListNode* head) {
		if(head == NULL) 
			return NULL;
		return reverse(head, NULL);
    	}
	ListNode * reverse(ListNode * node , ListNode *pre){
		if(node->next == NULL){
			node->next = pre;
			return node;
		}
		else{
			ListNode* head = reverse(node->next, node);
			node->next = pre;
			return head;
		}
	}
};
int main(){
	int arr[5] = {1,2,3,4,5};
	ListNode * node = createList(arr, 5);
	printList(node);
	node = Solution().reverseList(node);
	printList(node);

}
