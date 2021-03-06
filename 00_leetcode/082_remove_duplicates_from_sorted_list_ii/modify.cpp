#include <iostream>
#include <vector>
#include <string>
using namespace std;
// sorted list;

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
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode dummy = ListNode(0);
		ListNode *dnode = &dummy, *delnode, *cur = head;
		int val;
		while( cur ){
			val = cur->val;
			if( cur->next != NULL && cur->next->val == val ){
				do{
					delnode = cur;
					cur = cur->next;
					delete delnode;
				}while( cur != NULL && cur->val == val );
				continue;
			}else{
				dnode->next = cur;
				dnode = dnode->next;
				cur = cur->next;
				dnode->next = NULL;
			}
		}
		return dummy.next;
    	}
};
int main(){
	int arr[5] = {1,2,2,4,5};
	ListNode * node = createList(arr, 5);
	printList(node);
	node = Solution().deleteDuplicates(node);
	printList(node);

}
