#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
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
	int res = INT_MIN;
	int helper(TreeNode* root) {
		if (!root) return 0;
		int left = max(helper(root->left), 0);
		int right = max(helper(root->right), 0);
		int value = root->val + left + right;
		res = max(value, res);

		return root->val + max(left, right);
	}
	int maxPathSum(TreeNode* root) {
		helper(root);
		return res;
	}
};