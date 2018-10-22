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
#include <stack>
class Solution {
public:
		bool isPalindrome(ListNode* head) {
				stack<int> stk;
				ListNode * cur = head;
				while(cur){
						stk.push(cur->val);
						cur = cur->next;
				}
				int cnt = stk.size() /2;
				int num;
				cur = head;
				for(int i = 0; i < cnt; ++i){
					num = stk.top();
					if(num != cur->val)
							return false;
					cur = cur->next;
					stk.pop();
				}
			 	return true;
		}
};
int main(){
	int arr[4] = {1,2, 2,3};
	ListNode * node = createList(arr, 4);
	printList(node);
	bool a = Solution().isPalindrome(node);
	cout << a << endl;;

}
