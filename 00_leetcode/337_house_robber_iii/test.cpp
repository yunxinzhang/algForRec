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
	int rob(TreeNode* root) {
		if(!root)
				return 0;
		int cur = root->val;
		if(root->left)
			cur += rob(root->left->left) + rob(root->left->right);
		if(root->right)
			cur += rob(root->right->left) + rob(root->right->right);
		return max(cur, rob(root->left) + rob(root->right));
	}
};
	
