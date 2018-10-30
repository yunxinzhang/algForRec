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
	TreeNode * l = root, * r = root;
	int h = 0;
	while( r ){
		++h;
		l = l->left;
		r = r->right;
	}
	if( !l )
		return pow(2, h) -1;
	return countNodes( root-> left ) + countNodes( root->right ) + 1;
    }
};

int main(){
	TreeNode *root = new TreeNode(-1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(6);
	cout <<  Solution().countNodes(root) << endl;
}
