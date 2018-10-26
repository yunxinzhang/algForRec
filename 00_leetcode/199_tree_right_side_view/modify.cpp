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
    void level( TreeNode * root, int lv, vector<int> & ans ){
	if(root == nullptr)
	    return;
	if( lv == ans.size() ){// 1 0
	    ans.push_back( root->val );
	}
	if(root->right != NULL)
	    level( root->right, lv+1, ans );
	if(root->left != NULL)
	    level( root->left, lv+1, ans );
    }
    vector<int> levelOrder(TreeNode* root) {
  	vector<int> ans;
	level( root, 0, ans );
	return ans;		        
    }
};

int main(){
	TreeNode root(3);
	TreeNode lr(9);
	TreeNode rr(20);
	TreeNode lrr(15);
	TreeNode rrr(7);
	root.left = &lr;
	root.right = &rr;
	rr.left = & lrr;
	rr.right = & rrr;
	vector<int> v = Solution().levelOrder( &root );
	for(auto it : v){
		cout << it<< " ";
	}
		
}
