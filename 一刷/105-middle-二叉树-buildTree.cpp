#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<limits.h>
#include<queue>
#include<deque>
#include<stack>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() != inorder.size() || preorder.empty() || inorder.empty())return NULL;
		return buildTree(preorder, inorder, 0, 0, inorder.size());
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int l, int mid, int r) {
		if (r - l == 0) return NULL;
		int val = preorder[mid];
		int inIdx = l;
		while (inorder[inIdx] != val)
			inIdx++;
		int lend = inIdx;
		int rstart = inIdx + 1;
		TreeNode* root = new TreeNode(val);
		root->left = buildTree(preorder, inorder, l, mid + 1, lend);
		root->right = buildTree(preorder, inorder, rstart, mid + 1 + (lend - l), r);
		return root;
	}
};