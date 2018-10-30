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
    int height(TreeNode * node, bool& flag){
	if( !node ){
		return 0;
	}
	int l = height( node->left, flag);
	int r = height( node->right,flag);
	if( abs(l-r) > 1)
		flag = false;
	return max( l , r ) + 1;
    }
    bool isBalanced(TreeNode* root) {
	if( !root )
		return true;
	bool flag = true;
	height(root, flag);
	return  flag;	
    }
};

int main(){
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(1);
	//root->right = new TreeNode(6);
	cout <<  Solution().isBalanced(root) << endl;
}
