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
	ListNode* oddEvenList(ListNode* head) {
		ListNode ol = ListNode(0);
		ListNode el = ListNode(0);
		ListNode *cur = head, *l = &ol, *e = &el, *next;
		int cnt = 0;
		while( cur ){
			next = cur->next;
			if(++cnt % 2 == 1 ){
				l->next = cur;
				l = l->next;
			}else{
				e->next = cur;
				e = e->next;
			}
			cur->next = NULL;
			cur = next;
		}
		if( ol.next == NULL )
			return NULL;
		l->next = el.next;
		return ol.next;
    	}
};
int main(){
	int arr[5] = {1,2,3,4,5};
	ListNode * node = createList(arr, 5);
	printList(node);
	node = Solution().oddEvenList(node);
	printList(node);

}
