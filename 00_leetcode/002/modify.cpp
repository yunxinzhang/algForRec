#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
		// my implement   add
		void add(int x){
				ListNode *nextNode = new ListNode(x);
				ListNode * p = next;
				if(next==NULL){
						next = nextNode;
						return;
				}
				while(p->next != NULL){
						p = p->next;
				}
				p->next = nextNode;
		}
};

class Solution {
		public:
				ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
						ListNode *p1 = l1, *p2 = l2, ans(0), *p=&ans;
						bool extra = false;
 						int sum;
						while( p1!=NULL || p2!=NULL || extra ){
								sum = (p1 ? p1->val: 0) +(p2 ? p2->val: 0) + extra;
								if(p1!=NULL)p1 = p1->next;
								if(p2!=NULL)p2 = p2->next;
								p->next = new ListNode(sum%10);
								extra = sum / 10;
								p = p->next;
						}
						return ans.next;
				}
};


int main(){
		ListNode node(2);
		node.add(4);
		node.add(3);
		ListNode node2(5);
		node2.add(6);
		node2.add(4);
		Solution slv;
		ListNode * ans = slv.addTwoNumbers(&node, &node2);	
		ListNode *p = ans;
		while(p!=NULL){
				cout << p->val<<endl;
				p = p->next;
		}
}
