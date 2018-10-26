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
    void level( TreeNode * root, int lv, vector<vector<int>> & ans ){
	if(root == nullptr)
	    return;
	if( lv > ans.size() ){// 1 0
	    ans.push_back( vector<int>( 1, root->val ));
	}else{
	    ans[lv-1].push_back( root->val );
	}
	if(root->left != NULL)
	    level( root->left, lv+1, ans );
	if(root->right != NULL)
	    level( root->right, lv+1, ans );
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
  	vector<vector<int>> ans;
	level( root, 1, ans );
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
	vector<vector<int>> v = Solution().levelOrder( &root );
	for(auto it : v){
		for( auto it2 : it )
			cout << it2 << " ";
		cout << endl;
	}
		
}
