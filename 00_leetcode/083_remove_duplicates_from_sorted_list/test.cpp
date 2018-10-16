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
	ListNode* deleteDuplicates(ListNode* head) {
		if(head == NULL || head->next == NULL)
			return head;
		ListNode * pre = head, * cur = head->next, *delNode;
		while(cur != NULL){
			if(cur->val == pre->val){
				delNode = cur;
				cur = cur->next;
				delete delNode;
				pre->next = cur;
			}else{
				pre = cur;
				cur = cur->next;
			}
		}
		return head;
    	}
};
int main(){
	int arr[5] = {1,2,2,4,5};
	ListNode * node = createList(arr, 5);
	printList(node);
	node = Solution().deleteDuplicates(node);
	printList(node);

}
