#include <iostream>
#include <vector>
#include <string>
#include <stack>
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> s1, s2;
		while( l1 ){
			s1.push(l1->val);
			l1 = l1->next;
		}		
		while( l2 ){
			s2.push(l2->val);
			l2 = l2->next;
		}
		int extra = 0, sum = 0;
		ListNode dummy = ListNode(0);
		ListNode * re = &dummy;
		while( !s1.empty() && !s2.empty() ){
			sum = s1.top() + s2.top() + extra;
			ListNode * node = new ListNode( sum % 10 );
			node->next = dummy.next;
			dummy.next = node;
			extra = sum / 10;
			s1.pop();
			s2.pop();
		}
		while( !s1.empty() ){
			sum = s1.top() + extra;
			ListNode * node = new ListNode( sum % 10 );
			node->next = dummy.next;
			dummy.next = node;
			extra = sum / 10;
			s1.pop();
		}
		while( !s2.empty() ){
			sum = s2.top() + extra;
			ListNode * node = new ListNode( sum % 10 );
			node->next = dummy.next;
			dummy.next = node;
			extra = sum / 10;
			s2.pop();
		}
		if(extra > 0){
			ListNode * node = new ListNode( 1 );
			node->next = dummy.next;
			dummy.next = node;
		}
		return dummy.next;
    	}
};
int main(){
	int arr[5] = {1,2,3,4,5};
	ListNode * node = createList(arr, 5);
	int arr2[5] = {2,3,4,5};
	ListNode * node2 = createList(arr2, 4);
	printList(node);
	printList(node2);
	node = Solution().addTwoNumbers(node, node2);
	printList(node);

}
