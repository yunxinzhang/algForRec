#include <iostream>
#include <unordered_map>
using namespace std;
struct TreeNode {
 	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	unordered_map<TreeNode*, int> um;
	int _rob(TreeNode* & root){
		if(!root)
				return 0;
		auto it = um.find(root);
		if(it != um.end())
				return it->second;
		int cur = root->val;
		if(root->left)
			cur += _rob(root->left->left) + _rob(root->left->right);
		if(root->right)
			cur += _rob(root->right->left) + _rob(root->right->right);
		cur = max(cur, _rob(root->left) + _rob(root->right));
		um.insert(make_pair(root, cur));
		return um;
	}	
	int rob(TreeNode* root) {
		return _rob(root);	
	}
};
	
