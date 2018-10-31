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
    void help(TreeNode* node, int sum, int& ans){
	if( !node )
		return;
	if( !node->left && !node->right ){
		ans += sum + node->val;
		return; 		
	}else{
		help(node->left, (sum + node->val)*10, ans);
		help(node->right,(sum + node->val)*10, ans);	
	}		
    }
    int sumNumbers(TreeNode* root) {
	int ans = 0;
	help(root, 0, ans);	
	return ans;
    }
};

int main(){
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(6);
	cout <<  Solution().sumNumbers(root) << endl;
}
