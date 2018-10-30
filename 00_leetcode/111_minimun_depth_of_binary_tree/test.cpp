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
    int minDepth(TreeNode* root) {
        if( root == nullptr )
		return 0;
	if( root->left == nullptr && root->right == nullptr )
		return 1;
	else if( root->left && root->right )
		return min( minDepth(root->left), minDepth(root->right) ) + 1;  
	else if( root->left )
		return minDepth(root->left) + 1;
	else 
		return minDepth(root->right) + 1;
    }
};

int main(){
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(5);
	cout << Solution().minDepth( root ) << endl;
}
