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
    void helper( vector<int> & nums, TreeNode*& node, int st, int ed){
	int mid = (st+ed)/2;
	node = new TreeNode(nums[mid]);
	if( mid-1 >= st )
		helper(nums, node->left, st, mid-1);
	if( ed >= mid+1 )
		helper(nums, node->right,mid+1, ed);
    }
    TreeNode* sortedArrayToBST( vector<int> &nums) {
	TreeNode *ans = nullptr;
	helper(nums, ans, 0, nums.size()-1);
	return ans;
    }
};
void disp(TreeNode * root){
	if( !root )
		return;
	cout << root->val << endl;
	if( root->left )
		cout << root->val << "-left->" << root->left->val <<endl;
	if( root->right )
		cout << root->val << "-right->" << root->right->val <<endl;
	disp( root->left );
	disp( root->right);
}
int main(){
	vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	TreeNode * ans = Solution().sortedArrayToBST(vec);
	disp(ans);
}
