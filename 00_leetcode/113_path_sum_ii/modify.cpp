#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void helper(TreeNode* node , vector<int> &path, vector<vector<int>>& ans, int sum){
	if( !node )
		return;
	if( !node->left && !node->right ){
	    if(node->val == sum){
		path.push_back( sum );
		ans.push_back(path);
		path.pop_back();
	    }
	    return;
	}
	path.push_back(node->val);
	helper(node->left, path, ans, sum - node->val);
	helper(node->right,path, ans, sum - node->val);
	path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
	if( !root )
		return {};
	vector<int> path;
	vector<vector<int>> ans;
	helper(root, path, ans, sum);
	return ans;
    }
};

int main(){
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(6);
	vector<vector<int>> ans = Solution().pathSum(root, 6);
	for( auto it : ans ){
		for( auto it2 : it )
			cout << it2 << " ";
		cout <<endl;
	}
}
