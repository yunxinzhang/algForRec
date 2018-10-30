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
    TreeNode* invertTree(TreeNode* root) {
	if(root == nullptr)
		return root;
	invertTree(root->left);
	invertTree(root->right);
	swap(root->left, root->right);        
	return root;
    }
};

int main(){
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root = Solution().invertTree(root);
	cout << root->left->val << endl;
	cout << root->right->val << endl;
}
