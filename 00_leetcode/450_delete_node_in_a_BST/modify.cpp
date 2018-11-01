#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* getMin(TreeNode* node){
	TreeNode * cur = node->right;
	while( cur  && cur->left ){
		cur = cur->left;
	}
	return cur;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
	if( !root )
		return nullptr;
	if( root->val == key ){
		if( !root->left )
			return root->right;
		if( !root->right )
			return root->left;
		TreeNode * p = getMin(root);
		root->val = p->val;
		root->right = deleteNode(root->right, p->val);
		delete p;
		return root;
	}else{
		if(root->val > key ){
			root->left = deleteNode(root->left, key);
		}
		else if(root->val < key)
			root->right = deleteNode( root->right, key );
	}
	return root;
    }
};
void disp(TreeNode* root){
	if( !root )
		return;
	disp(root->left);
	cout <<"disp >> "<< root->val << endl;
	disp(root->right);
//	cout << "======" <<endl;
}

int main(){
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(6);
	root->right->right = new TreeNode(7);
	disp(root);
	cout <<"-----"<<endl;
	Solution().deleteNode(root, 3);
	disp(root);
	cout << (root->left == nullptr)<<endl;
}
