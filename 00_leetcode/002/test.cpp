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
						ListNode *p1 = l1;
						ListNode *p2 = l2;
						ListNode * p = NULL;
						ListNode * ans = NULL;
						int sum;
						bool addOne = false;
						bool firstNode = true;
						while(p1!=NULL || p2!=NULL){
								sum = (p1==NULL ? 0 : p1->val) +(p2==NULL ? 0 :p2->val);
								if(p1!=NULL)
										p1 = p1->next;
								if(p2!=NULL)
										p2 = p2->next;
								ListNode * node = new ListNode((sum+addOne)%10);
								if(sum+addOne >= 10)
										addOne=true;
								else
										addOne = false;
								if(p==NULL){
										p = node;
								}else{
										p->next = node;
								}
								if(firstNode){
										ans = p;
										firstNode = false;
								}else{	
										p = p->next;
								}
						}
						if(addOne){
								p->next = new ListNode(1);
						}

						return ans;
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
