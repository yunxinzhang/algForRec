#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool helper(TreeNode* node, int p, vector<TreeNode*> &path){
	if( !node )
		return false;
	if( node->val == p ){
		path.push_back(node);
		return true;
	}
	path.push_back( node);
	if (helper( node->left, p, path ))
		return true;
	if (helper( node->right,p, path ))
		return true;
	path.pop_back();
	return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode *p, TreeNode* q) {
	vector<TreeNode*>path1, path2;
	helper(root,p->val, path1);
	helper(root,q->val, path2);
	unordered_set<int> uset;
	for(auto it : path1)
		uset.insert(it->val);
	for(auto it = path2.rbegin(); it!=path2.rend(); ++it){
		if(uset.find( (*it)->val ) != uset.end())
			return *it;
 	}
	return nullptr;
    }
};

int main(){
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(6);
	TreeNode *p = new TreeNode(2);
	TreeNode *q = new TreeNode(6);
	vector<int> v;
	TreeNode* tn = Solution().lowestCommonAncestor(root, p, q);
	cout << tn->val <<endl;
}
