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
	ListNode* rotateRight(ListNode* head, int k) {
		if( !head || !head->next )
			return head;
		ListNode *  cur = head;
		int cnt = 0;
		while( cur->next ){
			++cnt;
			cur = cur->next;
		}		
		cur->next = head;
		int mv = (cnt - k)%(cnt + 1);
		mv = mv < 0 ? mv+cnt+1 : mv;
		cur = head;
		for( int i=0; i<mv; ++i){
			cur = cur->next;
		}
		ListNode * ans = cur->next;
		cur->next = NULL;
		return ans;		
    	}
};
int main(){
	int arr[3] = {0,1,2,};
	ListNode * node = createList(arr, 3);
	printList(node);
	node = Solution().rotateRight(node, 4);
	printList(node);
}
