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
    bool isSameTree(TreeNode* p, TreeNode* q) {
	if( (!p && q )||( !q && p ) )
		return false;
	if( !p && !q )
		return true;
	if( p->val != q->val )
		return false;
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(){
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(6);
	TreeNode *root2 = new TreeNode(4);
	root2->left = new TreeNode(2);
	root2->right = new TreeNode(7);
	cout <<  Solution().isSameTree(root, root2) << endl;
}
