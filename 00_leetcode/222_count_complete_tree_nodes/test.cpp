#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
	if(!root)
		return 0;
	TreeNode * lr = root, * rr = root;
	int ln = 0, rn = 0;
	while( lr ){
		++ln;
		lr = lr->left;
	}
	while( rr ){
		++rn;
		rr = rr->right;
	}
	if( ln == rn )
		return pow(2, rn) -1;
	return countNodes( root-> left ) + countNodes( root->right ) + 1;
    }
};

int main(){
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(6);
	cout <<  Solution().countNodes(root) << endl;
}
