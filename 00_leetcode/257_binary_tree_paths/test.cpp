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
    vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> ans;
	if( !root )
		return 	ans;
	if( !root->left && !root->right){
		ans.push_back(to_string(root->val));
		return ans;
	}
	vector<string> v1 = binaryTreePaths( root->left );
	for(auto it : v1)
		ans.push_back( to_string(root->val) +"->"+ it );
	vector<string> v2 = binaryTreePaths( root->right);	
	for(auto it : v2)
		ans.push_back( to_string(root->val) +"->"+ it );
	return ans;
    }
};

int main(){
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(6);
	vector<string> v = Solution().binaryTreePaths(root);
	for(auto it : v)
		cout << it << endl;
}
