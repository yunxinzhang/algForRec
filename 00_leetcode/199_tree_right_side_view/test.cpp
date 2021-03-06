#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
	vector<int> ans;
	if(root == nullptr)
		return ans;
	queue<TreeNode*> q;
	q.push(root);
	int lc = 0, ln = 1, cnt = 0;
	TreeNode* node;
	while( !q.empty() ){
		node = q.front();
		q.pop();
		++lc;	
		if(node->left){
			q.push(node->left);
			++cnt;
		}
		if(node->right){
			q.push(node->right);
			++cnt;
		}
		if( lc == ln ){
			ans.push_back( node->val );
			lc = 0;
			ln = cnt;
			cnt = 0;
		}		
	}
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
		cout << it << " ";
	}
		
}
