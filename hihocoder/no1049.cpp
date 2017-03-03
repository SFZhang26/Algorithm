#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <map>
#include <string>
#include <bitset>
#include <set>

using namespace std;

typedef long long ll;

int T;

struct TreeNode {
	char val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(char c) :val(c), left(NULL), right(NULL) {};
};

TreeNode* build(string preorder, int start1, int end1,string inorder, int start2, int end2) {
	if (start1 > end1) return NULL;
	TreeNode *root = new TreeNode(preorder[start1]);
	if (start1==end1){
		return root;
	}

	for (int i = start2; i <= end2; i++) {
		if (inorder[i] == preorder[start1]) {
			root->left = build(preorder, start1 + 1, start1 + i - start2, inorder, start2, i - 1);
			root->right = build(preorder, start1 + i - start2 + 1, end1, inorder, i + 1, end2);
			break;
		}
	}
	return root;
}

void printPostOrder(TreeNode *root) {
	if (root == NULL) return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout << root->val;
}


int main() {
	string preorder, inorder;
	string postorder;
	cin >> preorder >> inorder;

	TreeNode *root = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	printPostOrder(root);
	return 0;
}