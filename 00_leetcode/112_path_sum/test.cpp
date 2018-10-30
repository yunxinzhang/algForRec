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
    bool hasPathSum(TreeNode* root, int sum) {
	if(!root)
		return false;
	if( !root->left && !root->right && root->val == sum){
		return true;
	}
	return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum - root->val);
    }
};

int main(){
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(3);
	root->right = new TreeNode(6);
	cout <<  Solution().hasPathSum(root, 6) << endl;
}
