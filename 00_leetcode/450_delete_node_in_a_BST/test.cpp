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
	if ( !node->left ){
		return node;
	}
	if( !node->left->left ){
		TreeNode* cur = node->left;
		node->left = cur->right;
		//cur->right = node;
		return cur;
	}
	return getMin(node->left);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
	if( !root )
		return nullptr;
	if( root->val == key ){
		if( !root->right ){
			TreeNode * cur = root->left;
			//cout << ">>>";
			//cout << (cur==nullptr)<<endl;
			delete root;
			return cur;
		}else{
			TreeNode * cur = getMin(root->right);
			cur->left = root->left;
			if(cur->val == root->right->val)
				cur->right = root->right->right;
			else
				cur->right = root->right;
			delete root;
			return cur;
		}
	}else{
		if(root->val > key ){
			TreeNode* t = deleteNode(root->left, key);
			//cout <<"...";
			//cout << (t==nullptr)<<endl;;
			root->left = t;
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
