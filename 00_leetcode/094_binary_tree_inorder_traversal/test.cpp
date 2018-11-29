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
		void inorder( TreeNode* node , vector<int> & ans){
				if( node == nullptr )
						return;
				else{
						inorder(node->left, ans );
						ans.push_back(node->val);
						inorder(node->right, ans);
				}
		}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		inorder(root, ans);						        
		return ans;    
	}
};
int main(){
	TreeNode root(1);
	TreeNode right(2);
	root.right = &right;
	TreeNode rleft(3);
	root.right->left = &rleft;
	vector<int> ans = Solution().inorderTraversal(&root);
	for(auto it : ans)
			cout << it << endl;
}
