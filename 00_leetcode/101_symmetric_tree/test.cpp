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
    bool isSymmetric(TreeNode* p, TreeNode* q){
	if( (!p && q )||( !q && p ) )
		return false;
	if( !p && !q )
		return true;
	if( p->val != q->val )
		return false;
	return isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
	if( !root )
		return true;
	return isSymmetric( root->left, root->right);
    }
};

int main(){
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	cout <<  Solution().isSymmetric(root) << endl;
}
