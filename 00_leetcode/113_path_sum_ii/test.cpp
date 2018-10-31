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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
	if( !root )
		return {};
	vector<vector<int>> ans;
	if( !root->left	 && !root->right )
		if( root->val == sum )
			return vector<vector<int>>(1, vector<int>(1,sum));
		else
			return {};
	vector<vector<int>> v1 = pathSum( root->left, sum - root->val );
	for(auto it : v1){
		vector<int> temp(1, root->val);
		for(auto it2 : it )
			temp.push_back( it2 );
		ans.push_back(temp);
	}
	vector<vector<int>> v2 = pathSum( root->right,sum - root->val );	
	for(auto it : v2){
		vector<int> temp(1, root->val);
		for(auto it2 : it )
			temp.push_back( it2 );
		ans.push_back(temp);
	}
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
