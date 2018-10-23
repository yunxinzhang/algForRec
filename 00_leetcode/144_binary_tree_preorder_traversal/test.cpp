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
		void preorder( TreeNode* node , vector<int> & ans){
				if( node == nullptr )
						return;
				else{
						ans.push_back(node->val);
						preorder(node->left, ans );
						preorder(node->right, ans);
				}
		}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ans;
		preorder(root, ans);						        
		return ans;    
	}
};
int main(){
	TreeNode root(1);
	TreeNode right(2);
	root.right = &right;
	TreeNode rleft(3);
	root.right->left = &rleft;
	vector<int> ans = Solution().preorderTraversal(&root);
	for(auto it : ans)
			cout << it << endl;
}
