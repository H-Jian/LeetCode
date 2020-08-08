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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (postorder.size() != inorder.size() || postorder.empty() || inorder.empty())return NULL;
		int pos = postorder.size() - 1;
		return buildTree(inorder, postorder, 0, pos, inorder.size()-1);
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int l, int &mid, int r) {
		if (l > r || mid < 0) return NULL;
		TreeNode* root = new TreeNode(postorder[mid]);
		int ihead = l;
		while (ihead <= r && inorder[ihead] != postorder[mid])
			ihead++;
		if (ihead + 1 <= r)
			root->right = buildTree(inorder, postorder, ihead + 1, --mid, r);
		if (l <= ihead - 1)
			root->left = buildTree(inorder, postorder, l, --mid, ihead - 1);
		return root;
	}
};