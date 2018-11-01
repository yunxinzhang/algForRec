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
    int getMax(TreeNode* node){
	if(node->right)
	    return getMax(node->right);
	return node->val;
    }
    int getMin(TreeNode* node){
	if(node->left)
	    return getMin(node->left);
	return node->val;
    }
    bool isValidBST(TreeNode* root) {
	if( !root )
		return true;
	if( isValidBST( root->left ) && isValidBST( root->right )){
		if( root->left && getMax(root->left) >= root->val )
			return false;
		if( root->right && getMin(root->right) <= root->val )
			return false;
		return true;
	}	
	return false;
    }
};

int main(){
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(7);
	root->right = new TreeNode(6);
	cout <<  Solution().isValidBST(root) << endl;
}
