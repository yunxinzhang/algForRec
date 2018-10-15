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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if(head == NULL) 
			return NULL;
		ListNode dummyNode = ListNode(0);
		dummyNode.next = head;
		int cnt = 0;
		ListNode * cur = &dummyNode;
		ListNode * l ;
		ListNode * pre;
		ListNode * next;
		while( cur != NULL && cnt < n+1 ){
			if(cnt < m-1 || cnt > n){
				++cnt;
				cur = cur->next;
				continue;
			}
			pre = cur;
			l = cur;
			next = cur->next;
			while( ++cnt <= n){
				cur = next;
				next = cur->next;
				cur->next = pre;
				pre = cur;
			}
			l->next->next = next;
			l->next = cur;
			break;	
		}	
		return dummyNode.next;
	
    	}
};
int main(){
	int arr[5] = {1,2,3,4,5};
	ListNode * node = createList(arr, 5);
	printList(node);
	node = Solution().reverseBetween(node,2,4);
	printList(node);

}
