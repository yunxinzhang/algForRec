#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void helper( TreeNode* node,int k, priority_queue<int> & pq ){
	if( !node )
		return;
	if(pq.size() < k)
		pq.push(node->val);
	else{
		if(pq.top() > node->val){
			pq.pop();
			pq.push( node->val );
 		}
	}
	helper(node->left, k, pq);	
	helper(node->right, k, pq);
    }
    int kthSmallest(TreeNode* root, int k) {
	priority_queue<int> pq;
	helper( root, k , pq );	
	return pq.top();
    }
};

int main(){
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->left->right = new TreeNode(1);
	root->left->left = new TreeNode(3);
	root->right = new TreeNode(6);
	cout <<  Solution().kthSmallest(root, 2) << endl;
}
