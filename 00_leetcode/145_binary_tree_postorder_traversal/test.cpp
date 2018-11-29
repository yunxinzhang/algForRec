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
		void postorder( TreeNode* node , vector<int> & ans){
				if( node == nullptr )
						return;
				else{
						postorder(node->left, ans );
						postorder(node->right, ans);
						ans.push_back(node->val);
				}
		}
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ans;
		postorder(root, ans);						        
		return ans;    
	}
};
int main(){
	TreeNode root(1);
	TreeNode right(2);
	root.right = &right;
	TreeNode rleft(3);
	root.right->left = &rleft;
	vector<int> ans = Solution().postorderTraversal(&root);
	for(auto it : ans)
			cout << it << endl;
}
