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
	int n = 0;
	if( !node )
		return 0;
	if( node->val == sum ){
		++n;
	}
    	n += helper( node->left,  sum - node->val);	
    	n += helper( node->right, sum - node->val);
	return n;
    }
    void helper2(TreeNode* node, int sum, int& ans){
	if( !node )
		return;
	ans += helper(node, sum);
	helper2(node->left, sum, ans);
	helper2(node->right,sum, ans);
    }
    int pathSum(TreeNode* root, int sum) {
	int ans = 0;	
	if( !root )
		return ans;
	helper2(root, sum, ans);
	return ans;
    }
};

int main(){
	TreeNode *root = new TreeNode(6);
	root->left = new TreeNode(0);
	root->right = new TreeNode(1);
	cout <<  Solution().pathSum(root, 6) << endl;
}
