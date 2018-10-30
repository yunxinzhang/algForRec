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
    int maxDepth(TreeNode* root) {
        if( root == nullptr )
		return 0;
	return max( maxDepth(root->left), maxDepth(root->right) ) + 1;  
    }
};

int main(){
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(5);
	cout << Solution().maxDepth( root ) << endl;
}
