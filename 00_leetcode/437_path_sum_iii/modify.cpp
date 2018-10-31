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
    int helper(TreeNode* node, int sum){
	if( !node )
		return 0;
	int n = 0;
	if( node->val == sum ){
		++n;
	}
    	n += helper( node->left,  sum - node->val);	
    	n += helper( node->right, sum - node->val);
	return n;
    }
    int pathSum(TreeNode* root, int sum) {
	if( !root )
		return 0;
	return helper(root, sum) + pathSum(root->left,sum) + pathSum(root->right, sum);
    }
};

int main(){
	TreeNode *root = new TreeNode(6);
	root->left = new TreeNode(6);
	root->right = new TreeNode(6);
	cout <<  Solution().pathSum(root, 6) << endl;
}
