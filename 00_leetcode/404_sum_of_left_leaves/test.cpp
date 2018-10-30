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
    int sumOfLeft(TreeNode* node, bool l){
	if( !node )
		return 0;
	if( !node->left && !node->right  )
		if(l)
			return node->val;
		else
			return 0;
	return sumOfLeft( node->left, true) + sumOfLeft( node->right, false);
		
    }
    int sumOfLeftLeaves(TreeNode* root) {
	return sumOfLeft( root, true );
    }
};

int main(){
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(6);
	root->right->left = new TreeNode(3);
	cout <<  Solution().sumOfLeftLeaves(root) << endl;
}
