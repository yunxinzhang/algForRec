#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* helper( TreeNode* node, int a, int b){
	if( !node )
		return nullptr;
	if( node->val >= a && node->val <= b )
		return node;
	if( node->val > a && node->val > b )
		return helper( node->left, a, b);
	if( node->val < b && node->val < a )
		return helper( node->right, a, b);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if( p->val > q->val )
		return helper(root, q->val, p->val);
	return helper(root, p->val, q->val);
    }
};

int main(){
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(6);
	TreeNode *p = new TreeNode(2);
	TreeNode *q = new TreeNode(6);
	cout <<  Solution().lowestCommonAncestor(root,p,q )->val << endl;
	
}
