#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int height(TreeNode * node){
	if( !node )
		return 0;
	return max( height( node->left ) , height( node->right ) ) + 1;
    }
    bool isBalanced(TreeNode* root) {
	if( !root )
		return true;
	int hl = height( root->left );
	int hr = height( root->right);
	return abs(hl-hr) <=1 && isBalanced(root->left) && isBalanced(root->right) ;	
    }
};

int main(){
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(1);
	//root->right = new TreeNode(6);
	cout <<  Solution().isBalanced(root) << endl;
}
